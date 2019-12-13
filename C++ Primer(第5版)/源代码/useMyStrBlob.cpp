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

	//Ԫ�ط��ʺ�����ʹ��
	sb.front();//�����ǰָ��ĵ�ַ
	sb.back();//�����ǰָ��ĵ�ַ

	system("pause");
	return 0;
}