/*************************************************************************
        > File Name: my_ls.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年07月21日 星期四 15时36分34秒
 ************************************************************************/

/*文件读写和文件读写指针的移动*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<linux/limits.h>
#include<dirent.h>
#include<grp.h>
#include<pwd.h>
 

#define N  0                          //无参数
#define PARAM_A     1                          
#define PARAM_L     2
#define PARAM_R     5
#define MAXROWLEN    80                    //一行显示的最多字符数

int shengyulength = MAXROWLEN;                   //一行剩余长度，用于输出对齐
int maxlength;                              //存放某目录下最长文件名的长度

/*错误处理函数，打印出错误所在行的行数和错误信息*/
void error(char *err_string,int line)
{
    fprintf(stderr,"%d line have error",line);
    perror(err_string);
    exit(1);
}

/*获取文件属性并打印*/
void display_attribute (struct stat buf, char * name)
{
    char buf_time[32];
    struct passwd *yonghuname;                         //从该结构体中获取文件所有者的用户名
    struct group *groupname;                           //从该结构体中获取文件所有者所属组的组名

    
    /*获取并打印文件类型*/
    if (S_ISLNK(buf.st_mode)) {
        printf("l");
    }
    else if (S_ISREG(buf.st_mode)) {
        printf("-");
    }
    else if(S_ISDIR(buf.st_mode)) {
        printf("d");
    }
    else if(S_ISCHR(buf.st_mode)) {
        printf("c");
    }
    else if(S_ISBLK(buf.st_mode)) {
        printf("b");
    }
    else if(S_ISFIFO(buf.st_mode)) {
        printf("f");
    }
    else if(S_ISSOCK(buf.st_mode)) {
        printf("s");
    }

    /*获取并打印文件所有者的权限*/
    if (buf.st_mode & S_IRUSR) {
        printf("r");
    }
    else {
        printf("-");
    }

    if (buf.st_mode & S_IWUSR) {
        printf("w");
    }
    else {
        printf("-");
    }
    if (buf.st_mode & S_IXUSR) {
        printf("x");
    }
    else {
        printf("-");
    }
    
    /*获取并打印与文件所有者同组的用户对该文件的操作权限*/
    if (buf.st_mode & S_IRGRP) {
        printf("r");
    }
    else {
        printf("-");
    }
    if (buf.st_mode & S_IWGRP) {
        printf("w");
    }
    else {
        printf("-");
    }
    if(buf.st_mode & S_IXGRP) {
        printf("x");
    }
    else {
        printf("-");
    }

    /*获取并打印其他用户对该文件的操作权限*/
    if (buf.st_mode & S_IROTH) {
        printf("r");
    }
    else {
        printf("-");
    }
    if (buf.st_mode & S_IWOTH) {
        printf("w");
    }
    else {
        printf("-");
    }
    if (buf.st_mode & S_IXOTH) {
        printf("x");
    }
    else {
        printf("-");
    }

    printf("  ");                                       

    /*根据uid和gid获取文件所有者的用户名和组名*/
    yonghuname = getpwuid(buf.st_gid);
    groupname = getgrgid(buf.st_gid);
    printf("%4ld",buf.st_nlink);                          //打印文件的链接数
    printf("%-8s", yonghuname -> pw_name);
    printf("%-8s",groupname -> gr_name);
    
    printf("%6ld",buf.st_size);          //打印文件的大小
    strcpy(buf_time, ctime(&buf.st_mtime));
    buf_time[strlen(buf_time) - 1]  = '\0';                 //去掉换行符
    printf(" %s",buf_time);                               //打印文件时间信息

}


/*在没有使用-l选项时，打印一个文件名，打印时上下行对齐*/  
void display_single(char *name)
{    int i, len;
    if (shengyulength < maxlength) {
        printf("\n");
        shengyulength = MAXROWLEN;                        
    }

    len = strlen(name);
    len = maxlength- len;
    printf("%-s", name);

    for (i = 0; i < len; i++) {
        printf(" ");                             //用空格补齐空位
    }

    printf(" ");
    //下面的2指示空两格
    shengyulength = shengyulength - (maxlength + 2);  
}


//添加ls -R命令函数
int display_r(char pathnamex[maxlength])
{
    struct stat buf;
    DIR *dir;
    struct dirent *ptr;                                
    printf("%s:\n",pathnamex);
    dir = opendir( pathnamex );                         //打开目录，返回DIR *目录文件流
    while((ptr = readdir(dir)) != NULL) {
            display_single(ptr -> d_name);
        }

    closedir(dir);

    dir = opendir(pathnamex);
    while((ptr = readdir(dir)) != NULL) {
        if(ptr -> d_name[0] != '.') {
            if(S_ISDIR(buf.st_mode)) {
                char temp[maxlength];
                strcpy(temp,pathnamex);
                strcat(temp,"/");
                strcat(temp,ptr -> d_name);
                display_r(temp);
            }
        }
    }

    closedir(dir);
    return 0;
}
 
//结束

