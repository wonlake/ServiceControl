// ServiceControlDlg.h : 头文件
//

#pragma once


// CServiceControlDlg 对话框
class CServiceControlDlg : public CDialog
{
// 构造
public:
	CServiceControlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SERVICECONTROL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON		 m_hIcon;
	BOOL		 m_bInstallService;
	BOOL         m_bIsDriver;
	DWORD        m_dwServiceType;
	// 生成的消息映射函数
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
