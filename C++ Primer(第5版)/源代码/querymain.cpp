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

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cin; using std::cout; using std::cerr;
using std::endl;

#include <cstdlib>  // EXIT_FAILURE 的头文件

#include "TextQuery.h"
#include "make_plural.h"

void runQueries(ifstream &infile)
{
	//infile是一个ifstream，它是我们要查询的文件
	TextQuery tq(infile);  // 存储文件并创建map
	//与用户进行交互：提示输入单词以查找并打印结果
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		//如果检测到文件结尾标识符或输入了“ q”，则停止
		if (!(cin >> s) || s == "q") break;
		//运行查询并打印结果
		print(cout, tq.query(s)) << endl;
	}
}

//程序采用单个参数指定要查询的文件
int main(int argc, char **argv)
{
	//打开用户要查询单词的文件
	ifstream infile("query.txt");
	//open返回void，因此我们使用逗号运算符XREF（commaOp）在打开后检查infile的状态（未看懂）
	/*if (argc < 2 || !(infile.open(argv[1]), infile)) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}*/
	runQueries(infile);
	system("pause");
	return 0;
}