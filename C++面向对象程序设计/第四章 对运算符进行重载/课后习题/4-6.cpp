#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex() :real(0), imag(0) {}
	Complex(double x, double y) :real(x), imag(y) {}
	Complex(Complex & c) { real = c.real; imag = c.imag; }
	Complex(double x) { real = x; imag = 0; }
	~Complex() { cout << real << "+" << imag << "i" << " is been created!" << endl; }
	operator double() { return real; }                        //此函数的返回值就是函数名所表示的类型（类-->非(原)类）
	friend Complex operator + (Complex &, Complex &);
	void display();
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
	Complex c1(2, -0.5);
	double i = 2.3, sum1, sum2;
	sum1 = c1 + i;
	sum2 = i + c1;
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;
	system("pause");
	return 0;
}