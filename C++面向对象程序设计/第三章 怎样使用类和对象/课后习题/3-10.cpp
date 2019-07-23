#include <iostream>
using namespace std;
class Date;                  //不输入这一句后面42行会报错！！(成员 "Time::hour" (已声明 所在行数 : 10) 不可访问   ？？？？？为什么？)
class Time
{
public:
	Time(int, int, int);
	friend void display(Date &, Time &);
private:
	int hour;
	int minute;
	int sec;
};
class Date
{
public:
	Date(int, int, int);
	friend void display(Date &, Time &);
private:
	int month;
	int day;
	int year;
};

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	sec = s;
}

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

void display(Date &date, Time &time)
{
	cout << date.year << '/' << date.month << '/' << date.day << endl;
	cout << time.hour << ':' << time.minute << ":" << time.sec << endl;
}

int main()
{
	Time t1(10, 13, 56);
	Date d1(12, 25, 2004);
	display(d1, t1);
	system("pause");
	return 0;
}