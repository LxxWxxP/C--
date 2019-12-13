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

#ifndef BLOB_H
#define BLOB_H

#include <iterator>
#include <string>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

//前置声明，在Blob中声明友元所需呀的
template <typename> class BlobPtr;
template <typename> class Blob; //运算符==中的桉树所需要的
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T> (const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	//构造函数
	Blob();
	template <typename It> Blob(It b, It e);
	Blob(T*, std::size_t);

	//返回第一个和最后一个个元素
	BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	BlobPtr<T> end()
	{
		BlobPtr<T> ret = BlobPtr<T>(*this, data->size());
		return ret;
	}

	//Blob中的元素数目
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	//增加和删除元素
	void push_back(const T &t) { data->push_back(t); }
	void pop_back();

	//元素访问
	T& front();
	T& back();
	T& at(size_type);
	const T& back() const;
	const T& front() const;
	const T& at(size_type) const;
	T& operator[](size_type i);
	const T& operator[](size_type i) const;

	//Blob类型对象交换
	void swap(Blob &b) { data.swap(b.data); }
private:
	std::shared_ptr<std::vector<T> > data;
	void check(size_type i, const std::string &msg) const;
};

//构造函数
template <typename T>
Blob<T>::Blob(T *p, std::size_t n) :data(new std::vector<T>(p, p + n)) { }

template <typename T>
Blob<T>::Blob() :data(new std::vector<T>()) { }

template <typename T>   
template <typename It>  
Blob<T>::Blob(It b, It e) :data(new std::vector<T>(b, e)) { }

//检查索引数据的合理性
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

//元素访问成员函数
template <typename T>
T& Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T> void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}
//重载其const型元素访问成员函数
template <typename T>
const T& Blob<T>::front() const
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::at(size_type i)
{
	// 如果i太大，将会抛出检查，从而阻止访问不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];  //(*data)是此对象指向的容器
}
//重载const型的at函数
template <typename T>
const T& Blob<T>::at(size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	// 如果i太大，将会抛出检查，从而阻止访问不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

//运算符重载
template <typename T>
std::ostream& operator<<(std::ostream &os, const Blob<T> a)
{
	os << "< ";
	for (size_t i = 0; i < a.size(); ++i)
		os << a[i] << " ";
	os << " >";
	return os;
}

template <typename T>
bool operator==(const Blob<T> lhs, const Blob<T> rhs)
{
	if (rhs.size() != lhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

// 如果BlobPtr访问不存在的元素时将会引发异常
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> 
class BlobPtr : public std::iterator<std::bidirectional_iterator_tag, T> {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr() : curr(0) { }
	BlobPtr(Blob<T> &a, size_t sz = 0) :wptr(a.data), curr(sz) { }

	T &operator[](std::size_t i)
	{
		std::shared_ptr<std::vector<T> > p =
			check(i, "subscript out of range");
		return (*p)[i];  //(*p)是此对象指向的vector
	}

	const T &operator[](std::size_t i) const
	{
		std::shared_ptr<std::vector<T> > p =
			check(i, "subscript out of range");
		return (*p)[i];  //(*p)是此对象指向的vector
	}

	T& operator*() const
	{
		std::shared_ptr<std::vector<T> > p = check(curr, "dereference past end");
		return (*p)[curr];  //(*p)是此对象指向的vector
	}
	T* operator->() const
	{ // delegate the real work to the dereference operator？不懂。
		return &this->operator*();
	}

	// ++运算符与--运算符
	BlobPtr& operator++();       // 后置++
	BlobPtr& operator--();

	BlobPtr operator++(int);     // 前置++
	BlobPtr operator--(int);

private:
	// 如果检查成功，将检查返回一个shared_ptr到vector
	std::shared_ptr<std::vector<T> > check(std::size_t, const std::string&) const;
	//定义一个weak_ptr，意味着底层vector可能被销毁
	std::weak_ptr<std::vector<T> > wptr;
	std::size_t curr;//数组中的当前位置
};

//==运算符
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.wptr.lock().get() == rhs.wptr.lock().get() &&
		lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}

// check member
template <typename T>
std::shared_ptr<std::vector<T> > BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
	std::shared_ptr<std::vector<T> > ret =
		wptr.lock();   //是否还存在vector？
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret; //返回指向vector的智能指针shared_ptr
}

//重载运算符成员函数
//后缀：增加/减少对象，但返回不变的值
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	//这里不需要check；调用前缀++将进行检查
	BlobPtr ret = *this;   //储存当前值
	++*this;     // advance one element; prefix ++ checks the increment
	return ret;  // return the saved state
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	// no check needed here; the call to prefix decrement will do the check
	BlobPtr ret = *this;  // save the current value
	--*this;     // move backward one element; prefix -- checks the decrement
	return ret;  // return the saved state
}

// prefix: return a reference to the incremented/decremented object
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	// if curr already points past the end of the container, can't increment it
	check(curr, "increment past end of BlobPtr");
	++curr;       // advance the current state
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	// if curr is zero, decrementing it will yield an invalid subscript
	--curr;       // move the current state back one element
	check(-1, "decrement past begin of BlobPtr");
	return *this;
}
#endif