#include "MySQL.h"

MySQL::MySQL() {
	//��ʼ��mysql
	_mysql = mysql_init(nullptr);
}

bool MySQL::ConnectionMySql(const char* host, const char* user, const char* passward, const char* dbName, int port) {
	//����mysql
	if (!mysql_real_connect(_mysql, host, user, passward, dbName, port, NULL, 0)) {
		return false;
	}
	/*
		���mysql������ʾ��������
	*/
	mysql_query(_mysql, "set names 'gbk'");

	return true;
}


bool MySQL::Insert(const string& strSql) {
	//ִ��sql���
	if (mysql_query(_mysql, strSql.c_str())) {
		return false;
	}
	return true;
}

bool MySQL::Update(const string& strSQL) {
	if (mysql_query(_mysql, strSQL.c_str()))
		return false;
	return true;
}

vector<vector<string>> MySQL::Select(const string& sql) {
	vector<vector<string>> vRet;
	if (mysql_query(_mysql, sql.c_str())) {
		string vsRet(mysql_error(_mysql));
		return vRet;
	}
	//������������ݼ����ͻ���
	MYSQL_RES* res = mysql_store_result(_mysql);
	if (res == NULL) {
		return vRet;
	}
	//���������������е���Ϣ
	MYSQL_ROW rows;

	//��������ܹ�����������

	int num_fields = mysql_num_fields(res);
	while (rows = mysql_fetch_row(res)) {
		int i = 0;
		vector<string> vItem;
		vItem.resize(num_fields);
		for (i = 0; i < num_fields; ++i) {
			vItem[i] = rows[i];
		}
		vRet.push_back(vItem);
	}
	const char* str = mysql_error(_mysql);
	mysql_free_result(res);
	return vRet;
}

size_t MySQL::GetCount(const string& strSQL) {
	//ָ��SQL���
	if (mysql_query(_mysql, strSQL.c_str())) {
		return 0;
	}
	//�������������ݼ����ͻ���
	MYSQL_RES* res = mysql_store_result(_mysql);
	if (res == NULL) {
		return 0;
	}
	return mysql_num_fields(res);
}

bool MySQL::Delete(const string& strSQL) {
	if (mysql_query(_mysql, strSQL.c_str()))
		return false;
	return true;
}

MySQL::~MySQL() {
	mysql_close(_mysql);
}