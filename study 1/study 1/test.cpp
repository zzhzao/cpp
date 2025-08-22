#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//using namespace std;
//

//struct person
//{
//	//...
//};
//int main()
//{
//	std::cout << "hello world" << std::endl; 
//	//自动识别类型
//	int x = 0;
//	std::cout << x;
//	double y = 0.1;
//	std::cout << y;
//	//换行
//	std::cout << x << "\n" << y << "\n";
//	std::cout << std::endl;
//	std::cin >> x >> y;
//	std::cout << x << "\n" << y << "\n";
//	struct person p1;
//	//cout 能输出复合类型（自定义类型），而printf不可以
//	//通过运算符重载实现。        
//
//	return 0;
//
// 
//}
//namespace zzh {
//	int x = 0;
//	int ADD(int x, int y)
//	{
//		return x + y;
//	}
//	struct Node
//	{
//		struct Node* next;
//	};
//	//嵌套
//	namespace ZZH
//	{
//		int x = 2;
//	}
//
//	namespace ZZH
//	{
//		//int x = 3;
//	}
//}
////展开一个成员
//using zzh::x;
//int main()
//{
//	//int x = 1;
//	//域作用限定符,域外访问变量
//	printf("%d\n", x);
//
//	printf("%d\n", zzh::x);
//
//	printf("%d\n", zzh::ZZH::x);
//
//	return 0;
//}

//////////////////////////////////////////////////////////////

using namespace std;

int Add(int left, int right)
{
	cout << "int Add(int left, int right)" << endl;
	return left + right;
}

double Add(double left, double right)
{
	cout << "double Add(double left, double right)" << endl;
	return left + right;
}


int main()
{
	cout << Add(1, 1) << endl;
	cout << Add(1.1, 1.1) << endl;
	return 0;
}