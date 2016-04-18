Polynom::Polynom()
{
   this->coefficients.push_front((MegaRational) 0);
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
	  this->coefficients.push_back((MegaRational) coeffs[i]);
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
	Polynom res;
	return res;
}
Polynom operator /(const Polynom &p1, const Polynom &p2)
{
	return p1;
}
Polynom operator %(const Polynom &p1, const Polynom &p2)
{
	return p1;
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
	Polynom res;
	return res;
}

Polynom Polynom::mulByXPowK(MegaInteger k)
{
	long i;
	for(i = 0; i < k; i = i + 1)
	{
		this->coefficients.push_back((MegaRational) 0);
	}
	return *this;
}

MegaRational factorization()
{
	MegaRational coefficient;
	return coefficient;
}