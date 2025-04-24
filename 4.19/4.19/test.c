#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//// 插入排序
//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n- 1;i++)
//	{
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (a[end] > tmp)
//			{
//				a[end+1] = a[end];
//				end--;
//			}
//			else
//				break;
//		}
//		a[end + 1] = tmp;
//	}
//}
//
//// 希尔排序
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0;i < n-gap; i++)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end = end - gap;
//				}
//				else
//					break;
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}
//
//// 选择排序
//void SelectSort(int* a, int n)
//{
//	int begin = 0;
//	int end = n - 1;
//	while (begin < end)
//	{
//		int max = end;
//		int min = begin;
//		for (int i = begin; i <= end;i++)
//		{
//			if (a[i] > max)
//				max = i;
//			if (a[i] < min)
//				min = i;
//		}
//		if (max == begin)
//		{
//			max = min;
//		}
//		swap(&a[begin], &a[min]);
//		swap(&a[end], &a[max]);
//		begin++;
//		end--;
//	}
//}
//
//
//// 堆排序
//void AdjustDwon(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		if (child + 1 < n && a[child] < a[child + 1])
//			child++;
//		if (a[parent] < a[child])
//			swap(&a[parent], &a[child]);
//		else
//			break;
//		parent = child;
//		child = parent * 2 + 1;
//	}
//}
//void HeapSort(int* a, int n)
//{
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDwon(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		swap(&a[0], &a[end]);
//		AdjustDwon(a, end, 0);
//		end--;
//	}
//}
//
//void bubblesort(int* a, int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < n - i - 1;j++)
//		{
//			if (a[j] > a[j + 1])
//				swap(&a[j], &a[j + 1]);
//		}
//	}
//}
//// 快速排序
//
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right) {
//		return;
//	}
//	//_QuickSort?于按照基准值将区间[left,right)中的元素进?划分 
//	int meet = _QuickSort(a, left, right);
//	QuickSort(a, left, meet - 1);
//	QuickSort(a, meet + 1, right);
//}
//int _QuickSort(int* a, int left, int right)
//{
//	int key = left;
//	left++;
//	while (left <= right)
//	{
//		while (left <= right && a[right] > a[key])
//		{
//			right--;
//		}
//		while (left <= right && a[left] < a[key])
//		{
//				left++;
//		}
//		if(left<=right)
//		swap(&a[left++], &a[right--]);
//	}
//	swap(&a[key], &a[right]);
//	return right;
//}
//
//int _QuickSort(int* a, int left, int right)
//{
//	int hole = left;
//	int key = a[hole];
//	while (left < right)
//	{
//		while (left < right && a[right] > key)
//		{
//			right--;
//		}
//		a[hole] = a[right];
//		hole = right;
//		while (left < right && a[left] < key)
//		{
//			left++;
//		}
//		a[hole] = a[left];
//		hole = left;
//	}
//	a[hole] = key;
//	return hole;
//}
//int _QuickSort(int* a, int left, int right)
//{
//	int prev = left;
//	int cur = left + 1;
//	int key = left;
//	while (cur <= right)
//	{
//		if (a[cur] < a[key] && ++prev != cur)
//		{
//			swap(&a[prev], &a[cur]);
//		}
//		cur++;
//	}
//	swap(&a[key], &a[prev]);
//	return prev;
//}
//void _MergeSort(int* arr, int left, int right, int* tmp)
//{
//	if (left >= right)
//		return;
//	
//	int mid = (left + right) / 2;
//	_MergeSort(arr, left, mid, tmp);
//	_MergeSort(arr, mid + 1, right, tmp);
//	int begin1 = left; int end1 = mid;
//	int begin2 = mid + 1;int end2 = right;
//	int index = left;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (arr[begin1] < arr[begin2])
//		{
//			tmp[index++] = arr[begin1++];
//		}
//		else
//		{
//			tmp[index++] = arr[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[index++] = arr[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[index++] = arr[begin2++];
//	}
//	for (int i = left;i < right;i++)
//	{
//		arr[i] = tmp[i];
//	}
//}
//
//// 归并排序递归实现
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	_MergeSort(a, 0, n - 1, tmp);
//	free(tmp);
//	tmp == NULL;
//}
// 归并排序非递归实现
//void MergeSortNonR(int* arr, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	int gap = 1;
//	while (gap < n)
//	{
//		for (int i = 0;i <n;i = i+2*gap)
//		{
//			int begin1 = i;int end1 = i + gap - 1;
//			int begin2 = i + gap; int end2 = i + 2 * gap - 1;
//			int index = i;
//			if (begin2 >= n)
//				break;
//			if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (arr[begin1] < arr[begin2])
//				{
//					tmp[index++] = arr[begin1++];
//				}
//				else
//				{
//					tmp[index++] = arr[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				tmp[index++] = arr[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				tmp[index++] = arr[begin2++];
//			}
//			memcpy(arr + i, tmp + i, sizeof(int) * 2*gap);
//		}
//
//		gap *= 2;
//	}
//
//}
//int main()
//{
//	int a[10] = { 5,7,9,4,2,3,1,6,8,10 };
//	MergeSortNonR(a, 10);
//	for (int i = 0;i < 10;i++)
//	{
//		printf("%d ", a[i]);
//	}
//}
// 计数排序
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0;i < n;i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;
	int* count = (int*)calloc(0,sizeof(int) * range);
	for (int i = 0;i < n;i++)
	{
		count[a[i] - min]++;
	}
	int index = 0;
	for (int i = 0;i < range;i++)
	{
		while (count[i]--)
			a[index++] = i+min;
	}
}