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

//��ԭ���۳�����Ʒ
//�����ཫ��������ۿ۲���
class Quote {
	//����������Ԫ���������������������������ȡ�����
	//�û��Լ���������͵����ݣ��ǲ���ֱ����"<<"">>"������������ģ������ã���������
	//���ܶ���Ϊ��Ա��������Ϊ��Ϊ��Ա���������һ�����������и���Ķ��󣬶�����ֻ����istream����ostream
	friend std::istream& operator>>(std::istream&, Quote&);         
	friend std::ostream& operator<<(std::ostream&, const Quote&);   
public:
	Quote() : price(0.0) { }//Ĭ�Ϲ��캯��
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) { }//�������Ĺ��캯��

	//���ɾ����ָ����������Ļ���ָ�룬����Ҫ����������
	virtual ~Quote() { } //���������Ķ�̬��

	std::string isbn() const { return bookNo; }//�������ISBN��

	//����ָ����������Ʒ�������ۼ۸������ཫ���ǲ�Ӧ�ò�ͬ���ۿ��㷨
	//�����ཫ���ǲ�Ӧ�ò�ͬ���ۿ��㷨
	virtual double net_price(std::size_t n) const
	{
		return n * price;
	}

	//�麯����������Ķ�̬���丱��
	virtual Quote* clone() const { return new Quote(*this); }
private:
	std::string bookNo; //���ISBN��
protected:
	double price;       //ԭ��
};

//������ࣺ���ڱ��������ʺ�����
//�����ཫʹ����Щ����ʵʩ���۲���
class Disc_quote : public Quote {
public:
	Disc_quote() : quantity(0), discount(0.0) { }//Ĭ�Ϲ��캯��
	Disc_quote(const std::string& book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) { }//�������Ĺ��캯��

	double net_price(std::size_t) const = 0;//��

	std::pair<size_t, double> discount_policy() const
	{
		return std::make_pair(quantity, discount);
	}
protected:
	std::size_t quantity; //����
	double discount;      //�ۿ�
};

//���۳�ָ��������ͬһ����ʱ���ۿ۾ͻ���Ч
//�ۿ۱�ʾΪ���������۸����õķ���
class Bulk_quote : public Disc_quote { // Bulk_quote�̳���Disc_quote
public:
	Bulk_quote() { }//Ĭ�Ϲ��캯��
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc) { }//�������Ĺ��캯��

	//���ػ����Ա��������ʵʩ���������ۿ�����
	double net_price(std::size_t) const;
	//���������ɸ���
	Bulk_quote* clone() const { return new Bulk_quote(*this); }
};

//��ָ�������ĸ��������ۿۣ��ۿۼ۵�һ���֣�
//�Ա�׼�۸���۵���������
class Lim_quote : public Disc_quote {
public:
	Lim_quote(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0) :Disc_quote(book, sales_price, qty, disc_rate) { }//�������Ĺ��캯��

	//���ػ����Ա��������ʵʩ���޵��ۿ�����
	double net_price(std::size_t) const;
	//���������ɸ���
	Lim_quote* clone() const { return new Lim_quote(*this); }
};

double print_total(std::ostream &, const Quote&, std::size_t);

#endif