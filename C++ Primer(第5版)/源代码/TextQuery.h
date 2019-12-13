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

#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "QueryResult.h"

class QueryResult; //为了定义函数query的返回类型，这里必须提前声明QueryResult类
class TextQuery {
public:
	typedef std::vector<std::string>::size_type line_no;//为std::vector<std::string>::size_type声明别名line_no
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
	void display_map();//调试例程，将打印查找映射的内容
private:
	std::shared_ptr<std::vector<std::string> > file; //输入文件
	std::map<std::string, std::shared_ptr<std::set<line_no> > > wm;	//每个单词到它所在的行号的集合的映射
	static std::string cleanup_str(const std::string&);//规范化文本：删除标点符号并使所有内容变为小写
};
#endif
/* this version of the query classes includes two
 * members not covered in the book:
 *   cleanup_str: which removes punctuation and
 *                converst all text to lowercase
 *   display_map: a debugging routine that will print the contents
 *                of the lookup mape
*/