// ServiceControlDlg.h : ͷ�ļ�
//

#pragma once


// CServiceControlDlg �Ի���
class CServiceControlDlg : public CDialog
{
// ����
public:
	CServiceControlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SERVICECONTROL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON		 m_hIcon;
	BOOL		 m_bInstallService;
	BOOL         m_bIsDriver;
	DWORD        m_dwServiceType;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
//	afx_msg void OnBnClickedInstallservice();
	afx_msg void OnBnSetfocusInstallservice();
	afx_msg void OnBnSetfocusRemoveservice();
	afx_msg void OnBnClickedInstallservice();
	afx_msg void OnBnClickedRemoveservice();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedGetpath();
//	afx_msg void OnBnClickedTypeservice();
//	afx_msg void OnBnClickedTypedriver();
	afx_msg void OnBnClickedTypeservice();
	afx_msg void OnBnClickedTypedriver();
};
