#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	//pq->size = 0;
}
//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	//pq->size = 0;
}
//入队——队尾
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//队列为空
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else {
		//队列非空
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;
	}
	//pq->size++;
}
//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}
//出队——队头
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	//只有一个节点，phead和ptail都套置为空
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else {
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	//pq->size--;
}
//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}
//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}

//队列有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	//第一种方式：遍历链表——适用于不会频繁调用队列有效数据个数的场景
	QueueNode* pcur = pq->phead;
	int size = 0;
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}
	return size;

	//第二种方式：遍历链表——适用于频繁调用队列有效数据个数的场景
	//return pq->size;
}