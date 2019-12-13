#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo {
public:
	Foo sorted() && ;//�����ڿɸı����ֵ
	Foo sorted() const &;//�������κ����͵�Foo
	Foo sorted(int);
private:
	vector<int> data;
};
//������Ϊ��ֵ����˿���ԭַ����
Foo Foo::sorted() &&
{
	cout << "Rvalue reference version." << endl;
	sort(data.begin(), data.end());//����
	return *this;
}
//��������const����һ����ֵ������������Ƕ����ܶ������ԭַ����
Foo Foo::sorted() const &
{
	cout << "Lvalue reference version." << endl;
	Foo ret(*this);//����һ������
	sort(ret.data.begin(), ret.data.end());//���򸱱�
	return ret;//���ظ���
}

Foo retVal()
{
	return Foo();//����һ����ֵ����һ����ʱ����
}

Foo& retFoo()
{
	return *(new Foo());//����һ����ֵ
}

int main(void)
{
	retVal().sorted();
	retFoo().sorted();
	system("pause");
	return 0;
}
