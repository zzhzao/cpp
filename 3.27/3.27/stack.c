#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_a, sizeof(STDataType) * newcapacity);
		ps->_a = tmp;
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	ps->_top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}
int StackSize(Stack* ps)
{
	return ps->_top;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
void stackPrint(Stack* ps)
{
	STDataType* pcur = ps->_a;
	int i = 0;
	for (i = 0; i < ps->_top; i++)
	{
		printf("%d ", *pcur);
		pcur++;
	}
}