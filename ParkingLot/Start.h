#pragma once
#include "afxwin.h"


// CStart �Ի���

class CStart : public CDialogEx
{
	DECLARE_DYNAMIC(CStart)

public:
	CStart(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStart();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit Sedit1;
	CEdit Sedit;
	CEdit Sedit3;
};
