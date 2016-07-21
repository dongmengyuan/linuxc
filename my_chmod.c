/*************************************************************************
        > File Name: my_chmod.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年07月21日 星期四 08时33分23秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char ** argv)
{
    int mode;                            //权限
    int mode_u;                          //所有者的权限
    int mode_g;                          //所属组的权限
    int mode_o;                          //其他用户的权限
    char *filename;


    /*检查参数个数的合法性*/
    if (argc  < 3) {                             //参数默认为3个(chmod 777 test.c);
                                                 //argv[0]:指向程序的全路径名
                    //                           //argv[1]:指向命令行中执行程序名后的第一个字符串
                    //                           //argv[2]:指向第二个字符串
        printf("%s <mode num> <target file>", argv[0]);
        exit(0);

    }

    /*获取命令行参数*/
    mode = atoi(argv[1]);               //atoi()函数将字符串转换成整形数
    if (mode > 777 || mode < 0) {
        printf("mode error\n");
        exit(0);
    }

    mode_u = mode / 100;
    mode_g = ( mode - mode_u * 100 ) /10;
    mode_o = mode - mode_u * 100 - mode_g *10;
    mode = (mode_u * 8 * 8) + (mode_g * 8) + mode_o;            //转换成八进制表示
    filename = argv[2];

    if ( chmod (filename,mode) ==  -1  ) {                      //权限修改失败返回-1
        perror("chmod fail");
        exit(1);
    }
    
    return 0;
}


