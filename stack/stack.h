#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
//��̬������ջ
typedef int STDataType;
typedef struct stack
{
	STDataType* a;
	int top;//ջ��
	int capacity;//����
}Stack;
//��ʼ��ջ
void StackInit(stack* ps);
void StackDestory(stack* ps);
// ��ջ
void StackPush(Stack* ps, STDataType data);
//��ջ
void StackPop(Stack* ps);
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
//�п�
bool StackEmpty(Stack* ps);
//��ȡջ����ЧԪ��
int StackSize(Stack* ps);