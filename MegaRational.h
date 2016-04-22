#ifndef MEGA_RATIONAL
#define MEGA_RATIONAL

#include "MegaInteger.h"
#include "DiscreteMath.h"

using namespace std;

class MegaRational
{
public:
	MegaRational();
	MegaRational(const MegaInteger &a);
	MegaRational(const MegaInteger &a, const MegaNatural &b);
	MegaRational(const MegaRational &a);
	~MegaRational();

	MegaRational& operator =(const MegaRational &ob);
	string toString();

	//Имя модуля: RED_Q_Q
	//Базовые модули: GCF_NN_N, DIV_ZZ_Z
	//Выполнил:
	void reduction();

	//Имя модуля: INT_Q_B
	//Базовые модули: -
	//Выполнил:
	bool isInteger();

	//Имя модуля: TRANS_Q_Z
	//Базовые модули: -
	//Выполнил:
	MegaInteger toMegaInteger();

	//Имя модуля: COM_QQ_D
	//Базовые модули: COM_ZZ_D, COM_NN_D
	//Выполнил:
	friend bool operator ==(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator !=(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator <(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator >(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator <=(const MegaRational &ob1, const MegaRational &ob2);
	friend bool operator >=(const MegaRational &ob1, const MegaRational &ob2);

	//Имя модуля: ADD_QQ_Q
	//Базовые модули: ADD_ZZ_Z, TCD_ZZ_Z, RED_Q_Q
	//Выполнил:
	friend MegaRational operator +(const MegaRational &ob1, const MegaRational &ob2);	

	//Имя модуля: SUB_QQ_Q
	//Базовые модули: ADD_QQ_Q, POZ_Q_Q
	//Выполнил:
	friend MegaRational operator -(const MegaRational &ob1, const MegaRational &ob2);

	//Имя модуля: MUL_QQ_Q
	//Базовые модули: MUL_ZZ_Z, RED_Q_Q
	//Выполнил:
	friend MegaRational operator *(const MegaRational &ob1, const MegaRational &ob2);

	//Имя модуля: DIV_QQ_Q
	//Базовые модули: MUL_ZZ_Z, COM_ZZ_D, RED_Q_Q
	//Выполнил:
	friend MegaRational operator /(const MegaRational &ob1, const MegaRational &ob2);

	//Имя модуля: POZ_Q_Q
	//Базовые модули: POZ_Z_Z
	//Выполнил:
	friend MegaRational operator -(const MegaRational &ob);

	//Имя модуля: TCD_Q_Q
	//Базовые модули: LCM_NN_N, MUL_ZZ_Z
	//Выполнил:
	friend void toCommonDenominator(MegaRational &ob1, MegaRational &ob2);
private:
	MegaInteger numerator;
	MegaNatural denominator;
};

#include "MegaRational.cpp"

#endif MEGA_RATIONAL