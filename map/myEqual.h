/*************************
*** File myEqual.h
**************************/
#ifndef MYEQUAL_H_INCLUDED
#define MYEQUAL_H_INCLUDED

//Ĭ�ϵ���ȵķ���
int myEqualDefault(void* a, void* b);

//int������ȵķ���
int myEqualInt(void* a, void* b);

//char������ȵķ���
int myEqualChar(void* a, void* b);

//string������ȵķ���
int myEqualString(void* a, void* b);

#endif // MYEQUAL_H_INCLUDED