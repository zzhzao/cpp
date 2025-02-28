#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"

int main()
{
	SLT* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTprint(plist);
	SLTPopBack(&plist);
	SLTprint(plist);
	SLTPopFront(&plist);
	SLTprint(plist);
	SLTInsert(&plist, 1, 5);
	SLTprint(plist);
	SLTPop(&plist, 1);
	SLTprint(plist);
	return 0;
}