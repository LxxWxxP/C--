#include"数据库.h"
#include<iostream>

using namespace std;

void reveal(const map< int, string >&, int pre, int curr)
{

}
void readdatabase(ifstream& read, map<int, vector<string> >& appliances, map<int, scale>& scales)
{
	int num = 0;//问题，真的需要零状态吗???????
	string tempapp;
	double tempmin;
	double tempmax;
	getline(read, tempapp);

	while (read >> tempapp)
	{
		
		
		
		while (tempapp!="!")
		{
			appliances[num].push_back(tempapp);
			read.get();
			read >> tempapp;
			
			
		}
		
		read >> tempmin;
		read.get();
		read >> tempmax;
		
		scales[num].min = tempmin;
		scales[num].max = tempmax;
		num++;
	}
}

