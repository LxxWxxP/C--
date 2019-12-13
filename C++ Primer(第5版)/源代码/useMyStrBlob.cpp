#include "myStrBlob.h"

int main()
{
	initializer_list<string> temp = { "a","ab","abc","abcd" };
	StrBlob sb(temp);
	cout << "sb.size: " << sb.size() << endl;
	cout << "sb.empty: " << sb.empty() << endl;

	string s("abcde");
	sb.push_back(s);
	cout << "sb.size: " << sb.size() << endl;

	sb.pop_back();
	cout << "sb.size: " << sb.size() << endl;

	//元素访问函数的使用
	sb.front();//输出当前指向的地址
	sb.back();//输出当前指向的地址

	system("pause");
	return 0;
}