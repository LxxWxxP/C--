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
	if (!str.empty())          //如果使用字符串的索引功能，必须首先确保字符串不空
		cout << str[0] << endl;//使用下标（索引）输出字符串中的第一个字符

	if (!str.empty())       
		str[0] = toupper(str[0]);//将字符串中第一个字符转为大写
	cout << str << endl;

	str = orig; //重置字符串s为初始字符串orig

	//使用string类的迭代器遍历string类字符串
	if (str.begin() != str.end())//通过判定字符串头≠字符串尾来确保字符串不空
	{ 
		string::iterator it = str.begin(); //string类迭代器it指向str的第一个字符
		*it = toupper(*it);//通过*运算符获取当前字符的值，并且转为大写
	}
	cout << str << endl;

	str = orig;//重置字符串s为初始字符串orig

	// 四种将字符串转为大写的方法:
	// 1. 使用for语句遍历string（使用下标/索引）
	for (string::size_type index = 0; index != str.size() && !isspace(str[index]); ++index)
		str[index] = toupper(str[index]); // 将当前字符转为大写
	cout << str << endl;

	str = orig;//重置字符串s为初始字符串orig

	// 2. 使用for语句遍历string（使用迭代器iterator）
	for (string::iterator it = str.begin(); it != str.end() && !isspace(*it); ++it)
		*it = toupper(*it); // 将当前字符转为大写
	cout << str << endl;

	str = orig;//重置字符串s为初始字符串orig

	// 3. 使用while语句遍历string（使用下标/索引）
	string::size_type index = 0; // 定义下标/索引用于遍历string
	while (index != str.size() && !isspace(str[index])) 
	{
		str[index] = toupper(str[index]);  // 将当前字符转为大写
		++index;        // 下标+1
	}
	cout << str << endl;

	// 4. 使用while语句遍历string（使用迭代器iterator）
	string::iterator beg = str.begin();
	while (beg != str.end() && !isspace(*beg)) 
	{
		*beg = toupper(*beg);
		++beg;
	}
	cout << str << endl;

	str = orig;//重置字符串s为初始字符串orig

	// 使用for语句遍历字符串（使用迭代器iterator）
	// 输出str字符串，每个字符之间用换行隔开
	for (string::const_iterator c = str.begin(); c != str.end(); ++c)
		cout << *c << endl; // 输出当前字符，并且使用换行符隔开

	// 修改字符串
	for (string::iterator c = str.begin(); c != str.end(); ++c)
		*c = '*'; // 使用‘*’来替代当前字符
	cout << str << endl;

	str = orig;//重置字符串s为初始字符串orig

	// 使用for语句遍历字符串（使用下标/索引）
	// 输出str字符串，每个字符之间用换行隔开
	for (string::size_type ix = 0; ix != str.size(); ++ix)
		cout << str[ix] << endl;  // 输出当前字符，并且使用换行符隔开

	// 修改字符串
	for (string::size_type ix = 0; ix != str.size(); ++ix)
		str[ix] = '*';  // 使用‘*’来替代当前字符
	cout << str << endl;

	str = orig;//重置字符串s为初始字符串orig

	// 使用for语句遍历字符串（使用迭代器iterator）
	// 输出str字符串，每个字符之间用换行隔开
	for (string::const_iterator beg = str.begin(); beg != str.end(); ++beg)
		cout << *beg << endl;  // 输出当前字符，并且使用换行符隔开

	// 修改字符串
	for (string::iterator beg = str.begin(); beg != str.end(); ++beg)
		*beg = '*';  // 使用‘*’来替代当前字符
	cout << str << endl;

	system("pause");
	return 0;
}