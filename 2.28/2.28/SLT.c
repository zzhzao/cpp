#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"
//SLT* STLInit()
//{
//	SLT* head = (SLT*)malloc(sizeof(SLT));
//	if (head == NULL)
//	{
//		printf("malloc failed");
//		return NULL;
//	}
//	head -> next = NULL;
//	return head;
//}
//void SLTDestory(SLT* phead)
//{
//	SLT* cur = phead;
//	while (cur != NULL)
//	{
//		cur = phead->next;
//		free(phead);
//		phead = cur;

//	
// 
//}

SLT* BuyNewNode(SLTDataType x)
{
	SLT* newnode = (SLT*)malloc(sizeof(SLT));
	if (newnode == NULL) {
		printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


void SLTPushBack(SLT** pphead, SLTDataType x)
{
	SLT* newnode = (SLT*)malloc(sizeof(SLT));
	if (newnode == NULL) {
		printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (*pphead == NULL) 
	{
		*pphead = newnode;
	}
	else
	{
		SLT* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SLTprint(SLT* phead)
{
	SLT* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLTPushFront(SLT** pphead, SLTDataType x)
{
	SLT* newnode = (SLT*)malloc(sizeof(SLT));
	if (newnode == NULL) {
		printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
		return;
	}
	newnode->data = x;
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLT** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SLT* tail = *pphead;
	SLT* prev = NULL;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	prev->next = NULL;
}

void SLTPopFront(SLT** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SLT* head = (*pphead)->next;
	free(*pphead);
	*pphead = head;
}


void SLTInsert(SLT** pphead, int pos, SLTDataType x)
{
	SLT* newnode = BuyNewNode(x);
	if (newnode == NULL) {
		printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
		return;
	}
	if (pos == 0)
	{
		newnode->next = (*pphead);
		*pphead = newnode;
	}
	SLT* cur = *pphead;
	while (--pos&& cur !=NULL)
	{
		cur = cur->next;
	}
	SLT* tmp = cur->next;
	cur->next = newnode;
	newnode->next = tmp;
}

void SLTPop(SLT** pphead, int pos)
{

	if (*pphead == NULL)
	{
		return;
	}
	if (pos == 0)
	{
		SLT* temp = *pphead;
		*pphead = (*pphead)->next;
		free(temp);
		return;
	}

	SLT* cur = *pphead;
	SLT* prev = NULL;
	while (pos-- && cur != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		return;
	}

	prev->next = cur->next;
	free(cur);
	cur = NULL;
}