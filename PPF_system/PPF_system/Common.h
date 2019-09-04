#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <mysql.h>
#include <vector>
#include <string>
#include "UIlib.h"

using namespace DuiLib;
#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif
#define  _CRT_SECURE_NO_WARNINGS


using namespace std;
CDuiString ANSIToUnicode(const string& str);
string UnicodeToANSI(const CDuiString& str);
