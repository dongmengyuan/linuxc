/*************************************************************************
        > File Name: fork2.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年07月25日 星期一 20时42分06秒
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
    pid_t pid;
    char * msg;
    int k = 3;

    pid = fork();
    switch(pid) {
        case 0:
              msg = "child process is running";
              k = 3;
              break;
        case -1:
              msg = ("process creation failed\n");
              break;
        default :
              msg = "parent process is running";
              k = 5;
              break;
    }

    while(k > 0) {
        puts(msg);
        sleep(1);
        k--;
    }
  
    exit(0);

}
