#include "funciones.hpp"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	NodoMenu *Menu = NULL;
	FILE *F;
	F = fopen("Precios.dat", "wb+");
	if (F == NULL)
	{
		cout << "Error al abrir el archivo" << endl;
	}
	// NodoCliente*  cliente = NULL;
	// NodoPedidos* Pedidos = NULL;
	// NodoPedidosCola * PedidosCola = NULL;
	OpcionesPrincipales(Menu, F);
	fclose(F);
	return 0;
}
