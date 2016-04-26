Polynom::Polynom()
{
	this->coefficients.push_front((MegaRational)0);
}

Polynom::Polynom(const Polynom &ob)
{
	this->coefficients = deque<MegaRational>(ob.coefficients);
}

Polynom::Polynom(const MegaRational *coeffs, long degree)
{
	for (long i = 0; i < degree; i++)
		this->coefficients.push_back(coeffs[i]);
}

Polynom::Polynom(const long *coeffs, long degree)
{
	for (long i = 0; i < degree; i++)
		this->coefficients.push_back((MegaRational)coeffs[i]);
}

Polynom::~Polynom()
{

}

long long Polynom::getDegree()
{
	return this->coefficients.size() - 1;
}

Polynom Polynom::fluxion()
{
	Polynom p;

	for (int i = 1; i <= this->getDegree(); i++)
		p.coefficients.push_front((this->coefficients[i])*(MegaRational)i);

	return p;
}


bool operator ==(const Polynom &p1, const Polynom &p2)
{
	if (p1.coefficients.size() != p2.coefficients.size())
		return false;
	for (int i = 0; i < p1.coefficients.size(); i++)
		if (p1.coefficients[i] != p2.coefficients[i])
			return false;
	return true;
}
bool operator !=(const Polynom &p1, const Polynom &p2)
{
	return !(p1 == p2);
}

Polynom operator +(const Polynom &p1, const Polynom &p2)
{
	Polynom res, tmp;
	if (p1.coefficients.size() >= p2.coefficients.size())
		res = p1, tmp = p2;
	else
		res = p2, tmp = p1;
	for (int i = 0; i < tmp.coefficients.size(); i++)
		res.coefficients[i] = res.coefficients[i] + tmp.coefficients[i];
	for (int i = res.coefficients.size(); i > 0 && res.coefficients[i] == (MegaRational)0; i--)
		res.coefficients.pop_back();
	return res;
}
Polynom operator -(const Polynom &p1, const Polynom &p2)
{
	return p1 + -p2;
}
Polynom operator /(const Polynom &p1, const Polynom &p2)
{
	Polynom res, _p1 = p1, _p2 = p2;
	if (_p2.getDegree() == 0)
	{
		cout << "Error! Division by zero in Polynom /.";
		return Polynom();
	}

	long long n = _p2.getDegree(), k = _p1.getDegree() - n;
	while (k >= 0)
	{
		res.coefficients.push_back(_p1.coefficients[k + n] / _p2.coefficients[n]);
		for (long long i = k + n; i >= k; i--)
			_p1.coefficients[i] = _p1.coefficients[i] -
			_p2.coefficients[i - k] * res.coefficients[k];
		k--;
	}

	return res;
}
Polynom operator %(const Polynom &p1, const Polynom &p2)
{
	return p1 - p2 * (p1 / p2);
}

Polynom operator *(const Polynom &p1, const Polynom &p2)
{
	Polynom p1Cpy = p1, p2Cpy = p2, res = Polynom();
	MegaRational p1Coefficient = p1Cpy.factorization(),
		p2Coefficient = p2Cpy.factorization();

	for (long long i = p2Cpy.coefficients.size() - 1; i >= 0; i--)
		res = res + (p1Cpy * p2Cpy.coefficients[i]).mulByXPowK(i);

	return res;
}

Polynom operator *(const Polynom &p, const MegaRational &a)
{
	Polynom res = p;
	if (a == (MegaRational)0)
	{
		res.coefficients.empty();
		res.coefficients.push_back((MegaRational)0);
		return res;
	}

	for (int i = 0; i < p.coefficients.size(); i++)
		res.coefficients[i] = res.coefficients[i] * a;
	return res;

}

Polynom operator -(const Polynom &p)
{
	return p * MegaRational(-1);
}

Polynom& Polynom::operator= (const Polynom &p)
{
	if (p != *this)
		coefficients = p.coefficients;
	return *this;
}

Polynom Polynom::mulByXPowK(long long k)
{
	if (*this != Polynom())
		if (k < 0)
			while (k++ && *this != Polynom())
				if (coefficients.size() > 1)
					coefficients.pop_front();
				else
					coefficients[0] = MegaRational(0);
		else
			while (k--)
				coefficients.push_front(MegaRational(0));
	return *this;
}

MegaRational Polynom::factorization()
{
	MegaNatural gcd, lcm = 1;
	MegaRational coefficent;

	if (*this != Polynom())
		return (MegaRational)0;

	gcd = coefficients[coefficients.size() - 1].getNumerator().toMegaNatural();
	for (long long i = coefficients.size() - 2; i >= 0; i--)
		if (coefficients[i] != (MegaRational)0)
			gcd = DiscreteMath::gcd(gcd, coefficients[i].getNumerator().toMegaNatural());

	for (long long i = coefficients.size() - 1; i >= 0; i--)
		lcm = DiscreteMath::lcm(lcm, coefficients[i].getDenominator());

	coefficent = coefficent * MegaRational(MegaInteger(gcd), lcm);

	for (long long i = coefficients.size() - 1; i >= 0; i--)
		coefficients[i] = coefficients[i] * MegaRational(MegaInteger(lcm), gcd);

	return coefficent;
}