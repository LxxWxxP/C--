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

#include <cctype>
using std::isupper; using std::toupper;
using std::islower; using std::tolower;
using std::isalpha; using std::isspace;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	string s("Hello World!!!");

	//用于计算输入的字符串的标点符号的个数
	string::size_type punct_cnt = 0;//punct_cnt为string类的size_type类型
	for (string::size_type c = 0; c != s.size(); ++c)
		if (ispunct(s[c]))   //判断当前字符是否标点符号
			++punct_cnt;     //punct_cnt累计加一
	cout << punct_cnt
		<< " punctuation characters in " << s << endl;

	//使用for语句遍历string(直到string的结尾，不忽略空格符)
	string orig = s;
	for (string::size_type c = 0; c != s.size(); ++c)
		s[c] = toupper(s[c]);//将字符串s转换成大写字母
	cout << s << endl;

	//使用while语句遍历string（遇到字符串结尾标志或者遇到空格符则结束循环）
	s = orig;  //重置s为原来的字符串orig
	string::size_type index = 0;
	while (index != s.size() && !isspace(s[index])) 
	{
		s[index] = toupper(s[index]);//将字符串s转换成大写字母
		++index;
	}
	cout << s << endl;

	system("pause");
	return 0;
}