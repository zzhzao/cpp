#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int i = 1;
//	//0x00 00 00 01
//	//只需比较取出的下一为是00 还是 01 即可
//	if (*(char*)&i == 1)
//		printf("小端 ");
//	else
//		printf("大端");
//	return 0;
//}

//char* my_strncpy(char* dest, char* src, int num)
//{
//	char* ret = dest;
//	while (num--)
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return ret;
//}
//int main()
//{
//	char arr1[] = { "abcdef" };
//	char arr2[20];
//	printf("%s",my_strncpy(arr2, arr1, 3));
//	return 0;
//}
//char* my_strcat(char* dest, char* src, int num)
//{
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (num--&&*src)
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = { "hello " };
//	char arr2[] = { "world abc" };
//	printf("%s", my_strcat(arr1, arr2, 5));
//	return 0;
//}
//
//void* my_mymcpy(int* dest, int* src, int num)
//{
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	my_mymcpy(arr2,arr1,20);
//	for (int i = 0;i < 10;i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}


void* my_mymmove(int* dest, int* src, int num)
{
	void* ret = dest;
	if (dest < src)
	{
		while (num--)
			{
				*(char*)dest = *(char*)src;
				dest = (char*)dest + 1;
				src = (char*)src + 1;
			}
		return ret;
	}
	else
	{
		dest = (char*)dest + num - 1;
		src = (char*)src + num - 1;
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
		return ret;
	}
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_mymmove(arr1+2,arr1,20);
	for (int i = 0;i < 10;i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}