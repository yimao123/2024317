

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "ThreadPool1.h"
void *process(void *arg)
{
	printf("thread 0x%x working on task %d\n", (unsigned int)pthread_self(), *(int*)arg);
	sleep(1);
	printf("task %d is end\n", *(int*)arg);
	return NULL;
}
void test01()
{
	/*创建线程池池里最小3个线程，最大100个线程，队列最大100*/
	threadpool_t *thp = threadpool_create(3, 100, 100);
	printf("pool inited\n");
	int num[20], i;
	for (i = 0; i < 20; i++)
	{
		num[i] = i;
		printf("add task %d\n", i);
		threadpool_add(thp, process, (void*)&num[i]);
		
	}
	printf("子线程完工\n");
	sleep(10);/*等待子线程完成任务*/
	threadpool_destroy(thp);
}
int main()
{
	test01();


	
	return 0;
}
