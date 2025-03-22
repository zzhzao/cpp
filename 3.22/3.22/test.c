#define _CRT_SECURE_NO_WARNINGS 1
#include"slist.h"
int main()
{
	SListNode* sl = NULL;
	SListPushBack(&sl,1);
	SListPushBack(&sl,2);
	SListPushBack(&sl,3);
	SListPrint(sl);
	return 0;
}