#include "MegaNaturalBase.h"

class MegaNatural : MegaNaturalBase
{
public:
	MegaNatural();
	MegaNatural(MegaNaturalBase &ob);
	~MegaNatural();

	//��������: ��������, �������� �� ����� 0
	//�������: (1/0)
	virtual bool isZero() override;
	//��������: ��������� ����� �� �����
	virtual void multByK(int k) override;
	//��������: ��������� ����� �� 10^k
	virtual void multByTenPowK(int k) override;
	//��������: ��������� ������������, ����������� �� �����
	virtual void subNatMulK(MegaNaturalBase &ob, int k) override;
	//��������: ������ ����� �������� ��� ������� �� �����������
	virtual int firstDigOfDivByNat(MegaNaturalBase &ob) override;
	//��������: ��� �����������
	virtual MegaNaturalBase &gcd(MegaNaturalBase &ob) override;
	//��������: ��� �����������
	virtual MegaNaturalBase &lcm(MegaNaturalBase &ob) override;
};

#ifndef MEGA_NATURAL
#define MEGA_NATURAL
#include "MegaNatural.cpp"
#endif