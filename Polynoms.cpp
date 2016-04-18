Polynom::Polynom(){}
Polynom::Polynom(const Polynom &ob)
{

}
Polynom::~Polynom()
{

}

const long long Polynom::getDegree()
{
	return this->coefficients.size() - 1;
}

Polynom Polynom::fluxion()
{
	Polynom p;

	for (int i = 1; i <= this->getDegree(); i++)
	   p.coefficients.push_front((this->coefficients[i])*(MegaRational) i);

	return p;
}


Polynom operator *(const Polynom &p1, const Polynom &p2)
{
	Polynom res;
	return res;
}
Polynom operator /(const Polynom &p1, const Polynom &p2)
{
	Polynom res, _p1 = p1, _p2 = p2;
	if (_p2.getDegree() == 0)
	{
		cout << "Error! Division by zero in Polynom /.";
		return Polynom();
	}

	long long n = _p2.getDegree(), k = _p1.getDegree - n;
	while (k >= 0)
	{
		res.coefficients.push_back( _p1.coefficients[k + n] / _p2.coefficients[n] );
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

Polynom operator *(const Polynom &p, const MegaRational &a)
{
	Polynom res;
	return res;
}

Polynom operator -(const Polynom &p)
{
	return p;
}

Polynom& Polynom::operator= (const Polynom &p)
{
	if (p != *this)
		coefficients = p.coefficients;
	return *this;
}

Polynom Polynom::mulByXPowK(long long k)
{
	if (*this != 0)
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

MegaRational factorization()
{
	MegaRational coefficient;
	return coefficient;
}