#pragma  once
#include "Common.h"
#include "MySQL.h"
class Pmanger :public WindowImplBase
{
public:
	Pmanger(MySQL* mysql,string useid) :_mysql(mysql), _useid(useid)
	{}
	virtual void	   Notify(TNotifyUI& msg);
protected:
	virtual LPCTSTR    GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
private:
	MySQL* _mysql;
	string  _useid;
};