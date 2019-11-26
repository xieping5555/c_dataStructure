/*************************
*** File myStack.c
**************************/
#include "myStack.h"

//创建堆栈
MyStack * createMyStack()
{
    return createMyList();
}

//释放堆栈
void freeMyStack(MyStack * stack)
{
    freeMyList(stack);
}

//加入
void myStackAdd(MyStack* const stack, void* const data)
{
    myListInsertDataAtFirst(stack, data);
}

//删除
void* myStackRemove(MyStack * const stack)
{
    return myListRemoveDataAtFirst(stack);
}

//取得堆栈头
void* myStackGetTop(const MyStack * const stack)
{
    return myListGetDataAtFirst(stack);
}