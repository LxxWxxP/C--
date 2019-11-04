#include "class_ATM.h"
#include<cstdlib>
#include<ctime>



string ATM::login()
{
	try
	{
		return enterNumberPassword();                  
	}
	catch (int)
	{
		srand((int)time(NULL));
		int randIndex = rand() % 10;                     
		staffs[randIndex].passwordChange();         //If it is abnormal, execute passwordchange ()
		return enterNumberPassword();
	}
}



void ATM::display()
{
	cout << endl;
	cout << "----------Welcome to use automated teller machine----------" << endl;
	cout << "-- Please choose an operation as follow:                 --" << endl;
	cout << "-- 1. deposit                                            --" << endl;
	cout << "-- 2. withdraw                                           --" << endl;
	cout << "-- 3. check balance                                      --" << endl;
	cout << "-- 4. quit                                               --" << endl;
	cout << "-----------------------------------------------------------" << endl << endl;
}



void ATM::operate(const string& number)
{
	while (1)
	{
		int x;
		cin >> x;
		double sum = checkMoney(number);
		if (x == 1)          //deposit
		{
			cout << endl;
			cout << "Please put your money to the machine and click the confirm button(in this system we just input the amount of your money)" << endl;
			int inmoney;
			cin >> inmoney;
			money += inmoney;  // update ATM balance
			updateMoney(number, sum + inmoney);  //Deposit money into user's balance
		}
		else if (x == 2)     //withdraw
		{
			cout << endl;
			cout << "Please enter the amount of the money which you need." << endl;
			int outmoney;
			cin >> outmoney;
			if (money < outmoney)
			{
				cout << "Sorry, the amount in the ATM is not enough!" << endl;
				throw money;
				break;
			}
			money -= outmoney;
			updateMoney(number, sum - outmoney);  //Update balance after withdrawing money
		}
		else if (x == 3)
		{
			cout << endl;
			cout << "The balance of your account is " << sum << endl << endl;
		}
		else if (x == 4)
		{
			cout << endl;
			break;
		}
		else
		{
			cout << endl;
			cout << "Please enter an available number!" << endl << endl;
		}
	}
	return;
}


int ATM::logout()
{
	cout << "The bank card has been ejected. Please take your card and keep it." << endl;
	return 1;
}