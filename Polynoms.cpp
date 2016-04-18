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
	if (p != *this)
		coefficients = p.coefficients;
	return *this;
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