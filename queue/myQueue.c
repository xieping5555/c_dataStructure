#include "myQueue.h"

//创建队列
MyQueue * createMyQueue()
{
    return createMyList();
}

//释放队列
void freeMyQueue(MyQueue * queue)
{
    freeMyList(queue);
}

//插入
void myQueueAdd(MyQueue* const queue, void* const data)
{
    myListInsertDataAtLast(queue, data);
}

//删除
void* myQueueRemove(MyQueue * const queue)
{
    return myListRemoveDataAtFirst(queue);
}

//取得队头
void* myQueueGetTop(const MyQueue * const queue)
{
    return myListGetDataAtFirst(queue);
}