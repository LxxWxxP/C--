#include<iostream>
using namespace std;
class CExample
{
private:
	int a;
public:
	CExample(int b)
	{
		a = b;
		printf("constructor is called\n");
	}
	CExample(const CExample & c)
	{
		a = c.a;
		printf("copy constructor is called\n");
	}
	~CExample()
	{
		cout << "destructor is called\n";
	}
	void Show()
	{
		cout << a << endl;
	}
};
void g_fun(CExample c)//ʹ���Զ�������Ϊ�����ĺ���g_fun
{
	cout << "g_func" << endl;
}
int main()
{
	CExample A(100);
	CExample B = A;
	B.Show();
	g_fun(A);//��A��Ϊʵ�δ�����ʱ�������ᴴ��һ���ֲ������ں�������ʱ�ͷŸ��ڴ�
	system("pause");
	return 0;
}