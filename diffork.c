/*************************************************************************
        > File Name: diffork.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年07月26日 星期二 09时59分25秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int g = 5;

int main(void)
{
    pid_t pid;
    int i;
    int v = 1;
    pid = fork();
    /*pid = vfork()*/;
    switch(pid) {
        case 0:
              i = 3;
        while(i-- > 0) {
            printf("child process is running\n");
            g++;
            v++;
            sleep(1);
        }
        printf("child's g = %d,v = %d\n",g,v);
        break;
        case -1:
              perror("process creation is failed\n");
              exit(0);
        default:
              i = 5;
        while(i-- > 0) {
            printf("parent process is running\n");
            g++;
            v++;
            sleep(1);
        }
        printf("parent's g = %d,v = %d\n",g,v);
        exit(0);
    }
      
}
