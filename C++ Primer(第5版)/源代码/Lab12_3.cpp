#include<iostream>
using namespace std;
class CExample
{
private:
	int a;
public:
	//���˽�cout��Ϊʹ��printf��ûʲô����
	CExample(int b)
	{
		a = b;
		printf("constructor is called\n");
	}
	//���˽�cout��Ϊʹ��printf��ûʲô����
	CExample(const CExample & c)
	{
		a = c.a;
		printf("copy constructor is called\n");
	}
	//���������û����
	~CExample()
	{
		cout << "destructor is called\n";
	}
	void Show()
	{
		cout << a << endl;
	}
};
CExample g_fun()
{
	CExample temp(0);//����CExample�����temp������ʼ��Ϊ0����ʱʹ�õĹ��캯����CExample(int b)���������constructor is called\n
	return temp;//���ض����һ����������ʱ�����CExample(const CExample & c)���������copy constructor is called\n
}//��һ��temp���������Ѿ����������destructor is called\n
int main()
{
	g_fun();
	system("pause");
	return 0;//�ڶ���temp���������Ѿ����������destructor is called\n
}