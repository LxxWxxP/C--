#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct worker
{
	int num;
	string name;
	int age;
	float wages;
};

void initialize_data()
{
	cout << "Please input data(including number, name, age and wages) of five workers in the order of their working numbers:" << endl;
	worker w[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> w[i].num >> w[i].name >> w[i].age >> w[i].wages;
	}
	ofstream outfile("workers_data.txt");
	if (!outfile)
	{
		cout << "Open the workers_data error!" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < 5; i++)
	{
		outfile << w[i].num << " ";
		outfile << w[i].name << " ";
		outfile << w[i].age << " ";
		outfile << w[i].wages << " " << endl;
	}
	outfile.close();
	return;
}

void input_data()
{
	cout << "Please input two workers' data(requirement: the numbers of two workers are larger than the workers numbers before)" << endl;
	ofstream outfile("workers_data.txt", ios::app);
	if (!outfile)
	{
		cout << "Open the workers_data error!" << endl;
		system("pause");
		exit(1);
	}
	worker w[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "Please enter the " << i << "th workers' data(including number, name, age and wages):" << endl;
		cin >> w[i].num >> w[i].name >> w[i].age >> w[i].wages;
		outfile << w[i].num << " ";
		outfile << w[i].name << " ";
		outfile << w[i].age << " ";
		outfile << w[i].wages << " " << endl;
	}
	outfile.close();
	return;
}

void output_data()
{
	cout << "The data of all workers as follows:" << endl;
	ifstream infile("workers_data.txt", ios::in);
	//判断文件是否为空
	if (infile.peek() == EOF)
	{
		cerr << "The file is empty!" << endl;
		system("pause");
		exit(1);
	}
	worker w;
	//判断是否到了文件末尾
	while (!infile.eof())
	{
		infile >> w.num >> w.name >> w.age >> w.wages;
		cout << "worker " << w.num << ":" << endl;
		cout << "name: " << w.name << endl;
		cout << "age: " << w.age << endl;
		cout << "wages: " << w.wages << endl << endl;
	}
	infile.close();
	return;
}

void check()
{
	while (1)
	{
		cout << "Please enter the number of a worker:(0 represents ending!)" << endl;
		int n;
		cin >> n;
		if (n == 0)
		{
			cout << "ending..." << endl;
			break;
		}
		ifstream infile("workers_data.txt", ios::in);
		if (!infile)
		{
			cerr << "Open the workers_data error!" << endl;
			system("pause");
			exit(1);
		}
		int exist = 0;
		worker w;
		//判断是否到了文件末尾
		while (!infile.eof())
		{
			infile >> w.num >> w.name >> w.age >> w.wages;
			if (w.num == n)
			{
				exist = 1;
				break;
			}
		}
		if (exist == 1)
		{
			cout << "worker " << w.num << ":" << endl;
			cout << "name: " << w.name << endl;
			cout << "age: " << w.age << endl;
			cout << "wages: " << w.wages << endl << endl;
		}
		else if (exist == 0)
		{
			cout << "无此人" << endl;
		}
	}
	return;
}

int main()
{
	initialize_data();
	output_data();
	input_data();
	output_data();
	check();
	system("pause");
	return 0;
}