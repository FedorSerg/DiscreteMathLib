#include <iostream>

MegaNatural::MegaNatural() : MegaNaturalBase::MegaNaturalBase() {}
MegaNatural::MegaNatural(MegaNaturalBase &ob) : MegaNaturalBase::MegaNaturalBase(ob) {}
MegaNatural::~MegaNatural() {}

//��������: ��������, �������� �� ����� 0
//�������: (1/0)
bool MegaNatural::isZero() 
{
	return true;
}

//��������: ��������� ����� �� �����
void MegaNatural::multByK(int k)
{

}

//��������: ��������� ����� �� 10^k
void MegaNatural::multByTenPowK(int k)
{

}

//��������: ��������� ������������, ����������� �� �����
void MegaNatural::subNatMulK(MegaNaturalBase &ob, int k)
{

}

//��������: ������ ����� �������� ��� ������� �� �����������
int MegaNatural::firstDigOfDivByNat(MegaNaturalBase &ob)
{
	return 0;
}

//��������: ��� �����������
MegaNaturalBase &MegaNatural::gcd(MegaNaturalBase &ob)
{
	return ob;
}

//��������: ��� �����������
MegaNaturalBase &MegaNatural::lcm(MegaNaturalBase &ob)
{
	return ob;
}