MegaRational::MegaRational()
{
	numerator = MegaInteger();
	denominator = MegaNatural(1);
}

MegaRational::MegaRational(const MegaInteger &a)
{
	numerator = a;
	denominator = MegaNatural(1);
}

MegaRational::MegaRational(const MegaInteger &a, const  MegaNatural &b)
{
	numerator = a;
	denominator = b;
	this->reduction();
}

MegaRational::MegaRational(const MegaRational &a)
{
	numerator = a.numerator;
	denominator = a.denominator;
	this->reduction();
}

MegaRational::~MegaRational() {}

void MegaRational::reduction()
{
	MegaNatural gcd = DiscreteMath::gcd(this->denominator, this->numerator.toMegaNatural());
	if (gcd > 1)
	{
		this->numerator = this->numerator / gcd;
		this->denominator = this->denominator / gcd;
	}
}
bool MegaRational::isInteger()
{
	return this->denominator == 1;
}
MegaInteger MegaRational::toMegaInteger()
{
	MegaInteger ob;
	if (this->denominator != 1)
		ob = this->numerator;
	else
		std::cout << "Error in MegaRational::toMegaInteger. Number isnt Integer" << endl;
	return ob;
}

bool operator ==(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational ob1Cpy = ob1, ob2Cpy = ob2;
	if (&ob1 == &ob2)
		return true;
	toCommonDenominator(ob1Cpy, ob2Cpy);
	return ob1Cpy.numerator == ob2.numerator &&
		ob1.denominator == ob2.denominator;
}
bool operator !=(const MegaRational &ob1, const MegaRational &ob2)
{
	return !(ob1 == ob2);
}
bool operator <(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational ob1Cpy = ob1, ob2Cpy = ob2;
	if (&ob1 == &ob2)
		return true;
	toCommonDenominator(ob1Cpy, ob2Cpy);
	return ob1Cpy.numerator < ob2Cpy.numerator;
}
bool operator >(const MegaRational &ob1, const MegaRational &ob2)
{
	return ob2 < ob1;
}
bool operator <=(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational ob1Cpy = ob1, ob2Cpy = ob2;
	if (&ob1 == &ob2)
		return true;
	toCommonDenominator(ob1Cpy, ob2Cpy);
	return ob1Cpy.numerator <= ob2Cpy.numerator;
}
bool operator >=(const MegaRational &ob1, const MegaRational &ob2)
{
	return ob2 <= ob1;
}

MegaRational operator +(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational res, ob1Cpy = ob1, ob2Cpy = ob2;
	toCommonDenominator(ob1Cpy, ob2Cpy);
	res.numerator = ob1Cpy.numerator + ob2Cpy.numerator;
	res.denominator = ob1Cpy.denominator;
	res.reduction();
	return res;
}

MegaRational operator -(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational res = ob1 + (-ob2);
	return res;
}

MegaRational operator *(const MegaRational &ob1, const MegaRational &ob2)
{
	MegaRational res = MegaRational(ob1.numerator * ob2.numerator,
		ob1.denominator * ob2.denominator);
	res.reduction();
	return res;
}
MegaRational operator /(const MegaRational &ob1, const MegaRational &ob2)
{
   MegaRational res;
   //ob2Cpy = ob2;
	//MegaInteger temp;
	////Переворот ob2Cpy
	//temp = ob2Cpy.numerator;
	//ob2Cpy.numerator = MegaInteger(ob2Cpy.denominator) * (temp < 0 ? -1 : 1);
	//ob2Cpy.denominator = temp.toMegaNatural();

	//res = (ob1 * ob2Cpy);
	//return res;
   if (ob2.numerator == 0)
   {
	  res.denominator = 1;
	  res.numerator = 0;
	  std::cout << "Error division by zero!\n";
	  return res;
   }

	res.numerator = ob1.numerator*ob2.denominator;
	res.denominator = (ob1.denominator*ob2.numerator).toMegaNatural();
	res.numerator = res.numerator * ((ob2.numerator > 0) ? 1 : -1);
	res.reduction();

	return res;
}
MegaRational operator -(const MegaRational &ob)
{
	MegaRational res;
	res.numerator = -ob.numerator;
	res.denominator = ob.denominator;
	return res;
}

MegaRational& MegaRational::operator =(const MegaRational &ob)
{
	MegaRational res;
	if (this != &ob)
	{
		res.numerator = ob.numerator;
		res.denominator = ob.denominator;
	}
	else res = ob;
	return res;
}

void toCommonDenominator(MegaRational &ob1, MegaRational &ob2)
{
	MegaNatural lcm = DiscreteMath::lcm(ob1.denominator, ob2.denominator);
	ob1.numerator = ob1.numerator * (lcm / ob1.denominator);
	ob2.numerator = ob2.numerator * (lcm / ob2.denominator);
	ob1.denominator = ob2.denominator = lcm;
}

string MegaRational::toString()
{
	string str = numerator.toString() + "/" + denominator.toString();
	return str;
}

ostream& operator<<(ostream &os, MegaRational &ob)
{
	os << ob.toString();
	return os;
}