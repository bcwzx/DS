#pragma once
#include<stdio.h>
#include<stdlib.h.>
#include<assert.h>
//顺序表的动态存储
typedef int  SeqDataType;
typedef struct SeqList
{
	SeqDataType* array;//指向动态开辟的数组
	size_t size;//有效数据的大小
	size_t capacity;//容量空间的大小
}SeqList;
void SeqListInit(SeqList* pq);
void SeqListDestory(SeqList* pq);
void SeqListPrint(SeqList* pq);
//尾插头插，尾删头删
void SeqListPushFront(SeqList* pq, SeqDataType x);
void SeqListPushBack(SeqList* pq, SeqDataType x);
void SeqListPopFront(SeqList* pq);
void SeqListPopBack(SeqList* pq);
int SeqListFind(SeqList* pq, SeqDataType x); 
void SeqListInsert(SeqList* pq,int pos, SeqDataType x);//在pos位置插入
void SeqListErase(SeqList* pq, int pos);//在pos位置删除
void SeqListModify(SeqList* pq, int pos, SeqDataType x);//修改
//void SeqListRemove(SeqList* pq, SeqDataType x);//全部删除