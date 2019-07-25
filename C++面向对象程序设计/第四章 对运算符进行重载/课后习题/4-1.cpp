#include <iostream>
using namespace std;
class Complex
{
private:
	double real;
	double imag;
public:
	Complex() :real(0), imag(0) {}                                           //默认构造函数
	Complex(double a, double b) :real(a), imag(b) {}                         //初始化构造函数
	Complex(double x) { real = x; imag = 0; }                                //转换构造函数
//  为什么我这里定义了复制构造函数就会使后面运算符重载函数报错？（类“Complex”没有适当的复制构造函数）	Complex(Complex & c) { real = c.real; imag = c.imag; }                   //复制构造函数
//	friend Complex operator + (Complex & c1, Complex & c2) {}                //为什么这里错了？因为你声明函数的时候不能加上{}？  
	friend Complex operator + (Complex & c1, Complex & c2);                 //声明双目运算符重载函数为友元函数
	~Complex() { cout << "OK, this is " <<  "(" << real << "+" << imag << "i)'s " << "destructor!" << endl; }       //析构函数
//	void display() {}
	void display();
};

void Complex::display()
{
	cout << "(" << real;
	if (imag > 0)
		cout << "+" << imag << "i)" << endl;
	else if (imag == 0)
		cout << endl;
	else
		cout << imag << "i)" << endl;
}

Complex operator + (Complex &c1, Complex &c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main()
{
	Complex c1(5, 2), c2(1, -1), c3;
	c1.display();
	c2.display();
	c3 = c1 + c2;
	c3.display();
	system("pause");
	return 0;
}