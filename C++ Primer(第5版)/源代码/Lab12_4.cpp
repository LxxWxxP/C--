#include<iostream>
using namespace std;
class Rect
{
public:
	Rect()//构造函数
	{
		count++;
	}
	~Rect()//析构函数
	{
		count--;
	}
	static int getCount()//成员函数,可以使用列提里面私有的数据成员
	{
		return count;
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
	cout << "The count of Rect:" << Rect::getCount() << endl;
	Rect rect2(rect1);
	cout << "The count of Rect:" << Rect::getCount() << endl;
	system("pause");
	return 0;
}