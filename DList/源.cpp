#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"SList.h"

void TestList1()
{
	ListNode* plist=ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	ListPushFront(plist, 7);
	ListPushFront(plist, 8);
	ListPushFront(plist, 9);
	ListPushFront(plist, 10);
	ListPrint(plist);

	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	//指定pos之前插入
	ListNode* pos = ListFind(plist, 3);
	if (pos)
		ListErase(pos);
	ListPrint(plist);
}



int main()
{
	TestList1();
	
	return 0;
}