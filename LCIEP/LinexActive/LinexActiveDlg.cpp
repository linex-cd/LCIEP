// LinexActiveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LinexActive.h"
#include "LinexActiveDlg.h"
#include "LCIEP.h"
#pragma comment(lib, "LCIEP.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinexActiveDlg dialog

CLinexActiveDlg::CLinexActiveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLinexActiveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLinexActiveDlg)
	m_strProtocolName = _T("");
	m_strAppFile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLinexActiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinexActiveDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strProtocolName);
	DDX_Text(pDX, IDC_EDIT2, m_strAppFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLinexActiveDlg, CDialog)
	//{{AFX_MSG_MAP(CLinexActiveDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, OnCheck)
	ON_BN_CLICKED(IDB_BRW, OnBrw)
	ON_BN_CLICKED(IDB_ADD, OnAdd)
	ON_BN_CLICKED(IDB_DEL, OnDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinexActiveDlg message handlers

BOOL CLinexActiveDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLinexActiveDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLinexActiveDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLinexActiveDlg::OnCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strProtocolName.GetLength() == 0 )
	{
				MessageBox(_T("请填写协议名字"));
		return;
	}
	
	if (CheckCIEP(m_strProtocolName.GetBuffer(0)) != 0)
	{
		MessageBox(_T("字串已被占用，请删除或改为其它名字！"));
		return;
	}
	else
	{
		MessageBox(_T("字串可用！"));
		return;
	}
		

}

void CLinexActiveDlg::OnBrw() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CFileDialog dlg( TRUE, _T("exe"), _T(""), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T( "可执行文件|*.exe||" ) );
	if ( dlg.DoModal() == IDOK )
	{
		m_strAppFile = dlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CLinexActiveDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strAppFile.GetLength() == 0 )
	{
		MessageBox(_T("请填写协议名字"));
		return;
	}
	if (m_strProtocolName.GetLength() == 0)
	{
		MessageBox(_T("请选择协议支持程序"));
		return;
	}

	if (CheckCIEP(m_strProtocolName.GetBuffer(0)) != 0)
	{
		MessageBox(_T("字串已被占用，请删除或改为其它名字！"));
		return;
	}

	int nFlag = CreateCIEP(m_strProtocolName.GetBuffer(0),m_strAppFile.GetBuffer(0));
	if (0 == nFlag)
	{
		MessageBox(_T("自定义IE协议添加成功！"));
	}
	else
	{
		MessageBox(_T("自定义IE协议添加失败，请使用管理员权限运行并加入安全软件白名单！"));
	}
}

void CLinexActiveDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strProtocolName.GetLength() == 0 )
	{
		MessageBox(_T("请填写协议名字"));
		return;
	}

	if (CheckCIEP(m_strProtocolName.GetBuffer(0)) == 0)
	{
		MessageBox(_T("协议不存在！"));
		return;
	}


	int nFlag = DeleteCIEP(m_strProtocolName.GetBuffer(0));
	if (0 == nFlag)
	{
		MessageBox(_T("自定义IE协议删除成功！"));
	}

	else
	{
		MessageBox(_T("自定义IE协议删除失败，请使用管理员权限运行并加入安全软件白名单！"));
	}
}
