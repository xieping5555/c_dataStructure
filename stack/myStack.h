/*************************
*** File myStack.h
**************************/
#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include "myList.h"
typedef MyList MyStack;

//创建堆栈
MyStack * createMyStack();

//释放堆栈
void freeMyStack(MyStack * stack);

//加入
void myStackAdd(MyStack* const stack, void* const data);

//删除
void* myStackRemove(MyStack * const stack);

//取得堆栈头
void* myStackGetTop(const MyStack * const stack);

#endif // MYSTACK_H_INCLUDED