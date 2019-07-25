#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex() :real(0), imag(0) {}                                                         //默认构造函数
	Complex(double a, double b) :real(a), imag(b) {}                                       //初始化构造函数
	Complex(const Complex & c) { real = c.real; imag = c.imag; }                           //复制构造函数
	Complex(double x) { real = x; imag = 0; }                                              //转换构造函数
	~Complex() { cout << real << "+" << imag << "i" << " has been create!" << endl; }      //析构函数
	operator double() { return real; }                                                     //类型转换函数
	void display();
	friend Complex operator + (Complex & c1, const Complex & c2);                          //+友元函数
	friend Complex operator - (Complex & c1, const Complex & c2);                          //-友元函数
	friend Complex operator * (Complex & c1, const Complex & c2);                          //*友元函数
	friend Complex operator / (Complex & c1, const Complex & c2);                          // /友元函数
};

Complex operator + (Complex & c1, const Complex & c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator - (Complex & c1, const Complex & c2)
{
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

Complex operator * (Complex & c1, const Complex & c2)
{
	return Complex(c1.real * c2.real, c1.imag * c2.imag);
}

Complex operator / (Complex & c1, const Complex & c2)
{
	return Complex(c1.real / c2.real, c1.imag / c2.imag);
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
	Complex c1(5, 2), c2(2, -0.5), c3;
	c1.display();
	c2.display();
	c3 = c1 + c2;
	c3.display();
	c3 = c1 - c2;
	c3.display();
	c3 = c1 * c2;
	c3.display();
	c3 = c1 / c2;
	c3.display();
	system("pause");
	return 0;
}