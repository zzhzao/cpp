#define _CRT_SECURE_NO_WARNINGS 1

//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//
//int main()
//{
//	f(0);
//// 本想通过f(NULL)调⽤指针版本的f(int*)函数，但是由于NULL被定义成0，调⽤了f(int x)，因此与程序的初衷相悖。
//	f(NULL);
//	f((int*)NULL);
//	// 编译报错：error C2665: “f”: 2 个重载中没有⼀个可以转换所有参数类型 
//	// f((void*)NULL);
//
//
//	f(nullptr);
//	return 0;
//}


#include<iostream>

using namespace std;


class A

{

public:
	void Print()
	{
		cout << _ch << endl;
	}

private:
	char _ch;
	int _i;
};

class B

{

public:
	void Print()
	{
		//...

	}
};

class C

{
};

int main()
{
	A a;
	B b;
	C c;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	cout << sizeof(c) << endl;
	return 0;
}
