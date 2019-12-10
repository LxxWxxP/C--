#include "attendence_system.h"
#include <string>
using namespace std;

void show_database(MYSQL mysql)
{
	SelectData(mysql, "*", "clerk");
	cout << endl;
	cout << "服务类型表如下:" << endl
		<< "1. 考勤" << endl
		<< "2. 修改数据" << endl
		<< "3. 退出系统" << endl << endl;
	cout << "请输入您所需要的服务类型: " << endl;
	int input_server;
	cin >> input_server;
	while (input_server != 3)
	{
		switch (input_server)
		{
			case 1:
			{
				attendence(mysql);
				break;
			}
			case 2:
			{
				change_data(mysql);
				break;
			}
			case 3:
			{
				break;
			}
			default:
			{
				cout << "Unvalid select number!" << endl;
				break;
			}
		}
		cout << "服务类型表如下:" << endl
			<< "1. 考勤" << endl
			<< "2. 修改数据" << endl
			<< "3. 退出系统" << endl << endl;
		cout << "请输入您所需要的服务类型: " << endl;
		cin >> input_server;
	}
	cout << endl << "请您确认操作后的数据库，表格如下:" << endl << endl;
	SelectData(mysql, "*", "clerk");
	cout << endl << endl << "本次数据库服务结束，感谢您的使用！" << endl << endl;
}

void attendence(MYSQL mysql)
{
	MYSQL_RES * result;                          //保存结果集
	MYSQL_ROW row;                               //代表的是结果集中的一行(返回string类的数据)

	cout << endl << "可参与考勤的教职工的职工号如下：" << endl;

	const char * i_query = "select * from clerk"; //查询语句
	mysql_query(&mysql, i_query);
	result = mysql_store_result(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
		cout << row[0] << endl;
	cout << endl << "考勤名单如下：\n请输入本次考勤的职工号(未参与本次考勤的教职工默认通过考勤/使用Crtl+Z结束输入)：" << endl;


	int temp;
	vector<int> input_id;
	while (cin >> temp)
	{
		input_id.push_back(temp);
	}
	cout << "输入完成！" << endl << endl;
	cout << "请输入本次考勤情况(y代表到场,n代表缺席):" << endl;
	char attendence;
	for (vector<int>::iterator iter = input_id.begin(); iter < input_id.end(); iter++)          //本次考勤名单的考勤(这里不能到input_id.end())
	{
		mysql_query(&mysql, i_query);
		result = mysql_store_result(&mysql);
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			//WHERE后面的条件
			const string limitde_info = "id=";
			const string limit = limitde_info + row[0];
			//C++提供了两个函数将string转化为char *：c_str()和data()
			const char * lim = limit.c_str();


			if (*iter == stoi(row[0], nullptr, 10))
			{
				cout << *iter << ":";
				cin.clear(); 			               //错误位重置
				cin >> attendence;
				if (attendence == 'y')
				{
					UpdateData(mysql, "clerk", "attendence='pass'", lim);
					UpdateData(mysql, "clerk", "grade = grade + 1", lim);
					UpdateData(mysql, "clerk", "not_pass_times = 0", lim);
					const string record = row[4];
					if (stoi(record, nullptr, 10) >= 5)                         //超过五次考勤不通过永久置零
					{
						UpdateData(mysql, "clerk", "grade = 0", lim);
					}
					cout << *iter << " " << row[1] << ": pass!" << endl << endl;
					break;
				}
				else if (attendence == 'n')
				{
					UpdateData(mysql, "clerk", "attendence='not pass'", lim);
				//	UpdateData(mysql, "clerk", "record += 1", lim);              //+=在数据库里面不可用
					UpdateData(mysql, "clerk", "record = record + 1", lim);
					UpdateData(mysql, "clerk", "not_pass_times = not_pass_times + 1", lim);
					const string record = row[4];
					
					 //超过五次考勤不通过永久置零
					if (stoi(record, nullptr, 10) >= 5)                         
					{
						UpdateData(mysql, "clerk", "grade = 0", lim);
					}
					
					 //连续三次考勤不通过，grade置零
					if (stoi(row[7], nullptr, 10) >= 3)                         
					{
						UpdateData(mysql, "clerk", "grade = 0", lim);
					}
					cout << *iter << " " << row[1] << ": not pass!" << endl << endl;
					break;
				}
			}
		}
	}

	mysql_query(&mysql, i_query);
	result = mysql_store_result(&mysql);
	vector<int> not_input_id;
	int exist = 0;
	cout << "未参与本次考勤的名单如下(默认考勤通过)：" << endl;
	
	
	      //不在考勤名单上的默认考勤通过
	while ((row = mysql_fetch_row(result)) != NULL)                                  
	{
		const string limitde_info = "id=";
		const string limit = limitde_info + row[0];
		const char * lim = limit.c_str();
		for (vector<int>::iterator iter = input_id.begin(); iter < input_id.end(); iter++)       //这里不能到input_id.end()，所以不能取等号
		{
			if (*iter == stoi(row[0], nullptr, 10))
			{
				exist = 1;
				break;
			}
			else
				exist = 0;
		}
		if (exist == 0)
		{
			UpdateData(mysql, "clerk", "attendence='pass'", lim);
			UpdateData(mysql, "clerk", "grade = grade + 1", lim);
			UpdateData(mysql, "clerk", "not_pass_times = 0", lim);
			const string record = row[4];
			
			 //超过五次考勤不通过永久置零
			if (stoi(record, nullptr, 10) >= 5)                                 
			{
				UpdateData(mysql, "clerk", "grade = 0", lim);
			}
			cout << row[0] << " " << row[1] << ": pass!" << endl << endl;
			not_input_id.push_back(stoi(row[0], nullptr, 10));
		}
	}
}

