#include <iostream>
using namespace std;
class Complex
{
private:
	double real;
	double imag;
public:
	Complex() :real(0), imag(0) {}                                           //Ĭ�Ϲ��캯��
	Complex(double a, double b) :real(a), imag(b) {}                         //��ʼ�����캯��
	Complex(double x) { real = x; imag = 0; }                                //ת�����캯��
//  Ϊʲô�����ﶨ���˸��ƹ��캯���ͻ�ʹ������������غ����������ࡰComplex��û���ʵ��ĸ��ƹ��캯����	Complex(Complex & c) { real = c.real; imag = c.imag; }                   //���ƹ��캯��
//	friend Complex operator + (Complex & c1, Complex & c2) {}                //Ϊʲô������ˣ���Ϊ������������ʱ���ܼ���{}��  
	friend Complex operator + (Complex & c1, Complex & c2);                 //����˫Ŀ��������غ���Ϊ��Ԫ����
	~Complex() { cout << "OK, this is " <<  "(" << real << "+" << imag << "i)'s " << "destructor!" << endl; }       //��������
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