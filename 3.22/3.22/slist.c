#define _CRT_SECURE_NO_WARNINGS 1
#include"slist.h"
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
}
void SListPrint(SListNode* plist)
{
	assert(plist);
	while (plist)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else 
	{
		SListNode* ptail = *pplist;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
void SListPopBack(SListNode** pplist)
{
	assert(pplist&&*pplist);
	SListNode* ptail = *pplist;
	if((*pplist)->next)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		prev->next = NULL;
	}
}
void SListPopFront(SListNode** pplist)
{
	assert(pplist && *pplist);
	SListNode* phead = *pplist;
	*pplist = phead->next;
	free(phead);
	phead = NULL;
}
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	while (plist->next)
	{
		if (plist->data == x)
		{
			return plist;
		}
		plist = plist->next;
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* next = pos->next;
	SListNode* newnode = BuySListNode(x);
	pos->next = newnode;
	newnode->next = next;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos&&pos->next);
	SListNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDateType x)
{
	assert(pphead && pos);
	if (*pphead = pos)
	{
		SListPushFront(pphead, x);
	}
	else 
	{
		SListNode* newnode = BuySListNode(x);
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
void SLTErase(SListNode** pphead, SListNode* pos)
{
	assert(pphead && pos);
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void SLTDestroy(SListNode** pphead)
{
	SListNode* prev = *pphead;
	while (prev)
	{
		SListNode* next = prev->next;
		free(prev);
		prev = next;
	}
	*pphead = NULL;
}