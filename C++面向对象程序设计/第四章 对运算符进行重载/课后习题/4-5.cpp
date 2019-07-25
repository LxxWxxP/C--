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
	Matrix operator + (Matrix & m);
	friend ostream & operator << (ostream &, Matrix &);
	friend istream & operator >> (istream &, Matrix &);
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

istream & operator >> (istream & input, Matrix & m)
{
	cout << "Please enter the elements of the Matrix[2][3]:" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			input >> m.mat[i][j];
	}
	return input;
}

ostream & operator << (ostream & output, Matrix & m)
{
	output << "The matrix is:" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			output << m.mat[i][j] << "\t";
		output << endl;
	}
	output << endl;
	return output;
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
	cin >> m1 >> m2;
	m3 = m1 + m2;
	cout << m1 << m2 << m3;
	system("pause");
	return 0;
}