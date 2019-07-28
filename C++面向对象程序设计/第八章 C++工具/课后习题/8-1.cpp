#include <iostream>
#include <cmath>
using namespace std;

void fun_two(float a, float b, float c)
{
	float dieta = sqrt(b*b - 4 * a*c);
	if (dieta < 0)throw dieta;
	float x1 = (-b + dieta) / (2 * a);
	float x2 = (-b - dieta) / (2 * a);
	cout << "x1 = " << x1 << "   " << "x2 = " << x2 << endl;
	return;
}

int main()
{
	cout << "Please enter a,b,c of the function two(ax^2+bx+c=0): ";
	float a, b, c;
	cin >> a >> b >> c;
	try
	{
		fun_two(a, b, c);
	}
	catch (float)
	{
		cout << "The function has no answer!" << endl;
	}
	system("pause");
	return 0;
}