// LinexActiveDlg.h : header file
//

#if !defined(AFX_LINEXACTIVEDLG_H__F6A40F29_8279_4431_AF16_0DCEF0C6B885__INCLUDED_)
#define AFX_LINEXACTIVEDLG_H__F6A40F29_8279_4431_AF16_0DCEF0C6B885__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLinexActiveDlg dialog

class CLinexActiveDlg : public CDialog
{
// Construction
public:
	CLinexActiveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLinexActiveDlg)
	enum { IDD = IDD_LINEXACTIVE_DIALOG };
	CString	m_strProtocolName;
	CString	m_strAppFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinexActiveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLinexActiveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheck();
	afx_msg void OnBrw();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEXACTIVEDLG_H__F6A40F29_8279_4431_AF16_0DCEF0C6B885__INCLUDED_)
