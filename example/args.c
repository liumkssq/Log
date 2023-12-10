// 不定参 宏函数
#define _GNU_SOURCE // must
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define LOG(fmt,...) printf("[%s:%d]:"fmt"\n",__FILE__,__LINE__,##__VA_ARGS__);

void printNum(int count,...)
{
    va_list ap;
    va_start(ap,count); // 指定参数的起始地址
    for(int i = 0; i < count;i++)
    {
        int num = va_arg(ap,int); // int 4 类似汇编
        printf("params[%d]:%d\n",i,num);
    }
    va_end(ap); // ap 置空
}

void myprintf(const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    char* res;
    int ret = vasprintf(&res,fmt,ap);
    if(ret != -1)
    {
        printf(res);
        free(res);
    }
    va_end(ap);
}


int main()
{
    LOG("hello")
    myprintf("%d",12);
    return 0;
}