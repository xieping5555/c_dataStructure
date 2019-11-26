/*************************
*** File main.c
*** test for MyHashSet
**************************/
#include <stdio.h>
#include <stdlib.h>
#include "myEqual.h"
#include "myHashCode.h"
#include "myHashSet.h"

#define S 10

char* strs[S]=
{
    "abc",
    "qq",
    "hello",
    "abc",
    "lmy",
    "ab",
    "qq",
    "lqw",
    "sww",
    "lqw"
};


int main()
{
    //创建集合需要指定两个函数，hashCode函数和equal函数。
    MyHashSet * set = createMyHashSet(myHashCodeString, myEqualString);

    //插入数据
    for (int i=0; i<S; i++)
    {
        myHashSetAddData(set, strs[i]);
    }

    //输出大小
    printf("size=%d\n",myHashSetGetSize(set));

    //测试删除
    myHashSetRemoveData(set,"qq");
    myHashSetRemoveData(set,"ab");
    myHashSetRemoveData(set,"qwert");

    //输出大小
    printf("after remove size=%d\n",myHashSetGetSize(set));

    //遍历
    MyHashSetIterator * it = createMyHashSetIterator(set);
    while(myHashSetIteratorHasNext(it))
    {
        char * pp= myHashSetIteratorNext(it);
        puts(pp);
    }
    //释放遍历器
    freeMyHashSetIterator(it);

    //释放集合
    freeMyHashSet(set);
    return 0;
}