MegaNatural::MegaNatural() : MegaNaturalBase() {}
MegaNatural::MegaNatural(MegaNaturalBase &ob) : MegaNaturalBase(ob) {}
MegaNatural::MegaNatural(std::string str) : MegaNaturalBase(str) {}
MegaNatural::~MegaNatural() {}


//��������: ��������� ����� �� �����
void MegaNatural::multByK(int k)
{

}

//��������: ��������� ����� �� 10^k
void MegaNatural::multByTenPowK(int k)
{

}

//��������: ��������� ������������, ����������� �� �����
void MegaNatural::subNatMulK(MegaNatural &ob, int k)
{

}

//��������: ������ ����� �������� ��� ������� �� �����������
int MegaNatural::firstDigOfDivByNat(MegaNatural &ob)
{
	return 0;
}

//��������: ��� �����������
MegaNatural MegaNatural::gcd(MegaNatural &ob1, MegaNatural &ob2)
{
	return ob1;
}

//��������: ��� �����������
MegaNatural MegaNatural::lcm(MegaNatural &ob1, MegaNatural &ob2)
{
	return ob1;
}