void change_data(MYSQL mysql)
{
	cout << endl;
	cout << "请输入要修改的数据对应的职工号:" << endl;
	int input_number;
	cin >> input_number;

	MYSQL_RES * result;
	MYSQL_ROW row;
	string limitde_info;
	string limit;

	const char * i_query = "select * from clerk";
	mysql_query(&mysql, i_query);
	result = mysql_store_result(&mysql);
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		if (input_number == stoi(row[0], nullptr, 10))
		{
			limitde_info = "id=";
			limit = limitde_info + row[0];
			break;
		}
	}
	const char * lim = limit.c_str();

	cout << endl;
	cout << "请输入要修改的属性对应的序号:" << endl
		<< "1. id" << endl
		<< "2. name" << endl
		<< "3. department" << endl
		<< "4. leader" << endl
		<< "5. record" << endl
		<< "6. grade" << endl
		<< "7. attendence" << endl
		<< "8. not_pass_times" << endl << endl;
	int input_select;
	cin >> input_select;
	switch (input_select)
	{
		case 1:
		{//这个大括号不可少，不然会报错
			cout << endl << "Please enter a new id: " << endl;
			int new_id;
			cin >> new_id;
			cout << endl;
			const string id1 = "id=";
			const string id2 = id1 + to_string(new_id);
			const char * id = id2.c_str();
			UpdateData(mysql, "clerk", id, lim);
			cout << "Change id success!" << endl;
			break;
		}
		case 2:
		{
			cout << endl << "Please enter a new name: " << endl;
			string new_name;
			cin >> new_name;
			cout << endl;
			const string name1 = "name=";
			const string name2 = name1 + new_name;
			const char * name = name2.c_str();
			UpdateData(mysql, "clerk", name, lim);
			cout << "Change name success!" << endl;
			break;
		}
		case 3:
		{
			cout << endl << "Please enter a new department: " << endl;
			string new_department;
			cin >> new_department;
			cout << endl;
			const string department1 = "department=";
			const string department2 = department1 + new_department;
			const char * department = department2.c_str();
			UpdateData(mysql, "clerk", department, lim);
			cout << "Change department success!" << endl;
			break;
		}
		case 4:
		{
			cout << endl << "Please enter a new leader: " << endl;
			string new_leader;
			cin >> new_leader;
			cout << endl;
			const string leader1 = "leader=";
			const string leader2 = leader1 + new_leader;
			const char * leader = leader2.c_str();
			UpdateData(mysql, "clerk", leader, lim);
			cout << "Change leader success!" << endl;
			break;
		}
		case 5:
		{
			cout << endl << "Please enter a new record: " << endl;
			int new_record;
			cin >> new_record;
			cout << endl;
			const string record1 = "record=";
			const string record2 = record1 + to_string(new_record);
			const char * record = record2.c_str();
			UpdateData(mysql, "clerk", record, lim);
			cout << "Change record success!" << endl;
			break;
		}
		case 6:
		{
			cout << endl << "Please enter a new grade: " << endl;
			int new_grade;
			cin >> new_grade;
			cout << endl;
			const string grade1 = "grade=";
			const string grade2 = grade1 + to_string(new_grade);
			const char * grade = grade2.c_str();
			UpdateData(mysql, "clerk", grade, lim);
			cout << "Change grade success!" << endl;
			break;
		}
		case 7:
		{
			cout << endl << "Please enter a new attendence: " << endl;
			string new_attendence;
			cin >> new_attendence;
			cout << endl;
			const string attendence1 = "attendence=";
			const string attendence2 = attendence1 + new_attendence;
			const char * attendence = attendence2.c_str();
			UpdateData(mysql, "clerk", attendence, lim);
			cout << "Change attendence success!" << endl;
			break;
		}
		case 8:
		{
			cout << endl << "Please enter a new not_pass_times: " << endl;
			int new_not_pass_times;
			cin >> new_not_pass_times;
			cout << endl;
			const string not_pass_times1 = "not_pass_times=";
			const string not_pass_times2 = not_pass_times1 + to_string(new_not_pass_times);
			const char * not_pass_times = not_pass_times2.c_str();
			UpdateData(mysql, "clerk", not_pass_times, lim);
			cout << "Change not_pass_times success!" << endl;
			break;
		}
		default:
		{
			cout << endl << "Unvalid select number!" << endl;
			break;
		}
	}
}

