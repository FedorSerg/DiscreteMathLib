#include "MegaNaturalBase.h"

class MegaNatural : MegaNaturalBase
{
public:
	MegaNatural() : MegaNaturalBase();
	MegaNatural(MegaNaturalBase &ob) : MegaNaturalBase(ob);
	~MegaNatural() : ~MegaNaturalBase();

	//��������: ��������� ����������� �����
	//�������(1,0,-1)
	virtual int compare(MegaNaturalBase &ob) override;
	//��������: ��������, �������� �� ����� 0
	//�������: (1/0)
	virtual bool isZero() override;
	//��������: ��������� � ����� 1
	virtual void plusOne() override;
	//��������: ��������� ������������ �����
	virtual void subNat(MegaNaturalBase &ob) override;
	//��������: ��������� ����� �� �����
	virtual void multByK(int k) override;
	//��������: ��������� ����� �� 10^k
	virtual void multByTenPowK(int k) override;
	//��������: ����������� ������������
	virtual void addNat(MegaNaturalBase &ob) override;
	//��������: ��������� ������������, ����������� �� �����
	virtual void subNatMulK(MegaNaturalBase &ob, int k) override;
	//��������: ��������� �� �����������
	virtual void multByNat(MegaNaturalBase &ob) override;
	//��������: ������ ����� �������� ��� ������� �� �����������
	virtual int firstDigOfDivByNat(MegaNaturalBase &ob) override;
	//��������: ������� �� �����������
	virtual void divByNat(MegaNaturalBase &ob) override;
	//��������: ������� �� ������� �� �����������
	//�������: ������� �� �������
	virtual MegaNaturalBase &modByNat(MegaNaturalBase &ob) override;
	//��������: ��� �����������
	virtual MegaNaturalBase &gcd(MegaNaturalBase &ob) override;
	//��������: ��� �����������
	virtual MegaNaturalBase &lcm(MegaNaturalBase &ob) override;
};

#ifndef MEGA_NATURAL
#define MEGA_NATURAL
#include "MegaNatural.cpp"
#endif