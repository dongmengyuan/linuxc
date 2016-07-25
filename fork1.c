/*************************************************************************
        > File Name: fork1.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年07月25日 星期一 17时35分40秒
 ************************************************************************/

 #include<stdio.h>
 #include<sys/types.h>
 #include<unistd.h>

 int main(void)
 {
     pid_t pid;               //将pid定义为pid_t类型，等价于int pid;
     pid = fork();            //调用fork函数创建自进程，pid用于记录返回值
     switch(pid) {
         case 0:printf("child process is running now,childpid is %d,parentpid is %d\n",pid,getppid() );
                break;
         case -1:printf("process creation failed\n");
                 break;
         default:
                printf("parent process is running now,childpid is %d,parentpid is %d\n",getpid(),pid);
                break;
     }

 }