//初始化
bool ConnectDatabase(MYSQL &mysql)
{
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, "192.168.209.1", "root", "asdjkl11you", "attendence_check", 3306, NULL, 0)) {
		printf("Error connecting to database:%s\n", mysql_error(&mysql));
		return false;
	}
	else {
		mysql_query(&mysql, "set names gbk");
		printf("Connected..\n");
		return true;
	}
}

//插入数据函数
bool InsertData(MYSQL& mysql, const int id, const char *name, const char *department, const char *leader, int record, int grade, const char *attdence)
{
	char insertsql[1024];
	int len = sprintf_s(insertsql, 256, "INSERT INTO table_name values (%d,'%s','%s','%s',%d,%d,'%s');", id, name, department, leader, record, grade, attdence);
	printf("%s\n", insertsql);
	if (len < 0) {
		printf("Insert data failed!\n");
		return false;
	}
	if (mysql_query(&mysql, insertsql) == 0) {
		printf("Insert data success!\n");
		return true;
	}
	else {
		printf("Insert failed (%s)\n", mysql_error(&mysql));
		return false;
	}
}

//选择函数（没有where的情况） 
bool SelectData(MYSQL &mysql, const char *columns_name, const char *table_name)
{
	char querysql[1024];
	int len = sprintf_s(querysql, 256, "SELECT %s FROM %s;", columns_name, table_name);
	printf("%s\n", querysql);
	if (len < 0) {
		printf("Select data failed!\n");
		return false;
	}
	if (mysql_query(&mysql, querysql) == 0) {
		printf("Select data success!\n");
	}
	else {
		printf("Select failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	MYSQL_RES *res;             //返回行的查询结果集
	MYSQL_FIELD *fd;            //字段列数组
	MYSQL_ROW column;
	char field[32][32];

	//查询返回的数据
	res = mysql_store_result(&mysql);

	//打印数据行数
	printf("number of dataline returned:%d\n", mysql_affected_rows(&mysql));
	//获取列数
	int column_num = mysql_num_fields(res);
	//输出选择完的列名称
	for (int i = 0; fd = mysql_fetch_field(res); i++)
		strcpy_s(field[i], strlen(fd->name) + 1, fd->name);

	for (int i = 0; i < column_num; i++)
		printf("%10s\t", field[i]);
	printf("\n");
	//输出每一行的数据
	while (column = mysql_fetch_row(res))
	{
		for (int i = 0; i < column_num; i++)
			printf("%10s\t", column[i]);
		printf("\n");
	}
	return true;
}


//重载查询（有where的情况）
bool SelectData(MYSQL &mysql, const char *columns_name, const char *table_name, const char *limited_info)
{
	char querysql[1024];
	int len = sprintf_s(querysql, 256, "SELECT %s FROM %s WHERE %s;", columns_name, table_name, limited_info);
	printf("%s\n", querysql);
	if (len < 0) {
		printf("Select data failed!\n");
		return false;
	}
	if (mysql_query(&mysql, querysql) == 0) {
		printf("Select data success!\n");
	}
	else {
		printf("Select failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	MYSQL_RES *res;             //返回行的查询结果集
	MYSQL_FIELD *fd;            //字段列数组
	MYSQL_ROW column;
	char field[32][32];

	//查询返回的数据
	res = mysql_store_result(&mysql);

	//打印数据行数
	printf("number of dataline returned:%d\n", mysql_affected_rows(&mysql));
	//获取列数
	int column_num = mysql_num_fields(res);
	//输出选择完的列名称
	for (int i = 0; fd = mysql_fetch_field(res); i++)
		strcpy_s(field[i], strlen(fd->name) + 1, fd->name);

	for (int i = 0; i < column_num; i++)
		printf("%10s\t", field[i]);
	printf("\n");
	//输出每一行的数据
	while (column = mysql_fetch_row(res))                                  //返回结果集中的下一行
	{
		for (int i = 0; i < column_num; i++)
			printf("%10s\t", column[i]);
		printf("\n");
	}
	return true;
}

//修改操作
bool UpdateData(MYSQL &mysql, const char *table_name, const char *modified_info, const char *limitde_info)
{
	char updatesql[1024];
	int len = sprintf_s(updatesql, 256, "UPDATE %s SET %s WHERE %s;", table_name, modified_info, limitde_info);
	printf("%s\n", updatesql);
	if (len < 0) {
		printf("Update data failed!\n");
		return false;
	}
	if (mysql_query(&mysql, updatesql) == 0) {
		printf("Update data success!\n");
		return true;
	}
	else {
		printf("Update failed (%s)\n", mysql_error(&mysql));
		return false;
	}
}

//删除数据函数
bool DeleteData(MYSQL &mysql, const char *table_name, const char *limited_info)
{
	char deletesql[1024];
	int len = sprintf_s(deletesql, 256, "DELETE FROM %s WHERE %s;", table_name, limited_info);
	printf("%s\n", deletesql);
	if (len < 0) {
		printf("Delete data failed!\n");
		return false;
	}
	if (mysql_query(&mysql, deletesql) == 0) {
		printf("Delete data success!\n");
		return true;
	}
	else {
		printf("Delete failed (%s)\n", mysql_error(&mysql));
		return false;
	}
}
