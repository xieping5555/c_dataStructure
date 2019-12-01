/*************************
*** File myList.h
**************************/

#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED
#include <stdio.h>


typedef struct myNode
{
	void* data;
	struct myNode* next;
} MyNode;

typedef struct myList
{
	MyNode* first;
	MyNode* last;
	int count;
	int (*equal)(void* a, void* b);
} MyList;

typedef struct myListIterator
{
	MyNode* p;
	int count;
	int allSize;
} MyListIterator;

//��������
MyList* createMyList();

//��������������Ȳ��������ڲ���
MyList* createMySearchList(int(*equal)(void* a, void* b));

//�ͷ�����
void freeMyList(MyList* list);

//������β��
void myListInsertDataAtLast(MyList* const list, void* const data);

//�������ײ�
void myListInsertDataAtFirst(MyList* const list, void* const data);

//����
void myListInsertDataAt(MyList* const list, void* const data, int index);

//ɾ����β��
void* myListRemoveDataAtLast(MyList* const list);

//ɾ�����ײ�
void* myListRemoveDataAtFirst(MyList* const list);

//ɾ��
void* myListRemoveDataAt(MyList* const list, int index);

//ɾ������,�����Ƿ�ɾ���ɹ�
int myListRemoveDataObject(MyList* const list, void* data);

//����
int myListGetSize(const MyList* const list);

//��ӡ
void myListOutput(const MyList* const list, void(*pt)(const void* const));

//ȡ������
void* myListGetDataAt(const MyList* const list, int index);

//ȡ�õ�һ������
void* myListGetDataAtFirst(const MyList* const list);

//ȡ�����һ������
void* myListGetDataAtLast(const MyList* const list);

//����ĳ�����ݵ�λ��,���equal����Ϊ�գ��Ƚϵ�ַ���������equal����
//��������ڷ���-1��������ڣ����س��ֵĵ�һ��λ��
int myListFindDataIndex(const MyList* const list, void* data);

//����������
MyListIterator* createMyListIterator(const MyList* const list);

//�ͷű�����
void freeMyListIterator(MyListIterator* iterator);

//�������Ƿ�����һ��Ԫ��
int myListIteratorHasNext(const MyListIterator* const iterator);

//���ر���������һ��Ԫ��
void* myListIteratorNext(MyListIterator* const iterator);

#endif // MYLIST_H_INCLUDED