#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo {
public:
	Foo sorted() && ;//可用于可改变的右值
	Foo sorted() const &;//可用于任何类型的Foo
	Foo sorted(int);
private:
	vector<int> data;
};
//本对象为右值，因此可以原址排序
Foo Foo::sorted() &&
{
	cout << "Rvalue reference version." << endl;
	sort(data.begin(), data.end());//排序
	return *this;
}
//本对象是const或是一个左值，那种情况我们都不能对其进行原址排序
Foo Foo::sorted() const &
{
	cout << "Lvalue reference version." << endl;
	Foo ret(*this);//拷贝一个副本
	sort(ret.data.begin(), ret.data.end());//排序副本
	return ret;//返回副本
}

Foo retVal()
{
	return Foo();//返回一个右值，是一个临时变量
}

Foo& retFoo()
{
	return *(new Foo());//返回一个左值
}

int main(void)
{
	retVal().sorted();
	retFoo().sorted();
	system("pause");
	return 0;
}
