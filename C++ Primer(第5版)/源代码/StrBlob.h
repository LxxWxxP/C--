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
 * reproduced. Any commercial use of this code requires the explicit written
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

#ifndef STRBLOB_H
#define STRBLOB_H
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>


class StrBlobPtr;//由于StrBlobPtr类是StrBlob的友元类，所以这里要提前声明StrBlobPtr类

class StrBlob {
	friend class StrBlobPtr;//声明StrBlobPtr类是StrBlob的友元类
public:
	typedef std::vector<std::string>::size_type size_type;//为命名空间std中的vector<string>::size_type类型声明别名为size_type

	//构造函数
	StrBlob() : data(new std::vector<std::string>()) { }//默认构造函数
	StrBlob(const std::string*, const std::string*);//含参数的构造函数

	size_type size() const { return data->size(); }//返回StrBlob类中数据成员data的大小
	bool empty() const { return data->empty(); }//判断data是否为空

	void push_back(const std::string &t) { data->push_back(t); }//增加元素
	void pop_back();//删除元素

	// 元素存取
	std::string& front();
	std::string& back();

	//StrBlobPtr类的接口，用于遍历类中的元素
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string> > data;//数据成员data
	void check(size_type i, const std::string &msg) const;//如果data为空，抛出异常信息msg
};

//定义含参数的构造函数
inline//inline关键字用于表示内置成员函数，使用此关键字可以在类外定义成员函数，否则，也可以在雷替里面用inline声明
StrBlob::StrBlob(const std::string *beg, const std::string *end) :
	data(new std::vector<std::string>(beg, end)) { }//使用两个string参数beg、end初始化数据成员data（即vector容器data里面是指针beg，end之间的数据）


class StrBlobPtr {
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);//声明友元函数
public:
	StrBlobPtr() : curr(0) { }//默认构造函数
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }//含参数的构造函数，可以传入两个或者一个参数，如果不传入第二个参数，则curr默认为零

	//成员函数声明如下：
	std::string& deref() const;
	StrBlobPtr& incr();     // prefix version？
	StrBlobPtr& decr();     // prefix version？
private:
	std::shared_ptr<std::vector<std::string> > check(std::size_t, const std::string&) const;//私有成员函数check：若size_t=0，则抛出参数string所传进来的异常信息；否则，返回shared_ptr指针
	std::weak_ptr<std::vector<std::string> > wptr;//数据成员wptr，weak_ptr类型（是一个伴随类，是一种弱引用，指向shared_ptr多管理的对象）
	std::size_t curr;//数据成员curr，size_t类型（无符号整型）
};

inline
std::string& StrBlobPtr::deref() const//常成员函数：只能引用本类中的数据成员，而不能修改他们
{
	std::shared_ptr<std::vector<std::string> >
		p = check(curr, "dereference past end");
	return (*p)[curr];  //返回vector的第curr个string对象
}

inline
std::shared_ptr<std::vector<std::string> >
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	//判断wptr的生命周期还在吗，若在，返回到ret里面
	std::shared_ptr<std::vector<std::string> > ret = wptr.lock();//weak_ptr的成员函数lock():生命期未结束，则返回一个shared_ptr，指向同样的对象。否则返回一个指向null的shared_ptr

	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");

	if (i >= ret->size())
		throw std::out_of_range(msg);

	return ret; //返回ret
}

//Prefix: 返回对递增对象的引用
inline
StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");//如果不存在指向该对象的智能指针，抛出异常信息increment past end of StrBlobPtr
	++curr;//递增curr
	return *this;//返回vector的下一个元素
}

inline
StrBlobPtr& StrBlobPtr::decr()
{
	--curr;//递减curr
	check(-1, "decrement past begin of StrBlobPtr");
	return *this;//返回vector的上一个元素
}

inline
StrBlobPtr
StrBlob::begin()//StrBlob的对象的第一个元素
{
	return StrBlobPtr(*this);
}

inline
StrBlobPtr
StrBlob::end()//StrBlob的对象的最后一个元素
{
	StrBlobPtr ret = StrBlobPtr(*this, data->size());
	return ret;
}

//对比两个StrBlobPtr是否相等
inline
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	std::shared_ptr<std::vector<std::string> >
		l = lhs.wptr.lock(), r = rhs.wptr.lock();

	if (l == r)
		return (!r || lhs.curr == rhs.curr);//如果两个StrBlobPtr相等，要么都为空，要么指向相同的内存地址
	else
		return false; //如果他们指向不同的vector容器，返回false
}

//对比两个StrBlobPtr是否不等
inline
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}
#endif