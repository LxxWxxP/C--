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

#include "Quote.h"
#include "Basket.h"
#include <cstddef>
using std::size_t;
#include <set>
using std::multiset;
#include <string>
using std::string;
#include <iostream>
using std::ostream; using std::endl;
using std::cout;
#include <memory>
using std::shared_ptr;

//显示Basket里面的内容
void Basket::display(ostream &os) const
{
	os << "Basket size: " << items.size() << endl;

	// 在购物篮中打印每个不同的ISBN以及
	// 订购的数量及其价格将是多少
	// upper_bound将迭代器返回到集合中的下一个元素
	for (auto next_item = items.begin(); next_item != items.end(); next_item = items.upper_bound(*next_item))
	{
		// 购物篮中至少有一个与此键相关的元素
		os << (*next_item)->isbn() << " occurs "               //IBSN
			<< items.count(*next_item) << " times"             //数量
			<< " for a price of "                        
			<< (*next_item)->net_price(items.count(*next_item))//价格
			<< endl;
	}
}

double Basket::total_receipt(ostream &os) const
{
	double sum = 0.0;    //总价
	// iter指向的是一批具有相同ISBN的元素中的第一个元素
	// upper_bound返回一个迭代器，该元素刚好在该批处理结束之后
	for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)) {
		// 购物篮中至少有一个与此键相关的元素
		// 打印这本书的订单项
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl; //打印最终的总价
	return sum;
}
