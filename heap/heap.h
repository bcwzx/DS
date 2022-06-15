#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
//大堆
typedef int HPDataType;
struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
};
typedef struct Heap  HP;

void Swap(int* p1, int* p2);
void AdjustDown(int* a, int n, int parent);
void AdjustUp(int* a, int child);


void HeapInit(HP* php, HPDataType* a, int x);
void HeapDestory(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);
void HeapPrint(HP* php);



//void HeapSort(int* a, int n)
//{
//	//建堆 时间复杂度O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
