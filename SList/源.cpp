#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}
}
void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPrint(plist);
	SLTNode* pos = SListFind(plist, 1);
	SListInsertAfter(pos, 30);
	SListInsertbefore(&plist,pos,300);
	SListPrint(plist);
}
     
int main()
{
	TestSList2();
	return 0;
}