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

#ifndef FOO_H
#define FOO_H

#include <iostream>

typedef int T;//为int定义别名T
struct Foo {  //使用struct定义一个类Foo
	Foo(T t) : val(t) { }//Foo类的构造函数，使用传进来的T类型的数据对数据成员val进行初始化（使用了类的初始化列表）
	T val;
};

std::ostream&
print(std::ostream &os, const Foo &f)//定义一个print函数，返回类型是一个ostream类，参数类型是标准输出流、Foo类的引用
{
	os << f.val;
	return os;
}

#endif