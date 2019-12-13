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

#ifndef QUOTE_H
#define QUOTE_H
#include <memory>
#include <iostream>
#include <string>
#include <cstddef>

//以原价售出的商品
//派生类将定义各种折扣策略
class Quote {
	//定义两个友元函数：重载流插入运算符和流提取运算符
	//用户自己定义的类型的数据，是不能直接用"<<"">>"进行输入输出的，若想用，必须重载
	//不能定义为成员函数，因为若为成员函数，则第一个参数必须有该类的对象，而这里只能是istream或者ostream
	friend std::istream& operator>>(std::istream&, Quote&);         
	friend std::ostream& operator<<(std::ostream&, const Quote&);   
public:
	Quote() : price(0.0) { }//默认构造函数
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) { }//含参数的构造函数

	//如果删除了指向派生对象的基本指针，则需要虚析构函数
	virtual ~Quote() { } //析构函数的动态绑定

	std::string isbn() const { return bookNo; }//返回书的ISBN号

	//返回指定数量的商品的总销售价格派生类将覆盖并应用不同的折扣算法
	//派生类将覆盖并应用不同的折扣算法
	virtual double net_price(std::size_t n) const
	{
		return n * price;
	}

	//虚函数返回自身的动态分配副本
	virtual Quote* clone() const { return new Quote(*this); }
private:
	std::string bookNo; //书的ISBN号
protected:
	double price;       //原价
};

//抽象基类：用于保存折现率和数量
//派生类将使用这些数据实施定价策略
class Disc_quote : public Quote {
public:
	Disc_quote() : quantity(0), discount(0.0) { }//默认构造函数
	Disc_quote(const std::string& book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) { }//含参数的构造函数

	double net_price(std::size_t) const = 0;//？

	std::pair<size_t, double> discount_policy() const
	{
		return std::make_pair(quantity, discount);
	}
protected:
	std::size_t quantity; //数量
	double discount;      //折扣
};

//当售出指定数量的同一本书时，折扣就会生效
//折扣表示为降低正常价格所用的分数
class Bulk_quote : public Disc_quote { // Bulk_quote继承自Disc_quote
public:
	Bulk_quote() { }//默认构造函数
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc) { }//含参数的构造函数

	//重载基类成员函数，以实施批量购买折扣政策
	double net_price(std::size_t) const;
	//复制以生成副本
	Bulk_quote* clone() const { return new Bulk_quote(*this); }
};

//仅指定数量的副本享有折扣（折扣价的一部分）
//以标准价格出售的其他副本
class Lim_quote : public Disc_quote {
public:
	Lim_quote(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0) :Disc_quote(book, sales_price, qty, disc_rate) { }//含参数的构造函数

	//重载基类成员函数，以实施有限的折扣政策
	double net_price(std::size_t) const;
	//复制以生成副本
	Lim_quote* clone() const { return new Lim_quote(*this); }
};

double print_total(std::ostream &, const Quote&, std::size_t);

#endif