#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include "myStrBlobPtr.h"

int main()
{
	StrBlob b1;
	{
		initializer_list<string> temp = { "a", "ab", "abc" };
		StrBlob b2(temp);//定义一个StrBlob对象，并且用在区间[temp,temp+sizeof(temp)/sizeof(*temp)]的数据来初始化
		b1 = b2;//b1指向b2所指向的内容（两者指向了同一个vector容器）
		b2.push_back("abcd");//在智能指针b2指向的vector末尾添加元素"abcd"
		cout << b2.size() << endl;//输出b2指向的vector大小
	}//在这之后b2已经被销毁，因为b2在大括号里面声明的
	cout << b1.size() << endl;//这里b1的size和b2的size一样

	for (StrBlobPtr it = b1.begin(); neq(it,b1.end()); it.incr())//遍历b1对象
		cout << it.deref() << endl;//返回当前指向的元素
	system("pause");
	return 0;
}