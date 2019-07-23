#include <iostream>
#include <stdlib.h>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int sec;
public:
	inline void set_time();
	inline void show_time();
};

void Time::set_time()
{
	cin >> hour >> minute >> sec;
}
void Time::show_time()
{
	cout << hour << ":" << minute << ":" << sec << endl;
}

int main()
{
	Time t1;
	t1.set_time();
	t1.show_time();
	system("pause");
	return 0;
}