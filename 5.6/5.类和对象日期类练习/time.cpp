#define _CRT_SECURE_NO_WARNINGS 1
#include"time.h"
int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);
	static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;
	return arr[month];
}
Date::Date(int year , int month , int day)
{
	this->_year = year;
	this->_month = month;
	this->_day = day;
}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}
Date::~Date()
{
	_year = _month = _day = 0;
}
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		_day += GetMonthDay(_year, _month);
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month > d._month)
			return true;
		else if (_month == d._month)
			return _day > d._day;
	}
	return false;
}
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}
int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	int count = 0;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	while (max != min)
	{
		count++;
		min++;
	}
	return count;
}