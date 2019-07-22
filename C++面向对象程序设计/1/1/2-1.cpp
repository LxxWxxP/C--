#include <iostream>
#include <stdlib.h>
using namespace std;

class Time
{
public:
	void set_time();
	void show_time();
private:
	int hour;
	int minute;
	int sec;
};

Time t;
int main()
{
	t.set_time();
	t.show_time();
	system("pause");
	return 0;
}

void Time::set_time()
{
	cin >> hour;
	cin >> minute;
	cin >> sec;
}

void Time::show_time()
{
	cout << hour << ":" << minute << ":" << sec << endl;
}