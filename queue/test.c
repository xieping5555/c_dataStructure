/*************************
*** File main.c
*** test for MyQueue
**************************/
#include <stdio.h>
#include <stdlib.h>
#include "myQueue.h"

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
        data[i].c=(char)('A'+i);
    }

    //创建队列
    MyQueue * queue= createMyQueue();

    //插入数据
    myQueueAdd(queue, &data[0]);
    myQueueAdd(queue, &data[2]);
    myQueueAdd(queue, &data[6]);

    //测试删除
    while(myListGetSize(queue))
    {
        A * pp = myQueueRemove(queue);
        printf("%d[%c] ", pp->i, pp->c);
    }
    puts("");

    //释放链表
    freeMyQueue(queue);

    //释放数据
    free(data);
    return 0;
}