#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "mysql.h"
using namespace std;

void show_database(MYSQL mysql);//���ݿ����ϵͳ 
void attendence(MYSQL mysql);//���ڹ��� 
void change_data(MYSQL mysql);//�޸����ݹ��� 
bool ConnectDatabase(MYSQL &mysql);//��ʼ��
bool InsertData(MYSQL& mysql, const int id, const char *name, const char *department, const char *leader, int record, int grade, const char *attdence);//�������ݺ���
bool SelectData(MYSQL &mysql, const char *columns_name, const char *table_name);//ѡ����,û��where�����
bool SelectData(MYSQL &mysql, const char *columns_name, const char *table_name, const char *limited_info);//������where�����
bool UpdateData(MYSQL &mysql, const char *table_name, const char *modified_info, const char *limitde_info);//�޸Ĳ���
bool DeleteData(MYSQL &mysql, const char *table_name, const char *limited_info);//ɾ�����ݺ���
