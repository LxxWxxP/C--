
#pragma once

#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include <cstring>

using namespace std;

string enterNumberPassword();

double checkMoney(const string& number) ;

void updateMoney(const string& number, double money);

int idToNumber(string id, string number) ;

void thawAndChange(string number, string newPassword) ;

int rightPassword(string number, string password);

int searchNumber(string number);

//bool judgeMoney(double money);             //  When accessing money, judge whether it is a multiple of 100.

