#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//int my_strlen(char *str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//
//}
//
//int main()
//{
//	char str[] = "hello";
//	int r = my_strlen(str);
//	printf("%d", r);
//	return 0;
//}

//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char str1[] = "hello";
//	char str2[20] ;
//	printf("%s",my_strcpy(str2, str1));
//
//	return 0;
//}
//int my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//
//int main()
//{
//	char str1[] = "abcd";
//	char str2[] = "abq";
//
//	printf("%d",my_strcmp(str1, str2));
//	return 0;
//}

//
//char* my_strcat(char* str1, const char* str2)
//{
//	char* ret = str1;
//	while (*str1 != '\0')
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++);
//	return ret;
//}
//int main()
//{
//	char str1[20] = "hello ";
//	char str2[] = "world";
//	printf("%s",my_strcat(str1, str2));
//	return 0;
//}


char* strstr(const char* str1, const char* str2)
{
	char* s1 = str1;
	char* s2 = str2;
	char* cur = s1;
	if (*s2 = '\0')
		return str1;
	while (*s1 != '\0')
	{
		s2 = str2;
		s1 = cur;
		while (*s1++ == *s2++)
		{

			if (*s2 == '\0')
			{
				printf("ур╣╫ак\n");
				return cur;
			}
		}
		cur++;
	}
	return NULL;
}

int main()
{
	char str1[] = "abbbcdef";
	char str2[] = "bbc";
	strstr(str1, str2);
	return 0;
}