#include "mysql.h"
#include "attendence_system.h"
#include <iostream>
#include<iomanip>
using namespace std;

MYSQL mysql, *sock;   //声明MySQL的句柄

int main(void)
{
	ConnectDatabase(mysql);        //连接数据库 
	cout << endl;
	show_database(mysql);          //显示数据库操作系统 

	mysql_close(sock);             //关闭数据库 
	system("pause");
	exit(EXIT_SUCCESS);
}
