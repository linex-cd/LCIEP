
/***********************************************************************/
/*                                                                     */
/*	Description: Linex custom IE Protocol Interface                    */
/*	Wrote by   : Linex                                                 */
/*	QQ         : 909090185                                             */
/*	E-mail     : www@loginar.com                                       */
/*	Update Data: 2012/11/27                                            */
/*                                                                     */
/***********************************************************************/
//////////////////////////////////////////////////////////////////////

#ifndef __LCIEP_H__
#define __LCIEP_H__

#pragma comment(lib, "Advapi32")
#pragma comment(lib, "shlwapi")
#include <winreg.h>
#include <shlwapi.h>
#include <stdio.h>

int CreateCIEP(LPCTSTR szProtocolName, LPCTSTR szProtocolApp)
{

	if (0 == szProtocolName || 0 == szProtocolApp)
	{
		return -3;
	}
	HKEY hRootKey;//ProtocolRoot   HKEY_CURRENT_USER//szProtocolName
	HKEY hIconKey;//DefaultIcon    HKEY_CURRENT_USER//szProtocolName//DefaultIcon
	HKEY hShellKey;//Shell         HKEY_CURRENT_USER//szProtocolName//Shell
	HKEY hOpenKey;//ShellOpen	   HKEY_CURRENT_USER//szProtocolName//Shell//Open
	HKEY hCmdKey;//OpenCommand	   HKEY_CURRENT_USER//szProtocolName//Shell//Open//Command

	wchar_t IconString[255];
	wchar_t AppString[255];

	wchar_t szLinex[32] = L"Created By Linex LCIEP";


	swprintf(IconString, L"%s,1", szProtocolApp);
	swprintf(AppString, L"\"%s\" \"%%1\"", szProtocolApp);

	if (ERROR_SUCCESS != RegCreateKey(HKEY_CLASSES_ROOT, szProtocolName, &hRootKey))
	{
		return -1;
	}
	if (ERROR_SUCCESS != RegSetValueEx(hRootKey, L"URL Protocol", 0, REG_SZ, 0, 0))
	{
		return -2;
	}

	HKEY hLinex;
	if (ERROR_SUCCESS != RegCreateKey(hRootKey, L"Linex", &hLinex))
	{
		return -1;
	}
	if (ERROR_SUCCESS != RegSetValue(hLinex, L"", REG_SZ, szLinex, wcslen(szLinex)))
	{
		return -2;
	}

	if (ERROR_SUCCESS != RegCreateKey(hRootKey, L"DefaultIcon", &hIconKey))
	{
		return -1;
	}
	if (ERROR_SUCCESS != RegSetValue(hIconKey, L"", REG_SZ, IconString, wcslen(IconString)))
	{
		return -2;
	}

	if (ERROR_SUCCESS != RegCreateKey(hRootKey, L"Shell", &hShellKey))
	{
		return -1;
	}

	if (ERROR_SUCCESS != RegCreateKey(hShellKey, L"Open", &hOpenKey))
	{
		return -1;
	}

	if (ERROR_SUCCESS != RegCreateKey(hOpenKey, L"Command", &hCmdKey))
	{
		return -1;
	}

	if (ERROR_SUCCESS != RegSetValue(hCmdKey, L"", REG_SZ, AppString, wcslen(AppString)))
	{
		return -2;
	}


	RegCloseKey(hCmdKey);
	RegCloseKey(hOpenKey);
	RegCloseKey(hShellKey);
	RegCloseKey(hIconKey);
	RegCloseKey(hRootKey);

	return 0;
}

int DeleteCIEP(LPCTSTR szProtocolName)
{
	if (0 == szProtocolName)
	{
		return -3;
	}

	if (ERROR_SUCCESS != SHDeleteKey(HKEY_CLASSES_ROOT, szProtocolName))
	{
		return -2;
	}
	return 0;
}

int CheckCIEP(LPCTSTR szProtocolName)
{
	if (0 == szProtocolName)
	{
		return -3;
	}

	long nCount;

	if (ERROR_SUCCESS != RegQueryValue(HKEY_CLASSES_ROOT, szProtocolName, 0, &nCount))
	{
		return 0;
	}

	return -1;
}

#endif