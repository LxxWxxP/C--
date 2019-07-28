#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float a, b, c, s, area;
	cout << "Please enter three line of the triangle(a,b,c):" << endl;
	cin >> a >> b >> c;
	if (a + b <= c || b + c <= a || c + a <= b)
	{
		cerr << "a,b,c can't created a triangle!" << endl;
		system("pause");
		exit(1);
	}
	s = (a + b + c) / 2;
	area = sqrt(s*(s - a)*(s - b)*(s - c));
	cout << "The area of the triangle is: " << area << endl;
	system("pause");
	return 0;
}