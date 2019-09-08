#pragma once
#include "Common.h"
class MySQL
{
public:
	MySQL();
	bool ConnectMySql(const char* host = "127.0.0.1", // ��������
		const char* user="root", // �û���
		const char* passward = "hjc857916", // ����
		const char* dbName = "ppf_system", // ���ݿ���
		int port = 3306); // �˿ںţ�Ĭ��Ϊ3306
	~MySQL();
	bool Insert(const string& strSQL);
	bool Delete(const string& strSQL);
	bool Update(const string& strSQL);
	size_t GetCount(const string& strSQL);
	vector<vector<string>> Select(const string& strSQL);
	// �л����ݿ�
	bool SelectDB(const string& daName);
private:
	MYSQL* _mySql; // mysql���ӵ�ʵ������
	string _dbName;
	vector<string> _tables;
};
