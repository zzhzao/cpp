#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	string s("hello  world");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s[0]++;
	cout << s << endl;
	s.at(0)--;
	cout << s << endl;
	cout << s.front() << endl;
	cout << s.back() << endl;
	string::iterator t1= s.begin();
	for (auto e : s)
	{
		cout << e << ' ';
	}

	cout << endl;
	s.insert(0, 3, 'x');
	s.insert(s.end(), 3, 'x');
	s.erase(0, 3);
	cout << s << endl;



	string s1("hello   world");

	/*s[100];*/
	//s1.replace(5, 3, "#");
	s1.replace(5, 3,"#");
	cout << s1 << endl;
	return 0;
}