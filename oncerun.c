/*************************************************************************
        > File Name: oncerun.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年08月01日 星期一 19时55分47秒
 ************************************************************************/

//函数只被执行一次


#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void run(void)
{
    printf("function run is running in thread %lu\n",pthread_self());
}

void * thread1(void *arq)
{
    pthread_t thid = pthread_self();
    printf("current thread's ID is %lu\n",thid);
    pthread_once(&once,run);
    printf("thread1 ends\n");
}


void * thread2(void *arq)
{
    pthread_t thid = pthread_self();
    
    printf("current thread's ID is %lu\n",thid);
    pthread_once(&once,run);
    printf("thread2 ends\n");
}

int main()
{
    pthread_t thid1,thid2;

    pthread_create(&thid1,NULL,thread1,NULL);
    pthread_create(&thid2,NULL,thread2,NULL);
    sleep(3);
    printf("main thread exit !\n");
    exit(0);
}

