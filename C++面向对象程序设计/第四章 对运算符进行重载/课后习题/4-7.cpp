#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	int grade;
	double score;
public:
	Student() :num(0), name("xxx"), sex("male"), grade(1), score(0) {}
	Student(int n, string str, string s, int g, double sc) :num(n), name(str), sex(s), grade(g), score(sc) {}
	Student(Student & s) { num = s.num; name = s.name; sex = s.sex; grade = s.grade; score = s.score; }
	~Student() { cout << "A student data has been created!" << endl; }
	int num;
	string name;
	string sex;
};

class Teacher
{
private:
	int num;
	string name;
	string sex;
public:
	Teacher() :num(0), name("xxx"), sex("male") {}
	Teacher(int n, string str, string s) :num(n), name(str), sex(s) {}
	Teacher(Teacher & t) { num = t.num; name = t.name; sex = t.sex; }
	Teacher(Student & s) { num = s.num; name = s.name; sex = s.sex; }
};