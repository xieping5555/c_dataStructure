#ifndef MYHASHMAP_H_INCLUDED
#define MYHASHMAP_H_INCLUDED
#include "myList.h"

#define DEFAULT_INITIAL_CAPACITY 16
#define DEFAULT_LOAD_FACTOR 0.75f

typedef struct entry {
	void* key;
	void* value;
} Entry;

typedef struct myHashMap {
	int size;
	int initialCapacity;
	float loadFactor;
	int (*hashCode)(void* key);
	int (*equal)(void* key1, void* key2);
	MyList** entryList;
} MyHashMap;

typedef struct myHashMapEntryIterator {
	int index;
	MyHashMap* map;
	MyNode* current;
	int count;
} MyHashMapEntryIterator;

// ����HashMap
MyHashMap* createMyHashMap(int (*hashCode)(void* key), int (*Equal)(void* key1, void* key2));

// ʹ��ȫ����������HashMap
MyHashMap* createMyHashMapForAll(int initialCapacity, float loadFactor, int (*hashCode)(void* key), int (*Equal)(void* key1, void* key2));

// �ͷ�HashMap
void freeMyHashMap(MyHashMap* map);

// �Ƿ����ĳ��key
void myHashMapContainsKey(MyHashMap* const map, void* const key);

// ����һ��ӳ��
void myHashMapPutData(MyHashMap* const map, void* const key);

// ͨ��key�õ����ݣ����û�������򷵻�null
void* myHashMapGetDataByKey(MyHashMap* const map, void* const key);

// ���ݵ�����
int MyHashMapGetSize(const MyHashMap* const map);

//����Entry������  
MyHashMapEntryIterator* createMyHashMapEntryIterator(MyHashMap* const map);

//�ͷ�Entry������  
void freeMyHashMapEntryIterator(MyHashMapEntryIterator* iterator);

//Entry�������Ƿ�����һ��  
int myHashMapEntryIteratorHasNext(MyHashMapEntryIterator* iterator);

//������һ��EntryԪ��  
Entry* myHashMapEntryIteratorNext(MyHashMapEntryIterator* iterator);

//ɾ��һ�����ݣ������Ƿ�ɾ���ɹ�  
int myHashMapRemoveDataByKey(MyHashMap* const map, void* const key);

//����  
void myHashMapOutput(MyHashMap* map, void(*pt)(Entry*));

#endif