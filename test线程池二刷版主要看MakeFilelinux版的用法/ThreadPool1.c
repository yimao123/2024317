﻿#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include "ThreadPool1.h"

#define DEFAULT_TIME 10                 /*10s检测一次*/
#define MIN_WAIT_TASK_NUM 10            /*如果queue_size > MIN_WAIT_TASK_NUM 添加新的线程到线程池*/ 
#define DEFAULT_THREAD_VARY 10          /*每次创建和销毁线程的个数*/
#define true 1
#define false 0

typedef struct
{
	//任务队列实质是给线程设置回调函数
	void *(*function)(void*);/*函数指针，回调函数*/
	void *arg;   /*上面函数的参数*/
}threadpool_task_t;//匿名结构体别名
/*描述线程相关信息*/
struct threadpool_t/*数据类型*/
{
	pthread_mutex_t lock;		/*用于所著本结构体*/
	pthread_mutex_t thread_counter;		/*记录忙状态线程个数的锁--busy_thr_num*/
	pthread_cond_t queue_not_full;		/*当任务队列满时，添加任务的线程阻塞，等待此条件的满足*/
	pthread_cond_t queue_not_empty;		/*任务队列里不为空时，通知等待任务的线程，*/

	pthread_t *threads;		/*存放线程池中每个线程的tid,数组*/
	pthread_t adjust_tid;	/*存管理线程tid*/
	threadpool_task_t *task_queue;		/*任务队列*/

	int min_thr_num;	/*线程池最小线程数*/
	int max_thr_num;	/*线程池最大线程数*/
	int live_thr_num;	/*当前存活线程数*/
	int busy_thr_num;	/*忙状态线程数*/
	int wait_exit_thr_num;		/*要销毁的线程个数*/

	int queue_front;	/*task_queue对头下标*/
	int queue_rear;		/*tadk_queue队尾下标*/
	int queue_size;		/*task_queue队中实际任务数*/
	int queue_max_size;		/*task_queue队列可容纳任务数上限*/
	int shutdown;		/*标志位，线程池使用状态，true或false*/

};
/*判断队列与线程之间的关系*/
void *threadpool_thread(void *threadpool);

//管理者线程
void *adjust_thread(void *threadpool);
//是否是活着的线程
int is_thread_alive(pthread_t tid);
//线程池资源的释放
int threadpool_free(threadpool_t *pool);
threadpool_t * threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size)
{
	/*初始化线程池*/
	int i;
	threadpool_t *pool = NULL;
	do/*配合break语句类似于goto语句的用法*/
	{
		if ((pool = (threadpool_t*)malloc(sizeof(threadpool_t))) == NULL)
		{
			printf("malloc threadpool fail");
			break;
		}
		//初始化初始值
		pool->min_thr_num = min_thr_num;
		pool->max_thr_num = max_thr_num;
		pool->busy_thr_num = 0;
		pool->live_thr_num = min_thr_num;
		pool->queue_size = 0;
		pool->queue_max_size = queue_max_size;
		pool->queue_front = 0;
		pool->queue_rear = 0;
		pool->shutdown = false;/*不关闭线程池*/
		//根据最大线程上限数据，开工作线程数组开辟空间，并清零
		pool->threads = (pthread_t*)malloc(sizeof(pthread_t)*max_thr_num);
		if (pool->threads == NULL)
		{
			printf("malloc threads fail");
			break;
		}
		memset(pool->threads, 0, sizeof(pthread_t)*max_thr_num);
		/*队列开辟空间*/
		pool->task_queue = (threadpool_task_t*)malloc(sizeof(threadpool_task_t)*queue_max_size);
		if (pool->task_queue == NULL)
		{
			printf("malloc task_queue faile");
			break;
		}
		/*初始化互斥锁，条件变量*/
		if (pthread_mutex_init(&(pool->lock), NULL) != 0
			||pthread_mutex_init(&(pool->thread_counter),NULL)!=0
			||pthread_cond_init(&(pool->queue_not_empty),NULL)!=0
			||pthread_cond_init(&(pool->queue_not_full),NULL)!=0)
		{
			printf("init the lock or cond failed");
			break;
		}
		//启动线程初始值
		for (i = 0; i < min_thr_num; i++)
		{
			pthread_create(&pool->threads[i], NULL, threadpool_thread, (void*)pool);

		}
		pthread_create(&(pool->adjust_tid), NULL, adjust_thread, (void*)pool);/*启动管理者线程*/
		return pool;


	} while (0);
	threadpool_free(pool);
	return NULL;
}
/*向线程池中添加一个任务*/
int threadpool_add(threadpool_t * pool, void *(*function)(void *arg), void * arg)
{
	//线程池专用锁
	pthread_mutex_lock(&(pool->lock));
	/*队列中满了，线程池没有关闭，调用线程添加函数会阻塞*/
	while ((pool->queue_size == pool->queue_max_size) && (!pool->shutdown))
	{
		pthread_cond_wait(&(pool->queue_not_full), &(pool->lock));
	}
	if (pool->shutdown)
	{
		//如果线程池不存在，就解锁
		pthread_mutex_unlock(&(pool->lock));
	}
	/*以下是满足添加的执行语句：队列没满*/
	/*清空工作线程调用的回调函数的参数*/
	if (pool->task_queue[pool->queue_rear].arg != NULL)
	{
		free(pool->task_queue[pool->queue_rear].arg);
		pool->task_queue[pool->queue_rear].arg = NULL;
	}
	/*添加任务到任务队列中，队尾添加*/
	pool->task_queue[pool->queue_rear].function = function;
	pool->task_queue[pool->queue_rear].arg = arg;
	pool->queue_rear = (pool->queue_rear + 1) % pool->queue_max_size;/*模拟环形队列*/
	pool->queue_size++;
	/*添加完任务后，队列不为空，唤醒线程池中等待处理任务的线程*/
	pthread_cond_signal(&(pool->queue_not_empty));/*任务队列不为空，唤醒线程中的线程*/
	/*线程池添加任务结束，解开互斥锁*/
	pthread_mutex_unlock(&(pool->lock));
	return 0;
}

