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
	return 0;
}

Polynom fluxion()
{
	Polynom p;
	return p;
}

Polynom operator +(const Polynom &p1, const Polynom &p2)
{
	Polynom res = p1;
	Polynom tmp = p2;
	if(p1.getDegree() < p2.getDegree())
	{
		for(i = p2.getDegree() - p1.getDegree(); i > 0; i--)
		{
			res.coefficients.push_front(0);
		}
	}
	else if(p1.getDegree() > p2.getDegree())
	{
		for(i = p1.getDegree() - p2.getDegree(); i > 0; i--)
		{
			tmp.coefficients.push_front(0);
		}
	}
	for(i = 0; i <= p2.getDegree(); i++)
		{
			res.coefficients[i] = res.coefficients[i] + tmp.coefficients[i];
		}
	return res;
}
Polynom operator -(const Polynom &p1, const Polynom &p2)
{
	Polynom res = p1;
	Polynom tmp = p2;
	int i;
	if(p1.getDegree() < p2.getDegree())
	{
		for(i = p2.getDegree() - p1.getDegree(); i > 0; i--)
		{
			res.coefficients.push_front(0);
		}
	}
	else if(p1.getDegree() > p2.getDegree())
	{
		for(i = p1.getDegree() - p2.getDegree(); i > 0; i--)
		{
			tmp.coefficients.push_front(0);
		}
	}
	for(i = 0; i <= p2.getDegree(); i++)
		{
			res.coefficients[i] = res.coefficients[i] - tmp.coefficients[i];
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
	int i;
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

Polynom mulByXPowK(MegaInteger k)
{
	MegaInteger i;
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