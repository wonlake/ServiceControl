// ServiceControlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ServiceControl.h"
#include "ServiceControlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CServiceControlDlg �Ի���




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


// CServiceControlDlg ��Ϣ�������

BOOL CServiceControlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	GetDlgItem(IDC_INSTALLSERVICE)->SendMessage(BM_CLICK,0,0);
	GetDlgItem(IDC_TYPESERVICE)->SendMessage(BM_SETCHECK,(WPARAM)BST_CHECKED,0);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CServiceControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CServiceControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CServiceControlDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//void CServiceControlDlg::OnBnClickedInstallservice()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}

void CServiceControlDlg::OnBnSetfocusInstallservice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CServiceControlDlg::OnBnSetfocusRemoveservice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CServiceControlDlg::OnBnClickedInstallservice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_TYPESERVICE)->EnableWindow(TRUE);
	GetDlgItem(IDC_TYPEDRIVER)->EnableWindow(TRUE);
	GetDlgItem(IDC_DISPLAYNAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_SERVICEPATH)->EnableWindow(TRUE);
	GetDlgItem(IDC_GETPATH)->EnableWindow(TRUE);
	m_bInstallService = TRUE;
}

void CServiceControlDlg::OnBnClickedRemoveservice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_TYPESERVICE)->EnableWindow(FALSE);
	GetDlgItem(IDC_TYPEDRIVER)->EnableWindow(FALSE);
	GetDlgItem(IDC_DISPLAYNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_SERVICEPATH)->EnableWindow(FALSE);
	GetDlgItem(IDC_GETPATH)->EnableWindow(FALSE);
	m_bInstallService = FALSE;
}

void CServiceControlDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR szServiceName[100+1];
	TCHAR szDisplayName[100+1];
	TCHAR szServicePath[MAX_PATH+1];
	if(m_bInstallService)
	{
		if(GetDlgItem(IDC_SERVICENAME)->GetWindowTextLength()<=0)
		{
			MessageBox(TEXT("�����������!"));
			return;
		}

		if(GetDlgItem(IDC_DISPLAYNAME)->GetWindowTextLength()<=0)
		{
			MessageBox(TEXT("�������������!"));
			return;
		}

		if(GetDlgItem(IDC_SERVICEPATH)->GetWindowTextLength()<=0)
		{
			MessageBox(TEXT("���������·��!"));
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
			MessageBox(TEXT("�����������!"));
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
		service = CreateService(hSCManager,					//SCM���
							    szServiceName,				//���� "beep_srv"
							    szDisplayName,				//���� "Beep Service"
								SERVICE_ALL_ACCESS,			//����Ȩ��
								m_dwServiceType,			//�Լ�ӵ���Լ��Ľ���
								SERVICE_DEMAND_START,		//�ֹ�����
							    SERVICE_ERROR_NORMAL,
								szServicePath,				//���� "c:\winnt\xxx.exe"
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
		CloseServiceHandle(service);						//�رշ�����
		CloseServiceHandle(hSCManager);						//�ر�SCM���
}

void CServiceControlDlg::OnBnClickedGetpath()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlgFile(TRUE);
	dlgFile.m_ofn.lpstrFilter = TEXT("��ִ��ӳ���ļ�(.exe;.dll;.sys)\0*.exe;*.dll;*.sys\0");
	if(dlgFile.DoModal() == IDCANCEL)
		return;
	GetDlgItem(IDC_SERVICEPATH)->SetWindowText((LPCTSTR)dlgFile.GetPathName());
}

void CServiceControlDlg::OnBnClickedTypeservice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_TYPESERVICE)->SendMessage(BM_SETCHECK,(WPARAM)BST_CHECKED,0);
	GetDlgItem(IDC_TYPEDRIVER)->SendMessage(BM_SETCHECK,(WPARAM)BST_UNCHECKED,0);
	m_dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	m_bIsDriver = FALSE;
}

void CServiceControlDlg::OnBnClickedTypedriver()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_TYPEDRIVER)->SendMessage(BM_SETCHECK,(WPARAM)BST_CHECKED,0);
	GetDlgItem(IDC_TYPESERVICE)->SendMessage(BM_SETCHECK,(WPARAM)BST_UNCHECKED,0);
	m_dwServiceType = SERVICE_KERNEL_DRIVER;
	m_bIsDriver = FALSE;
}

