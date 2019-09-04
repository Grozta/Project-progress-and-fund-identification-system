#pragma  once
#include "Common.h"
#include "MySQL.h"

class Captain :public WindowImplBase
{
public:
	Captain(MySQL* mysql, string useid) :_mysql(mysql), _useid(useid)
	{}
	void BT_SELECT_FUNC();
	void BT_INSERT_FUNC();
	void BT_UPDATE_FUNC();
	void BT_DELETE_FUNC();
	void BT_SALE_FUNC();
	void UpDataListDisplay(vector<vector<string>>& Ret);
protected:
	virtual LPCTSTR    GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
public:
	virtual void	   Notify(TNotifyUI& msg);
private:
	MySQL* _mysql;
	string  _useid;
};