/*
 * 根据命令行参数和完整路径名显示目标文件
 * 参数flag: 命令行参数
 * 参数pathname: 包含了文件名的路径名
*/
//命令行参数存放在flag中，完整路径名存放在pathname中
void display (int flag,char * pathname)
{
    int i, j;
    struct stat buf;
    char name[NAME_MAX + 1];
    char pathnamex[maxlength];

    /*从路径中解析出文件名*/
    for (i = 0; i < strlen(pathname); i++) {
        if ( pathname[i] == '/' ) {
            j = 0;
            continue;
        }
        name[j++] = pathname[i];
    }
    name[j] = '\0';

    /*用lstat而不是stat以方便解析链接文件*/
    if (lstat(pathname, &buf) == -1) {
        error("stat",__LINE__);
    }

    switch(flag) {
        case N:          //没有-l和-a选项
        if (name[0] != '.') {
            display_single(name);
        } 
        break;

        case PARAM_A:             //-a:显示包括隐藏文件在内的所有文件
        display_single(name);   
        break;

        case PARAM_L:            //-l:每个文件单独占一行，显示文件的详细属性信息
        if (name[0] != '.') {
            display_attribute(buf, name);
            printf(" %-s\n", name);
        }
        break;

        case PARAM_A + PARAM_L:                     //同时有-a和-l 选项的情况
        display_attribute(buf, name);
        printf(" %-s\n",name);
        break;

        case PARAM_R:          
        getcwd(pathnamex,maxlength);
        display_r(pathname);
        break;

        default:
                 break;
        }
        
    }

/*为显示某个目录下的文件做准备*/
//参数flag_param用于在调用display函数时作为其参数flag的实参，path是要显示的目录
void display_dir (int flag_param,char *path)
{
    DIR *dir;
    struct dirent *ptr;
    int count = 0;
    char filenames[1024][PATH_MAX+1],temp[PATH_MAX+1];

    //获取该目录下文件总数和最长的文件名
    dir = opendir(path);
    if (dir == NULL) {
        error("opendir",__LINE__);
    }
    while ((ptr = readdir(dir)) != NULL) {
        if(maxlength < strlen(ptr -> d_name))
             maxlength = strlen(ptr -> d_name);
        count++;
    }
    closedir(dir);

    if(count > 256) 
        error("too many files under this dir",__LINE__);

    int i,j,len = strlen(path);
    //获取该目录下所有的文件名
     dir = opendir(path);
    for (i = 0; i < count; i++) {
                ptr = readdir(dir);
        if (ptr == NULL) {
                error("readdir",__LINE__);
                    
        }
                strncpy(filenames[i], path, len);
                filenames[i][len] = '\0';
                strcat(filenames[i],ptr -> d_name);
                filenames[i][len + strlen(ptr -> d_name)] = '\0';
        }

    //使用冒泡法对文件名进行排序，排序后文件名按字母顺序存储于filenames
        for (i = 0; i < count - 1; i++)
             for(j = 0; j < count - 1 - i; j++) {
                if (strcmp(filenames[j], filenames[j+1]) > 0) {
                        strcpy(temp,filenames[j+1]);
                        temp[strlen(filenames[j+1])] = '\0';
                        strcpy(filenames[j+1],filenames[j]);
                        filenames[j+1][strlen(filenames[j])];
                        strcpy(filenames[j],temp);
                        filenames[j][strlen(temp)] = '\0';
                    
        }
            
    }
    for (i = 0; i < count; i++) 
             display(flag_param,filenames[i]);
                 closedir(dir);
       
   //如果命令行没有-l选项，打印一个换行符
   if ((flag_param & PARAM_L) == 0)
          printf("\n");
}


int main(int argc,char *argv[])
{
    int i,j,k;
    char canshu[100];                                      //保存参数
    int count;
    int flag_canshu = N;                         //参数种类，即是否有-l -a 选项
    char path[PATH_MAX+1];
    struct stat buf;

    /*命令行参数的解析，分析-l -a -al -la选项*/ 
    j = 0;
    count = 0;

    //i初始化置为1,是因为agrv[0]规定指向程序的全路径名
    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {                           //判断每一个参数的第一个字符是否为'-'
            for (k = 1; k < strlen(argv[i]); k++,j++) {        //k初始化置为1,原因是进入此循环已经满足第一个字符为'-'
                canshu[j] = argv[i][k];                    //二维数组中i表示命令行参数的总个数，k表示每一个参数中的字符
            }
         count++;                                         //记录保存'-'的个数
        }
    } 

    /*只支持参数a,l,R.如果含有其他选项就报错*/
    for (i = 0; i < j; i++) {
        if(canshu[i] == 'a') {
            flag_canshu |= PARAM_A;
            continue;
        }
        else if(canshu[i] == 'l') {
            flag_canshu |= PARAM_L;
            continue;
        }
        else if(canshu[i] == 'R') {
            flag_canshu |= PARAM_R;
            continue;
        }
        else {

            printf("my_ls:invalid option -%c\n",canshu[i]);
            exit(1);
        }
    }
    canshu[j] = '\0';

    /*如果没有输入文件名或目录，就显示当前目录*/
    if (count + 1 == argc) {                       //'-'命令行参数的个数加上argv[0]第一个参数后等于argc的个数
        strcpy(path, "./");
        path[2] = '\0';
        display_dir(flag_canshu, path);
        return 0;
    }
     i = 1;
     do {
          //如果不是文件名或目录，解析下一个命令行参数
          if(argv[i][0] == '-'){
             i++;                     //跳过
             continue;
          }
          else {
                strcpy(path, argv[i]);
                
              //如果文件或目录不存在，报错并退出程序
                 if ( stat(path, &buf) == -1)
                        error("stat",__LINE__);
                 if (S_ISDIR(buf.st_mode))
                 {
                  if (path[ strlen(argv[i]) - 1 ] != '/') {
                      path[strlen(argv[i])] = '/';
                      path[strlen(argv[i] + 1)] = '\0';
                    }
                 }
              else
                 path[strlen(argv[i])] = '\0';

              display_dir(flag_canshu,path);
              i++;
             }
        } while(i < argc);
     return 0;
}


