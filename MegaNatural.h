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
	
	void mulByTenPowK(long long k);
	long long tenDivisiorCt();

	friend ostream& operator<<(ostream &os, MegaNatural &ob);
	friend bool operator ==(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator !=(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator <=(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator >=(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator <(const MegaNatural &ob1, const MegaNatural &ob2);
	friend bool operator >(const MegaNatural &ob1, const MegaNatural &ob2);
	friend MegaNatural operator +(const MegaNatural &ob1, const MegaNatural &ob2);
	friend MegaNatural operator -(const MegaNatural &ob1, const MegaNatural &ob2);
	friend MegaNatural operator /(const MegaNatural &ob1, const MegaNatural &ob2);
	friend MegaNatural operator %(const MegaNatural &ob1, const MegaNatural &ob2);
	friend MegaNatural operator *(const MegaNatural &ob1, const MegaNatural &ob2);

	MegaNatural& operator =(const MegaNatural &ob);
	MegaNatural& operator +=(const MegaNatural &ob1, const MegaNatural &ob2);
	MegaNatural& operator -=(const MegaNatural &ob1, const MegaNatural &ob2);
	MegaNatural& operator *=(const MegaNatural &ob1, const MegaNatural &ob2);
	MegaNatural& operator /=(const MegaNatural &ob1, const MegaNatural &ob2);
	MegaNatural& operator %=(const MegaNatural &ob1, const MegaNatural &ob2);

	string toString();
	
	
private:
	deque<uchar> nums;
	
	//Описание: умножение на цифру
	MegaNatural mulByK(uchar k);
};

#include "MegaNatural.cpp"
#endif


