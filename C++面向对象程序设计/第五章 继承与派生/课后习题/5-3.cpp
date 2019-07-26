#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
protected:
	int num;
	string name;
	char sex;
};

class Student1 :protected Student
{
public:
	void get_value1();
	void display1();
private:
	int age;
	string addr;
};

void Student1::get_value1()
{
	cout << "Please enter the number, name, sex, age, address of the student: " << endl;
	cin >> num >> name >> sex >> age >> addr;
}

void Student1::display1()
{
	cout << "number: " << num << endl;
	cout << "name: " << name << endl;
	cout << "sex: " << sex << endl;
	cout << "age: " << age << endl;
	cout << "address: " << addr << endl;
}

int main()
{
	Student1 stu1;
	stu1.get_value1();
	stu1.display1();
	system("pause");
	return 0;
}