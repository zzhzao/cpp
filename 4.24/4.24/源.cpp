#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int main()
//{
//	cout << "hello world"; 
//	return 0;
//}
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	Func();
//	Func(1,2,3);
//	Func(1, 2);
//	return 0;
//}
//int ADD(int a, int b)
//{
//	cout << a + b << endl;
//	return a + b;
//}
//double ADD(double c, double d)
//{
//	cout << c + d << endl;
//	return c + d;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	double c = 0.1;
//	double d = 0.2;
//	ADD(a, b);
//	ADD(c, d);
//	return 0;
//}
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//int main()
//{
//	int a = 0;
//	f();
//	f(a);
//	return 0;
//}
int main()
{
	int a = 0;
	int& b = a;
	return 0;
}
void f(int x)
{
	cout << "f(int x)" << endl;
}
void f(int* x)
{
	cout << "f(int* x)" << endl;
}