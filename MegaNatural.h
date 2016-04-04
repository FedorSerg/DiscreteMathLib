#include "MegaNaturalBase.h"

class MegaNatural : MegaNaturalBase
{
public:
	MegaNatural();
	MegaNatural(MegaNaturalBase &ob);
	~MegaNatural();

	//��������: ��������, �������� �� ����� 0
	//�������: (1/0)
	bool isZero() override;
	//��������: ��������� ����� �� �����
	void multByK(int k) override;
	//��������: ��������� ����� �� 10^k
	void multByTenPowK(int k) override;
	//��������: ��������� ������������, ����������� �� �����
	void subNatMulK(MegaNaturalBase &ob, int k) override;
	//��������: ������ ����� �������� ��� ������� �� �����������
	int firstDigOfDivByNat(MegaNaturalBase &ob) override;
	//��������: ��� �����������
	MegaNaturalBase &gcd(MegaNaturalBase &ob) override;
	//��������: ��� �����������
	MegaNaturalBase &lcm(MegaNaturalBase &ob) override;
};

#ifndef MEGA_NATURAL
#define MEGA_NATURAL
#include "MegaNatural.cpp"
#endif