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


class StrBlobPtr;//����StrBlobPtr����StrBlob����Ԫ�࣬��������Ҫ��ǰ����StrBlobPtr��

class StrBlob {
	friend class StrBlobPtr;//����StrBlobPtr����StrBlob����Ԫ��
public:
	typedef std::vector<std::string>::size_type size_type;//Ϊ�����ռ�std�е�vector<string>::size_type������������Ϊsize_type

	//���캯��
	StrBlob() : data(new std::vector<std::string>()) { }//Ĭ�Ϲ��캯��
	StrBlob(const std::string*, const std::string*);//�������Ĺ��캯��

	size_type size() const { return data->size(); }//����StrBlob�������ݳ�Աdata�Ĵ�С
	bool empty() const { return data->empty(); }//�ж�data�Ƿ�Ϊ��

	void push_back(const std::string &t) { data->push_back(t); }//����Ԫ��
	void pop_back();//ɾ��Ԫ��

	// Ԫ�ش�ȡ
	std::string& front();
	std::string& back();

	//StrBlobPtr��Ľӿڣ����ڱ������е�Ԫ��
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string> > data;//���ݳ�Աdata
	void check(size_type i, const std::string &msg) const;//���dataΪ�գ��׳��쳣��Ϣmsg
};

//���庬�����Ĺ��캯��
inline//inline�ؼ������ڱ�ʾ���ó�Ա������ʹ�ô˹ؼ��ֿ��������ⶨ���Ա����������Ҳ����������������inline����
StrBlob::StrBlob(const std::string *beg, const std::string *end) :
	data(new std::vector<std::string>(beg, end)) { }//ʹ������string����beg��end��ʼ�����ݳ�Աdata����vector����data������ָ��beg��end֮������ݣ�


class StrBlobPtr {
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);//������Ԫ����
public:
	StrBlobPtr() : curr(0) { }//Ĭ�Ϲ��캯��
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }//�������Ĺ��캯�������Դ�����������һ�����������������ڶ�����������currĬ��Ϊ��

	//��Ա�����������£�
	std::string& deref() const;
	StrBlobPtr& incr();     // prefix version��
	StrBlobPtr& decr();     // prefix version��
private:
	std::shared_ptr<std::vector<std::string> > check(std::size_t, const std::string&) const;//˽�г�Ա����check����size_t=0�����׳�����string�����������쳣��Ϣ�����򣬷���shared_ptrָ��
	std::weak_ptr<std::vector<std::string> > wptr;//���ݳ�Աwptr��weak_ptr���ͣ���һ�������࣬��һ�������ã�ָ��shared_ptr�����Ķ���
	std::size_t curr;//���ݳ�Աcurr��size_t���ͣ��޷������ͣ�
};

inline
std::string& StrBlobPtr::deref() const//����Ա������ֻ�����ñ����е����ݳ�Ա���������޸�����
{
	std::shared_ptr<std::vector<std::string> >
		p = check(curr, "dereference past end");
	return (*p)[curr];  //����vector�ĵ�curr��string����
}

inline
std::shared_ptr<std::vector<std::string> >
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	//�ж�wptr���������ڻ��������ڣ����ص�ret����
	std::shared_ptr<std::vector<std::string> > ret = wptr.lock();//weak_ptr�ĳ�Ա����lock():������δ�������򷵻�һ��shared_ptr��ָ��ͬ���Ķ��󡣷��򷵻�һ��ָ��null��shared_ptr

	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");

	if (i >= ret->size())
		throw std::out_of_range(msg);

	return ret; //����ret
}

//Prefix: ���ضԵ������������
inline
StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");//���������ָ��ö��������ָ�룬�׳��쳣��Ϣincrement past end of StrBlobPtr
	++curr;//����curr
	return *this;//����vector����һ��Ԫ��
}

inline
StrBlobPtr& StrBlobPtr::decr()
{
	--curr;//�ݼ�curr
	check(-1, "decrement past begin of StrBlobPtr");
	return *this;//����vector����һ��Ԫ��
}

inline
StrBlobPtr
StrBlob::begin()//StrBlob�Ķ���ĵ�һ��Ԫ��
{
	return StrBlobPtr(*this);
}

inline
StrBlobPtr
StrBlob::end()//StrBlob�Ķ�������һ��Ԫ��
{
	StrBlobPtr ret = StrBlobPtr(*this, data->size());
	return ret;
}

//�Ա�����StrBlobPtr�Ƿ����
inline
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	std::shared_ptr<std::vector<std::string> >
		l = lhs.wptr.lock(), r = rhs.wptr.lock();

	if (l == r)
		return (!r || lhs.curr == rhs.curr);//�������StrBlobPtr��ȣ�Ҫô��Ϊ�գ�Ҫôָ����ͬ���ڴ��ַ
	else
		return false; //�������ָ��ͬ��vector����������false
}

//�Ա�����StrBlobPtr�Ƿ񲻵�
inline
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}
#endif