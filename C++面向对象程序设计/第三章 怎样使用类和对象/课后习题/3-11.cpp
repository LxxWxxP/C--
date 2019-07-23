#include <iostream>
using namespace std;
class Date;                          //��ǰ������Date�������ڣ���Time�����õ�ʱ��Ҫ��С��
class Time
{
public:
	Time(int, int, int);
	void display(Date &);            //Time˵���ҵļ���display�����Date������
private:
	int hour;
	int minute;
	int sec;
};

class Date
{
public:
	Date(int, int, int);
	friend Time;                     //Date˵������һ�����ѽ�Time�������������ҵ�����
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