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

#include <iostream>
#include <memory>
using namespace std;
using std::shared_ptr;
using std::unique_ptr;

void deleter(int *p) { delete[] p; }//删除器

int main()
{
	 //在pre-c++11库中不支持unique_ptr
	unique_ptr<int[]> up(new int[10]);
	for (size_t i = 0; i != 10; ++i)
	{
		up[i] = i;
		cout << up[i] << endl;
	}
	up.release();   //自动使用delete[]来销毁它的指针
	cout << endl;

	// 要使用shared_ptr我们必须提供一个删除器
	shared_ptr<int> sp(new int[10], deleter);//定义一个共享智能指针，指向一个含10个int型数据的数组，并且指定销毁时使用的删除器
	// shared_ptr没有下标操作符
	// 也不支持指针运算
	for (size_t i = 0; i != 10; ++i)
	{
		*(sp.get() + i) = i;  //用get函数来取得共享智能指针的地址
		cout << *(sp.get()+i) << endl;
	}
	sp.reset();//这里使用我们定义的删除器函数来销毁int数组对象
	system("pause");
	return 0;
}
