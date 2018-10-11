#pragma once
#pragma once
#include <afx.h>

CString MaxT;
typedef struct queue {
	CString  carname[100];
	int head;
	int tail;
	int length;
}queue;

queue carque;
int max;

void initial(int Lmax) {
	carque.head = 0;
	carque.tail = 0;
	carque.length = 0;
	max = Lmax;
}

CString topcar() {
	CString temp = carque.carname[carque.head];
	carque.head++;
	carque.length--;
	return temp;
	/*CString temp = carque.carname[carque.head];
	if (carque.head == max-1)
		carque.head = 0;
	else
		carque.head++;
	carque.length--;
	return temp;*/
}

bool putcar(CString name) {

	carque.length++;
	if (carque.length <= max)
	{
	carque.carname[carque.tail] = name;
	carque.tail++;
	return true;
	}
	else
	{
		carque.length--;
		return false;
	}
	/*if (carque.length == max)
		return false;
	else {
		carque.carname[carque.tail] = name;
		if (carque.tail == max-1)
			carque.tail = 0;
		else
			carque.tail++;
		carque.length++;
		return true;
	}*/
}
int getlength() {
	return carque.length;
}
