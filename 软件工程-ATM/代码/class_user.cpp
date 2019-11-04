#include "class_user.h"


void user::show_user()
{
	cout << "name: " << name << endl << "id: " << id << endl << "tel: " << tel << endl <<
		"cardNumber: " << cardNumber << endl << "balance: " << balance << endl;
}


void user::Open_account()
{
	cout << "Please enter your name, ID and telephone number in order." << endl;
	cin >> name >> id >> tel;
	long int card_number;
	ifstream fin0("cardnumber.txt", ios::in);
	fin0 >> card_number;
	cardNumber = to_string(card_number++);
	fin0.close();

	ofstream fout("cardnumber.txt", ios::out);
	fout << card_number;
	fout.close();

	while (1)
	{
		cout << "Please enter the password." << endl;
		string p1;
		cin >> p1;
		cout << "Please enter the password again to make sure!" << endl;
		string p2;
		cin >> p2;
		if (p1 == p2)
		{
			cardPassword = p1;
			break;
		}
		else
		{
			cout << "The two passwords entered are inconsistent, please enter again!" << endl;
		}
	}

	//  Write information to a file
	fstream fin("password.txt");
	if (!fin)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	fin.seekp(0L, ios::end);
	fin << endl;
	fin << "NAME: " << name << endl;
	fin << "tel: " << tel << endl;
	fin << "id: " << id << endl;
	fin << "number: " << cardNumber << endl;
	fin << "password: " << cardPassword << endl;
	fin << "freeze: " << 0 << endl;
	fin.close();

	fstream fin2("balance.txt");
	if (!fin2)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	fin2.seekp(0L, ios::end);
	fin2 << endl;
	fin2 << "number: " << cardNumber << endl;
	fin2 << "balance: " << "0                   " << endl;
	fin2.close();

	cout << "Congratulations! Dear " << name << ". The account was opened successfully. Your information is:" << endl;
	show_user();
}