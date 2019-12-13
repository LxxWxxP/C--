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
 * reproduced. Any commercial use of this code requires the explicit written
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
#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include "StrBlob.h"

int main()
{
	StrBlob b1;
	{
		string temp[] = { "a", "an", "the" };
		StrBlob b2(temp, temp + sizeof(temp) / sizeof(*temp));//sing以一个StrBlob对象，并且用在区间[temp,temp+sizeof(temp)/sizeof(*temp)]的数据来初始化
		b1 = b2;//b1指向b2所指向的内容（两者指向了同一个vector容器）
		b2.push_back("about");//在智能指针b2指向的vector末尾添加元素"about"
		cout << b2.size() << endl;//输出b2指向的vector大小
	}//在这之后b2已经被销毁，因为b2在大括号里面声明的
	cout << b1.size() << endl;//这里b1的size和b2的size一样

	for (StrBlobPtr it = b1.begin(); neq(it, b1.end()); it.incr())//遍历b1对象
		cout << it.deref() << endl;//返回当前指向的元素
	system("pause");
	return 0;
}