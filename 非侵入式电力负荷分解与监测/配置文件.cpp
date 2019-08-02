#include"配置文件.h"
using namespace std;
void consumption_set(std::ifstream& readin, std::map<std::string, double>& daset, std::vector<std::string> allappliance)
{
	string tempname;//功率配置文件电器名字
	double tempdata;//功率配置文件实际功率值
	std::getline(readin,tempname);//文件格式需要删掉第一行

	while (readin >> tempname && readin >> tempdata)
	{
		allappliance.push_back(tempname);
		daset[tempname] = tempdata;
	}

}

