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

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::istream; using std::ostream;
using std::cin; using std::cout; using std::endl;

#include "Foo.h"

//定义一个函数：传入一个T类型数据，返回一个Foo类对象指针
Foo* factory(T arg)
{
	return new Foo(arg); //返回一个新的Foo类对象
}

Foo* use_factory(T arg)
{
	Foo *p = factory(arg);//调用factory函数
	print(cout, *p);//输出p指针指向的对象的值
	cout << endl;
	return p;  //返回p指针
}
//动态内存实现
int main()
{
	T arg;
	while (cin >> arg) //当遇到不符合cin条件的时候结束循环（比如输入非T类型的数据）
	{
		Foo *p = use_factory(arg);
		delete p; //使用完指针之后记得删除指针
	}
	system("pause");
	return 0;
}