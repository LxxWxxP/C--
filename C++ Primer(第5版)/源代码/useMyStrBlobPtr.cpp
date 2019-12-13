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
		StrBlob b2(temp);//����һ��StrBlob���󣬲�����������[temp,temp+sizeof(temp)/sizeof(*temp)]����������ʼ��
		b1 = b2;//b1ָ��b2��ָ������ݣ�����ָ����ͬһ��vector������
		b2.push_back("abcd");//������ָ��b2ָ���vectorĩβ���Ԫ��"abcd"
		cout << b2.size() << endl;//���b2ָ���vector��С
	}//����֮��b2�Ѿ������٣���Ϊb2�ڴ���������������
	cout << b1.size() << endl;//����b1��size��b2��sizeһ��

	for (StrBlobPtr it = b1.begin(); neq(it,b1.end()); it.incr())//����b1����
		cout << it.deref() << endl;//���ص�ǰָ���Ԫ��
	system("pause");
	return 0;
}