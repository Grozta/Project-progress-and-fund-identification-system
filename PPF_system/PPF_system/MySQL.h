#pragma once
#include "Common.h"
class MySQL
{
public:
	MySQL();
	bool ConnectMySql(const char* host = "127.0.0.1", // 主机名称
		const char* user="root", // 用户名
		const char* passward = "hjc857916", // 密码
		const char* dbName = "ppf_system", // 数据库名
		int port = 3306); // 端口号：默认为3306
	~MySQL();
	bool Insert(const string& strSQL);
	bool Delete(const string& strSQL);
	bool Update(const string& strSQL);
	size_t GetCount(const string& strSQL);
	vector<vector<string>> Select(const string& strSQL);
	// 切换数据库
	bool SelectDB(const string& daName);
private:
	MYSQL* _mySql; // mysql连接的实例对象
	string _dbName;
	vector<string> _tables;
};
