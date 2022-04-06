#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SListNode* BuySListNode(SLTDateType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;
	return node;
}

void SListPushBack(SLTNode** pplist, SLTDateType x)
{
	SLTNode* newnode = BuySListNode(x);
	//1.空
	//2.非空
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SLTNode* tail = *pplist;
		while (tail->next!= NULL)
		{
			tail = tail->next;
		}
		tail->next=newnode;
	}
}


void SListPushFront(SLTNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPopBack(SListNode** pplist)
{
	//1.没有结点
	//2.一个结点
	//3.多个结点
	if (*pplist == NULL)
	{
		return;
	}
	else if((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SLTNode* prev=NULL;
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = (*pplist)->next;
		free(*pplist);
		*pplist = next;
	}
}
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SLTNode* cur = plist;
	while (cur)
	{
		if (cur->data = x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SLTNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next=newnode;
}
void SListInsertbefore(SListNode** pplist, SListNode* pos, SLTDateType x)
{
	assert(pos);
	SLTNode* newnode = BuySListNode(x);
	if (pos == *pplist)//头插
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = pos->next;
		pos->next = next->next;
		free(next);
	}
}
