#include <iostream>
#include <string>
using namespace std;
class Teacher
{
protected:
	string name;
	int age;
	string sex;
	string address;
	long long phone;
	string title;
public:
	Teacher(string n, int a, string s, string addr, long long p, string t) :name(n), age(a), sex(s), address(addr), phone(p), title(t) {}
	void display()
	{
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
		cout << "sex: " << sex << endl;
		cout << "address: " << address << endl;
		cout << "phone: " << phone << endl;
		cout << "title: " << title << endl;
	}
};

class Cadre
{
protected:
	string name;
	int age;
	string sex;
	string address;
	long long phone;
	string post;
public:
	Cadre(string n, int a, string s, string addr, long long p, string pos) :name(n), age(a), sex(s), address(addr), phone(p), post(pos) {}
	void display()
	{
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
		cout << "sex: " << sex << endl;
		cout << "address: " << address << endl;
		cout << "phone: " << phone << endl;
		cout << "post: " << post << endl;
	}
};

class Teacher_Cadre :public Teacher, public Cadre
{
protected:
	float wages;
public:
	Teacher_Cadre(string n, int a, string s, string addr, long long p, string t, string pos, float w) :Teacher(n, a, s, addr, p, t), Cadre(n, a, s, addr, p, pos), wages(w) {}
	void show();
};

void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "post: " << Cadre::post << endl;
	cout << "wages: " << wages << endl;
}

int main()
{
	Teacher_Cadre t_c("xxx", 25, "male", "Guangzhou", 123456789, "teacher", "professor", 20000);
	t_c.show();
	system("pause");
	return 0;
}