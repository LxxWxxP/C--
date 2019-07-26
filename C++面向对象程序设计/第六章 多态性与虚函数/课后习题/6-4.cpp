#include <iostream> 
using namespace std;

class Shape
{
public:
	virtual void shapename() const = 0;
	virtual void printArea() const {}
};

class Circle :public Shape
{
private:
	float radius;
public:
	Circle() :radius(0) {}
	Circle(float r) :radius(r) {}
	~Circle() { cout << "A circle has been created!" << endl; }
	void shapename() const { cout << "Circle:" << endl; }
	void printArea() const { cout << "area = " << 3.14159 * radius * radius << endl; }
};

class Ractangle :public Shape
{
private:
	float x, y;
public:
	Ractangle() :x(0), y(0) {}
	Ractangle(float a, float b) :x(a), y(b) {}
	~Ractangle() { cout << "A ractangle has been created!" << endl; }
	void shapename() const { cout << "Ractangle:" << endl; }
	void printArea() const { cout << "area = " << x * y << endl; }
};

class Triangle :public Shape
{
private:
	float a, b, c;
public:
	Triangle() :a(0), b(0), c(0) {}
	Triangle(float x, float y, float z) :a(x), b(y), c(z) {}
	~Triangle() { cout << "A triangle has been created!" << endl; }
	void shapename() const { cout << "Triangle:" << endl; }
	void printArea() const
	{
		if (a + b <= c || a + c <= b || b + c <= a)
		{
			cout << "They(a,b,c) can't create a triangle!" << endl;
			return;
		}
		else {
			float p = (a + b + c) / 2;
			float s = sqrt(p*(p - a)*(p - b)*(p - c));
			cout << "area = " << s << endl;
			return;
		}
	}
};

int main()
{
	Circle c = Circle(5);
	c.shapename();
	c.printArea();
	cout << endl;
	Ractangle r = Ractangle(3, 4);
	r.shapename();
	r.printArea();
	cout << endl;
	Triangle t = Triangle(3, 4, 5);
	t.shapename();
	t.printArea();
	cout << endl;
	system("pause");
	return 0;
}