// ServiceControlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ServiceControl.h"
#include "ServiceControlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CServiceControlDlg 对话框




CServiceControlDlg::CServiceControlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServiceControlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bInstallService = TRUE;
	m_bIsDriver       = FALSE;
	m_dwServiceType	  = SERVICE_WIN32_OWN_PROCESS;
}

void CServiceControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CServiceControlDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_SETFOCUS(IDC_INSTALLSERVICE, CServiceControlDlg::OnBnSetfocusInstallservice)
	ON_BN_SETFOCUS(IDC_REMOVESERVICE, CServiceControlDlg::OnBnSetfocusRemoveservice)
	ON_BN_CLICKED(IDC_INSTALLSERVICE, CServiceControlDlg::OnBnClickedInstallservice)
	ON_BN_CLICKED(IDC_REMOVESERVICE, CServiceControlDlg::OnBnClickedRemoveservice)
	ON_BN_CLICKED(IDOK, CServiceControlDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_GETPATH, CServiceControlDlg::OnBnClickedGetpath)
	ON_BN_CLICKED(IDC_TYPESERVICE, CServiceControlDlg::OnBnClickedTypeservice)
	ON_BN_CLICKED(IDC_TYPEDRIVER, CServiceControlDlg::OnBnClickedTypedriver)
END_MESSAGE_MAP()


// CServiceControlDlg 消息处理程序

BOOL CServiceControlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	GetDlgItem(IDC_INSTALLSERVICE)->SendMessage(BM_CLICK,0,0);
	GetDlgItem(IDC_TYPESERVICE)->SendMessage(BM_SETCHECK,(WPARAM)BST_CHECKED,0);

	// TODO: 在此添加额外的初始化代码
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CServiceControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CServiceControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CServiceControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CServiceControlDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}

//void CServiceControlDlg::OnBnClickedInstallservice()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}

void CServiceControlDlg::OnBnSetfocusInstallservice()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CServiceControlDlg::OnBnSetfocusRemoveservice()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CServiceControlDlg::OnBnClickedInstallservice()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_TYPESERVICE)->EnableWindow(TRUE);
	GetDlgItem(IDC_TYPEDRIVER)->EnableWindow(TRUE);
	GetDlgItem(IDC_DISPLAYNAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_SERVICEPATH)->EnableWindow(TRUE);
	GetDlgItem(IDC_GETPATH)->EnableWindow(TRUE);
	m_bInstallService = TRUE;
}

void CServiceControlDlg::OnBnClickedRemoveservice()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_TYPESERVICE)->EnableWindow(FALSE);
	GetDlgItem(IDC_TYPEDRIVER)->EnableWindow(FALSE);
	GetDlgItem(IDC_DISPLAYNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_SERVICEPATH)->EnableWindow(FALSE);
	GetDlgItem(IDC_GETPATH)->EnableWindow(FALSE);
	m_bInstallService = FALSE;
}

void CServiceControlDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szServiceName[100+1];
	TCHAR szDisplayName[100+1];
	TCHAR szServicePath[MAX_PATH+1];
	if(m_bInstallService)
	{
		if(GetDlgItem(IDC_SERVICENAME)->GetWindowTextLength()<=0)
		{
			MessageBox(TEXT("请输入服务名!"));
			return;
		}

		if(GetDlgItem(IDC_DISPLAYNAME)->GetWindowTextLength()<=0)
		{
			MessageBox(TEXT("请输入服务描述!"));
			return;
		}

		if(GetDlgItem(IDC_SERVICEPATH)->GetWindowTextLength()<=0)
		{
			MessageBox(TEXT("请输入服务路径!"));
			return;
		}

		GetDlgItem(IDC_SERVICENAME)->GetWindowText(szServiceName,100);
		GetDlgItem(IDC_DISPLAYNAME)->GetWindowText(szDisplayName,100);
		GetDlgItem(IDC_SERVICEPATH)->GetWindowText(szServicePath,MAX_PATH);
	}
	else
	{
		if(GetDlgItem(IDC_SERVICENAME)->GetWindowTextLength()<=0)
		{
			MessageBox(TEXT("请输入服务名!"));
			return;
		}

		GetDlgItem(IDC_SERVICENAME)->GetWindowText(szServiceName,100);
	}
	
	SC_HANDLE service,hSCManager;
	hSCManager = OpenSCManager(0,0,SC_MANAGER_CREATE_SERVICE);
	if (!hSCManager)
	    MessageBox(TEXT("OpenScManager Error!"));

	if(m_bInstallService)
	{
		service = CreateService(hSCManager,					//SCM句柄
							    szServiceName,				//例如 "beep_srv"
							    szDisplayName,				//例如 "Beep Service"
								SERVICE_ALL_ACCESS,			//所有权限
								m_dwServiceType,			//自己拥有自己的进程
								SERVICE_DEMAND_START,		//手工启动
							    SERVICE_ERROR_NORMAL,
								szServicePath,				//例如 "c:\winnt\xxx.exe"
								0, 
								0,
								0,
								0,
								0);
		if (!service) 
			MessageBox(TEXT("CreateService Failed!"));
		else 
			MessageBox(TEXT("Service installed!"));

	}
	else
	{
		BOOL success;
		SERVICE_STATUS status;

		service = OpenService(hSCManager, 
							  szServiceName,
							  SERVICE_ALL_ACCESS|DELETE);
		if (!service) 
			MessageBox(TEXT("OpenService Failed!"));

		success = QueryServiceStatus(service,&status);
		if (!success) 
			MessageBox(TEXT("QueryServiceStatus Failed!"));

		if (status.dwCurrentState != SERVICE_STOPPED)
		{
			success = ControlService(service,
									 SERVICE_CONTROL_STOP, 
									 &status);
			while(status.dwCurrentState == SERVICE_STOP_PENDING)
			{
				Sleep(50);
				QueryServiceStatus(service,&status);
			}
		}

		success = DeleteService(service);
		if (success) 
			MessageBox(TEXT("Service removed!"));
		else 
			MessageBox(TEXT("DeleteService Failed!"));

		}
		CloseServiceHandle(service);						//关闭服务句柄
		CloseServiceHandle(hSCManager);						//关闭SCM句柄
}

void CServiceControlDlg::OnBnClickedGetpath()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlgFile(TRUE);
	dlgFile.m_ofn.lpstrFilter = TEXT("可执行映像文件(.exe;.dll;.sys)\0*.exe;*.dll;*.sys\0");
	if(dlgFile.DoModal() == IDCANCEL)
		return;
	GetDlgItem(IDC_SERVICEPATH)->SetWindowText((LPCTSTR)dlgFile.GetPathName());
}

void CServiceControlDlg::OnBnClickedTypeservice()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_TYPESERVICE)->SendMessage(BM_SETCHECK,(WPARAM)BST_CHECKED,0);
	GetDlgItem(IDC_TYPEDRIVER)->SendMessage(BM_SETCHECK,(WPARAM)BST_UNCHECKED,0);
	m_dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	m_bIsDriver = FALSE;
}

void CServiceControlDlg::OnBnClickedTypedriver()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_TYPEDRIVER)->SendMessage(BM_SETCHECK,(WPARAM)BST_CHECKED,0);
	GetDlgItem(IDC_TYPESERVICE)->SendMessage(BM_SETCHECK,(WPARAM)BST_UNCHECKED,0);
	m_dwServiceType = SERVICE_KERNEL_DRIVER;
	m_bIsDriver = FALSE;
}

