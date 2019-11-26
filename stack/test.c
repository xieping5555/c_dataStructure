/*************************
*** File main.c
*** test for MyStack
**************************/
#include <stdio.h>
#include <stdlib.h>
#include "myStack.h"

typedef struct a
{
    int i;
    char c;
} A;


int main()
{
    const int S =10;

    //创建并初始化数据
    A * data= malloc(sizeof(A)*S);
    for (int i=0; i< S; i++)
    {
        data[i].i=i;
        data[i].c=(char)('A'+ i);
    }

    //创建椎栈
    MyStack * stack= createMyStack();

    //插入数据
    myStackAdd(stack, &data[0]);
    myStackAdd(stack, &data[2]);
    myStackAdd(stack, &data[6]);

    //测试删除
    while(myListGetSize(stack))
    {
        A * pp = myStackRemove(stack);
        printf("%d[%c] ", pp->i, pp->c);
    }
    puts("");

    //释放椎栈
    freeMyStack(stack);

    //释放数据
    free(data);
    return 0;
}