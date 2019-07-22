#include "student.h"
#include <iostream>
using namespace std;

void Student::display()
{
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex: " << sex << endl;
}

void Student::set_value()
{
	cin >> num >> name >> sex;
}