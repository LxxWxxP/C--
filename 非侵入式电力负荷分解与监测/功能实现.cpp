#include"����ʵ��.h"
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
			//���⣬���ֲ����ڵ�״̬��
			//����״̬��������״̬
			
			if (volt > scales[testi].min&&volt < scales[testi].max)
			{

				//�����ж��Ƿ�������������ֹ��ѹ�½�����ĳһ״̬������ĳһ��״̬
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
				if (skipclasp >= 55)//������Ҫ�����޸�?????
				{
					skipclasp = 1;

					//��Ϊ���޵�������״̬������Ҫ�ر�����һ���ж�
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
						testi = 0;//�仯�ˣ�������Ѱ�Һ��ʵ�״̬
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
					testi = 0;//�仯�ˣ�������Ѱ�Һ��ʵ�״̬
				}

			}
			testi++;
		}
		
		//�޵���״̬
		
		
	}
	

}

void DaFunction_consumption(map<string, gadget>& status, map<string, double>& daset)
{
	
}