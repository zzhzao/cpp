#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
int main()
{
	Stack ST;
	StackInit(&ST);
	StackPush(&ST, 1);
	StackPush(&ST, 2);
	StackPush(&ST, 3);
	StackPush(&ST, 4);
	StackPush(&ST, 5);
	stackPrint(&ST);
	printf("\n");
	StackPop(&ST);
	stackPrint(&ST);
	StackDestroy(&ST);
	return 0;
}