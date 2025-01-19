#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<time.h>
//void menu()
//{
//	printf("请选择:\n");
//	printf("*******************************\n");
//	printf("***********1.进行游戏**********\n");
//	printf("***********0.结束游戏**********\n");
//	printf("*******************************\n");
//}
//void game()
//{
//	srand((unsigned int)time(NULL));
//	int number = rand() % 100 + 1;
//	int guess = 0;
//	int flag = 1;
//	printf("请输入数字");
//	while (flag)
//	{
//		scanf("%d", &guess);
//		if (guess < number)
//			printf("猜小了");
//		else if (guess > number)
//			printf("猜大了");
//		else if (guess == number)
//		{
//			printf("猜对了");
//			flag = 0;
//		}
//	}
//}
//int main()
//{ 
//	int input = 0;
//
//    do
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("结束游戏");
//			break;
//		default:
//			printf("输入错误请重试");
//		}
//	} while (input);
//	return 0;
//}




//
//int main()
//{
//	int i = 0;
//
//	for (i = 100;i <= 200;i++)
//	{
//		int flag = 1;
//		for (int j = 2;j < i;j++)
//		{
//			if (i % j == 0)
//				flag = 0;
//			
//		}
//		if (flag)
//		{
//			printf("%d ", i);
//	}
//	}
//	return 0;
//}

int main()
{
	int arr[10] = {0};
	int max = 0;
	for (int i = 0;i < 10;i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int j = 0;j < 9;j++)
	{
		if (arr[j] < arr[j + 1])
			max = arr[j + 1];
	}
	printf("%d", max);
	return 0;
}