#include "mysql.h"
#include "attendence_system.h"
#include <iostream>
#include<iomanip>
using namespace std;

MYSQL mysql, *sock;   //����MySQL�ľ��

int main(void)
{
	ConnectDatabase(mysql);        //�������ݿ� 
	cout << endl;
	show_database(mysql);          //��ʾ���ݿ����ϵͳ 

	mysql_close(sock);             //�ر����ݿ� 
	system("pause");
	exit(EXIT_SUCCESS);
}
