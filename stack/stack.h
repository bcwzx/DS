#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
//动态增长的栈
typedef int STDataType;
typedef struct stack
{
	STDataType* a;
	int top;//栈顶
	int capacity;//容量
}Stack;
//初始化栈
void StackInit(stack* ps);
void StackDestory(stack* ps);
// 入栈
void StackPush(Stack* ps, STDataType data);
//出栈
void StackPop(Stack* ps);
//获取栈顶元素
STDataType StackTop(Stack* ps);
//判空
bool StackEmpty(Stack* ps);
//获取栈中有效元素
int StackSize(Stack* ps);