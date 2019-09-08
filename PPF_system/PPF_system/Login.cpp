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
void LogInWnd::Notify(TNotifyUI& msg)  //duillb�ⴴ���Ķ������Ϣ���в���
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
	// �ӱ༭���л�ȡ�û���������
	// ��ѯ���ݿ⣬�����û��Ƿ����
	// ����������

	//����ǿת
	///ͨ���ؼ������ֻ�ȡ���ؼ�����ָ��
	CEditUI* pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("USERNAME")); //��ȡ��������USEERNAME�ؼ�
	//ͨ���ؼ�ָ���ȡ�ؼ��е��ı�
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
		if (strcmp(Ret[0][4].c_str(), "�ܾ���")==0)
		{
			ShowWindow(false);  // �����˴���

			/*
			����������usrname �� password���ж��Ƿ��ܴ���������
			*/
			Gmanger mainWnd(_mysql, UnicodeToANSI(str_user));
			mainWnd.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			mainWnd.CenterWindow();  // ���ھ���
			mainWnd.ShowModal();
		}
		else if (strcmp(Ret[0][4].c_str(), "��������")==0)
		{
			Pmanger pmanger(_mysql, UnicodeToANSI(str_user));
			pmanger.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			pmanger.CenterWindow();  // ���ھ���
			pmanger.ShowModal();
		}
		else if (strcmp(Ret[0][4].c_str(), "�ӳ�") == 0)
		{
			Captain captain(_mysql, UnicodeToANSI(str_user));
			captain.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			captain.CenterWindow();  // ���ھ���
			captain.ShowModal();
		}
		else
		{
			MessageBox(NULL, _T("������󣬼�����ݿ����\n"), _T("LOGIN"), IDOK);
			PostQuitMessage(0); 
		}
	}
	else 
		MessageBox(NULL, _T("�û������������������������\n"), _T("LOGIN"), IDOK);
	
}