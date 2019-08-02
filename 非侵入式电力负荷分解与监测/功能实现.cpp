#include"功能实现.h"
#include<iostream>
using namespace std;
void DaFunction_on_off(map< string, gadget >& status, ifstream& readin,  map< int, vector<string> >& combination,  map< int, scale>& scales)
{
	string dispose;
	getline(readin,dispose);



	long double volt;
	string date;
	double hour;
	double minute;
	double second;
	time a;
	int testi = 0;
	while (readin)
	{
		readin >> date;
		readin >> hour >> minute >> second;
		readin >> volt;
		testi = 0;
		while (testi < scales.size())
		{
			//问题，出现不存在的状态呢
			//所有状态遍历电器状态
			
			if (volt > scales[testi].min&&volt < scales[testi].max)
			{

				//用来判断是否是有跳动，防止电压下降经过某一状态当作是某一种状态
				int skipclasp = 1;
				
				readin >> date;
				readin >> hour >> minute >> second;
				readin >> volt;
				while (volt > scales[testi].min&&volt < scales[testi].max)
				{
					skipclasp++;
					readin >> date;
					readin >> hour >> minute >> second;
					readin >> volt;
				}
				if (skipclasp >= 55)//此项需要测试修改?????
				{
					skipclasp = 1;

					//因为有无电器接入状态，所以要特别设置一个判断
					if (testi == 0)
					{
						for (map< string, gadget >::iterator iter = status.begin(); iter != status.end(); iter++)
						{
							if (iter->second.condition == 0)
							{

							}
							else
							{
								
								a.date = date;
								a.hour = hour;
								a.minute = minute;
								a.second = second;
								iter->second.endtime.push_back(a);

							}
						}
						testi = 0;//变化了，重置在寻找合适的状态
					}
					//

					else//
					{
						a.date = date;
						a.hour = hour;
						a.minute = minute;
						a.second = second;
						for (map< string, gadget >::iterator iter = status.begin(); iter != status.end(); iter++)
						{
							if (iter->second.condition == 1)
							{
								iter->second.condition = 2;
							}
						}
						for(vector<string>::iterator iter = combination[testi].begin(); iter != combination[testi].end(); iter++)
						{
							if (status[*iter].condition == 0)
							{
								status[*iter].condition = 1;
								
								status[*iter].begintime.push_back(a);
							}
							else if (status[*iter].condition == 2)
							{
								status[*iter].condition = 1;
							}
						}
						for(map< string, gadget >::iterator iter = status.begin(); iter != status.end(); iter++)
						{
							if (iter->second.condition == 2)
							{
								iter->second.condition = 0;
								iter->second.endtime.push_back(a);
							}
						}
					}

				}
				else
				{
					skipclasp = 1;
					testi = 0;//变化了，重置在寻找合适的状态
				}

			}
			testi++;
		}
		
		//无电器状态
		
		
	}
	

}

void DaFunction_consumption(map<string, gadget>& status, map<string, double>& daset)
{
	
}