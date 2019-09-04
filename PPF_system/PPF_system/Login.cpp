#include "Login.h"


LPCTSTR LogInWnd::GetWindowClassName() const
{
	return _T("LogInWnd");
}
CDuiString  LogInWnd::GetSkinFile()
{
	return _T("LogInWnd.xml");
}
CDuiString LogInWnd::GetSkinFolder()
{
	return  _T(""); 
}
void LogInWnd::Notify(TNotifyUI& msg)  //duillb库创建的对象的消息进行操作
{
	CDuiString str_name = msg.pSender->GetName();
	if (msg.sType == _T("click"))
	{
		if (str_name == _T("BT_MIN"))
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		else if (str_name == _T("BT_CLOSE"))
			Close();
		else if (str_name == _T("BT_LOGIN"))
			LogIn();
	}
}

void LogInWnd::LogIn()
{
	// 从编辑框中获取用户名和密码
	// 查询数据库，检测该用户是否存在
	// 创建主窗口

	//经过强转
	///通过控件的名字获取到控件操作指针
	CEditUI* pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("USERNAME")); //获取到名字是USEERNAME控件
	//通过控件指针获取控件中的文本
	CDuiString str_user = pEditUserName->GetText();
	CEditUI* pEditUserPassword = (CEditUI*)m_PaintManager.FindControl(_T("PASSWORD"));
	CDuiString str_pwd = pEditUserPassword->GetText();
	if (str_user.IsEmpty())
	{
		MessageBox(NULL, _T("please input user name...\n"), _T("LOGIN"), IDOK);
		return;
	}
	if (str_pwd.IsEmpty())
	{
		MessageBox(NULL, _T("please input password...\n"), _T("LOGIN"), IDOK);
		return;
	}
	
	string s_query("select * from Employee where id = '");
	s_query+=UnicodeToANSI(str_user);
	s_query  += "';";

	vector<vector<string>> Ret = _mysql->Select(s_query);
	
	/*if (MySQL.ResRow != 0
		&& str_user == _T("%s", (*MySQL._ResCon)[0][1].c_str()) 
		&&str_pwd == _T("%s", (*MySQL._ResCon)[0][4].c_str()))*/
	
	if (Ret.size()!=0 && Ret[0][2] == UnicodeToANSI(str_pwd))
	{
		if (strcmp(Ret[0][4].c_str(), "总经理")==0)
		{
			ShowWindow(false);  // 隐藏了窗口

			/*
			根据这两个usrname 和 password，判断是佛能创建主窗口
			*/
			Gmanger mainWnd(_mysql, UnicodeToANSI(str_user));
			mainWnd.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			mainWnd.CenterWindow();  // 窗口居中
			mainWnd.ShowModal();
		}
		else if (strcmp(Ret[0][4].c_str(), "生产经理")==0)
		{
			Pmanger pmanger(_mysql, UnicodeToANSI(str_user));
			pmanger.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			pmanger.CenterWindow();  // 窗口居中
			pmanger.ShowModal();
		}
		else if (strcmp(Ret[0][4].c_str(), "队长") == 0)
		{
			Captain captain(_mysql, UnicodeToANSI(str_user));
			captain.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			captain.CenterWindow();  // 窗口居中
			captain.ShowModal();
		}
		else
		{
			MessageBox(NULL, _T("编码错误，检查数据库编码\n"), _T("LOGIN"), IDOK);
			PostQuitMessage(0); 
		}
	}
	else 
		MessageBox(NULL, _T("用户名或者密码错误，请重新输入\n"), _T("LOGIN"), IDOK);
	
}