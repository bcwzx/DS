#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
void StackInit(stack* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType)*4);
	ps->top = NULL;
	ps->capacity = 4;

}
void StackDestory(stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	//ÂúÕ»
	if (ps->top ==ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a ,sizeof(STDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = data;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top ==0;

}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}