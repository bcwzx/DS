#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// ˫�������ӡ
void ListPrint(ListNode* plist);
//����ͷ���
ListNode* BuyListNode(LTDataType x);
ListNode* ListInit();
// ˫������β��
void ListPushBack(ListNode* phead, LTDataType x);
// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* phead);
// ˫������ͷɾ
void ListPopFront(ListNode* phead);
// ˫����������
void ListDestory(ListNode* phead);
// ˫���������
ListNode* ListFind(ListNode* phead, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
