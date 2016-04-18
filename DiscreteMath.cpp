MegaNatural DiscreteMath::gcd(const MegaNatural &a, const MegaNatural &b)
{
	if (a == 0 && b == 0) //a == (MegaNatural)0?
	{
		cout << "Error! Incorrect numbers in gcd.";
		return 0;
	} 

	MegaNatural temp,  _a = a, _b = b;
	if (_a < _b)
	{
		temp = _a;
		_a = _b;
		_b = temp;
	}
	else
		temp = _b;

	while (temp != 0) //same
	{
		temp = _a % _b;
		_a = _b;
		_b = temp;
	}
	return _a;
}

MegaNatural DiscreteMath::lcm(const MegaNatural &a, const MegaNatural &b)
{
	if (a == 0 && b == 0)
		return 0;
	return a * b / gcd(a,b);
}

Polynom DiscreteMath::gcd(const Polynom &a, const Polynom &b)
{
	Polynom temp,  _a = a, _b = b;
	if ( _a.getDegree() < _b.getDegree() )
	{
		temp = _a;
		_a = _b;
		_b = temp;
	}
	else
		temp = _b;

	while (temp.getDegree() != 0) 
	{
		temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}