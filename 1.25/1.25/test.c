#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//void move(char pos1, char pos2)
//{
//	printf(" %c->%c ", pos1, pos2);
//}
//
//void Hanoi(int n, char pos1, char pos2, char pos3)
//{
//	if (n == 1)
//		move(pos1, pos3);
//	else
//	{
//		Hanoi(n - 1, pos1, pos3, pos2);
//		move(pos1, pos3);
//		Hanoi(n - 1, pos2, pos1, pos3);
//	}
//}
//int main()
//{
//	Hanoi(1, 'A', 'B', 'C');
//	printf("\n");
//	Hanoi(2, 'A', 'B', 'C');
//	printf("\n");
//	Hanoi(3, 'A', 'B', 'C');
//	return 0;
//}

int jump(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return jump(n - 1) +  jump(n - 2);
}

int main()
{

	int ret = jump(5);
	printf("%d", ret);
	return 0;
}