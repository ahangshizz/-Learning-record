#pragma once
#include <iostream>
#include <WinSock2.h>
#include <mysql.h>
#include <string>
#include <vector>
#include "pch.cpp"
using namespace std;
class MySQL {
public:
	MySQL();
	//�������ݿ�
	bool ConnectionMySql(const char* host,const char* user,const char* passward,const char* dbName,int port=3306);
	~MySQL();
	//��������
	bool Insert(const string& strSQL);
	//ɾ������
	bool Delete(const string& strSQL);
	//�޸�����
	bool Update(const string& strSQL);
	size_t GetCount(const string& strSQL);
	//����
	vector<vector<string>> Select(const string& strSQL);

	//�л����ݿ�
	bool SelectDB(const string& daName);
private:
	MYSQL* _mysql;
	string _dbName;
	vector<string> _tables;
};