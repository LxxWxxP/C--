#include "class_staff.h"
#include"functions.h"

void staff::passwordChange()
{
	cout << endl << "Please provide your bank card numberand your id: " << endl;
	int count = 0;
	while (count < 5)
	{
		cout << "Please provide your bank card number and your id: " << endl;
		string number;
		string id;
		cin >> number >> id;                   
		
		
			if (idToNumber(id, number))     // Call the function to verify the card number and ID.
			{
				while (1)
				{
					cout << "Please enter a new password:" << endl;
					string newPassword;
					cin >> newPassword;
					string newPassword2;
					cout << "Please enter your new password again to make sure:" << endl;
					cin >> newPassword2;
					if (newPassword2 == newPassword)
					{
						thawAndChange(number, newPassword);
						cout << "Password modified successfully!" << endl;
						break;
					}
					else
						cout << "Two different passwords,please operate according to the prompt again!" << endl;
				}
				break;
			}		
			else
			{
				cout << "Wrong card number or id." << endl;
				count++;
			}
	}
	if (count >= 5)
		cout << "Please come when you remember your id and card number!" << endl;
	return;
}

void staff::checkATM(const ATM& a)
{
	cout << endl << "ATM" << a.id << " has been maintained daily!" << endl;
	if (a.money <= 10000)
		cout << "ATM" << a.id << " has insufficient inventory, the current inventory is:" << a.money << endl;
}
