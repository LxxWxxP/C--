#include <iostream>
using namespace std;
class Student
{
private:
	int num;
	int score;
public:
	Student(int n,int s):num(n),score(s){}
	Student* max(Student *stu);
	void display();
};

Student* Student::max(Student *stu)
{
	Student *topstudent = stu;
	int score_max = stu->score;
	for (int i = 0; i < 5; i++, stu++)
	{
		if (score_max < stu->score)
		{
			score_max = stu->score;
			topstudent = stu;
		}
	}
	return topstudent;
}

void Student::display()
{
	cout << "The number of the student is: " << num << endl;
}

int main()
{
	Student stu[5] =
	{
		Student(1,90),
		Student(2,86),
		Student(3,88),
		Student(4,69),
		Student(5,91)
	};
	Student *topstudent = stu->max(stu);
	topstudent->display();
	system("pause");
	return 0;
}