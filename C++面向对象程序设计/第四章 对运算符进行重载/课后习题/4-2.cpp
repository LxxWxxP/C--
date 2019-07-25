#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex() :real(0), imag(0) {}                                                         //Ĭ�Ϲ��캯��
	Complex(double a, double b) :real(a), imag(b) {}                                       //��ʼ�����캯��
	Complex(const Complex & c) { real = c.real; imag = c.imag; }                           //���ƹ��캯��
	Complex(double x) { real = x; imag = 0; }                                              //ת�����캯��
	~Complex() { cout << real << "+" << imag << "i" << " has been create!" << endl; }      //��������
	operator double() { return real; }                                                     //����ת������
	void display();
	friend Complex operator + (Complex & c1, const Complex & c2);                          //+��Ԫ����
	friend Complex operator - (Complex & c1, const Complex & c2);                          //-��Ԫ����
	friend Complex operator * (Complex & c1, const Complex & c2);                          //*��Ԫ����
	friend Complex operator / (Complex & c1, const Complex & c2);                          // /��Ԫ����
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