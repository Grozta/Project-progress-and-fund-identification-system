#include "Gmanger.h"

//  �����������    ���ڴ��麯�������������ں�����ǰ��virtual�����ⶨ���ʱ���ܼ�virtual�����Ǻ���ǰҪ��������
LPCTSTR Gmanger::GetWindowClassName() const
{
	return _T("Gmanger");
}
// xml�ļ���Ӧ���ļ���
CDuiString  Gmanger::GetSkinFile()
{
	return _T("Gmanger.xml");
}
//xml�ļ���Ӧ��Ŀ¼
CDuiString Gmanger::GetSkinFolder()
{
	return  _T(""); // �⽫�������г������ڵ��ļ�����Ѱ��
}
void Gmanger::BT_SELECT_FUNC(string& id, string& name, string& tel, string& pos, string& sub_Project, string& mag_Project, string& pay_Method, string& superior, string& CHOOSE, string& pwd, string& pwd_confirm)
{
	if (strcmp(CHOOSE.c_str(), "ALL") == 0)
	{
		string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior ,pwd from Employee";
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay(Ret);
	}
	if (strcmp(CHOOSE.c_str(), "�˺�") == 0)
	{
		string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior,pwd from Employee where id = '";
		s_query_all = s_query_all + id + "';";
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay(Ret);
	}
	if (strcmp(CHOOSE.c_str(), "����") == 0)
	{
		string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior,pwd from Employee where name = '";
		s_query_all = s_query_all + name + "';";
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay(Ret);
	}
	if (strcmp(CHOOSE.c_str(), "�绰") == 0)
	{
		string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior,pwd from Employee where tel = '";
		s_query_all = s_query_all + tel + "';";
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay(Ret);
	}
	if (strcmp(CHOOSE.c_str(), "ְλ") == 0)
	{
		string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior,pwd from Employee where pos = '";
		s_query_all = s_query_all + pos + "';";
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay(Ret);
	}
	if (strcmp(CHOOSE.c_str(), "������Ŀ") == 0)
	{
		string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior,pwd from Employee where sub_Project = '";
		s_query_all = s_query_all + sub_Project + "';";
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay(Ret);
	}
	if (strcmp(CHOOSE.c_str(), "������Ŀ") == 0)
	{
		string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior,pwd from Employee where mag_Project = '";
		s_query_all = s_query_all + mag_Project + "';";
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay(Ret);
	}
	if (strcmp(CHOOSE.c_str(), "֧����ʽ") == 0)
	{
		string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior,pwd from Employee where pay_Method = ";
		s_query_all = s_query_all + pay_Method + ";";
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay(Ret);
	}
	if (strcmp(CHOOSE.c_str(), "�ϼ��쵼") == 0)
	{
		string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior,pwd from Employee where superior = ";
		s_query_all = s_query_all + superior + ";";
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay(Ret);
	}
}
void Gmanger::BT_INSERT_FUNC(string& id, string& name, string& tel, string& pos, string& sub_Project, string& mag_Project, string& pay_Method, string& superior, string& CHOOSE, string& pwd, string& pwd_confirm)
{
	if ((pwd.empty()) || pwd != pwd_confirm)
	{
		MessageBox(NULL, _T("����������������������"), _T("����"), IDOK);
		return;
	}
	if (id.empty() || name.empty() || tel.empty() || pos.empty() || sub_Project.empty()||mag_Project.empty()||pay_Method.empty()||superior.empty())
	{
		MessageBox(NULL, _T("��Ϣ¼�벻����������������"), _T("����"), IDOK);
		return;
	}
	string s_query_all = "insert into Employee values(";
	s_query_all = s_query_all + id + ",'" + name + "','" + pwd + "'," + tel + ",'" + pos + "','" + sub_Project + "','" + mag_Project +"','"+ pay_Method + "','" + superior + "');";
	if (_mysql->Insert(s_query_all)) MessageBox(NULL, _T("����ɹ�"), _T("����"), IDOK);
	else MessageBox(NULL, _T("���ݿ����ʧ�ܣ������������ʽ��������������"), _T("����"), IDOK);
	s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior,pwd from Employee;";
	vector<vector<string>> Ret = _mysql->Select(s_query_all);
	UpDataListDisplay(Ret);
}

