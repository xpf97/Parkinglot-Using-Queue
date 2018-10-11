
// ParkingLotDlg.cpp : ʵ���ļ�
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
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CParkingLotDlg �Ի���



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


// CParkingLotDlg ��Ϣ�������

BOOL CParkingLotDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	maxpark = _ttoi(MaxPark);
	maxparker = _ttoi(MaxParker);
	money = _wtof(Money);
	carnum = maxpark;
	parknum = maxparker;
	initial(maxparker);
	CRect rect;
	park.GetClientRect(&rect);
	park.SetExtendedStyle(park.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	park.InsertColumn(0, L"��λ", LVCFMT_CENTER, rect.Width()/ 2, 0);
	park.InsertColumn(1, L"���ƺ�", LVCFMT_CENTER, rect.Width()/ 2, 1);
	parker.GetClientRect(&rect);
	parker.SetExtendedStyle(park.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	parker.InsertColumn(0, L"���ƺ�", LVCFMT_CENTER, rect.Width(), 1);

	edit1.SetWindowText(L"��λ����" + MaxPark + "                                    ʣ�ࣺ" + MaxPark);
	edit2.SetWindowText(L"��λ����" + MaxParker + "       ʣ�ࣺ" + MaxParker);
	//edit1.SetWindowText(L"��λ����100                                    ʣ�ࣺ100");
	//edit2.SetWindowText(L"��λ����10       ʣ�ࣺ10");
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CParkingLotDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CParkingLotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CParkingLotDlg::init(CString L1,CString L2,CString L3)
{
	MaxPark = L1;
	MaxParker = L2;
	Money = L3;
	//edit1.SetWindowText(L"��λ����" + MaxPark + "                                    ʣ�ࣺ" + MaxPark);
	//edit2.SetWindowText(L"��λ����" + MaxParker + "       ʣ�ࣺ" + MaxParker);
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
			temp.Format(cstr + _T("��ͣ����ͣ����%dСʱ%d��%d�롣"), timess / 3600, timess % 3600 / 60, timess % 60);
			MessageBox(temp);
			return;
		}
	}
	temp.Format(_T("�������Ϣ"));
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
			MessageBox(_T("����ͣ����ʱ����"), _T("��ʾ��Ϣ"), MB_ICONERROR);
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
			edit2.SetWindowText(L"��λ����" + MaxParker + "       ʣ�ࣺ" + temp);
		}
		else
		{
			MessageBox(_T("��ʱ����������ͣ��ʧ��"), _T("��ʾ��Ϣ"), MB_ICONERROR);
		}
		i++;
		return;
	}
		/*park.InsertItem(i, temp);
		park.SetItemText(i, 1, cstr);
		i++;
		temp.Format(_T("%d"), maxpark - i);
		carnum = maxpark - i;
		edit1.SetWindowText(L"��λ����" + MaxPark + "                                    ʣ��:" + temp);
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
		edit1.SetWindowText(L"��λ����" + MaxPark + "                                    ʣ��:" + temp);
		park.EnsureVisible(park.GetItemCount() - 1, FALSE);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("û��������"), _T("��ʾ��Ϣ"), MB_ICONERROR);
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
	edit1.SetWindowText(L"��λ����" + MaxPark + "                                    ʣ��:" + temp);
	temp.Format(cstr+_T("��ͣ����ͣ����%dСʱ%d��%d�롣\n�շ� %.2fԪ��"), times/3600,times%3600/60,times%60,times*(money/60));
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
		edit1.SetWindowText(L"��λ����" + MaxPark + "                                    ʣ��:" + temp);
		//edit.GetWindowTextW(cstr);
		/*temp.Format(_T("%d"), i + 1);
		park.InsertItem(i, temp);
		park.SetItemText(i, 1, cstr);
		i++;
		temp.Format(_T("%d"), maxpark - i);
		carnum = maxpark - i;
		edit1.SetWindowText(L"��λ����" + MaxPark + "                                    ʣ��:" + temp);
		incar(cstr);*/


		/*park.InsertItem(i, temp);
		park.SetItemText(i, 1, cstr);
		i++;
		temp.Format(_T("%d"), maxpark - i);
		carnum = maxpark - i;
		edit1.SetWindowText(L"��λ����" + MaxPark + "                                    ʣ��:" + temp);
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
		edit2.SetWindowText(L"��λ����" + MaxParker + "       ʣ�ࣺ" + temp);
		MessageBox(cstr+_T("��ʻ�복��"), _T("��ʾ��Ϣ"), MB_ICONERROR);


	}
	park.EnsureVisible(park.GetItemCount() - 1, FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CParkingLotDlg::OnBnClickedButton4()
{
	
}
