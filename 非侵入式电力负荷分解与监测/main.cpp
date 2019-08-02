
#include"配置文件.h"
#include"数据库.h"
#include"功能实现.h"
#include<iostream>

using namespace std;
int main(int argc,char* argv[])
{
	ifstream readin;


	//读取储存功率文件1111111111111111111
	map<string, double> daset;
	vector<string> allappliance;
	readin.open(argv[1]);
	if (!readin)
	{
		cout << "failed openning file!";
		exit(1)  ;

	}
	consumption_set(readin, daset,allappliance);
	readin.close();


	//读取储存各种组合（电路接入状态）的电压取值范围
	//每一种状态用整形表示
	map< int, vector<string> > appliances ;//储存每一种状态组合电器的名称2222222222222
	map< int, scale> scales;//每一种状态有一个电压波动范围3333333333333333 ,
	//需要填充
	
	readin.open(argv[2]);
	if (!readin)
	{
		cout << "failed openning file!";
		exit(1);

	}
	readdatabase(readin,appliances,scales);
	readin.close();
	

	readin.open(argv[3]);
	if (!readin)
	{
		cout << "failed openning file!";
		exit(1);

	}
	map< string, gadget > gadgets;//所有电器的状态
	for (vector<string>::iterator it = allappliance.begin(); it != allappliance.end(); it++)
		gadgets[*it];

	DaFunction_on_off(gadgets,readin,appliances,scales);


	/*string test;
	readin >> test;
	readin.close();
	cout << test;
	*/
	
	system("pause");
	return 0;

}