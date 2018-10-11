
// ParkingLotDlg.cpp : 实现文件
//
#include "stdafx.h"
#include "ParkingLot.h"
#include "ParkingLotDlg.h"
#include "afxdialogex.h"
#include"Start.h"
#include"Park.h"
#include"Queue.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int i = 0;
int carnum ;
int parknum ;
int maxpark;
int maxparker;
double money;
CString MaxPark;
CString MaxParker;
CString Money;
CStart *cs = new CStart();
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CParkingLotDlg 对话框



CParkingLotDlg::CParkingLotDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PARKINGLOT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CParkingLotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, park);
	DDX_Control(pDX, IDC_LIST2, parker);
	DDX_Control(pDX, IDC_EDIT3, edit1);
	DDX_Control(pDX, IDC_EDIT4, edit2);
	DDX_Control(pDX, IDC_EDIT1, edit);
}

BEGIN_MESSAGE_MAP(CParkingLotDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CParkingLotDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CParkingLotDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CParkingLotDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CParkingLotDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CParkingLotDlg 消息处理程序

BOOL CParkingLotDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	maxpark = _ttoi(MaxPark);
	maxparker = _ttoi(MaxParker);
	money = _wtof(Money);
	carnum = maxpark;
	parknum = maxparker;
	initial(maxparker);
	CRect rect;
	park.GetClientRect(&rect);
	park.SetExtendedStyle(park.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	park.InsertColumn(0, L"车位", LVCFMT_CENTER, rect.Width()/ 2, 0);
	park.InsertColumn(1, L"车牌号", LVCFMT_CENTER, rect.Width()/ 2, 1);
	parker.GetClientRect(&rect);
	parker.SetExtendedStyle(park.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	parker.InsertColumn(0, L"车牌号", LVCFMT_CENTER, rect.Width(), 1);

	edit1.SetWindowText(L"车位数：" + MaxPark + "                                    剩余：" + MaxPark);
	edit2.SetWindowText(L"车位数：" + MaxParker + "       剩余：" + MaxParker);
	//edit1.SetWindowText(L"车位数：100                                    剩余：100");
	//edit2.SetWindowText(L"车位数：10       剩余：10");
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CParkingLotDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CParkingLotDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CParkingLotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CParkingLotDlg::init(CString L1,CString L2,CString L3)
{
	MaxPark = L1;
	MaxParker = L2;
	Money = L3;
	//edit1.SetWindowText(L"车位数：" + MaxPark + "                                    剩余：" + MaxPark);
	//edit2.SetWindowText(L"车位数：" + MaxParker + "       剩余：" + MaxParker);
}



void CParkingLotDlg::OnBnClickedButton1()
{
	CString cstr;
	CString temp;
	edit.GetWindowTextW(cstr);
	for (int k = 0; k <getNumber(); k++)
	{
		if (cars[k].carname == cstr) 
		{
			long int timess = (long int)time(0) - (long int)cars[k].time;
			temp.Format(cstr + _T("在停车场停留了%d小时%d分%d秒。"), timess / 3600, timess % 3600 / 60, timess % 60);
			MessageBox(temp);
			return;
		}
	}
	temp.Format(_T("无相关信息"));
	MessageBox(temp);
}


void CParkingLotDlg::OnBnClickedButton2()
{
	CString cstr;
	CString temp;
	edit.GetWindowTextW(cstr);
	temp.Format(_T("%d"), i + 1);
	if (carnum == 0)
	{
		i--;
		//carnum++;
		if (putcar(cstr))
		{
			MessageBox(_T("车已停入临时车道"), _T("提示信息"), MB_ICONERROR);
			temp.Format(_T("%d"), maxparker - (carque.tail-carque.head));
			parknum = maxparker - getlength();
			parker.DeleteAllItems();
			//for (int n = carque.head; n <=carque.tail; n++)
			//{
			//	parker.InsertItem(0, carque.carname[n]);
			//}
			//parker.InsertItem(0, cstr);
			parker.DeleteAllItems();
			for (int n = carque.head; n <= carque.tail; n++)
			{
				parker.InsertItem(n, carque.carname[n]);
				//park.SetItemText(n, 1, cars[n].carname);
			}
			edit2.SetWindowText(L"车位数：" + MaxParker + "       剩余：" + temp);
		}
		else
		{
			MessageBox(_T("临时车道已满，停车失败"), _T("提示信息"), MB_ICONERROR);
		}
		i++;
		return;
	}
		/*park.InsertItem(i, temp);
		park.SetItemText(i, 1, cstr);
		i++;
		temp.Format(_T("%d"), maxpark - i);
		carnum = maxpark - i;
		edit1.SetWindowText(L"车位数：" + MaxPark + "                                    剩余:" + temp);
		incar(cstr);*/
	    incar(cstr);
		park.DeleteAllItems();
		for (int k = 0; k <getNumber(); k++)
		{
			temp.Format(_T("%d"), k + 1);
			park.InsertItem(k, temp);
			park.SetItemText(k, 1, cars[k].carname);
		}
		i++;
		temp.Format(_T("%d"), maxpark - i);
		carnum = maxpark - i;
		edit1.SetWindowText(L"车位数：" + MaxPark + "                                    剩余:" + temp);
		park.EnsureVisible(park.GetItemCount() - 1, FALSE);

	// TODO: 在此添加控件通知处理程序代码
}


void CParkingLotDlg::OnBnClickedButton3()
{
	i--;
	CString cstr;
	CString temp;
	edit.GetWindowTextW(cstr);
	temp.Format(_T("%d"), i + 1);
	CString boolcar = outcar(cstr);
	if (boolcar == L"")
	{
		MessageBox(_T("没有这辆车"), _T("提示信息"), MB_ICONERROR);
		i++;
		return;
	}
	park.DeleteAllItems();
	for (int k = 0; k <getNumber(); k++)
	{
		temp.Format(_T("%d"), k + 1);
		park.InsertItem(k, temp);
		park.SetItemText(k, 1, cars[k].carname);
	}
	carnum++;
	temp.Format(_T("%d"), carnum);
	edit1.SetWindowText(L"车位数：" + MaxPark + "                                    剩余:" + temp);
	temp.Format(cstr+_T("在停车场停留了%d小时%d分%d秒。\n收费 %.2f元。"), times/3600,times%3600/60,times%60,times*(money/60));
	MessageBox(temp);

	if (parknum != maxparker)
	{
		CString cstr = topcar();
		CString temp;
		incar(cstr);
		park.DeleteAllItems();
		for (int k = 0; k <getNumber(); k++)
		{
			temp.Format(_T("%d"), k + 1);
			park.InsertItem(k, temp);
			park.SetItemText(k, 1, cars[k].carname);
		}
		i++;
		temp.Format(_T("%d"), maxpark - i);
		carnum = maxpark - i;
		edit1.SetWindowText(L"车位数：" + MaxPark + "                                    剩余:" + temp);
		//edit.GetWindowTextW(cstr);
		/*temp.Format(_T("%d"), i + 1);
		park.InsertItem(i, temp);
		park.SetItemText(i, 1, cstr);
		i++;
		temp.Format(_T("%d"), maxpark - i);
		carnum = maxpark - i;
		edit1.SetWindowText(L"车位数：" + MaxPark + "                                    剩余:" + temp);
		incar(cstr);*/


		/*park.InsertItem(i, temp);
		park.SetItemText(i, 1, cstr);
		i++;
		temp.Format(_T("%d"), maxpark - i);
		carnum = maxpark - i;
		edit1.SetWindowText(L"车位数：" + MaxPark + "                                    剩余:" + temp);
		incar(cstr);*/


		parker.DeleteAllItems();
		/*for (int n = 0; n <=carque.tail; n++)
		{
			parker.InsertItem(0, carque.carname[n]);
		}*/
		for (int n = carque.head; n<=carque.tail; n++)
		{
			//park.SetItemText(n, 0, cars[n].carname);
		    parker.InsertItem(n, carque.carname[n]);
		}
		parknum++;
		temp.Format(_T("%d"), parknum);
		edit2.SetWindowText(L"车位数：" + MaxParker + "       剩余：" + temp);
		MessageBox(cstr+_T("已驶入车场"), _T("提示信息"), MB_ICONERROR);


	}
	park.EnsureVisible(park.GetItemCount() - 1, FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CParkingLotDlg::OnBnClickedButton4()
{
	
}
