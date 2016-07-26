/*************************************************************************
        > File Name: fork3.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年07月26日 星期二 09时18分03秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


int main(void)
{
    pid_t pid;
    
    pid = fork();
    switch(pid){
        case 0:
     while(1) {
            printf("A background process, PID:%d\n,ParentID: %d\n",getpid(),getppid());
            sleep(3);
        }
        case -1:
            perror("Process creation failed\n");
            exit(-1);
        default:
            printf("I am parent process ,my pid is %d\n",getpid());
            exit(0);
    }
    return 0;
}
