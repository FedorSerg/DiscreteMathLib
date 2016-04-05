#include "MegaNaturalBase.h"
#ifndef MEGA_NATURAL
#define MEGA_NATURAL

class MegaNatural : MegaNaturalBase
{
public:
	MegaNatural();
	MegaNatural(MegaNaturalBase &ob);
	~MegaNatural();

	//��������: ��������, �������� �� ����� 0
	//�������: (1/0)
	bool isZero();
	//��������: ��������� ����� �� �����
	void multByK(int k);
	//��������: ��������� ����� �� 10^k
	void multByTenPowK(int k);
	//��������: ��������� ������������, ����������� �� �����
	void subNatMulK(MegaNatural &ob, int k);
	//��������: ������ ����� �������� ��� ������� �� �����������
	int firstDigOfDivByNat(MegaNatural &ob);
	//��������: ��� �����������
	MegaNatural gcd(MegaNatural &ob1, MegaNatural &ob2);
	//��������: ��� �����������
	MegaNatural lcm(MegaNatural &ob1, MegaNatural &ob2);
};

#include "MegaNatural.cpp"
#endif