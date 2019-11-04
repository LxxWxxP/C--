#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;


class user
{
public:
	string name;
	user() :name("xxx"), id("00000000000"), tel("00000000000"), cardNumber("000000"), cardPassword("000000"),balance(0),freeze(0){}  //Default constructor
	user(const user & a)
	{
		name = a.name; id = a.id; tel = a.tel; cardNumber = a.cardNumber;
		cardPassword = a.cardPassword; balance = a.balance; freeze = a.freeze;
	}//Copy constructor
//	~user() { cout << "User's destructor called!" << endl; }//Destructor function

    //***Show user's information;
	void show_user();
	
	
	//*****************************           Account opening function          *************************************
	void Open_account();
	

private:
	string id;
	string tel;
	string cardNumber;
	string cardPassword;
	double balance;             
	int freeze;                
};