//线程池中各个工作线程
void *threadpool_thread(void *threadpool)
{
	threadpool_t *pool = (threadpool_t*)threadpool;
	//任务
	threadpool_task_t task;
	while (true)
	{
		/*刚创建出线程，等待任务队列里有任务，否则阻塞等待任务队列里有任务后再唤醒接受任务*/
		pthread_mutex_lock(&pool->lock);/*只要是改动线程池，就必须枷锁*/
		/*任务为零的情况开始*/
		while ((pool->queue_size==0)&&(!pool->shutdown))
		{
			printf("thread 0x%x is waiting\n", (unsigned int)pthread_self());
			pthread_cond_wait(&(pool->queue_not_empty), &(pool->lock));
			/*清除指定数目的空闲线程，如果要结束的线程个数大于0，结束线程*/
			if (pool->wait_exit_thr_num > 0)
			{
				pool->wait_exit_thr_num--;
				/*如果线程池里个数大于最小值时可以结束当前线程*/
				if (pool->live_thr_num > pool->min_thr_num)
				{
					printf("thread 0x%x is exiting\n", (unsigned int)pthread_self());
					pool->live_thr_num--;
					pthread_mutex_unlock(&(pool->lock));
					pthread_exit(NULL);
				}
			}
		}
		/*如果指定了true,需要关闭线程池中每个线程，自行退出处理*/
		if (pool->shutdown)
		{
			//如果线程池销毁，还阻塞啥，直接退出
			pthread_mutex_unlock(&(pool->lock));
			printf("thread 0x%x is exiting\n", (unsigned int)pthread_self());
			pthread_exit(NULL);
		}
		/*从任务线程中获取任务，是一个出队操作*/
		task.function = pool->task_queue[pool->queue_front].function;
		task.arg = pool->task_queue[pool->queue_front].arg;
		pool->queue_front = (pool->queue_front + 1) % pool->queue_max_size;
		/*出队，模拟队列，对头偏移还是对头，下标*/
		pool->queue_size--;
		/*通知有新的任务添加进来*/
		pthread_cond_broadcast(&(pool->queue_not_full));
		/*任务取出后，立即将线程池锁释放*/
		pthread_mutex_unlock(&(pool->lock));

		/*执行任务*/
		printf("thread 0x%x start working\n", (unsigned int)pthread_self());
		/*忙状态线程数变量锁*/
		pthread_mutex_lock(&(pool->thread_counter));
		pool->busy_thr_num++;
		pthread_mutex_unlock(&(pool->thread_counter));
		/*执行回调函数任务*/
		(*(task.function))(task.arg);/*函数名就是指针，指针就是函数名，*/
		//task.function(task.arg);
		
		/*任务结束处理*/
		printf("thread 0x%x end working\n", (unsigned int)pthread_self());
		pthread_mutex_lock(&(pool->thread_counter));
		pool->busy_thr_num--;
		pthread_mutex_unlock(&(pool->thread_counter));
		//不会释放，继续阻塞
		
	}
	pthread_exit(NULL);

}
/*管理线程*/
void *adjust_thread(void *threadpool)
{
	int i;
	threadpool_t *pool = (threadpool_t*)threadpool;
	while (!pool->shutdown)
	{
		sleep(DEFAULT_TIME);
		/*池锁*/
		pthread_mutex_lock(&(pool->lock));
		/*关注任务数*/
		int queue_size = pool->queue_size;
		int live_thr_num = pool->live_thr_num;/*存活线程数*/
		pthread_mutex_unlock(&(pool->lock));

		/*忙线程数*/
		pthread_mutex_lock(&(pool->thread_counter));
		int busy_thr_num = pool->busy_thr_num;
		pthread_mutex_unlock(&(pool->thread_counter));

		/*创建新线程算法：任务数大于最小线程池个数，且存活的线程数少于最大线程个数时:如30>=10&&40<100*/
		if (queue_size >= MIN_WAIT_TASK_NUM && live_thr_num < pool->max_thr_num)
		{
			pthread_mutex_lock(&(pool->lock));
			int add = 0;
			/*一次增加10个线程*/
			for (i = 0; i < pool->max_thr_num&&add < DEFAULT_THREAD_VARY&&pool->live_thr_num<pool->max_thr_num;i++)
			{
				if (pool->threads[i] == 0 || !is_thread_alive(pool->threads[i]))
				{
					pthread_create(&(pool->threads[i]), NULL, threadpool_thread, (void*)pool);
					add++;
					pool->live_thr_num++;
				}
			}
			pthread_mutex_unlock(&(pool->lock));
		}
		/*销毁多余的空闲：算法：忙线程X2小于存活的线程数且存活的线程数大于最小线程数时*/
		if ((busy_thr_num * 2) < live_thr_num&&live_thr_num > pool->min_thr_num)
		{
			/*一次销毁10个线程，随机10个即可*/
			pthread_mutex_lock(&(pool->lock));
			pool->wait_exit_thr_num = DEFAULT_THREAD_VARY;
			pthread_mutex_unlock(&(pool ->lock));

			for (i = 0; i < DEFAULT_THREAD_VARY; i++)
			{
				/*通知处在空闲状态的线程，他们会自行结束*/
				pthread_cond_signal(&pool->queue_not_empty);
			}

		}
	}
	return NULL;
}
int threadpool_destroy(threadpool_t * pool)
{
	int i;
	if (pool == NULL)
	{
		return -1;
	}
	pool->shutdown = true;
	/*先销毁管理线程*/
	pthread_join(pool->adjust_tid, NULL);
	for (i = 0; i < pool->live_thr_num; i++)
	{
		/*通知所有的线程：发送一个假消息*/
		pthread_cond_broadcast(&pool->queue_not_empty);
	}
	for (i = 0; i < pool->live_thr_num; i++)
	{
		pthread_join(pool->threads[i], NULL);
	}
	threadpool_free(pool);
	return 0;
}
/*释放初始资源*/
int threadpool_free(threadpool_t *pool)
{
	if (pool == NULL)
	{
		return -1;
	}
	if (pool->task_queue)
	{
		free(pool->task_queue);
	}
	if (pool->threads)
	{
		pthread_mutex_lock(&(pool->lock));
		pthread_mutex_destroy(&(pool->lock));
		pthread_mutex_lock(&(pool->thread_counter));
		pthread_mutex_destroy(&(pool->thread_counter));
		pthread_cond_destroy(&(pool->queue_not_empty));
		pthread_cond_destroy(&(pool->queue_not_full));
	}
	free(pool);
	pool = NULL;
	return 0;
}
int threadpool_all_thread_num(threadpool_t * pool)
{
	int all_threadnum = -1;
	pthread_mutex_lock(&(pool->lock));
	all_threadnum = pool->live_thr_num;
	pthread_mutex_unlock(&(pool->lock));
	return all_threadnum;
	
}

int threadpool_busy_thread_num(threadpool_t * pool)
{
	/*获取忙线程个数*/
	int busy_threadnum = -1;
	pthread_mutex_lock(&(pool->thread_counter));
	busy_threadnum = pool->busy_thr_num;
	pthread_mutex_unlock(&(pool->thread_counter));
	
	return busy_threadnum;
}
/*判断线程是否活着*/
int is_thread_alive(pthread_t tid)
{
	int kill_rc = pthread_kill(tid, 0);/*发0信号，测试线程是否存活*/
	if (kill_rc == ESRCH)
	{
		return false;
	}
	return true;
}
