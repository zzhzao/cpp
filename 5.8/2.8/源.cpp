#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int getmonthday(int year, int month)
{

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        return 29;
    return arr[month];
}
int main() {
    int a, b;
    int year, month , day;
    while (cin >> a >> b) { 
        year = a;
        month = 1;
        day = b;
        while (b > getmonthday(year,month))
        {
            b -= getmonthday(year,month);
            month++;

        }
        day = b;
        printf("%04d-%02d-%02d\n", year, month, day);
    }
}
