#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
void test()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestory(&st);
}
int main()
{
	test();
	return 0;
}