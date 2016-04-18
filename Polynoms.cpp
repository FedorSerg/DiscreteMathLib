Polynom::Polynom()
{

}
Polynom::Polynom(const Polynom &ob)
{

}
Polynom::~Polynom()
{

}

long long getDegree()
{
	return (*this).coefficients.size() - 1;
}

Polynom fluxion()
{
	Polynom p;
	return p;
}

Polynom operator +(const Polynom &p1, const Polynom &p2)
{
	Polynom res;
	Polynom tmp;
	long i;
	if(p1.getDegree() >= p2.getDegree())
	{
		res = p1;
		tmp = p2;
	}
	else
	{
		res = p2;
		tmp = p1;
	}
	for(i = res.coefficients.size(); i > tmp.coefficients.size(); i--)
	{
		res.coefficients[i] = res.coefficients[i] + tmp.coefficients[i];
	}
	return res;
}
Polynom operator -(const Polynom &p1, const Polynom &p2)
{
	Polynom res, tmp;
	long i;
	if(p1.getDegree() >= p2.getDegree())
	{
		res = p1;
		tmp = -p2;
	}
	else
	{
		res = -p2;
		tmp = p1;
	}
	for(i = res.coefficients.size(); i > tmp.coefficients.size(); i--)
	{
		res.coefficients[i] = res.coefficients[i] + tmp.coefficients[i];
	}
	i = 0;
	while (res.coefficients[i] == 0)
	{
		res.coefficients.pop_front();
		i++;
	}
	return res;
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
	Polynom res;
	res = p;
	long i;
	for(i = 0; i < res.coefficients.size(); i++)
	{
		res.coefficients[i] = -res.coefficients[i];
	}
	return res;
}

Polynom& Polynom::operator= (const Polynom &p)
{
	Polynom res;
	return res;
}

Polynom mulByXPowK(long k)
{
	long i;
	for(i = 0; i < k; i = i + 1)
	{
		*this.coefficients.push_back(0);
	}
	return *this;
}

MegaRational factorization()
{
	MegaRational coefficient;
	return coefficient;
}