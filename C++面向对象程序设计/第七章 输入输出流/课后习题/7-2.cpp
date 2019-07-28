#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	vector<float> data;
	float d;
	while ((d = cin.get()) != EOF)
	{
		data.push_back(d);
	}
	cout << setiosflags(ios::fixed | ios::right) << setprecision(3);
	for (vector<float>::iterator i = data.begin(); i != data.end(); i++)
	{
		cout << *i << endl;
	}
	system("pause");
	return 0;
}