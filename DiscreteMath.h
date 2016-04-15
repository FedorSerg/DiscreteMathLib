#ifndef DISCRETE_MATH
#define DISCRETE_MATH

#include "MegaNatural.h"

namespace DiscreteMath
{
	MegaNatural gcd(const MegaNatural &a, const MegaNatural &b);
	MegaNatural lcm(const MegaNatural &a, const MegaNatural &b);
	Polynom gcd(const Polynom &p1, const Polynom &p2);
}

#include "DiscreteMath.cpp"

#endif
