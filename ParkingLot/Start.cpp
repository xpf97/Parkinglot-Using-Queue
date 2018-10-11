// Start.cpp : 实现文件
//

#include "stdafx.h"
#include "ParkingLotDlg.h"
#include "ParkingLot.h"
#include "Start.h"
#include "afxdialogex.h"


// CStart 对话框

IMPLEMENT_DYNAMIC(CStart, CDialogEx)

CStart::CStart(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CStart::~CStart()
{
}

void CStart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Sedit1);
	DDX_Control(pDX, IDC_EDIT2, Sedit);
	DDX_Control(pDX, IDC_EDIT3, Sedit3);
}


BEGIN_MESSAGE_MAP(CStart, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CStart::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStart::OnBnClickedButton2)
END_MESSAGE_MAP()


// CStart 消息处理程序


void CStart::OnBnClickedButton1()
{
	CString cstr1;
	CString cstr2;
	CString cstr3;
	Sedit1.GetWindowText(cstr1);
	Sedit.GetWindowText(cstr2);
	Sedit3.GetWindowText(cstr3);
	CParkingLotDlg *cd = new CParkingLotDlg();
	cd->init(cstr1, cstr2,cstr3);
	CStart::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}


void CStart::OnBnClickedButton2()
{
	CStart::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}
