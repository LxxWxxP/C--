#pragma once
#include <iostream>
#include <string>
#include "class_ATM.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class staff
{
	friend class ATM;
public:
	string name;
	string id;

	staff() //Default constructor
	{
		ifstream fin("staff.txt",ios::in);
		long int iid;
		fin >> iid;
		fin.close();

		std::stringstream ss;
		ss << iid;
		ss >> id;

		name = "staff" + to_string(iid++);

		ofstream fout("staff.txt", ios::out);
		fout << iid;
		fout.close();
	}
	staff(const staff & s) { name = s.name; id = s.id; }    //Copy constructor
//	~staff() { cout << "Staff's destructor called!" << endl; }//Destructor function

	void passwordChange();                                  //change the password
	void checkATM(const ATM& a);                              // Maintain and update ATM.  Check ATM inventory and remind the staffs.
};


static staff s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
static vector<staff> staffs = { s1, s2, s3, s4, s5, s6, s7, s8, s9, s10 };   //10 staffs initialized by default