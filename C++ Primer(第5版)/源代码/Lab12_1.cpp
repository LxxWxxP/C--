#include<iostream>
using namespace std;
class CExample
{
private:
	int a;
public:
	//含参数的构造函数：使用int型参数b对数据成员a赋值
	CExample(int b)
	{
		a = b;
		printf("constructor is called\n");
	}
	//复制构造函数（拷贝构造函数）：传进一个const的CExample类对象，对取c的数据成员对a赋值，从而达到对CExample类对象进行初始化的作用
	CExample(const CExample & c)
	{
		a = c.a;
		printf("copy constructor is called\n");
	}
	//析构函数，当对象被销毁时，输出下述语句
	~CExample()
	{
		cout << "destructor is called\n";
	}
	void Show()//成员函数
	{
		cout << a << endl;
	}
};
int main()
{
	CExample A(100);//调用CExample(int b)
	CExample B = A;//调用CExample(const CExample & c)
	B.Show();
	system("pause");
	return 0;
}