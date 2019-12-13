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
using std::string;//����std�����ռ��string��

#include <vector>
using std::vector;//����std�����ռ��vector����

#include <iostream>
using std::cin; using std::cout; using std::endl;//�����׼����������ͻ��б�ʶ��

int main()
{
	vector<unsigned> grades;//������ĳɼ�����������Ϊunsigned(�޷�������)

	// ѧ���ɼ�������11��������: 
	// 0--9, 10--19, . ..  90--99, 100
	//������Ĺ����ǣ�����ÿ���ɼ���������ѧ������
	vector<unsigned> scores(11, 0); //����һ����unsigned�������ݵ�vector��������scores����ʼ��11��ֵΪ0������
	unsigned grade;
	while (cin >> grade) {      //�ӱ�׼�������������ȡgrade��ֱ���������������ʶ����Ctrl+Z��Ϊֹ
		if (grade <= 100)       //grades����ֻ������Ч�ĳɼ����ݣ�С�ڻ����100��
			grades.push_back(grade);
		++scores[grade / 10]; //�óɼ���������ѧ������һ��������һ��С���⣬����д�ᵼ�³���100�ĳɼ�Ҳ����¼��scores�������棩
	}
	cout << "grades.size = " << grades.size() << endl;//���grades������������С
	for (vector<unsigned>::const_iterator it = grades.begin();
		it != grades.end(); ++it)//ʹ�õ�����ѭ������grades����
		cout << *it << " ";      //iterָ�������еĵ�ǰλ�õ����ݣ�*iterΪ���ݵ�ֵ
	cout << endl;

	cout << "scores.size = " << scores.size() << endl;//���scores������������С
	for (vector<unsigned>::const_iterator it = scores.begin();
		it != scores.end(); ++it)//ʹ�õ�����ѭ������scores����
		cout << *it << " ";      //iterָ�������еĵ�ǰλ�õ����ݣ�*iterΪ���ݵ�ֵ
	cout << endl;

	vector<unsigned> alt_scores(11, 0);  //�ٶ���һ����unsigned�������ݵ�vector��������alt_scores����ʼ��11��ֵΪ0������
	for (vector<unsigned>::const_iterator it = grades.begin();it != grades.end(); ++it) 
	{
		unsigned i = *it;          //��itָ������ݸ�ֵ��i����
		++(*(alt_scores.begin() + i / 10));//�óɼ���������ѧ������һ�����������ô��⣺
		                                   //alt_scores.begin()ָ��alt_scores�����ĵ�һ�����ݣ�
		                                   //i/10Ϊ�ɼ�����������alt_scores.begin()������i/10����λǡ��Ϊ��������ѧ�������洢��λ�ã�
		                                   //�����ָ����С��������������*����Ϊ��ָ��ָ������ݣ�
		                                   //��ʱ���ٽ���������ʹ��++���㣬������ۼƸóɼ���������������
	}
	cout << "alt_scores.size = " << alt_scores.size() << endl;//���alt_scores�����Ĵ�С
	for (vector<unsigned>::const_iterator it = alt_scores.begin();it != alt_scores.end(); ++it)
		cout << *it << " ";//���ÿ���ɼ���������ѧ������
	cout << endl;
	system("pause");//Visual Studio 2017��Ҫ������һ����ܽ�����ͣ�����ñ����Ա�鿴���н��
	return 0;
}
