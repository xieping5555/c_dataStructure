/*************************
*** File myHashCode.h
**************************/
#ifndef MYHASHCODE_H_INCLUDED
#define MYHASHCODE_H_INCLUDED

#include <string.h>

#define HASHCODE_MULT 31

//Ĭ�ϵ�hashCode
int myHashCodeDefault(void * a);

//int����hashCode
int myHashCodeInt(void * a);

//char���͵�hashCode
int myHashCodeChar(void * a);

//string���͵�hashCode
int myHashCodeString(void * a);

#endif // MYHASHCODE_H_INCLUDED