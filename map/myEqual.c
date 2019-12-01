/*************************
*** File myEqual.c
**************************/
#include "myEqual.h"
#include <string.h>

//Ĭ�ϵ���ȵķ���
int myEqualDefault(void* a, void* b)
{
	return a == b;
}

//int������ȵķ���
int myEqualInt(void* a, void* b)
{
	int* aa = (int*)a;
	int* bb = (int*)b;
	return *aa == *bb;
}

//char������ȵķ���
int myEqualChar(void* a, void* b)
{
	char* aa = (char*)a;
	char* bb = (char*)b;
	return *aa = *bb;
}

//string������ȵķ���
int myEqualString(void* a, void* b)
{
	char* aa = (char*)a;
	char* bb = (char*)b;
	return strcmp(aa, bb) == 0;
}