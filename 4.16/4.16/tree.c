#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"
void HeapInit(Heap* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	if(hp->a)
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
// 堆的插入
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void AdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		int* tmp = (int*)realloc(php->a, sizeof(int) * newcapacity);
		if (tmp == NULL)
			exit(1);
		php->a = tmp;
	}
	php->a[php->size] = x;
	AdjustUp(php->a, php->size);
	php->size++;
}
void AdjustDown(HPDataType* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] > arr[child + 1])
			child++;
		if (arr[parent] > arr[child])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, 0, hp->size);

}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
// 堆的判空
bool HeapEmpty(Heap* hp)
{
	if (hp->size == 0)
		return true;
	else
		return false;
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
		end--;
	}
}