#ifndef MEGA_NATURAL_BASE
#define MEGA_NATURAL_BASE

#include <iostream>
#include <malloc.h>
#include <deque>
#include <string>

typedef unsigned char uchar;
using namespace std;

class MegaNatural
{
public:
	MegaNatural();
	MegaNatural(const MegaNatural &ob);
	MegaNatural(string str);
	MegaNatural(unsigned long long l);
	~MegaNatural();
	
	string toString();
	friend ostream& operator<<(ostream &os, MegaNatural &ob);
	MegaNatural& operator =(const MegaNatural &ob);

	//Имя модуля: TDC_N
	//Базовые модули: -
	//Выполнил:	
	long long tenDivisiorCt();

	//Имя модуля: MUL_Nk_N
	//Базовые модули: COM_NN_D
	//Выполнил:
	void mulByTenPowK(long long k);
	
	//Имя модуля: COM_NN_D
	//Базовые модули: -
	//Выполнил:
	friend bool operator ==(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator !=(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator <=(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator >=(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator <(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator >(const MegaNatural &ob1, const MegaNatural &ob2);

	//Имя модуля: ADD_NN_N 
	//Базовые модули: COM_NN_D
	//Выполнил:
	friend MegaNatural operator +(const MegaNatural &ob1, const MegaNatural &ob2);

	//Имя модуля: SUB_NN_N
	//Базовые модули: COM_NN_D
	//Выполнил:
	friend MegaNatural operator -(const MegaNatural &ob1, const MegaNatural &ob2);

	//Имя модуля: DIV_NN_N
	//Базовые модули: -
	//Выполнил:
	friend MegaNatural operator /(const MegaNatural &ob1, const MegaNatural &ob2);

	//Имя модуля: MOD_NN_N
	//Базовые модули: DIV_NN_N, SUB_NN_N
	//Выполнил:
	friend MegaNatural operator %(const MegaNatural &ob1, const MegaNatural &ob2);
	
	//Имя модуля: MUL_NN_N
	//Базовые модули: MUL_ND_N, MUL_Nk_N, ADD_NN_N
	//Выполнил:
	friend MegaNatural operator *(const MegaNatural &ob1, const MegaNatural &ob2);
	
private:
	deque<uchar> nums;
	
	//Имя модуля: MUL_ND_N
	//Базовые модули: -
	//Выполнил: 
	MegaNatural mulByK(uchar k);
};

#include "MegaNatural.cpp"
#endif


