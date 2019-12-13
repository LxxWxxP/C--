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
void g_fun(CExample c)//使用自定义类作为参数的函数g_fun
{
	cout << "g_func" << endl;
}
int main()
{
	CExample A(100);
	CExample B = A;
	B.Show();
	g_fun(A);//当A作为实参传进来时，函数会创建一个局部对象，在函数结束时释放该内存
	system("pause");
	return 0;
}