
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void print(int arr[], int sz)
//{
//	for (int i = 0;i < sz;i++)
//	{
//		printf("%d ", *arr);
//		arr = arr + 1;
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz;i++)
//	{
//		int flag = 1;//判断数组是否有序
//		for (int j = 0; j < sz - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	return 0;
//}

//void my_strlen(char* a)
//{
//	int count = 0;
//	while(*a != '\0')
//	{
//		a = a + 1;
//		count++;
//	}
//	printf("%d", count);
//}
//int main()
//{
//	char* a = "hello";
//	my_strlen(a);
//	return 0;
//}
//void swap(int arr[],int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int flag = 1;
//	while (left < right)
//	{
//		do
//		{
//			flag = 1;
//			if ((arr[left] % 2) == 1)
//				left++;
//			if ((arr[right] % 2) == 0)
//				right--;
//			if (((arr[left] % 2) == 0) && ((arr[right] % 2) == 1))
//				flag = 0;
//		} while (flag);
//		if(left<right)
//		{
//			int tmp = arr[right];
//			arr[right] = arr[left];
//			arr[left] = tmp;
//		}
//	}
//	for (int i = 0; i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	swap(arr,sz);
//	return 0;
//}

