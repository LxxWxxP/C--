#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s, result;
	cout << "Please enter a string,it's best to include some punctuation marks. " << endl;
	getline(cin, s);//����cin�����룬���뵽s�ַ����У������հ׷���������
	//ȥ��string�еı����Ų�����µ��ַ���
	for (decltype(s.size()) i = 0; i < s.size(); i++)
	{
		if (!ispunct(s[i]))
			result += s[i];//string������������+=������������������������result��ֵ
	}
	cout << result << endl;
	system("pause");
	return 0;
}
