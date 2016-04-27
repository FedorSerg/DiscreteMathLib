#ifndef MEGA_INTEGER
#define MEGA_INTEGER

#include "MegaNatural.h"
#include <string>

using namespace std;

class MegaInteger 
{
public:
	MegaInteger();
	MegaInteger(const MegaNatural &ob);
	MegaInteger(const MegaInteger &ob);
	MegaInteger(long long a);
	MegaInteger(string);
	~MegaInteger();

	string toString();
	MegaInteger& operator =(const MegaInteger &ob);

	//Имя модуля: TRANS_Z_N
	//Базовые модули: -
	//Выполнил: 
	MegaNatural toMegaNatural();

	//Имя модуля: ABS_Z_N
	//Базовые модули: -
	//Выполнил: 
	MegaInteger abs() const;


	//Имя модуля: COM_ZZ_D
	//Базовые модули: COM_NN_D
	//Выполнил: 
	friend bool operator ==(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator !=(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator <(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator >(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator <=(const MegaInteger &ob1, const MegaInteger &ob2);
	friend bool operator >=(const MegaInteger &ob1, const MegaInteger &ob2);

	//Имя модуля: MOD_ZZ_Z
	//Базовые модули: COM_ZZ_D, MOD_NN_N
	//Выполнил: 
	friend MegaInteger operator %(const MegaInteger &ob1, const MegaInteger &ob2);

	//Имя модуля: MUL_ZZ_Z
	//Базовые модули: COM_ZZ_D, MUL_NN_N
	//Выполнил:
	friend MegaInteger operator *(const MegaInteger &ob1, const MegaInteger &ob2);
	
	//Имя модуля: DIV_ZZ_Z
	//Базовые модули: COM_ZZ_D, DIV_NN_N
	//Выполнил:
	friend MegaInteger operator /(const MegaInteger &ob1, const MegaInteger &ob2);

	//Имя модуля: ADD_ZZ_Z
	//Базовые модули: COM_ZZ_D, ADD_NN_N
	//Выполнил:
	friend MegaInteger operator +(const MegaInteger &ob1, const MegaInteger &ob2);

	//Имя модуля: SUB_ZZ_Z
	//Базовые модули: ADD_ZZ_Z, MUL_ZM_Z
	//Выполнил:
	friend MegaInteger operator -(const MegaInteger &ob1, const MegaInteger &ob2);

	//Имя модуля: MUL_ZM_Z
	//Базовые модули: -
	//Выполнил:
	friend MegaInteger operator -(const MegaInteger &ob);
private:
	MegaNatural num;
	bool isNegative;
};

#include "MegaInteger.cpp"

#endif
