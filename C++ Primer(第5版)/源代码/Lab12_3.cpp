#include<iostream>
using namespace std;
class CExample
{
private:
	int a;
public:
	//除了将cout改为使用printf，没什么区别
	CExample(int b)
	{
		a = b;
		printf("constructor is called\n");
	}
	//除了将cout改为使用printf，没什么区别
	CExample(const CExample & c)
	{
		a = c.a;
		printf("copy constructor is called\n");
	}
	//与上面代码没区别
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
	CExample temp(0);//创建CExample类对象temp，并初始化为0，此时使用的构造函数是CExample(int b)，并且输出constructor is called\n
	return temp;//返回对象的一个拷贝，此时会调用CExample(const CExample & c)，并且输出copy constructor is called\n
}//第一个temp生命周期已经结束，输出destructor is called\n
int main()
{
	g_fun();
	system("pause");
	return 0;//第二个temp生命周期已经结束，输出destructor is called\n
}