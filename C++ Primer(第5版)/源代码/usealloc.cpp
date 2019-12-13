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

#include <string>
using std::string;

#include <memory>
using std::allocator;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout; using std::endl;

#include <fstream>
using std::ifstream;

int main()
{
	//�ĸ����裺
	//1.�����ڴ�
	const size_t n = 100;
	allocator<string> alloc;      //�ܹ�����string�����allocator�����alloc
	string *p = alloc.allocate(n);   //����n��δ��ʼ����string��������ָ�뵽p��
	string *q = p; //ָ��qָ�����һ���������Ԫ�أ���p

	//2.�������
	//C++11֮ǰ�ķ��������������ʽ����һ���ѷ������͵Ķ�����ˣ�������ʽ����һ���յ�string����
	alloc.construct(q++, string()); // *qΪ���ַ���
	cout << "����q1��" << *(q - 1) << endl;

	alloc.construct(q++, string(10, 'c')); // *qΪcccccccccc
	cout << "����q2��" << *(q - 1) << endl;

	alloc.construct(q++, string("hi"));    // *qΪhi
	cout << "����q3��" << *(q - 1) << endl;

	//���ٶ���
	cout << "����p��" << *p << endl; 
	while (q != p)
		alloc.destroy(--q);  // �ͷ�����ʵ�ʷ�����ַ���

	//4.�ͷ��ڴ�
	alloc.deallocate(p, n);  // �������Ƿ�����ڴ�


	p = alloc.allocate(n);   // ����n��δ��ʼ����string
	string s;
	q = p;                   // ָ��qָ���һ��string
	ifstream in("abc.txt");
	while (in >> s && q != p + n)
		alloc.construct(q++, s); // ֻ�����in������ַ���
	size_t size = q - p;         // �����ȡ��string����
	cout << "read " << size << " strings" << endl;
	for (q = p + size - 1; q != p; --q)
		alloc.destroy(q);         // �ͷ�����ʵ�ʷ�����ַ���
	alloc.deallocate(p, n);       // �������Ƿ�����ڴ�
	in.close();


	in.open("abc.txt");
	p = new string[n];            // ��ʼ��n�����ַ���
	q = p;                        // ָ��qָ���һ��string
	while (in >> s && q != p + n)
		*q++ = s;                 // ��ָ��qָ����ڴ渳һ���µ�ֵ
	size = q - p;                 // �����ȡ��string����
	cout << "read " << size << " strings" << endl;
	delete[] p;  // �ǵ�Ҫʹ��delete []���ͷ��ڴ�

	system("pause");
	return 0;
}