#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void print(int n)
//{
//	printf("%d", n % 10);
//	if(n>9)
//	print(n / 10);
//}
//
//int main()
//{
//	print(1234);
//	return 0;
//}

//int main()
//{
//	int count = 0;
//	int pay = 20;
//	int bottle = 0;
//	while (pay)
//	{
//		count++;
//		bottle++;
//		pay = pay - 1;
//	}
//	for (;bottle > 2;bottle = bottle - 2)
//	{
//		count++;
//		bottle++;
//	}
//	printf("%d", count);
//	return 0;
//}
//int Count(int i)
//{
//	int count = 0;
//	while (i)
//	{
//		count++;
//		i /= 10;
//	}
//	return count;
//}
//int result(int n, int count)
//{
//	int x = 1;
//	while (count)
//	{
//		x = x * n;
//		count--;
//	}
//	return x;
//}
//int Sum(int n, int count)
//{
//	int sum = 0;
//	for (;n != 0;n = n / 10)
//	{
//		int a = result(n% 10, count);
//		sum += a;
//	}
//	return sum;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1;i <= 100000;i++)
//	{
//		int count =	Count(i);
//		int sum = Sum(i, count);
//		//for (;i != 0;i = i / 10)
//		//{
//		//	int a = result(i / 10, count);
//		//	sum += a;
//		//}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	//int count = Count(153);
//	//int sum = Sum(153, count);
//	//if (sum == 153)
//	//	printf("%d", sum);
//	return 0;
//}



//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int x = n;
//	int sum = 0;
//	int count = 5;
//	while (count)
//	{
//		sum += n;
//		n = n * 10 + x;
//		count--;
//	}
//	printf("%d", sum);
//}


//int fac(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	return fac(n - 1) + fac(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("%d", ret);
//	return 0;
//}
//int fac(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	n = n - 2;
//	while (n)
//	{
//		a = b;
//		b = c;
//		c = a + b;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("%d", ret);
//	return 0;
//}
//int pow(int n, int r)
//{
//	if (r == 1)
//		return n;
//	return n * pow(n, r - 1);
//}
//
//int main() {
//	int n = 0;
//	int r = 0;
//	scanf("%d%d", &n, &r);
//	int ret = pow(n, r);
//	printf("%d", ret);
//	return 0;
//}


//int Sum(int n)
//{
//	if (n / 10 == 0)
//		return n;
//	return Sum(n / 10)+n%10;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Sum(n);
//	printf("%d", ret);
//	return 0;
//}

//void print(int n)
//{
//	if (n > 9)
//		 print(n / 10);
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	
//	return 0;
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