#include<iostream>
using namespace std;
class Rect
{
public:
	Rect()//���캯��
	{
		count++;
	}
	~Rect()//��������
	{
		count--;
	}
	static int getCount()//��Ա����,����ʹ����������˽�е����ݳ�Ա
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