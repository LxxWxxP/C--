#include <iostream>
#include <string>
using namespace std;
class Teacher
{
protected:
	int num;
	string name;
	string sex;
public:
	Teacher(int n = 1, string nam = "xxx", string s = "male") :num(n), name(nam), sex(s) {}
	void display_t()
	{
		cout << "num: " << num << endl;
		cout << "name: " << name << endl;
		cout << "sex: " << sex << endl;
	}
};

class Birthday
{
private:
	int year;
	int month;
	int day;
public:
	Birthday(int y = 2019, int m = 1, int d = 1) :year(y), month(m), day(d) {}
	void set_birthday(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void display_b()
	{
		cout << "birthday: " << year << "/" << month << "/" << day << endl;
	}
};

class Professor :public Teacher
{
private:
	Birthday birthday;
public:
	Professor(int n, string nam, string s, Birthday b) :Teacher(n, nam, s), birthday(b) {}
	void show()
	{
		display_t();
		birthday.display_b();
	}
};

int main()
{
	Birthday b(1992, 10, 24);
	Professor prof1(19, "zhoushen", "male", b);
	prof1.show();
	b.set_birthday(1998, 10, 19);
	prof1 = Professor(19, "zhoushen", "male", b);
	prof1.show();
	system("pause");
	return 0;
}