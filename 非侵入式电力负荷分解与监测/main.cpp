
#include"�����ļ�.h"
#include"���ݿ�.h"
#include"����ʵ��.h"
#include<iostream>

using namespace std;
int main(int argc,char* argv[])
{
	ifstream readin;


	//��ȡ���湦���ļ�1111111111111111111
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


	//��ȡ���������ϣ���·����״̬���ĵ�ѹȡֵ��Χ
	//ÿһ��״̬�����α�ʾ
	map< int, vector<string> > appliances ;//����ÿһ��״̬��ϵ���������2222222222222
	map< int, scale> scales;//ÿһ��״̬��һ����ѹ������Χ3333333333333333 ,
	//��Ҫ���
	
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
	map< string, gadget > gadgets;//���е�����״̬
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