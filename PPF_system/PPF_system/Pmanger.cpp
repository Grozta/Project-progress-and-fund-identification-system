#include "Pmanger.h"

LPCTSTR  Pmanger::GetWindowClassName() const
{
	return _T("Pmanger");
}
CDuiString Pmanger::GetSkinFile()
{
	return _T("Pmanger.xml");
}
CDuiString Pmanger::GetSkinFolder()
{
	return _T("");
}

void Pmanger::Notify(TNotifyUI& msg)
{
	//------------获取的而编辑框的内容
	CEditUI* pEditName = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_NAME"));
	CDuiString ED_name = pEditName->GetText();
	CEditUI* pEditSurplus = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_SUR_COUNT"));
	CDuiString ED_surplus = pEditSurplus->GetText();
	CEditUI* pEditBuy = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_BUY_COUNT"));
	CDuiString ED_buy = pEditBuy->GetText();
	CEditUI* pEditPrice = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_PRICE"));
	CDuiString ED_price = pEditPrice->GetText();
	//-------------------------------
	CDuiString str_name = msg.pSender->GetName();
	if (msg.sType == _T("click"))
	{
		if (str_name == _T("BT_MIN"))
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		else if (str_name == _T("BT_CLOSE"))
			PostQuitMessage(0);//Close();  
		else if (str_name == _T("BT_SELECT"))
			MessageBox(NULL, _T("BT_SELECT"), _T("TEST"), IDOK);
		else if (str_name == _T("BT_INSERT"))
			MessageBox(NULL, _T("BT_INSERT"), _T("TEST"), IDOK);
		else if (str_name == _T("BT_CONFIRM"))
			MessageBox(NULL, _T("BT_CONFIRM"), _T("TEST"), IDOK);
		else if (str_name == _T("BT_CANAEL"))
			MessageBox(NULL, _T("BT_CANAEL"), _T("TEST"), IDOK);
	}
}