void Gmanger::BT_DELETE_FUNC()
{
	CDuiString str;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("List")));
	int num = pList->GetCurSel();
	CListTextElementUI* elem = (CListTextElementUI*)pList->GetItemAt(num); //��ȡһ�е�����
	str = elem->GetText(1);  //��ȡһ�����±�Ϊ0��Ԫ��
	string del = UnicodeToANSI(str);
	del = "delete from employee where id ='" + del + "';";
	if (!_mysql->Delete(del)) MessageBox(NULL, _T("ɾ��ʧ�ܣ�����������ɾ��"), _T("����"), IDOK);
	pList->RemoveAt(num);
	string s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior ,pwd from Employee;";
	vector<vector<string>> Ret = _mysql->Select(s_query_all);
	UpDataListDisplay(Ret);
}
/*void Gmanger::BT_SELECT_1_FUNC(string choose_1)
{
	if (strcmp(choose_1.c_str(), "��Ŀ�ſ�") == 0)
	{
		string s_query_all = "select project_Number,project_Name,product_Manger,captain,completion_Rate,used_Fund,total_Project from Project_status;";
	
		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay_1(Ret);
	}
	else if (strcmp(choose_1.c_str(), "ȫ�����") == 0)
	{
		string s_query_all = "select name,id,pos,sub_Project,project_Number,review_Status,curApply_Fund, reviewer ,completion_Rate from product_and_project;";

		vector<vector<string>> Ret = _mysql->Select(s_query_all);
		if (Ret.size() == 0)
		{
			MessageBox(NULL, _T("�����ڲ�ѯ���"), _T("����"), IDOK);
			return;
		}
		UpDataListDisplay_2(Ret);
	}
}
*/
void Gmanger::BT_AGREE_1_FUNC() // TODO 1
{
	CDuiString str;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("List_1")));
	int num = pList->GetCurSel();
	CListTextElementUI* elem = (CListTextElementUI*)pList->GetItemAt(num); //��ȡһ�е�����
	str = elem->GetText(1);  //��ȡһ�����±�Ϊ0��Ԫ��
	string agree = UnicodeToANSI(str);
	// update Product_And_Project set review_Status = 'ͬ��' where serial_num = 2;
	agree = " update Product_And_Project set review_Status = 'ͬ��' where serial_num =" + agree + ";";
	if (!_mysql->Insert(agree)) MessageBox(NULL, _T("����ʧ�ܣ����������²���"), _T("����"), IDOK);
	else  MessageBox(NULL, _T("���ݿ���³ɹ���"), _T("����"), IDOK);
	pList->RemoveAt(num);
	string s_query_all = "select  serial_num,name,id,pos,sub_Project,project_Number,review_Status,curApply_Fund, reviewer ,completion_Rate from product_and_project;";
	vector<vector<string>> Ret = _mysql->Select(s_query_all);
	UpDataListDisplay_1(Ret);
}
void Gmanger::BT_AGAINST_1_FUNC()
{
	CDuiString str;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("List_1")));
	int num = pList->GetCurSel();
	CListTextElementUI* elem = (CListTextElementUI*)pList->GetItemAt(num); //��ȡһ�е�����
	str = elem->GetText(1);  //��ȡһ�����±�Ϊ0��Ԫ��
	string agree = UnicodeToANSI(str);
	// update Product_And_Project set review_Status = 'ͬ��' where serial_num = 2;
	agree = " update Product_And_Project set review_Status = '��ͬ��' where serial_num =" + agree + ";";
	if (!_mysql->Insert(agree)) MessageBox(NULL, _T("����ʧ�ܣ����������²���"), _T("����"), IDOK);
	else  MessageBox(NULL, _T("���ݿ���³ɹ���"), _T("����"), IDOK);
	pList->RemoveAt(num);
	string s_query_all = "select  serial_num,name,id,pos,sub_Project,project_Number,review_Status,curApply_Fund, reviewer ,completion_Rate from product_and_project;";
	vector<vector<string>> Ret = _mysql->Select(s_query_all);
	UpDataListDisplay_1(Ret);
}
void Gmanger::BT_CREATE_2_FUNC(string id_1, string name_1, string producter_1, string captain_1, string cRate_1, string usedFund_1, string  totalFund_1)
{
	
	if (id_1.empty() || name_1.empty() || producter_1.empty() || captain_1.empty() || cRate_1.empty() || usedFund_1.empty() || totalFund_1.empty())
	{
		MessageBox(NULL, _T("��Ϣ¼�벻����������������"), _T("����"), IDOK);
		return;
	}
	char s[1024];
	sprintf(s, "insert into Project_status values(%s,'%s','%s','%s',%s,%s,%s);", id_1.c_str(), name_1.c_str(), producter_1.c_str(), captain_1.c_str(), cRate_1.c_str(), usedFund_1.c_str(), totalFund_1.c_str());
	string s_query_all(s);
	if (_mysql->Insert(s_query_all)) MessageBox(NULL, _T("����ɹ�"), _T("����"), IDOK);
	else MessageBox(NULL, _T("���ݿ����ʧ�ܣ������������ʽ��������������"), _T("����"), IDOK);
	s_query_all = "select project_Number,project_Name,product_Manger,captain,completion_Rate,used_Fund,total_Project from Project_status;";
	vector<vector<string>> Ret = _mysql->Select(s_query_all);
	UpDataListDisplay_2(Ret);
}
void Gmanger::BT_DELETE_2_FUNC()
{
	CDuiString str;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("List_2")));
	int num = pList->GetCurSel();
	CListTextElementUI* elem = (CListTextElementUI*)pList->GetItemAt(num); //��ȡһ�е�����
	str = elem->GetText(1);  //��ȡһ�����±�Ϊ0��Ԫ��
	string del = UnicodeToANSI(str);
	del = "delete from Project_status where project_Number =" + del + ";";
	if (!_mysql->Delete(del)) MessageBox(NULL, _T("ɾ��ʧ�ܣ�����������ɾ��"), _T("����"), IDOK);
	else  MessageBox(NULL, _T("���ݿ�ɾ���ɹ���"), _T("����"), IDOK);
	pList->RemoveAt(num);
	string s_query_all = "select project_Number,project_Name,product_Manger,captain,completion_Rate,used_Fund,total_Project from Project_status;";
	vector<vector<string>> Ret = _mysql->Select(s_query_all);
	UpDataListDisplay_2(Ret);
}
void Gmanger::UpDataListDisplay(vector<vector<string>>& ret)
{

	CDuiString str;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("List")));// ���List�б����ݣ�������Add(pListElement)����SetText
	pList->RemoveAll();
	for (int i = 0; i < ret.size(); i++)
	{
		CListTextElementUI* pListElement = new CListTextElementUI;
		pListElement->SetTag(i);
		pList->Add(pListElement);

		str.Format(_T("%d"), i);
		pListElement->SetText(0, str);

		for (int j = 1; j <= ret[0].size(); j++)
		{
			str = ANSIToUnicode(ret[i][j - 1]);
			pListElement->SetText(j, str);
			//		MessageBox(NULL, str, _T("��ʾ"), IDOK);
		}
	}
}
void Gmanger::UpDataListDisplay_1(vector<vector<string>>& ret)
{

	CDuiString str;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("List_1")));// ���List�б����ݣ�������Add(pListElement)����SetText
	pList->RemoveAll();
	for (int i = 0; i < ret.size(); i++)
	{
		CListTextElementUI* pListElement = new CListTextElementUI;
		pListElement->SetTag(i);
		pList->Add(pListElement);

		str.Format(_T("%d"), i);
		pListElement->SetText(0, str);

		for (int j = 1; j <= ret[0].size(); j++)
		{
			//str.Format(_T("%s"), ret[i][j-1].c_str());
			str = ANSIToUnicode(ret[i][j - 1]);
			pListElement->SetText(j, str);
		}
	}
}
void Gmanger::UpDataListDisplay_2(vector<vector<string>>& ret)
{

	CDuiString str;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("List_2")));// ���List�б����ݣ�������Add(pListElement)����SetText
	pList->RemoveAll();
	for (int i = 0; i < ret.size(); i++)
	{
		CListTextElementUI* pListElement = new CListTextElementUI;
		pListElement->SetTag(i);
		pList->Add(pListElement);

		str.Format(_T("%d"), i);
		pListElement->SetText(0, str);

		for (int j = 1; j <= ret[0].size(); j++)
		{
			//str.Format(_T("%s"), ret[i][j-1].c_str());
			str = ANSIToUnicode(ret[i][j - 1]);
			pListElement->SetText(j, str);
		}
	}
}
void Gmanger::UpDataListDisplay_3(vector<vector<string>>& ret)
{

	CDuiString str;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("List_3")));// ���List�б����ݣ�������Add(pListElement)����SetText
	pList->RemoveAll();
	for (int i = 0; i < ret.size(); i++)
	{
		CListTextElementUI* pListElement = new CListTextElementUI;
		pListElement->SetTag(i);
		pList->Add(pListElement);

		str.Format(_T("%d"), i);
		pListElement->SetText(0, str);

		for (int j = 1; j <= ret[0].size(); j++)
		{
			//str.Format(_T("%s"), ret[i][j-1].c_str());
			str = ANSIToUnicode(ret[i][j - 1]);
			pListElement->SetText(j, str);
		}
	}
}
void Gmanger::Notify(TNotifyUI& msg)  // �������ɣ����ǵ�ÿһ�������������һ��ѭ�������ǵ�ÿһ���������������������Ϣѭ���У�ִ�д���
{
	//------------��ȡ�ı༭�������
	CEditUI* pEditId = (CEditUI*)m_PaintManager.FindControl(_T("id"));
	CDuiString ED_id = pEditId->GetText();
	string id = UnicodeToANSI(ED_id);
	CEditUI* pEditName = (CEditUI*)m_PaintManager.FindControl(_T("name"));
	CDuiString ED_name = pEditName->GetText();
	string name = UnicodeToANSI(ED_name);
	CEditUI* pEditTel = (CEditUI*)m_PaintManager.FindControl(_T("tel"));
	CDuiString ED_tel = pEditTel->GetText();
	string tel = UnicodeToANSI(ED_tel);
	CEditUI* pEditSProject = (CEditUI*)m_PaintManager.FindControl(_T("sub_Project"));
	CDuiString ED_s_project = pEditSProject->GetText();
	string sub_Project = UnicodeToANSI(ED_s_project);
	CEditUI* pEditMProject = (CEditUI*)m_PaintManager.FindControl(_T("mag_Project"));
	CDuiString ED_m_project = pEditMProject->GetText();
	string mag_Project = UnicodeToANSI(ED_m_project);
	CEditUI* pEditsup = (CEditUI*)m_PaintManager.FindControl(_T("superior"));
	CDuiString ED_sup = pEditsup->GetText();
	string  superior = UnicodeToANSI(ED_sup);
	CEditUI* pEditPwd = (CEditUI*)m_PaintManager.FindControl(_T("pwd"));
	CDuiString ED_pwd = pEditPwd->GetText();
	string  pwd = UnicodeToANSI(ED_pwd);
	CEditUI* pEditPwdC = (CEditUI*)m_PaintManager.FindControl(_T("pwd_confirm"));
	CDuiString ED_pwd_c = pEditPwdC->GetText();
	string  pwd_confirm = UnicodeToANSI(ED_pwd_c);


	CEditUI* pEditId_1 = (CEditUI*)m_PaintManager.FindControl(_T("id_1"));
	CDuiString ED_id_1 = pEditId_1->GetText();
	string id_1 = UnicodeToANSI(ED_id_1);
	CEditUI* pEditName_1 = (CEditUI*)m_PaintManager.FindControl(_T("name_1"));
	CDuiString ED_name_1 = pEditName_1->GetText();
	string name_1 = UnicodeToANSI(ED_name_1);
	CEditUI* pEditPd_1 = (CEditUI*)m_PaintManager.FindControl(_T("producter_1"));
	CDuiString ED_pd_1 = pEditPd_1->GetText();
	string  producter_1 = UnicodeToANSI(ED_pd_1);
	CEditUI* pEditCp_1 = (CEditUI*)m_PaintManager.FindControl(_T("captain_1"));
	CDuiString ED_cp_1 = pEditCp_1->GetText();
	string  captain_1 = UnicodeToANSI(ED_cp_1);
	CEditUI* pEditCr_1 = (CEditUI*)m_PaintManager.FindControl(_T("cRate_1"));
	CDuiString ED_cr_1 = pEditCr_1->GetText();
	string  cRate_1 = UnicodeToANSI(ED_cr_1);
	CEditUI* pEditUf_1 = (CEditUI*)m_PaintManager.FindControl(_T("usedFund_1"));
	CDuiString ED_uf_1 = pEditUf_1->GetText();
	string  usedFund_1 = UnicodeToANSI(ED_uf_1);
	CEditUI* pEditTf_1 = (CEditUI*)m_PaintManager.FindControl(_T("totalFund_1"));
	CDuiString ED_tf_1 = pEditTf_1->GetText();
	string  totalFund_1 = UnicodeToANSI(ED_tf_1);

	//------------��ȡ�Ķ���ѡ�������
	CComboBoxUI* pCOM_pos = (CComboBoxUI*)m_PaintManager.FindControl(_T("pos"));
	CDuiString COM_pos = pCOM_pos->GetText();
	string pos = UnicodeToANSI(COM_pos);
	CComboBoxUI* pCOMPMethod = (CComboBoxUI*)m_PaintManager.FindControl(_T("pay_Method"));
	CDuiString COM_p_method = pCOMPMethod->GetText();
	string pay_Method = UnicodeToANSI(COM_p_method);
	CComboBoxUI* pCOM_CHOOSE = (CComboBoxUI*)m_PaintManager.FindControl(_T("CHOOSE"));
	CDuiString COM_CHOOSE = pCOM_CHOOSE->GetText();
	string CHOOSE = UnicodeToANSI(COM_CHOOSE);
	
	
	//-------------------------------

	CDuiString str_name = msg.pSender->GetName(); 
	if (msg.sType == _T("click")) //����Ŀؼ������ǵ������Ӧ���ǰ�ť�ؼ�
	{
		if (str_name == _T("BT_MIN"))
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		else if (str_name == _T("BT_CLOSE"))
			PostQuitMessage(0);//Close(); ���������PostQuitMessage�ٴη�װ��������PostQuitMessage
		else if (str_name == _T("BT_SELECT"))
			BT_SELECT_FUNC(id, name, tel, pos, sub_Project, mag_Project, pay_Method, superior,CHOOSE,pwd,pwd_confirm);
		else if (str_name == _T("BT_INSERT"))
			BT_INSERT_FUNC(id, name, tel, pos, sub_Project, mag_Project, pay_Method, superior, CHOOSE, pwd, pwd_confirm); 
		else if (str_name == _T("BT_DELETE"))
			BT_DELETE_FUNC();
		
		else if (str_name == _T("BT_AGREE_1"))
			BT_AGREE_1_FUNC();
		else if (str_name == _T("BT_AGAINST_1"))
			BT_AGAINST_1_FUNC();
		else if (str_name == _T("BT_CREATE_PROJECT_1"))
			BT_CREATE_2_FUNC(id_1,name_1,producter_1,captain_1,cRate_1,usedFund_1,totalFund_1);
		else if (str_name == _T("BT_DELETE_PROJECT_1"))
			BT_DELETE_2_FUNC();
	}
	// else if (msg.sType == _T("itemselect"))  //����Ŀؼ�������ѡ�񣬶�Ӧ�Ŀؼ���ѡ���  TODO 2 ?������Ͷ��Ƕ�Ӧ��ʲô������
	else if (msg.sType == _T("selectchanged"))
	{
		CTabLayoutUI* pTab = (CTabLayoutUI*)m_PaintManager.FindControl(_T("TabLayOut"));
		if (str_name == _T("OPTION_EMPLOYEE"))
		{
			pTab->SelectItem(0);
			string s_query_all("select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior ,pwd from Employee;");
			vector<vector<string>> ret = _mysql->Select(s_query_all);
			UpDataListDisplay(ret);
			
		}
		else if (str_name == _T("OPTION_AUDIT"))
		{
			pTab->SelectItem(1); 
			
			string s_query_all("select  serial_num,name,id,pos,sub_Project,project_Number,review_Status,curApply_Fund, reviewer ,completion_Rate from product_and_project;");
			vector<vector<string>> ret = _mysql->Select(s_query_all);
			UpDataListDisplay_1(ret);
			

		}
		else if (str_name == _T("OPTION_MANAGE"))
		{
			pTab->SelectItem(2);
			string s_query_all = "select project_Number,project_Name,product_Manger,captain,completion_Rate,used_Fund,total_Project from Project_status;";
			vector<vector<string>> ret = _mysql->Select(s_query_all);
			UpDataListDisplay_2(ret);
		}
		else if (str_name == _T("OPTION_PROCESS"))
		{
			pTab->SelectItem(3);
			string s_query_all = "select applyer_Name ,applyer_Id ,applyer_Pos ,project_Number ,project_Name ,header ,cur_Amount_Work ,completion_Rate ,cur_Apply_Fund  from Project_Details; ";
			vector<vector<string>> ret = _mysql->Select(s_query_all);
			UpDataListDisplay_3(ret);

		}
		
	}
	else if (msg.sType == _T("windowinit"))//���ڴ�����ʼ���ڼ�������ó�ʼ��
	{
		CLabelUI* pLabel = (CLabelUI*)m_PaintManager.FindControl(_T("HLOG"));
		char tmp[1024];
		string s_query_all("select name ,id, pos from employee where id = ");
		s_query_all = s_query_all + _useid + ";";
		vector<vector<string>> res = _mysql->Select(s_query_all);
		sprintf(tmp, "��ǰ�û�[ ����:%s  ���ţ�%s  ְλ��%s ]",res[0][0].c_str(),res[0][1].c_str(),res[0][2].c_str());
		string display(tmp);
		pLabel->SetText(ANSIToUnicode(display));

		s_query_all = "select id,name,tel,pos,sub_Project,mag_Project,pay_Method, superior ,pwd from Employee;";
		vector<vector<string>> ret = _mysql->Select(s_query_all);
		UpDataListDisplay(ret);

	}
}