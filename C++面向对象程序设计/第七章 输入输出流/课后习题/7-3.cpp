#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	for (int i = 1; i < 8; i++)
	{
		cout << setw(20 - i) << setfill(' ') << " " << setw(2 * i - 1) << setfill('B') << "B" << endl;
	}
	system("pause");
	return 0;
}