#include <iostream>

MegaNatural::MegaNatural() : MegaNaturalBase() {}
MegaNatural::MegaNatural(MegaNaturalBase &ob) : MegaNaturalBase(ob) {}
MegaNatural::~MegaNatural() {}

//��������: ��������, �������� �� ����� 0
//�������: (1/0)
bool isZero()
{
	return true;
}

//��������: ��������� ����� �� �����
void multByK(int k)
{

}

//��������: ��������� ����� �� 10^k
void multByTenPowK(int k)
{

}

//��������: ��������� ������������, ����������� �� �����
void subNatMulK(MegaNaturalBase &ob, int k)
{

}

//��������: ������ ����� �������� ��� ������� �� �����������
int firstDigOfDivByNat(MegaNaturalBase &ob)
{
	return 0;
}

//��������: ��� �����������
MegaNatural gcd(MegaNatural &ob1, MegaNatural &ob2)
{
	return ob1;
}

//��������: ��� �����������
MegaNatural lcm(MegaNatural &ob1, MegaNatural &ob2)
{
	return ob1;
}