#include <iostream>
using namespace std;
class store
{
private:
	int num;
	int quantity;
	float price;
	static float sum;
	static int n;
	static float ave;
public:
	static float discount;
	store(int n = 0, int q = 0, float p = 0) :num(n), quantity(q), price(p) {}
//	store(float d = 1, float s = 0, int m = 0) :discount(d), sum(s), n(m) {}�����ڱ�����discount��sum��n������store��������ݳ�Ա�����Բ������������幹�캯��
	static void average(const store& s);
	static void display();
};

//��̬���ݳ�Աֻ�ܹ����������ʼ��
float store::discount = 1;
float store::sum = 0;
int store::n = 0;
float store::ave = 0;

void store::average(const store& s)
{
	sum += s.quantity * s.price * discount;
	n += s.quantity;
	ave = sum / n;
}

void store::display()
{
	cout << "The sum price of that day is: " << sum << endl;
	cout << "The average price of that day is: " << ave << endl;
}

int main()
{
	cout << "Please enter the discount of that day: ";
	cin >> store::discount;
	store sellers[3] = { store(101,5,23.5),store(102,12,24.56),store(103,100,21.5) };
	for (int i = 0; i < 3; i++)
	{
		store::average(sellers[i]);
	}
	store::display();
	system("pause");
	return 0;
}