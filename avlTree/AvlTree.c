#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AvlTree.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

AvlTree MakeEmpty(AvlTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

/**
 * 计算Avl节点高度
 * @param  P 节点P
 * @return 树高
 */
static int Height(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

static int Max(int a, int b)
{
    return a > b ? a : b;
}

/* 向左单旋 */
static Position SingleRotateWithLeft(Position K2)
{
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;

    return K1; /* New Root */
}

/* 向右单旋  */
static Position SingleRotateWithRight(Position K2)
{
    Position K1;

    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(K2->Height, Height(K1->Right)) + 1;

    return K1; /*New root */
}

/* 向左双旋 */
static Position DoubleRotateWithLeft(Position K3)
{
    /* Rotate between K1 and K2 */
    K3->Left = SingleRotateWithRight(K3->Left);

    /* Rotate between K3 and K2 */
    return SingleRotateWithLeft(K3);
}

/* 向右双旋 */
static Position DoubleRotateWithRight(Position K3)
{
    K3->Right = SingleRotateWithLeft(K3->Right);

    return SingleRotateWithRight(K3);
}

AvlTree Insert(ElementType X, AvlTree T)
{
    if (T == NULL)
    {
        T = malloc( sizeof( struct AvlNode ) );
        if (T == NULL)
            printf("Out of space!!!\n");
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element) /* 左子树插入新节点 */
    {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2)
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
    }
    else if (X > T->Element) /* 右子树插入新节点 */
    {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
    }
    /* Else X is in the tree alredy; we'll do nothing */
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

AvlTree Delete(ElementType X, AvlTree T)
{
    Position TmpCell;
     if(T == NULL) {
        printf("没找到该元素，无法删除！\n");
        return NULL;
     }
     else if (X < T->Element)
         T->Left = Delete(X, T->Left);
     else if (X > T->Element)
         T->Right = Delete(X, T->Right);
     else if(T->Left && T->Right) { //要删除的树左右都有儿子
         TmpCell = FindMin(T->Right);   //用该结点右儿子上最小结点替换该结点，然后与只有一个儿子的操作方法相同
         T->Element = TmpCell->Element;
         T->Right = Delete(T->Element, T->Right);
     }else{
         TmpCell = T;        //要删除的结点只有一个儿子
         if(T->Left == NULL)
             T = T->Right;
         else if(T->Right == NULL)
             T = T->Left;
         free(TmpCell);
     }
     return T;
}

/* 查找X元素所在的位置 */
Position Find(ElementType X, AvlTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}

/* search the min element in AvlTree*/
Position FindMin(AvlTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

/* search the max element in AvlTree */
Position FindMax(AvlTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Right == NULL)
        return T;
    else
        return FindMax(T->Right);
}

ElementType Retrieve(Position P)
{
    if(P != NULL)
        return P->Element;
    return -1;
}

/**
 * 前序遍历"二叉树"
 * @param T Tree
 */
void PreorderTravel(AvlTree T)
{
    if (T != NULL)
    {
        printf("%d\n", T->Element);
        PreorderTravel(T->Left);
        PreorderTravel(T->Right);
    }
}

/**
 * 中序遍历"二叉树"
 * @param T Tree
 */
void InorderTravel(AvlTree T)
{
    if (T != NULL)
    {
        InorderTravel(T->Left);
        printf("%d\n", T->Element);
        InorderTravel(T->Right);
    }
}

/**
 * 后序遍历二叉树
 * @param T Tree
 */
void PostorderTravel(AvlTree T)
{
    if (T != NULL)
    {
        PostorderTravel(T->Left);
        PostorderTravel(T->Right);
        printf("%d\n", T->Element);
    }
}

/* 打印二叉树信息 */
void PrintTree(AvlTree T, ElementType Element, int direction)
{
    if (T != NULL)
    {
        if (direction == 0)
            printf("%2d is root\n", T->Element);
        else
            printf("%2d is %2d's %6s child\n", T->Element, Element, direction == 1 ? "right" : "left");

        PrintTree(T->Left, T->Element, -1);
        PrintTree(T->Right, T->Element, 1);
    }
}
