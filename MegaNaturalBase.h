class MegaNaturalBase
{
public:
	MegaNaturalBase();
	MegaNaturalBase(MegaNaturalBase &ob);
	~MegaNaturalBase();
	
	int getN();
	int getNumAt(int pos);
	void setNumAt(int pos, int val);

	void addRank(int val);
	void deleteRank();
	void reverse();
	char *toString();
	void clearFromZero();

	//��������: ��������� ����������� �����
	//�������(1,0,-1)
	virtual int compare(MegaNaturalBase &ob) = 0;
	//��������: ��������, �������� �� ����� 0
	//�������: (1/0)
	virtual bool isZero() = 0;
	//��������: ��������� � ����� 1
	virtual void plusOne() = 0;
	//��������: ��������� ������������ �����
	virtual void subNat(MegaNaturalBase &ob) = 0;
	//��������: ��������� ����� �� �����
	virtual void multByK(int k) = 0;
	//��������: ��������� ����� �� 10^k
	virtual void multByTenPowK(int k) = 0;
	//��������: ����������� ������������
	virtual void addNat(MegaNaturalBase &ob) = 0;
	//��������: ��������� ������������, ����������� �� �����
	virtual void subNatMulK(MegaNaturalBase &ob, int k) = 0;
	//��������: ��������� �� �����������
	virtual void multByNat(MegaNaturalBase &ob) = 0;
	//��������: ������ ����� ������� ��� ������� �� �����������
	virtual int firstDigOfDivByNat(MegaNaturalBase &ob) = 0;
	//��������: ������� �� �����������
	virtual void divByNat(MegaNaturalBase &ob) = 0;
	//��������: ������� �� ������� �� �����������
	//�������: ������� �� �������
	virtual MegaNaturalBase &modByNat(MegaNaturalBase &ob) = 0;
	//��������: ��� �����������
	virtual MegaNaturalBase &gcd(MegaNaturalBase &ob) = 0;
	//��������: ��� �����������
	virtual MegaNaturalBase &lcm(MegaNaturalBase &ob) = 0;

private:
	int n;
	unsigned char *num;
};

#ifndef MEGA_NATURAL_BASE
#define MEGA_NATURAL_BASE
#include "MegaNaturalBase.cpp"
#endif


