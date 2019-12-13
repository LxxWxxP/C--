/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	string str("some string"), orig = str;
	if (!str.empty())          //���ʹ���ַ������������ܣ���������ȷ���ַ�������
		cout << str[0] << endl;//ʹ���±꣨����������ַ����еĵ�һ���ַ�

	if (!str.empty())       
		str[0] = toupper(str[0]);//���ַ����е�һ���ַ�תΪ��д
	cout << str << endl;

	str = orig; //�����ַ���sΪ��ʼ�ַ���orig

	//ʹ��string��ĵ���������string���ַ���
	if (str.begin() != str.end())//ͨ���ж��ַ���ͷ���ַ���β��ȷ���ַ�������
	{ 
		string::iterator it = str.begin(); //string�������itָ��str�ĵ�һ���ַ�
		*it = toupper(*it);//ͨ��*�������ȡ��ǰ�ַ���ֵ������תΪ��д
	}
	cout << str << endl;

	str = orig;//�����ַ���sΪ��ʼ�ַ���orig

	// ���ֽ��ַ���תΪ��д�ķ���:
	// 1. ʹ��for������string��ʹ���±�/������
	for (string::size_type index = 0; index != str.size() && !isspace(str[index]); ++index)
		str[index] = toupper(str[index]); // ����ǰ�ַ�תΪ��д
	cout << str << endl;

	str = orig;//�����ַ���sΪ��ʼ�ַ���orig

	// 2. ʹ��for������string��ʹ�õ�����iterator��
	for (string::iterator it = str.begin(); it != str.end() && !isspace(*it); ++it)
		*it = toupper(*it); // ����ǰ�ַ�תΪ��д
	cout << str << endl;

	str = orig;//�����ַ���sΪ��ʼ�ַ���orig

	// 3. ʹ��while������string��ʹ���±�/������
	string::size_type index = 0; // �����±�/�������ڱ���string
	while (index != str.size() && !isspace(str[index])) 
	{
		str[index] = toupper(str[index]);  // ����ǰ�ַ�תΪ��д
		++index;        // �±�+1
	}
	cout << str << endl;

	// 4. ʹ��while������string��ʹ�õ�����iterator��
	string::iterator beg = str.begin();
	while (beg != str.end() && !isspace(*beg)) 
	{
		*beg = toupper(*beg);
		++beg;
	}
	cout << str << endl;

	str = orig;//�����ַ���sΪ��ʼ�ַ���orig

	// ʹ��for�������ַ�����ʹ�õ�����iterator��
	// ���str�ַ�����ÿ���ַ�֮���û��и���
	for (string::const_iterator c = str.begin(); c != str.end(); ++c)
		cout << *c << endl; // �����ǰ�ַ�������ʹ�û��з�����

	// �޸��ַ���
	for (string::iterator c = str.begin(); c != str.end(); ++c)
		*c = '*'; // ʹ�á�*���������ǰ�ַ�
	cout << str << endl;

	str = orig;//�����ַ���sΪ��ʼ�ַ���orig

	// ʹ��for�������ַ�����ʹ���±�/������
	// ���str�ַ�����ÿ���ַ�֮���û��и���
	for (string::size_type ix = 0; ix != str.size(); ++ix)
		cout << str[ix] << endl;  // �����ǰ�ַ�������ʹ�û��з�����

	// �޸��ַ���
	for (string::size_type ix = 0; ix != str.size(); ++ix)
		str[ix] = '*';  // ʹ�á�*���������ǰ�ַ�
	cout << str << endl;

	str = orig;//�����ַ���sΪ��ʼ�ַ���orig

	// ʹ��for�������ַ�����ʹ�õ�����iterator��
	// ���str�ַ�����ÿ���ַ�֮���û��и���
	for (string::const_iterator beg = str.begin(); beg != str.end(); ++beg)
		cout << *beg << endl;  // �����ǰ�ַ�������ʹ�û��з�����

	// �޸��ַ���
	for (string::iterator beg = str.begin(); beg != str.end(); ++beg)
		*beg = '*';  // ʹ�á�*���������ǰ�ַ�
	cout << str << endl;

	system("pause");
	return 0;
}