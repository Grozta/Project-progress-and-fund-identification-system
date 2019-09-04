#pragma  once
#include "Common.h"
#include "MySQL.h"



class Gmanger :public WindowImplBase
{
public:
	Gmanger(MySQL* mysql,string useid) :_mysql(mysql), _useid(useid)
	{}
	void BT_SELECT_FUNC(string& id, string& name, string& tel, string& pos, string& sub_Project, string& mag_Project, string& pay_Method, string& superior, string& CHOOSE, string& pwd, string& pwd_confirm);
	void BT_INSERT_FUNC(string& id, string& name, string& tel, string& pos, string& sub_Project, string& mag_Project, string& pay_Method, string& superior, string& CHOOSE, string& pwd, string& pwd_confirm);
	void BT_DELETE_FUNC();
	void UpDataListDisplay(vector<vector<string>>& Ret);
	void UpDataListDisplay_1(vector<vector<string>>& ret);
	void UpDataListDisplay_2(vector<vector<string>>& ret);
	void UpDataListDisplay_3(vector<vector<string>>& ret);
	
	void BT_AGREE_1_FUNC();
	void BT_AGAINST_1_FUNC();
	void BT_CREATE_2_FUNC(string id_1, string name_1, string producter_1, string captain_1, string cRate_1, string usedFund_1,string  totalFund_1);
	void BT_DELETE_2_FUNC();
	protected:
	// WindowImpBase这个类的必须的纯虚函数
	//  窗口类的名字
	virtual LPCTSTR    GetWindowClassName() const;
    // xml文件对应的文件名
	virtual CDuiString GetSkinFile();
	//xml文件对应的目录
	virtual CDuiString GetSkinFolder();
public:
	virtual void	   Notify(TNotifyUI& msg);
private:
	MySQL* _mysql;
	string  _useid;
};