/*************************
*** File myHashCode.c
**************************/
#include "myHashCode.h"

//Ĭ�ϵ�hashCode
int myHashCodeDefault(void* a)
{
	return (int)a;
}

//int����hashCode
int myHashCodeInt(void* a)
{
	int* aa = (int*)a;
	return *aa;
}

//char���͵�hashCode
int myHashCodeChar(void* a)
{
	char* aa = (char*)a;
	return *aa;
}

//string���͵�hashCode
int myHashCodeString(void* a)
{
	int re = 0;
	char* aa = (char*)a;
	while (*aa)
	{
		re += HASHCODE_MULT * *aa;
		aa++;
	}
	return re;
}