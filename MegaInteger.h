#ifndef MEGA_INTEGER
#define MEGA_INTEGER

#include "MegaNatural.h"
#include <string>

using namespace std;

class MegaInteger 
{
public:
	MegaInteger();
	MegaInteger(const MegaNatural &ob);
	MegaInteger(const MegaInteger &ob);
	MegaInteger(long long a);
	MegaInteger(string);
	~MegaInteger();

	//Описание: модуль числа
	MegaInteger abs() const;
	//Описание: преобразование целого в натуральное
	MegaNatural toMegaNatural();
	string toString();

	MegaInteger& operator =(const MegaInteger &ob);

	friend bool operator ==(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator!=(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator <(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator >(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator <=(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator >=(const MegaInteger &ob1, const MegaInteger &ob2);

	friend MegaInteger operator %(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator *(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator /(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator +(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator -(const MegaInteger &ob1, const MegaInteger &ob2);
	friend MegaInteger operator -(const MegaInteger &ob);
private:
	MegaNatural num;
	bool isNegative;
};

#include "MegaInteger.cpp"

#endif
