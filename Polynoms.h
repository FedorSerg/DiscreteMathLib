#ifndef POLYNOMS
#define POLYNOMS

#include "MegaRational.h"
#include <deque>

using namespace std;

class Polynom
{
public:
	Polynom();
	Polynom(const Polynom &ob);
	Polynom::Polynom(const MegaRational *coeffs, long degree);
	Polynom::Polynom(const long *coeffs, long degree);
	~Polynom();

	const long long getDegree();
	Polynom fluxion(); 

	friend Polynom operator +(const Polynom &p1, const Polynom &p2);
	friend Polynom operator -(const Polynom &p1, const Polynom &p2);
	friend Polynom operator *(const Polynom &p, const MegaRational &a);
	friend Polynom operator *(const Polynom &p1, const Polynom &p2);
	friend Polynom operator /(const Polynom &p1, const Polynom &p2);
	friend Polynom operator %(const Polynom &p1, const Polynom &p2);

	friend bool operator ==(const Polynom &p1, const Polynom &p2);
	friend bool operator !=(const Polynom &p1, const Polynom &p2);

	Polynom operator -(const Polynom &p);
	Polynom &operator =(const Polynom &p);
	string toString();

private:
	deque<MegaRational> coefficients;

	Polynom mulByXPowK(long long k);
	MegaRational factorization();
};

#include "Polynoms.cpp"

#endif //POLYNOMS