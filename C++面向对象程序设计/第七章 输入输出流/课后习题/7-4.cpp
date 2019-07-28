#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	//从键盘输入20个整数，分别存放在两个磁盘文件中（每个文件中放10个整数）
	int a[20];
	cout << "Please enter 20 interger:" << endl;
	for (int i = 0; i < 20; i++)
		cin >> a[i];
	ofstream outfile;
/*	if (outfile.open("f1.dat", ios::out | ios::trunc) == 0)
		cout << "open error!";*/                           //这句都报错？

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

	//从f1.dat读入10个数，然后存放到f2.dat文件原有数据的后面
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

	//从f2.dat读入20个整数，对它们按从小到大的顺序存放到f2.dat（不保留原来的数据）
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

//注意：outfile/infile不可以多次初始化。即不可以多次写：ofstream outfile(...);如果要改变关联对象的话，就用outfile.open(...)