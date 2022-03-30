#include"seqList.h"
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s,1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);

	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);

	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPopFront(&s);


	SeqListPrint(&s);
	SeqListDestory(&s);
}
void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);
	
	SeqListInsert(&s, 2, 40);
	SeqListPrint(&s);

	SeqListInsert(&s, 1, 30);
	SeqListPrint(&s);

	SeqListErase(&s, 0);
	SeqListPrint(&s);

	SeqListErase(&s, 1);
	SeqListPrint(&s);

	SeqListModify(&s, 0, -1);
	SeqListPrint(&s);

	SeqListDestory(&s);
}
//void menu()
//{
//	printf("****************************************\n");
//	printf("****1.β������        2.ͷ������    ****\n");
//	printf("****3.β������        4.ͷɾ����********\n");
//	printf("****5.��������        6.��ӡ����********\n");
//	printf("****           0.�˳�           ********\n");
//	printf("****************************************\n");
//}
int main()
{
    TestSeqList2();
	/*SeqList s;
	SeqListInit(&s);
	int option = 0;
	do
	{
		menu();
		scanf_s("%d", &option);
		int x;
		switch (option)
		{
		case 1:
			printf("���������ݣ���-1����:");
			while(1)
			{
				scanf_s("%d", &x);
				if (x == -1)
					break;
				SeqListPushBack(&s, x);
			}
				break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			SeqListPrint(&s);
			break;
		default:
			break;
		}
			
	} while (option != 0);
		SeqListDestory(&s);*/
	return 0;
}