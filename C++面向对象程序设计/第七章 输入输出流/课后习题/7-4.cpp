#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	//�Ӽ�������20���������ֱ��������������ļ��У�ÿ���ļ��з�10��������
	int a[20];
	cout << "Please enter 20 interger:" << endl;
	for (int i = 0; i < 20; i++)
		cin >> a[i];
	ofstream outfile;
/*	if (outfile.open("f1.dat", ios::out | ios::trunc) == 0)
		cout << "open error!";*/                           //��䶼����

	outfile.open("f1.dat", ios::out);
	if (!outfile)
	{
		cerr << "open f1.dat error!" << endl;
		exit(1);
	}
	for (int i = 0; i < 10; i++)
		outfile << a[i] << " ";
	outfile.close();

	outfile.open("f2.dat", ios::out);
	if (!outfile)
	{
		cerr << "open f2.dat error!" << endl;
		exit(1);
	}
	for (int i = 10; i < 20; i++)
		outfile << a[i] << " ";
	outfile.close();

	//��f1.dat����10������Ȼ���ŵ�f2.dat�ļ�ԭ�����ݵĺ���
	ifstream infile("f1.dat", ios::in);
	if (!infile)
	{
		cerr << "open f1.dat error!" << endl;
		exit(1);
	}
	int b[10];
	for (int i = 0; i < 10; i++)
		infile >> b[i];
	infile.close();
	outfile.open("f2.dat", ios::app);
	if (!outfile)
	{
		cerr << "open f2.dat error!" << endl;
		exit(1);
	}
	for (int i = 0; i < 10; i++)
		outfile << b[i] << " ";
	outfile.close();

	//��f2.dat����20�������������ǰ���С�����˳���ŵ�f2.dat��������ԭ�������ݣ�
	int c[20];
	infile.open("f2.dat", ios::in);
	if (!infile)
	{
		cerr << "open f2.dat error!" << endl;
		exit(1);
	}
	for (int i = 0; i < 20; i++)
		infile >> c[i];
	infile.close();
	for (int i = 0; i < 19; i++)
	{
		int temp;
		for (int j = 19 - i; j > 0; j--)
		{
			if (c[j - 1] > c[j])
			{
				temp = c[j];
				c[j] = c[j - 1];
				c[j - 1] = temp;
			}
		}
	}
/*	int t;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19 - i; j++)
		{
			if (c[j] > c[j + 1])
			{
				t = c[j];
				c[j] = c[j + 1];
				c[j + 1] = t;
			}
		}
	}*/
	outfile.open("f2.dat", ios::out | ios::trunc);
	if (!outfile)
	{
		cerr << "open f2.dat error!" << endl;
		exit(1);
	}
	for (int i = 0; i < 20; i++)
		outfile << c[i] << " ";
	outfile.close();

	system("pause");
	return 0;
}

//ע�⣺outfile/infile�����Զ�γ�ʼ�����������Զ��д��ofstream outfile(...);���Ҫ�ı��������Ļ�������outfile.open(...)