#include "class_staff.h"
#include "class_ATM.h"
#include "functions.h"


string enterNumberPassword()
{
	int count = 0;
	while (1)
	{
		cout << endl << "Please enter your card number: ";
		string number;
		cin >> number;
		if (searchNumber(number))//correct card number
		{
			if (count >= 5)    //Error in entering password more than five times. find the corresponding card number location in password.txt file and modify freeze to 0
			{
				fstream fin("password.txt");
				if (!fin)
				{
					cerr << "open error!" << endl;
					exit(1);
				}
				while (!fin.eof())
				{
					char c;
					fin >> c;
					if (c == 'n')
					{
						fin.seekg(7L, ios::cur);
						string x;    //correct number
						fin >> x;
						if (number == x)  //If it is the same, it will jump out of the loop, indicating that the corresponding card number is found and the freeze is modified to 1
						{
							break;
						}
					}
				}

				fin.seekp(28L, ios::cur);
				fin << "1";    
				fin.close();
				cout << "Your account has been frozen, please find the staff to unfreeze!" << endl;
				throw count;         //throw a mistake(count)
				break;
			}
			cout << "The card number is available!" << endl << endl;
			cout << "Please enter the password: ";
			string password;
			cin >> password;
			if (rightPassword(number, password))
			{
				cout << "Login successfully!" << endl << endl;
				return number;
			}
			else
			{
				cout << "Incorrect password, please enter again!" << endl;
				count++;
			}
		}
		else
			cout << "The card number is inexistent, please enter again!" << endl;
	}
}

double checkMoney(const string& number)   
{
	fstream fin("balance.txt", ios::in);
	if (!fin)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	while (!fin.eof())
	{
		char c;
		fin >> c;
		if (c == 'n')
		{
			fin.seekg(7L, ios::cur);
			string x;
			fin >> x;
			if (number == x)		
				break;
		}
	}
	fin.seekg(11L, ios::cur);
	string balance;
	fin >> balance;
	fin.close();
	return stod(balance);    
}

void updateMoney(const string& number, double money) 
{ 
	fstream fin("balance.txt");
	if (!fin)
	{
		cerr << "open error!" << endl;
		exit(1);
	}

	while (!fin.eof())
	{
		char c;
		fin >> c;
		if (c == 'n')
		{
			fin.seekg(7L, ios::cur);
			string x;
			fin >> x;
			if (number == x)
				break;
		}
	}
	fin.seekp(11L, ios::cur);	
	fin << "                    ";    //blank*20
	fin.seekp(-20L,ios::cur);
	fin << money;                             //Note that if the balance is 99999, it will be 100 after change, and 10099 will be obtained after actual writing.  
                                              //Solution: Change the file format and force the balance to be digital.
	
	cout << "Your balance has been updated to:" << money << endl << endl;
	fin.close();
}

int idToNumber(string id, string number)       
{
	fstream fin("password.txt", ios::in);
	if (!fin)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	while (!fin.eof())
	{
		char c;
		fin >> c;
		if (c == 'i')
		{
			fin.seekg(3L, ios::cur);
			string x;    //correct id
			fin >> x;
			if (id == x)
				break;
		}
	}
	fin.seekg(10L, ios::cur);
	string y;//correct number
	fin >> y;
	fin.close();
	if (y == number)
		return 1;
	else
		return 0;
}

void thawAndChange(string number, string newPassword)
{
	fstream fin("password.txt");
	if (!fin)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	while (!fin.eof())
	{
		char c;
		fin >> c;
		if (c == 'n')
		{
			fin.seekg(7L, ios::cur);
			string x;    //correct number
			fin >> x;
			if (number == x)
				break;
		}
	}
	fin.seekp(12L, ios::cur);
	//change the password
	fin << newPassword;
	//unfreeze
	fin.seekp(10L, ios::cur);
	fin << "0";
	fin.close();
	return;
}

int rightPassword(string number, string password)
{
	fstream fin("password.txt", ios::in);
	if (!fin)
	{
		cerr << "open error!" << endl;
		exit(1);
	}

	string x;    
	while (!fin.eof())
	{
		char c;
		fin >> c;
		if (c == 'n')
		{
			fin.seekg(7L, ios::cur);
			string x;    
			fin >> x;
			if (number == x)
			{
				fin.seekg(12L, ios::cur);   
				break;
			}
		}
	}

	

	string y;    
	fin >> y;
	fin.close();
	if (password == y)
		return 1;
	else
		return 0;
}

int searchNumber(string number)  
{
	ifstream fin("password.txt", ios::in);
	if (!fin)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	while (!fin.eof())
	{
		char c;
		fin >> c;
		if (c == 'n')
		{
			string snum;
			fin.seekg(7L, ios::cur);
			fin >> snum;          

			if (number == snum)
			{
				fin.close();
				return 1;
			}
		}
	}
	fin.close();
	return 0;
}