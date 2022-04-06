#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode*next;
}SLTNode;
typedef struct SList
{
	SListNode*head;
}List;
void SListPrint(SLTNode* plist);
SListNode* BuySListNode(SLTDateType x);
void SListPushBack(SLTNode** pplist, SLTDateType x);
void SListPushFront(SLTNode** pplist, SLTDateType x);
void SListPopBack(SListNode** pplist);
void SListPopFront(SListNode** pplist);
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);//头插
void SListInsertbefore(SListNode** plist, SListNode* pos, SLTDateType x);
void SListEraseAfter(SListNode* pos);
void SListEraseCur(SListNode**pplist,SListNode* pos);//头删