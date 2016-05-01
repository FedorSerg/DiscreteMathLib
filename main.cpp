#include <iostream>
#include <stdexcept>

#include "Polynoms.h"

using namespace std;

void help();
void natApi(int argc, char **argv);
void intApi(int argc, char **argv);
void ratApi(int argc, char **argv);
void plnApi(int argc, char **argv);

int main(int argc, char* argv[])
{
	if (argc == 2 && !strcmp(argv[1], "help"))
	{
		help();
		return 0;
	}

	if (argc != 5 && argc != 4)
	{
		cout << "incorrect input. You can try help\n";
		return -1;
	}

	if (!strcmp(argv[1], "nat"))
		natApi(argc, argv);
	else if (!strcmp(argv[1], "int"))
		intApi(argc, argv);
	else if (!strcmp(argv[1], "rat"))
		ratApi(argc, argv);
	else if (!strcmp(argv[1], "pln"))
		plnApi(argc, argv);
	else
	{
		cout << "incorrect type. You can try help\n";
		return -1;
	}

	return 0;
}

void help()
{
	cout << "1. First parameter is type of object:" << endl;
	cout << "     nat - Natural number" << endl;
	cout << "     int - Integer number" << endl;
	cout << "     rat - Rational number" << endl;
	cout << "     pln - Polynom" << endl;
	cout << "2. Second parameter is operator:" << endl;
	cout << "   Examples:" << endl;
	cout << "     / - divison:" << endl;
	cout << "     * - multiply:" << endl;
	cout << "     flux - fluxion:" << endl;
	cout << "3. Third (and fourth) parameters are arguments:" << endl;
	cout << "   Examples:" << endl;
	cout << "     nat - \"5\"" << endl;
	cout << "     int - \"-6\"" << endl;
	cout << "     rat - \"7/8\"" << endl;
	cout << "     pln - \"(6/7)x^3+(8/9)x^0\"" << endl;
}

void natApi(int argc, char **argv)
{
	try
	{
		MegaNatural a = MegaNatural(argv[3]);
		MegaNatural b = MegaNatural(argv[4]);

		if (!strcmp(argv[2], "=="))
			cout << "result: " << ((a == b) ? "true" : "false");
		else if (!strcmp(argv[2], "!="))
			cout << "result: " << ((a != b) ? "true" : "false");
		else if (!strcmp(argv[2], ">="))
			cout << "result: " << ((a >= b) ? "true" : "false");
		else if (!strcmp(argv[2], "<="))
			cout << "result: " << ((a <= b) ? "true" : "false");
		else if (!strcmp(argv[2], ">"))
			cout << "result: " << ((a > b) ? "true" : "false");
		else if (!strcmp(argv[2], "<"))
			cout << "result: " << ((a < b) ? "true" : "false");
		else if (!strcmp(argv[2], "+"))
			cout << "result: " << (a + b);
		else if (!strcmp(argv[2], "-"))
			cout << "result: " << (a - b);
		else if (!strcmp(argv[2], "/"))
			cout << "result: " << (a / b);
		else if (!strcmp(argv[2], "%"))
			cout << "result: " << (a % b);
		else
			cout << "unknown comand. You can try help\n";
	}
	catch (invalid_argument &exc)
	{
		cout << exc.what();
	}
}

void intApi(int argc, char **argv)
{
	try
	{
		MegaInteger a = MegaInteger(argv[3]);
		MegaInteger b = argc == 5 ? MegaInteger(argv[4]) : MegaInteger();

		if (argc == 5)
		{
			if (!strcmp(argv[2], "=="))
				cout << "result: " << ((a == b) ? "true" : "false");
			else if (!strcmp(argv[2], "!="))
				cout << "result: " << ((a != b) ? "true" : "false");
			else if (!strcmp(argv[2], ">="))
				cout << "result: " << ((a >= b) ? "true" : "false");
			else if (!strcmp(argv[2], "<="))
				cout << "result: " << ((a <= b) ? "true" : "false");
			else if (!strcmp(argv[2], ">"))
				cout << "result: " << ((a > b) ? "true" : "false");
			else if (!strcmp(argv[2], "<"))
				cout << "result: " << ((a < b) ? "true" : "false");
			else if (!strcmp(argv[2], "+"))
				cout << "result: " << (a + b);
			else if (!strcmp(argv[2], "-"))
				cout << "result: " << (a - b);
			else if (!strcmp(argv[2], "/"))
				cout << "result: " << (a / b);
			else if (!strcmp(argv[2], "%"))
				cout << "result: " << (a % b);
			else
				cout << "unknown comand + argument ct. You can try help\n";
		}
		else if (argc == 4 && !strcmp(argv[2], "abs"))
			cout << "result: " << a.abs();
		else if (!strcmp(argv[2], "check"))
		{
			b = a;
			cout << a << "  " << b;
		}
		else
			cout << "unknown comand + argument ct. You can try help\n";

	}
	catch (invalid_argument &exc)
	{
		cout << exc.what();
	}
}

