#include <iostream>
using namespace std;
class Date;                          //提前声明有Date这个类存在，在Time中引用的时候不要大惊小怪
class Time
{
public:
	Time(int, int, int);
	void display(Date &);            //Time说：我的家人display想访问Date的数据
private:
	int hour;
	int minute;
	int sec;
};

class Date
{
public:
	Date(int, int, int);
	friend Time;                     //Date说：我有一个朋友叫Time，我允许他来我的卧室
private:
	int year;
	int month;
	int day;
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

void Time::display(Date &date)
{
	cout << date.year << "/" << date.month << "/" << date.day << endl;
	cout << hour << ":" << minute << ":" << sec << endl;
}

int main()
{
	Time t(10, 13, 56);
	Date d(12, 25, 2004);
	t.display(d);
	system("pause");
	return 0;
}