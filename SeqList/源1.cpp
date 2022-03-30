#include"seqList.h"
void SeqListInit(SeqList* pq)
{
	assert(pq);
	pq->array = 0;
	pq->size = pq->capacity = 0;
}
void SeqListDestory(SeqList* pq)
{
	assert(pq);
	free(pq->array);
	pq->array= NULL;
	pq->size = pq->capacity = 0;
}
void SeqListPrint(SeqList* pq)
{
	assert(pq);
	for (int i = 0; i<pq->size; i++)
	{
		printf("%d ", pq->array[i]);
	}
	printf("\n");
}
void SeqListCheckCapacity(SeqList* pq)
{
	//ÂúÁËÐèÒªÀ©ÈÝ
	if (pq->size == pq->capacity)
	{
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2;
		SeqDataType* newA = (SeqDataType*)realloc(pq->array, sizeof(SeqDataType) * newcapacity);
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pq->array = newA;
		pq->capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* pq, SeqDataType x)
{
	SeqListInsert(pq, pq->size, x);
	assert(pq);
	//SeqListCheckCapacity(pq);
	//SeqListInsert(pq, pq->size, x);
	///*pq->array[pq->size] = x;
	//pq->size++;*/

}
void SeqListPushFront(SeqList* pq, SeqDataType x)
{
	SeqListInsert(pq, 0, x);
//assert(pq);
//	SeqListCheckCapacity(pq);
//	int end = pq->size- 1;
//	while (end >= 0)
//	{
//		pq->array[end + 1] = pq->array[end];
//		end--;
//	}
//	pq->array[0] = x;
//	pq->size++;
}
void SeqListPopBack(SeqList* pq)
{
	SeqListErase(pq, pq->size-1);
	/*assert(pq);
	assert(pq->size > 0);
	pq->size--;*/

}
void SeqListPopFront(SeqList* pq)
{
	SeqListErase(pq, 0);
//	assert(pq);
//	assert(pq->size > 0);
//	int begin = 0;
//	while(begin<pq->size-1)
//	{
//		pq->array[begin] = pq->array[begin + 1];
//		begin++;
//	}
//	pq->size--;
}

int SeqListFind(SeqList* pq, SeqDataType x)
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
	{
		if (pq->array[i] = x)
		{
			return i;
		}
	}
	return -1;
	
}

void SeqListInsert(SeqList* pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos>=0 && pos<=pq->size);
	SeqListCheckCapacity(pq);
	int end = pq->size - 1;
	while (end >= pos)
	{
		pq->array[end + 1] = pq->array[end];
		end--;
	}
	pq->array[pos] = x;
	pq->size++; 
}

void SeqListErase(SeqList* pq, int pos)
{
	assert(pq);
	assert(pos>=0 && pos<pq->size);
	int begin = pos;
	while (begin < pq->size - 1)
	{
		pq->array[begin] = pq->array[begin + 1];
		begin++;
	}
	pq->size--;
}
void SeqListModify(SeqList* pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	pq->array[pos] = x;
}
//void SeqListRemove(SeqList* pq, SeqDataType x)
//{
//	assert(pq);
//	int i;
//	while ((i = SeqListFind(pq, x)) != -1)
//	{
//		SeqListErase(pq, i + 1);
//	}
//}