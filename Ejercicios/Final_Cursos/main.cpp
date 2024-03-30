#include "funciones.hpp"
#include <iostream>
using namespace std;

int main()
{
	Nodo *lista = NULL;
	
	agregarNodo(lista, 3);
	agregarNodo(lista, 7);
	agregarNodo(lista, 6);
	agregarNodo(lista, 4);
	mostrar(lista);
	return 0;
}
