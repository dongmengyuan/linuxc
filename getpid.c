/*************************************************************************
        > File Name: getpid.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年07月27日 星期三 15时33分53秒
 ************************************************************************/

/*getpid用来获取当前进程的ID*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>


int main(void)
{
    pid_t pid;
    pid = fork();
    if(pid == -1) {
        printf("fork error\n");
        exit(1);
    }
    if(pid == 0) 
        printf("getpid return %d\n",getpid());
    exit(0);
}
