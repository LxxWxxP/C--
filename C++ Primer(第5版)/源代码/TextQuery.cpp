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

#include "TextQuery.h"
#include "make_plural.h"

#include <cstddef>
#include <memory>  
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>

using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;

//因为我们不能使用auto关键字，所以我们将使用typedef来定义别名简化我们的代码

//TextQuery对象中查找映射的类型wmType
typedef map<string, shared_ptr<set<TextQuery::line_no> > > wmType;

//wmType的迭代器wmIter
typedef wmType::const_iterator wmIter;

//包含行号的集合的共享智能指针类型lineType
typedef shared_ptr<set<TextQuery::line_no> > lineType;

//set<TextQuery::line_no>的迭代器lineIter
typedef set<TextQuery::line_no>::const_iterator lineIter;

//读取输入文件并建立单词到行号的映射
TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while (getline(is, text)) {       //文件中的每一行读取到text中
		file->push_back(text);        //保存此文本到共享智能指针file指向的内存中
		int n = file->size() - 1;     //当前行号
		istringstream line(text);     //将行文本分解成单个单词
		string word;
		while (line >> word) {        //行中的每个单词逐个输入到word中
			word = cleanup_str(word);
			//如果单词不在wm中，以之为下标在wm中添加一项
			lineType &lines = wm[word]; //lines是一个shared_ptr 
			if (!lines) //第一次遇到这个单词时，此指针为空
				lines.reset(new set<line_no>); //分配一个新的set
			lines->insert(n);      //将此行号插入到set中
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	//如果未找到sought，返回一个执行此set的指针
	static lineType nodata(new set<line_no>);

	//使用find而不是下标运算符来查找单词，避免将单词添加到wm中
	wmIter loc = wm.find(cleanup_str(sought));

	if (loc == wm.end())
		return QueryResult(sought, nodata, file);  //未找到
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
	//如果找到了单词，打印出现次数和所有出现的位置
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;

	//打印单词出现的每一行
	for (lineIter num = qr.lines->begin(); num != qr.lines->end(); ++num)
		//避免行号从0开始给用户带困惑
		os << "\t(line " << *num + 1 << ") " << *(qr.file->begin() + *num) << endl;
	return os;
}

//本书未涵盖cleanup_str：删除标点符号并将所有文本转换为小写，以便查询以不区分大小写的方式运行
string TextQuery::cleanup_str(const string &word)
{
	string ret;
	for (string::const_iterator it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

//调试例程，将打印查找映射的内容
void TextQuery::display_map()
{
	wmIter iter = wm.begin(), iter_end = wm.end();

	//遍历整个map
	for (; iter != iter_end; ++iter) 
	{
		cout << "word: " << iter->first << " {";

		//提取位置向量作为const引用，以防止对它进行了修改（事实上并没有使用const？这里标注出错了？）
		lineType text_locs = iter->second;
		lineIter loc_iter = text_locs->begin(),	loc_iter_end = text_locs->end();

		//打印该单词的所有行号
		while (loc_iter != loc_iter_end)
		{
			cout << *loc_iter;
			if (++loc_iter != loc_iter_end)
				cout << ", ";
		}
		cout << "}\n";  // end list of output this word
	}
	cout << endl;  //完成对整个map的输出
}
