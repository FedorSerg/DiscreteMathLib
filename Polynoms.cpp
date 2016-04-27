MegaNatural getNextNum(string str, int& pos);

Polynom::Polynom()
{
	this->coefficients.push_front(MegaRational());
}

Polynom::Polynom(const Polynom &ob)
{
	coefficients = deque<MegaRational>(ob.coefficients);
}

Polynom::Polynom(const string str)
{
   int tmp, tmp1, tmp2;

   coefficients.clear();
   if (str.length() < 9)
	  return; 

   for (auto i = 0; i < str.length(); i++)
	  if (!isdigit(str[i]) && str[i] != 'x' && str[i] != '^' && str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '(' && str[i] != ')')
		 return;
	 
   tmp = 0;
   if (str[0] == '-' || str[0] == '+')
	  tmp++;

   do
   {
	  tmp1 = str.find("(", tmp);
	  if (tmp1 != tmp)
		 return;

	  tmp = ++tmp1;
	  while (tmp < str.size() && isdigit(str[tmp]))
		 tmp++;
	  if (tmp == tmp1)
		 return;

	  if (tmp != -1)
	  {
		 tmp1 = str.find("/", tmp);
		 if (tmp1 == -1 || (tmp1 - tmp) != 0)
			return;		

		 tmp = ++tmp1;
		 while (tmp < str.size() && isdigit(str[tmp]))
			tmp++;
		 if (tmp == tmp1)
			return;

		 tmp1 = str.find(")", tmp);
		 if (tmp1 == -1 || (tmp1 - tmp) != 0)
			return;

		 tmp = ++tmp1;
		 tmp1 = str.find("x^", tmp);
		 if (tmp1 == -1 || (tmp1 - tmp) != 0)
			return;

		 tmp1 += 2;
		 while (tmp1 < str.size() && isdigit(str[tmp1]))
			tmp1++;

		 if (tmp == tmp1)
			return;

		 if (tmp1 == str.size())
			break;

		 tmp2 = tmp = tmp1;
		 tmp = str.find("+", tmp);
		 tmp1 = str.find("-", tmp1);
		 if (tmp == -1 && tmp1 == -1)
			return;
		 
		 if (tmp == -1)
			tmp = tmp1;

		 if (tmp1 < tmp)
			tmp = tmp1;

		 if ((tmp - tmp2) != 0)
			return;
		 tmp++;
	  }
	  else
		 return;
   }
   while (true);

   MegaNatural lastCoef,b_lastCoef;
   int sign;
   MegaRational coef();
   bool first = true;
   int pos = 0;
   
   do
   {
	  if (first)
	  {
		 first = false;
		 if (str[0] == '-')
			sign = -1;
		 else
			sign = 1;

		 MegaInteger numerator(getNextNum(str, pos));
		 numerator = numerator*(MegaInteger)(-1);
		 MegaNatural denominator(getNextNum(str, pos));
		 coefficients.push_front(MegaRational(numerator, denominator));
		 lastCoef = getNextNum(str, pos);
		 continue;
	  }
	  tmp = str.find("+", pos);
	  tmp1 = str.find("-", pos);
	  if (tmp == -1 && tmp1 == -1)
		 break;

	  if (tmp != -1 && tmp1 != -1)
		 if (tmp < tmp1)
			sign = 1;
		 else
			sign = -1;

	  if (tmp == -1)
		 sign = -1;

	  if (tmp1 == -1)
		 sign = 1;

	  MegaInteger numerator(getNextNum(str, pos));
	  numerator = numerator*(MegaInteger) (-1);
	  MegaNatural denominator(getNextNum(str, pos));
	  coefficients.push_front(MegaRational(numerator, denominator));

	  b_lastCoef = lastCoef;
	  lastCoef = getNextNum(str, pos);
	  if (lastCoef >= b_lastCoef)
	  {
		 coefficients.clear();
		 coefficients.resize(0);
		 return;
	  } 
	  else
	  {
		 while ((b_lastCoef - (MegaNatural) 1) > lastCoef)
		 {
			b_lastCoef = b_lastCoef - (MegaNatural) 1;
			coefficients.push_front(MegaRational());
		 }
	  }
   }
   while (pos < str.size());
}

MegaNatural getNextNum(string str,int& pos)
{
   string res = "";

   while (pos < str.size() && !isdigit(str[pos]))
	  pos++;  

   while (pos < str.size() && isdigit(str[pos]))
   {
	  res += (str[pos]);
	  pos++;
   }	  
   return MegaNatural(res);
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
   if(this->coefficients.size() == 0)
	  return this->coefficients.size();
   else
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
	for (int i = res.coefficients.size(); i > 0 && res.coefficients[i] == MegaRational(); i--)
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
	if (a == MegaRational())
	{
		res.coefficients.empty();
		res.coefficients.push_back(MegaRational());
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
					coefficients[0] = MegaRational();
		else
			while (k--)
				coefficients.push_front(MegaRational());
	return *this;
}

MegaRational Polynom::factorization()
{
	MegaNatural gcd, lcm = 1;
	MegaRational coefficent;

	if (*this != Polynom())
		return MegaRational();

	gcd = coefficients[coefficients.size() - 1].getNumerator().toMegaNatural();
	for (long long i = coefficients.size() - 2; i >= 0; i--)
		if (coefficients[i] != MegaRational())
			gcd = DiscreteMath::gcd(gcd, coefficients[i].getNumerator().toMegaNatural());

	for (long long i = coefficients.size() - 1; i >= 0; i--)
		lcm = DiscreteMath::lcm(lcm, coefficients[i].getDenominator());

	coefficent = coefficent * MegaRational(MegaInteger(gcd), lcm);

	for (long long i = coefficients.size() - 1; i >= 0; i--)
		coefficients[i] = coefficients[i] * MegaRational(MegaInteger(lcm), gcd);

	return coefficent;
}