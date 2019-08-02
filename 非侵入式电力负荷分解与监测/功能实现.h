#ifndef 功能_GUARD
#define 功能_GUARD
#include<vector>
#include<string>
#include<map>
#include"数据库.h"
#include"配置文件.h"
#include<fstream>
using std::vector;
using std::string;
using std::map;
using std::ifstream;
typedef struct time {
	string date;
	double hour;
	double minute;
	double second;
}time;
class gadget
{
public:
	gadget() :condition(0) {}
	bool condition;
	
	
	vector<time> begintime;
	vector<time> endtime;
	
	
};

void DaFunction_on_off(map< string, gadget >& status, ifstream& readin, map< int, vector<string> >& combination, map< int, scale>& scales);
void DaFunction_consumption(map<string,gadget>& status,map<string,double>& daset);//耗电

#endif 
