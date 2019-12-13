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
using std::string;//引入std命名空间的string类

#include <vector>
using std::vector;//引入std命名空间的vector容器

#include <iostream>
using std::cin; using std::cout; using std::endl;//引入标准输入输出流和换行标识符

int main()
{
	vector<unsigned> grades;//存输入的成绩，数据类型为unsigned(无符号整型)

	// 学生成绩有以下11个数量级: 
	// 0--9, 10--19, . ..  90--99, 100
	//本代码的功能是：计算每个成绩数量级的学生人数
	vector<unsigned> scores(11, 0); //定义一个存unsigned类型数据的vector容器变量scores，初始化11个值为0的数据
	unsigned grade;
	while (cin >> grade) {      //从标准输入流中逐个读取grade，直到遇到输入结束标识符（Ctrl+Z）为止
		if (grade <= 100)       //grades容器只接收有效的成绩数据（小于或等于100）
			grades.push_back(grade);
		++scores[grade / 10]; //该成绩数量级的学生数加一（这里有一个小问题，这样写会导致超过100的成绩也被记录到scores容器里面）
	}
	cout << "grades.size = " << grades.size() << endl;//输出grades容器的容器大小
	for (vector<unsigned>::const_iterator it = grades.begin();
		it != grades.end(); ++it)//使用迭代器循环整个grades容器
		cout << *it << " ";      //iter指向容器中的当前位置的数据，*iter为数据的值
	cout << endl;

	cout << "scores.size = " << scores.size() << endl;//输出scores容器的容器大小
	for (vector<unsigned>::const_iterator it = scores.begin();
		it != scores.end(); ++it)//使用迭代器循环整个scores容器
		cout << *it << " ";      //iter指向容器中的当前位置的数据，*iter为数据的值
	cout << endl;

	vector<unsigned> alt_scores(11, 0);  //再定义一个存unsigned类型数据的vector容器变量alt_scores，初始化11个值为0的数据
	for (vector<unsigned>::const_iterator it = grades.begin();it != grades.end(); ++it) 
	{
		unsigned i = *it;          //将it指向的数据赋值给i变量
		++(*(alt_scores.begin() + i / 10));//该成绩数量级的学生数加一，这里可以这么理解：
		                                   //alt_scores.begin()指向alt_scores容器的第一个数据，
		                                   //i/10为成绩的数量级，alt_scores.begin()往后移i/10个单位恰好为该数量级学生人数存储的位置，
		                                   //将这个指针用小括号括起来加上*号则为该指针指向的数据，
		                                   //这时候再将其括起来使用++运算，则可以累计该成绩数量级的人数了
	}
	cout << "alt_scores.size = " << alt_scores.size() << endl;//输出alt_scores容器的大小
	for (vector<unsigned>::const_iterator it = alt_scores.begin();it != alt_scores.end(); ++it)
		cout << *it << " ";//输出每个成绩数量级的学生人数
	cout << endl;
	system("pause");//Visual Studio 2017需要加上这一句才能将程序停下来让编程人员查看运行结果
	return 0;
}
