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

//ǰ����������Blob��������Ԫ����ѽ��
template <typename> class BlobPtr;
template <typename> class Blob; //�����==�е���������Ҫ��
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T> (const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	//���캯��
	Blob();
	template <typename It> Blob(It b, It e);
	Blob(T*, std::size_t);

	//���ص�һ�������һ����Ԫ��
	BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	BlobPtr<T> end()
	{
		BlobPtr<T> ret = BlobPtr<T>(*this, data->size());
		return ret;
	}

	//Blob�е�Ԫ����Ŀ
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	//���Ӻ�ɾ��Ԫ��
	void push_back(const T &t) { data->push_back(t); }
	void pop_back();

	//Ԫ�ط���
	T& front();
	T& back();
	T& at(size_type);
	const T& back() const;
	const T& front() const;
	const T& at(size_type) const;
	T& operator[](size_type i);
	const T& operator[](size_type i) const;

	//Blob���Ͷ��󽻻�
	void swap(Blob &b) { data.swap(b.data); }
private:
	std::shared_ptr<std::vector<T> > data;
	void check(size_type i, const std::string &msg) const;
};

//���캯��
template <typename T>
Blob<T>::Blob(T *p, std::size_t n) :data(new std::vector<T>(p, p + n)) { }

template <typename T>
Blob<T>::Blob() :data(new std::vector<T>()) { }

template <typename T>   
template <typename It>  
Blob<T>::Blob(It b, It e) :data(new std::vector<T>(b, e)) { }

//����������ݵĺ�����
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

//Ԫ�ط��ʳ�Ա����
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
//������const��Ԫ�ط��ʳ�Ա����
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
	// ���i̫�󣬽����׳���飬�Ӷ���ֹ���ʲ����ڵ�Ԫ��
	check(i, "subscript out of range");
	return (*data)[i];  //(*data)�Ǵ˶���ָ�������
}
//����const�͵�at����
template <typename T>
const T& Blob<T>::at(size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	// ���i̫�󣬽����׳���飬�Ӷ���ֹ���ʲ����ڵ�Ԫ��
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

//���������
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

// ���BlobPtr���ʲ����ڵ�Ԫ��ʱ���������쳣
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
		return (*p)[i];  //(*p)�Ǵ˶���ָ���vector
	}

	const T &operator[](std::size_t i) const
	{
		std::shared_ptr<std::vector<T> > p =
			check(i, "subscript out of range");
		return (*p)[i];  //(*p)�Ǵ˶���ָ���vector
	}

	T& operator*() const
	{
		std::shared_ptr<std::vector<T> > p = check(curr, "dereference past end");
		return (*p)[curr];  //(*p)�Ǵ˶���ָ���vector
	}
	T* operator->() const
	{ // delegate the real work to the dereference operator��������
		return &this->operator*();
	}

	// ++�������--�����
	BlobPtr& operator++();       // ����++
	BlobPtr& operator--();

	BlobPtr operator++(int);     // ǰ��++
	BlobPtr operator--(int);

private:
	// ������ɹ�������鷵��һ��shared_ptr��vector
	std::shared_ptr<std::vector<T> > check(std::size_t, const std::string&) const;
	//����һ��weak_ptr����ζ�ŵײ�vector���ܱ�����
	std::weak_ptr<std::vector<T> > wptr;
	std::size_t curr;//�����еĵ�ǰλ��
};

//==�����
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
		wptr.lock();   //�Ƿ񻹴���vector��
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret; //����ָ��vector������ָ��shared_ptr
}

//�����������Ա����
//��׺������/���ٶ��󣬵����ز����ֵ
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	//���ﲻ��Ҫcheck������ǰ׺++�����м��
	BlobPtr ret = *this;   //���浱ǰֵ
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