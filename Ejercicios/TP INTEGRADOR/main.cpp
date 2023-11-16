#include "funciones.hpp"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main() {
NodoMenu *Menu = NULL;
NodoCliente *Cliente = NULL;

FILE *F;
  
  // NodoPedidos* Pedidos = NULL;
  OpcionesPrincipales(Menu, Cliente, F);
  return 0;
}