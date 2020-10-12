// LCIEP.cpp : Defines the entry point for the DLL application.
//
/***********************************************************************/
/*                                                                     */
/*	Description: Linex custom IE Protocol Interface                    */
/*	Wrote by   : Linex                                                 */
/*	QQ         : 909090185                                             */
/*	E-mail     : www@loginar.com                                       */
/*	Update Data: 2012/11/27                                            */
/*                                                                     */
/***********************************************************************/

#include "stdafx.h"

#pragma comment(lib, "Advapi32")
#pragma comment(lib, "shlwapi")
#include <winreg.h>
#include <shlwapi.h>
#include <stdio.h>
// __declspec(dllexport) int CreateCIEP(LPCTSTR szProtocolName, LPCTSTR szProtocolApp);
// __declspec(dllexport) int DeleteCIEP(LPCTSTR szProtocolName);
// __declspec(dllexport) int CheckCIEP(LPCTSTR szProtocolName);

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

__declspec(dllexport) int CreateCIEP(LPCTSTR szProtocolName, LPCTSTR szProtocolApp)
{

	if ( 0 == szProtocolName || 0 == szProtocolApp)
	{
		return -3;
	}
	HKEY hRootKey;//ProtocolRoot   HKEY_CURRENT_USER//szProtocolName
	HKEY hIconKey;//DefaultIcon    HKEY_CURRENT_USER//szProtocolName//DefaultIcon
	HKEY hShellKey;//Shell         HKEY_CURRENT_USER//szProtocolName//Shell
	HKEY hOpenKey;//ShellOpen	   HKEY_CURRENT_USER//szProtocolName//Shell//Open
	HKEY hCmdKey;//OpenCommand	   HKEY_CURRENT_USER//szProtocolName//Shell//Open//Command

	char IconString[255];
	char AppString[255];

	char szLinex[32] =  "Created By Linex LCIEP";


	sprintf(IconString, "%s,1",szProtocolApp);
	sprintf(AppString, "\"%s\" \"%%1\"",szProtocolApp);

	if (ERROR_SUCCESS != RegCreateKey(HKEY_CLASSES_ROOT, szProtocolName, &hRootKey))
	{
		return -1;
	}
 	if (ERROR_SUCCESS != RegSetValueEx(hRootKey, "URL Protocol", 0, REG_SZ, 0, 0))
 	{
 		return -2;
	}

	HKEY hLinex;
	if (ERROR_SUCCESS != RegCreateKey(hRootKey, "Linex", &hLinex))
	{
		return -1;
	}
	if (ERROR_SUCCESS != RegSetValue(hLinex, "", REG_SZ, szLinex, strlen(szLinex)))
	{
		return -2;
	}

	if (ERROR_SUCCESS != RegCreateKey(hRootKey, "DefaultIcon", &hIconKey))
	{
		return -1;
	}
	if (ERROR_SUCCESS != RegSetValue(hIconKey, "", REG_SZ, IconString, strlen(IconString)))
	{
		return -2;
	}
	
	if (ERROR_SUCCESS != RegCreateKey(hRootKey, "Shell", &hShellKey))
	{
		return -1;
	}

	if (ERROR_SUCCESS != RegCreateKey(hShellKey, "Open", &hOpenKey))
	{
		return -1;
	}
	
	if (ERROR_SUCCESS != RegCreateKey(hOpenKey, "Command", &hCmdKey))
	{
		return -1;
	}

	if (ERROR_SUCCESS != RegSetValue(hCmdKey, "", REG_SZ, AppString, strlen(AppString)))
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

__declspec(dllexport) int DeleteCIEP(LPCTSTR szProtocolName)
{
	if ( 0 == szProtocolName)
	{
		return -3;
	}

	if (ERROR_SUCCESS != SHDeleteKey(HKEY_CLASSES_ROOT, szProtocolName))
	{		
		return -2;
	}
	return 0;
}

__declspec(dllexport) int CheckCIEP(LPCTSTR szProtocolName)
{
	if ( 0 == szProtocolName)
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