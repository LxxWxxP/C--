#include <iostream> 
using namespace std;

class Shape
{
public:
	virtual void shapename() const = 0;
	virtual double area() const { return 0.0; }
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
	double area() const { return 3.14159 * radius * radius; }
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
	double area() const { return x * y; }
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
	double area() const
	{
		if (a + b <= c || a + c <= b || b + c <= a)
		{
			cout << "They(a,b,c) can't create a triangle!" << endl;
			return 0;
		}
		else {
			float p = (a + b + c) / 2;
			float s = sqrt(p*(p - a)*(p - b)*(p - c));
			return s;
		}
	}
};

class Square :public Shape
{
private:
	float x;
public:
	Square() :x(0) {}
	Square(float a) :x(a) {}
	~Square() { cout << "A square has been created!" << endl; }
	void shapename() const { cout << "Square:" << endl; }
	double area() const { return x * x; }
};

class Trapezoid :public Shape
{
private:
	float a, b, h;
public:
	Trapezoid() :a(0), b(0), h(0) {}
	Trapezoid(float x, float y, float z) :a(x), b(y), h(z) {}
	~Trapezoid() { cout << "A trapezoid has been created!" << endl; }
	void shapename() const { cout << "Trapezoid:" << endl; }
	double area() const { return (a + b) * h / 2; }
};

float volume_sum(Circle &c, Square &s, Ractangle &r, Trapezoid &tra, Triangle &tri)//不能用const，因为用const就代表不能改变，也就代表不能用指针指着
{
	Shape *p;
	double v1, v2, v3, v4, v5;
	p = &c;
	v1 = p->area();

	p = &s;
	v2 = p->area();

	p = &r;
	v3 = p->area();

	p = &tra;
	v4 = p->area();

	p = &tri;
	v5 = p->area();

	return v1 + v2 + v3 + v4 + v5;

}

int main()
{
	Circle c(12.6);
	Square s(3.5);
	Ractangle r(4.5, 8.4);
	Trapezoid tra(2, 4.5, 3.2);
	Triangle tri(3, 4, 5);
	cout << "The sum of five volume is: " << volume_sum(c, s, r, tra, tri) << endl;
	system("pause");
	return 0;
}