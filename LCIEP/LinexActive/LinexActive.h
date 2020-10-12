// LinexActive.h : main header file for the LINEXACTIVE application
//

#if !defined(AFX_LINEXACTIVE_H__D64D6488_A03F_440D_9B31_90363A36BA37__INCLUDED_)
#define AFX_LINEXACTIVE_H__D64D6488_A03F_440D_9B31_90363A36BA37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLinexActiveApp:
// See LinexActive.cpp for the implementation of this class
//

class CLinexActiveApp : public CWinApp
{
public:
	CLinexActiveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinexActiveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLinexActiveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEXACTIVE_H__D64D6488_A03F_440D_9B31_90363A36BA37__INCLUDED_)
