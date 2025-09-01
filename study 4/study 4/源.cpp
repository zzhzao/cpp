#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	//Date()
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	~Date()
//	{
//
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.print();
//	Date d2(2025, 9, 1);
//	d2.print();
//	Date d3(2025);
//	d3.print();
//	return 0;
//}

#include<iostream>

using namespace std;

class Date

{

public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 编译报错：error C2652: “Date”: ⾮法的复制构造函数: 第⼀个参数不应是“Date” 
	//Date(Date d)

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}



private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2025, 3, 7);
	d1.Print();
	Date d2(d1);
	d2.Print();
	return 0;
}