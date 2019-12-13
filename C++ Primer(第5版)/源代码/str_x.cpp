#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Please enter a string: " << endl;
	string str;
	cin >> str;
	for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
		str[index] = 'x';
	cout << "The string after changing is: " << endl <<  str << endl;
	system("pause");
	return 0;
}