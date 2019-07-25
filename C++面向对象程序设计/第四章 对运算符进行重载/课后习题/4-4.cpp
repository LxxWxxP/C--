#include <iostream>
using namespace std;

class Matrix
{
private:
	int mat[2][3];
public:
	Matrix();                                                    //默认构造函数
	Matrix(Matrix &);                                            //复制构造函数
	~Matrix() { cout << "A Matrix has been created!" << endl; }
	void mat_input();
	void display();
	Matrix operator + (Matrix & m);
};

Matrix::Matrix()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			mat[i][j] = 0;
	}
}

Matrix::Matrix(Matrix & m)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			mat[i][j] = m.mat[i][j];
	}
}

void Matrix::mat_input()
{
	cout << "Please enter the elements of the Matrix[2][3]:" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> mat[i][j];
	}
}

void Matrix::display()
{
	cout << "The matrix is:" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << mat[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

Matrix Matrix::operator + (Matrix & m)
{
	Matrix new_mat;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			new_mat.mat[i][j] = mat[i][j] + m.mat[i][j];
	}
	return new_mat;
}

int main()
{
	Matrix m1, m2, m3;
	m1.mat_input();
	m2.mat_input();
	m3 = m1 + m2;
	m1.display();
	m2.display();
	m3.display();
	system("pause");
	return 0;
}