void ratApi(int argc, char **argv)
{
	try
	{
		MegaRational a = MegaRational(argv[3]);
		MegaRational b = argc == 5 ? MegaRational(argv[4]) : MegaRational();

		if (argc == 5)
		{
			if (!strcmp(argv[2], "=="))
				cout << "result: " << ((a == b) ? "true" : "false");
			else if (!strcmp(argv[2], "!="))
				cout << "result: " << ((a != b) ? "true" : "false");
			else if (!strcmp(argv[2], "<="))
				cout << "result: " << ((a <= b) ? "true" : "false");
			else if (!strcmp(argv[2], ">="))
				cout << "result: " << ((a >= b) ? "true" : "false");
			else if (!strcmp(argv[2], "<"))
				cout << "result: " << ((a < b) ? "true" : "false");
			else if (!strcmp(argv[2], ">"))
				cout << "result: " << ((a > b) ? "true" : "false");
			else if (!strcmp(argv[2], "+"))
				cout << "result: " << (a + b);
			else if (!strcmp(argv[2], "-"))
				cout << "result: " << (a - b);
			else if (!strcmp(argv[2], "*"))
				cout << "result: " << (a * b);
			else if (!strcmp(argv[2], "/"))
				cout << "result: " << (a / b);
			else
				cout << "unknown comand + argument ct. You can try help\n";
		}
		else if (argc == 4)
		{
			if (!strcmp(argv[2], "reduct"))
			{
				a.reduction();
				cout << a;
			}
			else if (!strcmp(argv[2], "isint"))
				cout << (a.isInteger()) ? "true" : "false";
			else if (!strcmp(argv[2], "check"))
			{
				b = a;
				cout << b;
				cout << b.getNumerator() << "  " << b.getDenominator();
			}
			else
				cout << "unknown comand + argument ct. You can try help\n";
		}
		else if (argc == 3)
			if (!strcmp(argv[3], "help"))
			{
				cout << "Operators in polynom:" << endl;
				cout << "+" << endl;
				cout << "-" << endl;
				cout << "*" << endl;
				cout << "/" << endl;
				cout << "%" << endl;
				cout << "==" << endl;
				cout << "!=" << endl;
				cout << "!=" << endl;
				cout << "flux" << endl;
			}

	}
	catch (invalid_argument &exc)
	{
		cout << exc.what();
	}
}

void plnApi(int argc, char **argv)
{
	try
	{
		Polynom a = Polynom(argv[3]);
		Polynom b = (argc == 5) ? Polynom(argv[4]) : Polynom();

		if (argc == 5)
		{
			if (!strcmp(argv[2], "=="))
				cout << "result: " << ((a == b) ? "true" : "false");
			else if (!strcmp(argv[2], "!="))
				cout << "result: " << ((a != b) ? "true" : "false");
			else if (!strcmp(argv[2], "+"))
				cout << "result: " << (a + b);
			else if (!strcmp(argv[2], "-"))
				cout << "result: " << (a - b);
			else if (!strcmp(argv[2], "*"))
				cout << "result: " << (a * b);
			else if (!strcmp(argv[2], "/"))
				cout << "result: " << (a / b);
			else if (!strcmp(argv[2], "%"))
				cout << "result: " << (a % b);
			else
				cout << "unknown comand + argument ct. You can try help\n";
		}
		else if (argc == 4)
		{
			if (!strcmp(argv[2], "flux"))
				cout << a.fluxion();
			else
				cout << "unknown comand + argument ct. You can try help\n";
		}

	}
	catch (invalid_argument &exc)
	{
		cout << exc.what();
	}
}