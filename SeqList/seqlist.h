#pragma once
#include<stdio.h>
#include<stdlib.h.>
#include<assert.h>
//˳���Ķ�̬�洢
typedef int  SeqDataType;
typedef struct SeqList
{
	SeqDataType* array;//ָ��̬���ٵ�����
	size_t size;//��Ч���ݵĴ�С
	size_t capacity;//�����ռ�Ĵ�С
}SeqList;
void SeqListInit(SeqList* pq);
void SeqListDestory(SeqList* pq);
void SeqListPrint(SeqList* pq);
//β��ͷ�壬βɾͷɾ
void SeqListPushFront(SeqList* pq, SeqDataType x);
void SeqListPushBack(SeqList* pq, SeqDataType x);
void SeqListPopFront(SeqList* pq);
void SeqListPopBack(SeqList* pq);
int SeqListFind(SeqList* pq, SeqDataType x); 
void SeqListInsert(SeqList* pq,int pos, SeqDataType x);//��posλ�ò���
void SeqListErase(SeqList* pq, int pos);//��posλ��ɾ��
void SeqListModify(SeqList* pq, int pos, SeqDataType x);//�޸�
//void SeqListRemove(SeqList* pq, SeqDataType x);//ȫ��ɾ��