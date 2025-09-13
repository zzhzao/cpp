#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


void test1()
{
	string s1("hello world");
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << ' ';
		rit++;
	}
}

void test2(const string& s ){

	string::const_iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << ' ';
		++it;
	}
}
void test3()
{
	string s;
	size_t old = s.capacity();
	for (size_t i = 0; i < 100; i++)
	{
		s.push_back('x');
		if (s.capacity() != old)
		{
			cout << s.capacity() << endl;
			old = s.capacity();
		}
	}
}


int main()
{
	//test2("world");
	test3();
	return 0;
}