
// ParkingLot.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CParkingLotApp: 
// �йش����ʵ�֣������ ParkingLot.cpp
//

class CParkingLotApp : public CWinApp
{
public:
	CParkingLotApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CParkingLotApp theApp;