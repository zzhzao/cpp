#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//int add(int a, int b)
//{
//	return a + b;
//}
//double add(double a, double b)
//{
//	return a + b;
//}
//template<typename T>
//T add(T a, T b)
//{
//	return a + b;
//}
template<typename T1, typename T2>
T1 add(T1 a, T2 b)
{
	return a + b;
}
template<typename T >
class list
{
private:
	T _data;
	int size;
	int capacity;
};
int main()
{
	int x = 1, y = 1;
	double a = 0.1, b = 0.2;
	add(a, b);
	add(x, y);
	add((int)a, y);
	add<int>(x, b);
	list<int> l1;
	return 0;
}