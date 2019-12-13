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

#include <memory>
using std::allocator;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout; using std::endl;

#include <fstream>
using std::ifstream;

int main()
{
	//四个步骤：
	//1.分配内存
	const size_t n = 100;
	allocator<string> alloc;      //能够分配string对象的allocator类对象alloc
	string *p = alloc.allocate(n);   //分配n个未初始化的string，返回首指针到p中
	string *q = p; //指针q指向最后一个被构造的元素，即p

	//2.构造对象
	//C++11之前的分配器构造必须显式传递一个已分配类型的对象，因此，我们显式传递一个空的string（）
	alloc.construct(q++, string()); // *q为空字符串
	cout << "对象q1：" << *(q - 1) << endl;

	alloc.construct(q++, string(10, 'c')); // *q为cccccccccc
	cout << "对象q2：" << *(q - 1) << endl;

	alloc.construct(q++, string("hi"));    // *q为hi
	cout << "对象q3：" << *(q - 1) << endl;

	//销毁对象
	cout << "对象p：" << *p << endl; 
	while (q != p)
		alloc.destroy(--q);  // 释放我们实际分配的字符串

	//4.释放内存
	alloc.deallocate(p, n);  // 返回我们分配的内存


	p = alloc.allocate(n);   // 分配n个未初始化的string
	string s;
	q = p;                   // 指针q指向第一个string
	ifstream in("abc.txt");
	while (in >> s && q != p + n)
		alloc.construct(q++, s); // 只构造从in输入的字符串
	size_t size = q - p;         // 计算读取的string数量
	cout << "read " << size << " strings" << endl;
	for (q = p + size - 1; q != p; --q)
		alloc.destroy(q);         // 释放我们实际分配的字符串
	alloc.deallocate(p, n);       // 返回我们分配的内存
	in.close();


	in.open("abc.txt");
	p = new string[n];            // 初始化n个空字符串
	q = p;                        // 指针q指向第一个string
	while (in >> s && q != p + n)
		*q++ = s;                 // 向指针q指向的内存赋一个新的值
	size = q - p;                 // 计算读取的string数量
	cout << "read " << size << " strings" << endl;
	delete[] p;  // 记得要使用delete []来释放内存

	system("pause");
	return 0;
}