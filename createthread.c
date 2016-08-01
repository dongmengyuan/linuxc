/*************************************************************************
        > File Name: createthread.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年08月01日 星期一 19时26分47秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int *thread(void *arq)
{
    pthread_t newthid;

    newthid = pthread_self();
    printf("this is a new thread,thread ID = %lu\n",newthid);
    return NULL;
}

int main(void)
{
    pthread_t thid;

    printf("main thread ,ID is %lu\n",pthread_self());     //打印主线程的ID
    if(pthread_create(&thid,NULL,(void *)thread,NULL) != 0) {
        printf("thread creation failed\n");
        exit(1);
    }
    sleep(1);
    exit(0);
}
 

