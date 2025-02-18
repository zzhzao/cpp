#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//struct stu
//{
//	char name[20];
//	int age;
//};
////以结构体中名字大小为依据进行排序
//int cmp_stu_name(const void* e1, const void* e2)
//{
//	//比较字符串大小用strcmp函数
//	//将e1,e2强转类型进行比较
//	//因为strcmp比较完后返回的结果与比较函数所需返回大小一致,所以可以直接返回strcmp比较完所得值
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//
//int main()
//{
//
//	struct stu arr[] = { {"zhangsan",18},{"wangwu",20} };//定义两个结构体变量,用于测试qsort函数
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_stu_name);
//	for(int i = 0;i<sz;i++)
//	printf("%s %d", arr[i].name, arr[i].age);
//
//	return 0;
//}
