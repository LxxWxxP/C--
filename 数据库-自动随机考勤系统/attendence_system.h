#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "mysql.h"
using namespace std;

void show_database(MYSQL mysql);//数据库操作系统 
void attendence(MYSQL mysql);//考勤功能 
void change_data(MYSQL mysql);//修改数据功能 
bool ConnectDatabase(MYSQL &mysql);//初始化
bool InsertData(MYSQL& mysql, const int id, const char *name, const char *department, const char *leader, int record, int grade, const char *attdence);//插入数据函数
bool SelectData(MYSQL &mysql, const char *columns_name, const char *table_name);//选择函数,没有where的情况
bool SelectData(MYSQL &mysql, const char *columns_name, const char *table_name, const char *limited_info);//重载有where的情况
bool UpdateData(MYSQL &mysql, const char *table_name, const char *modified_info, const char *limitde_info);//修改操作
bool DeleteData(MYSQL &mysql, const char *table_name, const char *limited_info);//删除数据函数
