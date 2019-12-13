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

#ifndef BASKET_H
#define BASKET_H
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstddef>
#include <stdexcept>
#include <memory>
#include "Quote.h"

//购物车
class Basket {
public:
	// Basket uses synthesized copy-control members（Basket使用合成的复制控制成员？）
	//因为在C ++ 11之前没有类内初始化程序
	//我们需要定义一个默认的构造函数来初始化项目
	Basket() : items(compare) { }
	void add_item(const std::shared_ptr<Quote> &sale)
	{
		items.insert(sale);
	}

	void add_item(const Quote& sale) //复制给定的对象
	{
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}

	//打印每本书的总价
	//以及购物车中所有书的总和
	double total_receipt(std::ostream&) const;

	//为了debug，打印购物车中的内容
	void display(std::ostream&) const;
private:
	//比较shared_ptrs
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}

	//由比较成员排序
	typedef bool(*Comp)(const std::shared_ptr<Quote> &, const std::shared_ptr<Quote> &);
	std::multiset<std::shared_ptr<Quote>, Comp> items;
};

#endif