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
	~Polynom();

	const long long getDegree();
	Polynom fluxion(); 

	friend Polynom operator +(const Polynom &p1, const Polynom &p2);
	friend Polynom operator -(const Polynom &p1, const Polynom &p2);
	friend Polynom operator *(const Polynom &p, const MegaRational &a);
	friend Polynom operator *(const Polynom &p1, const Polynom &p2);
	friend Polynom operator /(const Polynom &p1, const Polynom &p2);
	friend Polynom operator %(const Polynom &p1, const Polynom &p2);

	Polynom operator -(const Polynom &p);
	Polynom &operator =(const Polynom &p);
private:
	deque<MegaRational> coefficients;

	Polynom mulByXPowK(MegaInteger k);
	MegaRational factorization();
};

#include "Polynoms.cpp"

#endif //POLYNOMS