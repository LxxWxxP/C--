#include <iostream>
using namespace std;

class Point
{
public:
	Point() :x(0), y(0) {}
	~Point()
	{
		cout << "executing Point destructor" << endl;
	}
protected:
	int x;
	int y;
};

class Circle :public Point
{
public:
	Circle() :Point(), radius(0) {}
	~Circle()
	{
		cout << "executing Circle destructor" << endl;
	}
private:
	int radius;
};

int main()
{
	Point *p = new Circle;
	Circle *pt = new Circle;
	delete pt;
	system("pause");
	return 0;
}