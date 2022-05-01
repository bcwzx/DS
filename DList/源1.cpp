#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void ListPrint(ListNode* phead )
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur=cur->next;
	}
	printf("NULL\n");
}
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListInsert(phead,x);
	/*assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
}
void ListPushFront(ListNode* phead, LTDataType x)
{
	ListInsert(phead->next, x);
	//assert(phead);
	//ListNode* first = phead->next;
	//ListNode* newnode = BuyListNode(x);
	////phead newnode first
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = first;
	//first->prev = newnode;
}
void ListPopFront(ListNode* phead)
{
	ListErase(phead->next);
	/*assert(phead);
	assert(phead->next!=phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;*/
}
void ListPopBack(ListNode* phead)
{
	ListErase(phead->prev);
	/*assert(phead);
	assert(phead != phead->next);
	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	free(tail);
	tailPrev->next = phead;
	phead->prev = tailPrev;*/
}
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data==x)
		{
			return cur;//找到了，返回该元素的地址
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* posPrev = pos->prev;
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}