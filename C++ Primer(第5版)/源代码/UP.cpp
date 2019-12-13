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

#include <iostream>
#include <memory>
using namespace std;
using std::shared_ptr;
using std::unique_ptr;

void deleter(int *p) { delete[] p; }//ɾ����

int main()
{
	 //��pre-c++11���в�֧��unique_ptr
	unique_ptr<int[]> up(new int[10]);
	for (size_t i = 0; i != 10; ++i)
	{
		up[i] = i;
		cout << up[i] << endl;
	}
	up.release();   //�Զ�ʹ��delete[]����������ָ��
	cout << endl;

	// Ҫʹ��shared_ptr���Ǳ����ṩһ��ɾ����
	shared_ptr<int> sp(new int[10], deleter);//����һ����������ָ�룬ָ��һ����10��int�����ݵ����飬����ָ������ʱʹ�õ�ɾ����
	// shared_ptrû���±������
	// Ҳ��֧��ָ������
	for (size_t i = 0; i != 10; ++i)
	{
		*(sp.get() + i) = i;  //��get������ȡ�ù�������ָ��ĵ�ַ
		cout << *(sp.get()+i) << endl;
	}
	sp.reset();//����ʹ�����Ƕ����ɾ��������������int�������
	system("pause");
	return 0;
}
