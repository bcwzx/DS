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
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);//ͷ��
void SListInsertbefore(SListNode** plist, SListNode* pos, SLTDateType x);
void SListEraseAfter(SListNode* pos);
void SListEraseCur(SListNode**pplist,SListNode* pos);//ͷɾ