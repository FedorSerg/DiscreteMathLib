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

Polynom fluxion()
{
	Polynom p;
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