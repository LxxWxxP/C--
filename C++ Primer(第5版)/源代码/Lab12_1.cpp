#include<iostream>
using namespace std;
class CExample
{
private:
	int a;
public:
	//�������Ĺ��캯����ʹ��int�Ͳ���b�����ݳ�Աa��ֵ
	CExample(int b)
	{
		a = b;
		printf("constructor is called\n");
	}
	//���ƹ��캯�����������캯����������һ��const��CExample����󣬶�ȡc�����ݳ�Ա��a��ֵ���Ӷ��ﵽ��CExample�������г�ʼ��������
	CExample(const CExample & c)
	{
		a = c.a;
		printf("copy constructor is called\n");
	}
	//��������������������ʱ������������
	~CExample()
	{
		cout << "destructor is called\n";
	}
	void Show()//��Ա����
	{
		cout << a << endl;
	}
};
int main()
{
	CExample A(100);//����CExample(int b)
	CExample B = A;//����CExample(const CExample & c)
	B.Show();
	system("pause");
	return 0;
}