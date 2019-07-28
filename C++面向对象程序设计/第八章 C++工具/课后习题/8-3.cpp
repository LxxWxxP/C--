#include <iostream>
#include <string>
using namespace std;

namespace pd                //Personnel Department
{
	class Student
	{
	private:
		int num;
		string name;
		int age;
		string address;
	public:
		Student(int n, string nam, int a, string addr) :num(n), name(nam), age(a), address(addr) {}
		void display()
		{
			cout << "number: " << num << endl;
			cout << "name: " << name << endl;
			cout << "age: " << age << endl;
			cout << "address: " << address << endl << endl;
		}
	};
}
namespace ead               //Educational Administration Department
{
	class Student
	{
	private:
		int num;
		string name;
		string sex;
		float score;
	public:
		Student(int n, string nam, string s,float sc) :num(n), name(nam), sex(s), score(sc) {}
		void display()
		{
			cout << "number: " << num << endl;
			cout << "name: " << name << endl;
			cout << "sex: " << sex << endl;
			cout << "score: " << score << endl << endl;
		}
	};
}

int main()
{
	pd::Student stu1(1, "Li", 21, "Guangzhou");
	ead::Student stud1(1, "Li", "male", 95);
	ead::Student stu2(2, "Xuan", "female", 98);
	stu1.display();
	stud1.display();
	stu2.display();
	system("pause");
	return 0;
}