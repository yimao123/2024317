#pragma once
#ifndef __THREADPOOL_H_
#define __THREADPOOL_H_


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<pthread.h>
//自定义类型
typedef struct threadpool_t threadpool_t;

//创建线程池
threadpool_t *threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size);

//往线程池中添加线程
int threadpool_add(threadpool_t *pool, void*(*function)(void *arg), void *arg);

//销毁线程池

int threadpool_destroy(threadpool_t *pool);

//计算所有的线程个数
int threadpool_all_thread_num(threadpool_t *pool);

//计算所有忙线程的总数
int threadpool_busy_thread_num(threadpool_t *pool);

#endif // !__THREADPOOL_H_