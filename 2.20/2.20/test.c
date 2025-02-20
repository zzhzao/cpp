#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void print(int arr[], int sz)
{
	for (int i = 0;i < sz;i++)
	{
		arr = arr + 1;
		printf("%d", arr);
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	return 0;
}