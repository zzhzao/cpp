#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//    int* arr = NULL;
//    int size = 5;
//    // 初始分配 5 个 int 大小的内存空间
//    arr = (int*)malloc(size * sizeof(int));
//    if (arr == NULL) {
//        printf("内存分配失败\n");
//        return 1;
//    } 
//    size = size * 3;
//    arr = realloc(arr, size * sizeof(int));
//    if (arr == NULL) {
//        printf("内存重新分配失败\n");
//        free(arr);  // 释放之前分配的内存
//        return 1;
//    }
//
//    int i;
//    // 输入数据
//    for (i = 0; i < size; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    // 释放分配的内存
//    free(arr);
//
//    return 0;
//}



int main()
{
	//开辟
	int** p = (int**)malloc(3 * sizeof(int*));
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		p[i] = (int*)malloc(5 * sizeof(int));
	}
	//使用
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			p[i][j] = 5 * i + j;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < 3; i++)
	{
		free(p[i]);
	}
	free(p);
	p = NULL;


	return 0;
}