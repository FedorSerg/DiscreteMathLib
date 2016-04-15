#ifndef MEGA_RATIONAL
#define MEGA_RATIONAL

#include "MegaInteger.h"
#include "DiscreteMath.h"

using namespace std;

class MegaRational
{
public:
	MegaRational();
	MegaRational(const MegaInteger &a);
	MegaRational(const MegaInteger &a, const MegaNatural &b);
	MegaRational(const MegaRational &a);
	~MegaRational();

	//ќписание: сокращение дроби
	void reduction();
	//ќписание: проверка, является ли число целым
	bool isInteger();
	MegaInteger toMegaInteger();

	friend bool operator ==(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator !=(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator <(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator >(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator <=(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator >=(const MegaRational &ob1, const MegaRational &ob2);
	friend MegaRational operator +(const MegaRational &ob1, const MegaRational &ob2);
	friend MegaRational operator -(const MegaRational &ob1, const MegaRational &ob2);
	friend MegaRational operator *(const MegaRational &ob1, const MegaRational &ob2);
	friend MegaRational operator /(const MegaRational &ob1, const MegaRational &ob2);
	friend MegaRational operator -(const MegaRational &ob);

	friend void toCommonDenominator(MegaRational &ob1, MegaRational &ob2);

	MegaRational& operator =(const MegaRational &ob);
	string toString();
private:
	MegaInteger numerator;
	MegaNatural denominator;
};

#include "MegaRational.cpp"

#endif MEGA_RATIONAL