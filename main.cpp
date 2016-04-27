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
		cout << "incorrect type. You can try help\n";

	return 0;
}

void help()
{

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
		else if (!strcmp(argv[2], "+"))
			cout << "result: " << (a + b);
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

}

void ratApi(int argc, char **argv)
{

}

void plnApi(int argc, char **argv)
{

}