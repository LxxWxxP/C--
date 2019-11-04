#include "functions.h"
#include "class_ATM.h"
#include "class_staff.h"
#include "class_user.h"
#include <cstdlib>
#include <ctime>

int main()
{
	cout << "Do you have an account?" << endl;
	cout << "1. Yes        2. No" << endl;
	while (1)
	{
		int yesOrNo;
		cin >> yesOrNo;
		if (yesOrNo == 1)
		{
			break;
		}
		else if (yesOrNo == 2)
		{
			user u1;
			u1.Open_account();
			break;
		}
		else
		{
			cout << endl << "Please enter the correct option(1 or 2)!" << endl;
		}
	}


	ATM a1, a2, a3, a4, a5;
	vector<ATM> atms = { a1, a2, a3, a4, a5 };   //Five ATM are initialized by default

	srand((int)time(NULL));
	int randIndex = rand() % 5;                   

	string number = atms[randIndex].login();
	atms[randIndex].display();
	atms[randIndex].operate(number);
	atms[randIndex].logout();

	cout << endl << endl << "staff[" << staffs[rand() % 10].id << "]: " << endl;
	staffs[rand() % 10].checkATM(atms[randIndex]);

	system("pause");
	return 0;
}