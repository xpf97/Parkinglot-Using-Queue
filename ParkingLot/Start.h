#pragma once
#include "afxwin.h"


// CStart 对话框

class CStart : public CDialogEx
{
	DECLARE_DYNAMIC(CStart)

public:
	CStart(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStart();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit Sedit1;
	CEdit Sedit;
	CEdit Sedit3;
};
