#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	string filename("test.cpp");
	string str1 = filename.substr(4, filename.size() - 4);
	cout << filename.size() << endl;
	cout << str1 << endl;
	size_t i = filename.find('.');
	if (i != string::npos)
	{
		cout << filename.substr(i);
	}
	return 0;
}