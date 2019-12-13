#include<iostream>
using namespace std;
class Rect
{
public:
	Rect()//默认构造函数
	{
		count++;
	}
	Rect(const Rect& r)//复制构造函数（拷贝构造函数）
	{
		width = r.width;
		height = r.height;
		count++;
	}
	~Rect()//析构函数
	{
		count--;
	}
	static int getCount()//静态成员函数：所有的类实例共享此函数，类实例对此函数的使用记录会继续保留
	{
		return count;//返回私有数据成员count
	}
private:
	int width;
	int height;
	static int count;
};
int Rect::count = 0;
int main()
{
	Rect rect1;
	cout << "The count of Rect:" << Rect::getCount() << endl;//将count加一，此时count=1
	Rect rect2(rect1);
	cout << "The count of Rect:" << Rect::getCount() << endl;//将count加一，此时count=2，因为静态成员函数是类的属性，类实例一旦修改了里面的数据，此类会继续保留下来
	system("pause");
	return 0;
}