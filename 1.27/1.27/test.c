#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int print(int n)
//{
//	int ret = 0;
//	while (n)
//	{
//		ret = ret * 10;
//		ret = ret + 9;
//		n--;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = print(n);
//	for (int i = 1;i <= ret;i++)
//		printf("%d ", i);
//	return 0;
//}

//void day1(int year, int month, int day)
//{
//	int ret = 0;
//	int days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//	if (month == 1)
//		ret = day;
//	else
//	{
//		for (int i = 0;i < month - 1;i++)
//		{
//			ret += days[i];
//		}
//		ret = ret + day;
//	}
//	printf("%d", ret);
//}
//void day2(int year, int month, int day)
//{
//	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int ret = 0;
//	if (month == 1)
//		ret = day;
//	else
//	{
//		for (int i = 0;i < month - 1;i++)
//		{
//			ret += days[i];
//		}
//		ret = ret + day;
//	}
//	printf("%d", ret);
//}
//
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	scanf("%d%d%d", &year,&month,&day);
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		day1(year,month,day);
//	else
//		day2(year,month,day);
//	return 0;
//}

//
//void print(int n)
//{
//	int x = 0;
//	x = n * n;
//	if (n % 2 == 1) {
//		x = x - (n / 2) * 2;
//		for (int i = 0;i < n;i++)
//		{
//			printf("%d ", x);
//			x += 2;
//		}
//	}
//	else
//	{
//		x = x - (n / 2) * 2+1;
//		for (int i = 0;i < n;i++)
//		{
//			printf("%d ", x);
//			x += 2;
//		}
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}


void start(int n)
{
	int sum = 0;
	int x = 2;
	while (n)
	{
		sum += x;
		n--;
		x += 3;
	}
	printf("%d", sum);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	start(n);
	return 0;
}