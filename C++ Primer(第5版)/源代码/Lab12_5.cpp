#include<iostream>
using namespace std;
class Rect
{
public:
	Rect()//Ĭ�Ϲ��캯��
	{
		count++;
	}
	Rect(const Rect& r)//���ƹ��캯�����������캯����
	{
		width = r.width;
		height = r.height;
		count++;
	}
	~Rect()//��������
	{
		count--;
	}
	static int getCount()//��̬��Ա���������е���ʵ������˺�������ʵ���Դ˺�����ʹ�ü�¼���������
	{
		return count;//����˽�����ݳ�Աcount
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
	cout << "The count of Rect:" << Rect::getCount() << endl;//��count��һ����ʱcount=1
	Rect rect2(rect1);
	cout << "The count of Rect:" << Rect::getCount() << endl;//��count��һ����ʱcount=2����Ϊ��̬��Ա������������ԣ���ʵ��һ���޸�����������ݣ�����������������
	system("pause");
	return 0;
}