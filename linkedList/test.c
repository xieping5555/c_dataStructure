/*************************
*** File main.c
*** test for MyList
**************************/
#include <stdio.h>
#include <stdlib.h>
#include "myList.h"

typedef struct a
{
    int i;
    char c;
} A;

void ppt(const void* const p)
{
    A * pp= p;
    printf("%d(%c) ", pp->i, pp->c);
}


int main()
{
    const int S =10;

    //创建并初始化数据
    A * data= malloc(sizeof(A)*S);
    for (int i=0; i< S; i++)
    {
        data[i].i=i;
        data[i].c=(char)('A'+0);
    }

    //创建链表
    MyList * list= createMyList();

    //测试三种插入方法
    myListInsertDataAtLast( list, &data[0]);
    myListInsertDataAtFirst( list, &data[4]);
    myListInsertDataAt(list, &data[1], 1 );


    //测试查找
    int index = myListFindDataIndex(list, &data[2]);
    printf("%d\n", index);
    index = myListFindDataIndex(list, &data[4]);
    printf("%d\n", index);

    //输出
    myListOutput(list, ppt );
    puts("");

    //测试使用迭代器输出
    MyListIterator * it = createMyListIterator(list);
    while(myListIteratorHasNext(it))
    {
        A * pp = myListIteratorNext(it);
        printf("%d[%c] ", pp->i, pp->c);
    }
    puts("");
    //释放迭代器
    freeMyListIterator(it);

    //释放链表
    freeMyList(list);

    //释放数据
    free(data);
    return 0;
}