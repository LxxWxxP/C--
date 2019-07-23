#include <iostream>
using namespace std;
class Student
{
public:
	Student(int n, float s) :num(n), score(s) {}
	void change(int n, float s){ num = n; score = s; }
	void display(){ cout << num << " " << score << endl; }
	friend void fun(Student &stu);
private:
	int num;
	float score;
};

void fun(Student &stu)
{
	stu.change(stu.num, stu.score);
	stu.display();
}

int main()
{
	Student stud(101, 78.5);
	stud.display();
	Student stu(101, 80.5);
	fun(stu);
	system("pause");
	return 0;
}