#include "funciones.hpp"
#include <iostream>
using namespace std;

int sum(const int xs[], const int lenght)
{
	if (lenght == 0)
	{
		return 0;
	}

	return xs[lenght - 1] + sum(xs, lenght - 1);
}