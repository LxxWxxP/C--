#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s, result;
	cout << "Please enter a string,it's best to include some punctuation marks. " << endl;
	getline(cin, s);//接收cin的输入，输入到s字符串中，遇到空白符结束输入
	//去掉string中的标点符号并输出新的字符串
	for (decltype(s.size()) i = 0; i < s.size(); i++)
	{
		if (!ispunct(s[i]))
			result += s[i];//string类里面重载了+=运算符，于是这里可以这样给result赋值
	}
	cout << result << endl;
	system("pause");
	return 0;
}
