#include"�����ļ�.h"
using namespace std;
void consumption_set(std::ifstream& readin, std::map<std::string, double>& daset, std::vector<std::string> allappliance)
{
	string tempname;//���������ļ���������
	double tempdata;//���������ļ�ʵ�ʹ���ֵ
	std::getline(readin,tempname);//�ļ���ʽ��Ҫɾ����һ��

	while (readin >> tempname && readin >> tempdata)
	{
		allappliance.push_back(tempname);
		daset[tempname] = tempdata;
	}

}

