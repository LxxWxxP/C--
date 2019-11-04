#pragma once

#include<iostream>
#include<string>
#include<vector>

#include"class_staff.h"
#include"functions.h"


using namespace std;

class ATM
{
	friend class user;
	friend class staff;
public:
	ATM(): money(1000000)//Default constructor
	{
		ifstream fin("atm.txt", ios::in);
		fin >> id;
		fin.close();

		ofstream fout("staff.txt", ios::out);
		fout << id;
		fout.close();
	}
	ATM(const ATM & atm) { money = atm.money; id = atm.id; }  //Copy constructor
//	~ATM() { cout << "ATM's destructor called!" << endl; }    //Destructor function

	
	string login();  
	void display();
	void operate(const string& number);//deposit, withdrawal, check balance, quit
	int logout(); 
  
private:
	double money;
	string id;
	//int fault;
};