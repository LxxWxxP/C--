#include <iostream>
using namespace std;

class Complex
{
private:
	int real;
	int imag;
public:
	Complex() :real(0), imag(0) {}
	Complex(int a, int b) :real(a), imag(b) {}
//	Complex(int x) :real(x), imag(0) {}//或者：Complex(int x){ real=x; imag=0; }那如果你这么写这两行的话（11、12行），还不如Complex(int a, int b = 0) :real(a), imag(b) {}这么写？
	Complex(int x) { real = x; imag = 0; }
	Complex(const Complex & c) { real = c.real; imag = c.imag; }
	operator int() { return real; }
	~Complex() { cout << real << "+" << imag << "i" << " has been create!" << endl; }
	void display();
	friend Complex operator + (Complex & c1, Complex & c2);
};

Complex operator + (Complex & c1, Complex & c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

void Complex::display()
{
	cout << real;
	if (imag > 0)
		cout << "+" << imag << "i" << endl;
	else if (imag == 0)
		cout << endl;
	else
		cout << imag << "i" << endl;
}

int main()
{
	Complex c1(5, 2), c2(2, -1), c3;
	int i = 12;
	c1.display();
	c2.display();
	c3 = c1 + c2;
	c3.display();
	c3 = c1 + i;
	c3.display();
	c3 = i + c1;
	c3.display();
	system("pause");
	return 0;
}