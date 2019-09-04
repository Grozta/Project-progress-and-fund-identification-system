#pragma  once
#include "Common.h"
#include "MySQL.h"
#include "Gmanger.h"
#include "Captain.h"
#include "Pmanger.h"

class LogInWnd:public WindowImplBase
{
public:
	LogInWnd(MySQL* mysql) :_mysql(mysql)
	{}
protected:
	virtual LPCTSTR    GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
public:
	virtual void	   Notify(TNotifyUI& msg);
	void LogIn();
private:
	MySQL* _mysql;
};