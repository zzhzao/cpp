#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//int main()
//{
//	struct A sa = { 0 };
//	int b = 0;
//	scanf("%d", &b);
//	sa._b = b;
//	return 0;
//}
//
//void Lilynumber(int i)
//{
//	if (i < 10)
//		printf("%d ", i);
//	else if (i < 100)
//	{
//		if (i == (i / 10) * (i % 10))
//			printf("%d ", i);
//	}
//	else if (i < 1000)
//	{
//		if (i == (i / 10) * (i % 10) + (i / 100) * (i % 100))
//			printf("%d ", i);
//	}
//	else if (i < 10000)
//	{
//		if (i == (i / 10) * (i % 10) + (i / 100) * (i % 100) + (i/1000)*(i%1000))
//			printf("%d ", i);
//	}
//	else if (i < 100000)
//	{
//		if (i == (i / 10) * (i % 10) + (i / 100) * (i % 100) + (i / 1000) * (i % 1000) + (i/10000)*(i%10000))
//			printf("%d ", i);
//	}
//}
//int main()
//{
//	for (int i = 0;i < 100000;i++)
//	{
//		Lilynumber(i);
//	}
//}

//
//void Lilynumber(int i)
//{
//
//	if (i == (i / 10) * (i % 10) + (i / 100) * (i % 100) + (i / 1000) * (i % 1000) + (i / 10000) * (i % 10000))
//	printf("%d ", i);
//
//}
//int main()
//{
//	for (int i = 10000;i < 100000;i++)
//	{
//		Lilynumber(i);
//	}
//}


//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int arr[100] = { 0 };
//	for (int i = 0;i < num;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int pop = 0;
//	scanf("%d", &pop);
//	for (int i = 0;i < num;i++)
//	{
//		if (arr[i] == pop)
//			arr[i] = 0;
//	}
//	for (int i = 0;i < num;i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	return 0;
//}

union A
{
	char s1 ;
	int i ;
};
int main()
{
	union A a;
	a.i = 1;
	if (a.s1 == 1)
		printf("Ð¡¶Ë");
	else
		printf("´ó¶Ë");
	return 0;
}