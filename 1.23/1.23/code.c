#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int bin_search(int arr[], int left, int right, int key)
//{
//	int mid = (right - left) / 2 + left;
//	while (arr[mid] != key)
//	{
//		mid = (right - left) / 2 + left;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//	}
//	return mid;
//}
//
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = (sizeof(arr) / sizeof(arr[0]));
//	int key = 0;
//	printf("请输入要查找的数字:");
//	scanf("%d", &key);
//	int ret = bin_search(arr, 0, sz - 1, key);
//	printf("%d", ret);
//	return 0;
//}

//void list(int n)
//{
//	int i = 0, j = 0;
//	for (i = 1;i <= n;i++)
//	{
//		for (j = 1;j <= i;j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("请输入:");
//	scanf("%d", &n);
//	list(n);
//	return 0;
//}
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//		printf("闰年");
//	else
//		printf("非闰年");
//	return 0;
//}
//
//void is_prime(int i)
//{ 
//	int flag = 1;
//		for (int n = 2;n < i;n++)
//		{
//			if (i % n == 0)
//				flag = 0;
//		}
//		if (flag)
//			printf("%d ", i);
//
//}
//int main()
//{
//	int i = 0;
//	for(i=100;i<=200;i++)
//	is_prime(i);
//	return 0;
//}

//void init(int arr[],int sz)
//{
//	for (int i = 0;i < sz;i++)
//		arr[i] = 0;
//}
//void print(int arr[], int sz)
//{
//	for (int i = 0;i < sz;i++)
//		printf("%d ", arr[i]);
//}
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left < right)
//	{
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//init(arr,sz);
//	//print(arr, sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	return 0;
//}
//
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}

int main()
{
	char a[13][13] = { ' ' };
	int i = 0, j = 0;
	for (i = 0;i < 13;i++)
	{
		for (j = 0;j < 13;j++)
			a[i][j] = ' ';
	}
	int count = 6;

	int left = 6;
	int right = 6;
	i = 0;
	while (count)
	{
		for (j = 0;j < 13; j++)
		{
			if (j >= left && j <= right)
				a[i][j] = '*';
		}
		left--;
		right++;
		i++;
		count--;
	}
	for (j = 0;j < 13;j++)
		a[6][j] = '*';
	i = 7;
	count = 6;
	left = 1;
	right = 11;
	while (count)
	{

		for (j = 0;j < 13; j++)
		{
			if (j >= left && j <= right)
				a[i][j] = '*';
		}
		left++;
		right--;
		i++;
		count--;
	}
	for (i = 0;i < 13;i++)
	{
		for (j = 0;j < 13;j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}