#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
void test1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4 = s2;
	string s5(s2, 6, 5);
	string s7(s2, 5);
	string s6(5, 'h');
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s6 << endl;
	cout << s5 << endl;
	cout << s7 << endl;
}
void test2()
{
	string s1("hello world");
	string::iterator it1 = s1.begin();
	auto a = 1;
	auto b = 10.1;
	for (auto e : s1)
	{
		cout << e << ' ';
	}
	cout << endl;
	while (it1 != s1.end())
	{
		cout << *it1 << ' ';
		it1++;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}
	cout << s1 << endl;
}
int main()
{
	test2();
	return 0;
}