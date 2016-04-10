static DiscreteMath::MegaNatural gcd(const MegaNatural &a, const MegaNatural &b)
{
	if (a == 0 && b == 0) //a == (MegaNatural)0?
	{
		cout << "Error! Incorrect numbers in gcd.";
		return 0;
	} 

	MegaNatural temp,  _a = a, _b = b;;
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

static DiscreteMath::MegaNatural lcm(const MegaNatural &a, const MegaNatural &b)
{
	if (a == 0 && b == 0)
		return 0;
	return a * b / gcd(a,b);
}