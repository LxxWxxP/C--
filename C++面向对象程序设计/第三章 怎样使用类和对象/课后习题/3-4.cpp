#include <iostream>
using namespace std;

class Student_infos
{
private:
	int num;
	int grade;
public:
//	Student_infos(int n = 0, int g = 0) : num(n), grade(g){}      //������Ϊ�������и���ֵ���Ի�������������ǣ�����Ϊ�Һ���ѭ������֮ǰ�Ǵ�0-5������i+2
	Student_infos(int n = 0, int g = 0) : num(n), grade(g) {}
	void output_data();
};

void Student_infos::output_data()
{
	cout << "The number of the student is: " << num << endl;
	cout << "The grade of the student is: " << grade << endl;
}

int main()
{
	Student_infos stu[5] = 
	{
		Student_infos(1,98),
		Student_infos(2,86),
		Student_infos(3,88),
		Student_infos(4,69),
		Student_infos(5,91)
	};
	Student_infos *pt = stu;
	for (int i = 0; i <= 2; i++, pt = pt + 2)
	{
		pt->output_data();
	}
	system("pause");
	return 0;
}