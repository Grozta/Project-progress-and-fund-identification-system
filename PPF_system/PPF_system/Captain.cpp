#include "Captain.h"

LPCTSTR  Captain::GetWindowClassName() const
{
	return _T("Captain");
}
CDuiString Captain::GetSkinFile()
{
	return _T("Captain.xml");
}
CDuiString Captain::GetSkinFolder()
{
	return _T("");
}

void Captain::Notify(TNotifyUI& msg)
{

}