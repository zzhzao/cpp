#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int i = 0, j = 0;
//	for (i = 1;i <= 9;i++)
//	{
//		for (j = 1;j <= i;j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	float a = 0,sum = 0;
//	float i = 0;
//	int tmp = 1;
//	for (i = 1;i <= 100;i++)
//	{
//		a = tmp/i;
//		sum += a;
//		tmp = -tmp;
//	}
//	printf("%f", sum);
//	return 0;
//}
//
//int main()
//{
//	int i = 0,cnt = 0;
//	for (i = 1;i <= 100;i++)
//	{
//		if (i % 10 == 9)
//			cnt++;
//		if (i / 10 == 9)
//			cnt++;
//	}
//	printf("%d", cnt);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for ( i = 1000;i <= 2000;i++)
//	{
//		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

int main()
{
	int a = 0, b = 0,min = 0,i = 0;
	scanf("%d%d", &a, &b);
	min = a < b ? a : b;
	for (i=min;i>0;i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}