#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED

#include "myList.h"

typedef MyList MyQueue;

//创建队列
MyQueue * createMyQueue();

//释放队列
void freeMyQueue(MyQueue * queue);

//插入
void myQueueAdd(MyQueue* const queue, void* const data);

//删除
void* myQueueRemove(MyQueue * const queue);

//取得队头
void* myQueueGetTop(const MyQueue * const queue);

#endif // MYQUEUE_H_INCLUDED