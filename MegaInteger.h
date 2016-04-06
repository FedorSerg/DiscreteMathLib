#ifndef MEGA_INTEGER
#define MEGA_INTEGER

#include "MegaNatural.h"
#include <string>

class MegaInteger 
{
public:
	MegaInteger();
	MegaInteger(MegaNatural &ob);
	MegaInteger(MegaInteger &ob);
	MegaInteger(std::string);
	~MegaInteger();

	//��������: ������ �����
	MegaInteger abs();
	//��������: �������������� ������ � �����������
	MegaNatural toMegaNatural();
	std::string toString();
private:
	MegaNatural num;
	bool isNegative;
};

#include "MegaInteger.cpp"

#endif
