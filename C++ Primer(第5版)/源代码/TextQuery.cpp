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

//��Ϊ���ǲ���ʹ��auto�ؼ��֣��������ǽ�ʹ��typedef��������������ǵĴ���

//TextQuery�����в���ӳ�������wmType
typedef map<string, shared_ptr<set<TextQuery::line_no> > > wmType;

//wmType�ĵ�����wmIter
typedef wmType::const_iterator wmIter;

//�����кŵļ��ϵĹ�������ָ������lineType
typedef shared_ptr<set<TextQuery::line_no> > lineType;

//set<TextQuery::line_no>�ĵ�����lineIter
typedef set<TextQuery::line_no>::const_iterator lineIter;

//��ȡ�����ļ����������ʵ��кŵ�ӳ��
TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while (getline(is, text)) {       //�ļ��е�ÿһ�ж�ȡ��text��
		file->push_back(text);        //������ı�����������ָ��fileָ����ڴ���
		int n = file->size() - 1;     //��ǰ�к�
		istringstream line(text);     //�����ı��ֽ�ɵ�������
		string word;
		while (line >> word) {        //���е�ÿ������������뵽word��
			word = cleanup_str(word);
			//������ʲ���wm�У���֮Ϊ�±���wm�����һ��
			lineType &lines = wm[word]; //lines��һ��shared_ptr 
			if (!lines) //��һ�������������ʱ����ָ��Ϊ��
				lines.reset(new set<line_no>); //����һ���µ�set
			lines->insert(n);      //�����кŲ��뵽set��
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	//���δ�ҵ�sought������һ��ִ�д�set��ָ��
	static lineType nodata(new set<line_no>);

	//ʹ��find�������±�����������ҵ��ʣ����⽫������ӵ�wm��
	wmIter loc = wm.find(cleanup_str(sought));

	if (loc == wm.end())
		return QueryResult(sought, nodata, file);  //δ�ҵ�
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
	//����ҵ��˵��ʣ���ӡ���ִ��������г��ֵ�λ��
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;

	//��ӡ���ʳ��ֵ�ÿһ��
	for (lineIter num = qr.lines->begin(); num != qr.lines->end(); ++num)
		//�����кŴ�0��ʼ���û�������
		os << "\t(line " << *num + 1 << ") " << *(qr.file->begin() + *num) << endl;
	return os;
}

//����δ����cleanup_str��ɾ�������Ų��������ı�ת��ΪСд���Ա��ѯ�Բ����ִ�Сд�ķ�ʽ����
string TextQuery::cleanup_str(const string &word)
{
	string ret;
	for (string::const_iterator it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

//�������̣�����ӡ����ӳ�������
void TextQuery::display_map()
{
	wmIter iter = wm.begin(), iter_end = wm.end();

	//��������map
	for (; iter != iter_end; ++iter) 
	{
		cout << "word: " << iter->first << " {";

		//��ȡλ��������Ϊconst���ã��Է�ֹ�����������޸ģ���ʵ�ϲ�û��ʹ��const�������ע�����ˣ���
		lineType text_locs = iter->second;
		lineIter loc_iter = text_locs->begin(),	loc_iter_end = text_locs->end();

		//��ӡ�õ��ʵ������к�
		while (loc_iter != loc_iter_end)
		{
			cout << *loc_iter;
			if (++loc_iter != loc_iter_end)
				cout << ", ";
		}
		cout << "}\n";  // end list of output this word
	}
	cout << endl;  //��ɶ�����map�����
}
