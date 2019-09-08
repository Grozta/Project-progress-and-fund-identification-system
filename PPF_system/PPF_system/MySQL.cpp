#include "MySQL.h"
MySQL::MySQL()
{
	// ��ʼ��mySql
	_mySql = mysql_init(nullptr);
}
bool MySQL::ConnectMySql(const char* host, const char* user, const char* passward , const char* dbName  , int port)
{
	// ����mySql���ݿ�
	if (!mysql_real_connect(_mySql, host, user, passward, dbName, port, NULL, 0))
	{
		MessageBox(NULL, _T("kkk"), _T("kkk"), IDOK);
		return false;
	}
	/*
	c++����mysqlʱ�������ѯ����к������ģ����ߵõ�����к������ģ��������ֱ�������������
	�⡣
	VS������Ĭ��ʹ��gbk���롣
	�����mysql����Ϊutf-8���룬����Ҫ�Ƚ�c++�еĸ��������ַ���תΪutf-8��������mysql���õ�
	�Ľ��Ϊutf-8���룬��ҪתΪgbk����������ʾ��ת��תȥ���鷳��
	*/
	//mysql_query(_mySql, "set names 'gbk'");
	return true;
}
bool MySQL::SelectDB(const string& dbName)
{
	if (mysql_select_db(_mySql, dbName.c_str()))
	{
		return false;
	}
	return true;
}
bool MySQL::Insert(const string& strSql)
{
	// ִ��sql���
	if (mysql_query(_mySql, strSql.c_str()))
	{
		return false;
	}
	return true;
}
bool MySQL::Update(const string& strSQL)
{
	// ִ��sql���
	if (mysql_query(_mySql, strSQL.c_str()))
	{
		return false;
	}
	return true;
}
vector<vector<string>> MySQL::Select(const string& sql)
{
	vector<vector<string>> vRet;
	// ָ��ָ��SQL���
	if (mysql_query(_mySql, sql.c_str()))     // TODO
	{
		string vsRet(mysql_error(_mySql));
		return vRet;
	}
	// �������������ݼ����ͻ���
	MYSQL_RES *res = mysql_store_result(_mySql);
	if (res == NULL)
	{
		return vRet;
	}
	// ���������������е���Ϣ
	MYSQL_ROW rows;
	// ��������ܹ��ж���������
	int num_fields = mysql_num_fields(res);
	while (rows = mysql_fetch_row(res))
	{
		int i = 0;
		vector<string> vItem;
		vItem.resize(num_fields);
		for (i = 0; i < num_fields; i++)
		{
			if (rows[i] == nullptr ) continue;
			else vItem[i] = rows[i];
		}
		
		vRet.push_back(vItem);
	}
	const char* str = mysql_error(_mySql);
	mysql_free_result(res);
	return vRet;
}
size_t MySQL::GetCount(const string& strSQL)
{
	// ָ��ָ��SQL���
	if (mysql_query(_mySql, strSQL.c_str()))
	{
		return 0;
	}
	// �������������ݼ����ͻ���
	MYSQL_RES *res = mysql_store_result(_mySql);
	if (res == NULL)
	{
		return 0;
	}
	return mysql_num_fields(res);
}
bool MySQL::Delete(const string& strSQL)
{
	// ִ��sql���
	if (mysql_query(_mySql, strSQL.c_str()))
	{
		return false;
	}
	return true;
}
MySQL::~MySQL()
{
	mysql_close(_mySql);
}