int main(int argc, char const *argv[])
{
    printf("Hello World\n");

    AvlTree T;
    Position P;
    int i;

    T = MakeEmpty(NULL);

    T = Insert(21, T);
    T = Insert(2150, T);
    T = Insert(50, T);
    T = Insert(12, T);
    T = Insert(1201, T);

    printf("Root: %d\n", T->Element);

    printf("树的详细信息: \n");
    PrintTree(T, T->Element, 0);

    printf("前序遍历二叉树: \n");
    PreorderTravel(T);

    printf("中序遍历二叉树: \n");
    InorderTravel(T);

    printf("后序遍历二叉树: \n");
    PostorderTravel(T);

    printf("最大值: %d\n", FindMax(T)->Element);
    printf("最小值: %d\n", FindMin(T)->Element);

    Delete(50, T);
    printf("树的详细信息: \n");
    PrintTree(T, T->Element, 0);

    return 0;
}

