#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int win = 0;
void initboard(char board[ROWS][COLS], int r, int c, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[ROWS][COLS], int r, int c)
{
	int i = 0;

	int j = 0;
	for(i = 1;i <= r;i++)
	{
		printf(" %d", i);
	}
	printf("\n");
	for (i = 1;i <= r;i++)
	{
		printf("%d", i);
		for (j = 1;j <= c;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char mine[ROWS][COLS],int r,int c)
{

	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (mine[x][y] != '1')
		{
			mine[x][y] = '1';
			count--;
		}
		
	}
}


int getcount(char mine[ROWS][COLS],int x,int y)
{
	int count = mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x - 1][y] + mine[x + 1][y] + mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] - 8 * mine[x][y];
}


void showboard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (x > 0 && y > 0 && x <= ROW && y <= COL)
	{
		if ((show[x][y] == '*')&&(mine[x][y]!='1'))
		{
			int count = getcount(mine, x, y);
			show[x][y] = '0' + count;
			win++;
			//如果周围雷的个数为0,则周围一圈的坐标都进行showboard操作
			if (show[x][y] < '1')
			{
				showboard(mine, show, x - 1, y - 1);
				showboard(mine, show, x - 1, y);
				showboard(mine, show, x - 1, y + 1);
				showboard(mine, show, x, y - 1);
				showboard(mine, show, x, y + 1);
				showboard(mine, show, x + 1, y - 1);
				showboard(mine, show, x + 1, y);
				showboard(mine, show, x + 1, y + 1);
			}
			else
				return;
		}
		else
			return;
	}
	else
		return;
	
}








void findmine(char mine[ROWS][COLS],char show[ROWS][COLS], int r, int c)
{
	while (win != r * c - EASY_COUNT)
	{
		printf("请输入你要查找的坐标:");
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		if (x > 0 && y > 0 && x <= r && y <= c)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾,你输了\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				//int count = getcount(mine, x, y);
				//show[x][y] = '0' + count;
				//win++;
				//displayboard(show, ROW, COL);
				showboard(mine, show, x, y);
			}
			displayboard(show, ROW, COL);
		}
		else
			printf("输入错误");
	}
	if (win == r * c - EASY_COUNT)
	{
		printf("你赢了\n");
		displayboard(mine, ROW, COL);
	}
}


//void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
//{
//	int win = 0;
//	while (win != r * c - EASY_COUNT)
//	{
//		printf("请输入你要查找的坐标:");
//		int x = 0, y = 0;
//		scanf("%d%d", &x, &y);
//		if (x > 0 && y > 0 && x <= r && y <= c)
//		{
//			if (mine[x][y] == '1')
//			{
//				printf("很遗憾,你输了\n");
//				displayboard(mine, ROW, COL);
//				break;
//			}
//			else
//			{
//				int count = getcount(mine, x, y);
//				show[x][y] = '0' + count;
//				win++;
//				displayboard(show, ROW, COL);
//			}
//		}
//		else
//			printf("输入错误");
//	}
//	if (win == r * c - EASY_COUNT)
//	{
//		printf("你赢了");
//		displayboard(mine, ROW, COL);
//	}
//}