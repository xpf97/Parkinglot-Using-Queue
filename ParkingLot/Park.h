#pragma once
#include"stdafx.h"

typedef struct Car
{
	CString carname;
	time_t time;

}Car;


int num = 0;
Car cars[500];
long int times;

CString incar(CString Lcstr)
{
	cars[num].carname = Lcstr;
	cars[num].time = time(0);
	num++;
	return Lcstr;
}

CString outcar(CString Lcstr)
{
	for (int i = 0; i < num; i++)
	{
		if (cars[i].carname == Lcstr)
		{
			times = (long int)time(0) - (long int)cars[i].time;
			for (int j = i; j <num; j++)
			{
				cars[j] = cars[j + 1];
			}
			num--;
			if (num == 0)
			{
				for (int m = 0; m < 500; m++)
				{
					cars[m].carname = L"";
				}
			}
			return Lcstr;
		}
	}
	return L"";
}

int getNumber()
{
	return num;
}