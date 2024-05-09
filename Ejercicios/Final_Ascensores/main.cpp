#include "funciones.hpp"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{

  // Final - Listas doblemente enlazadas 1
  NodoAscensor *ascensor = NULL;
  infoAscensor info;

  info.piso = -3;
  info.cantSuben = 10;
  info.cantBajan = 7;

  agregarNodoListaDoble(ascensor, info);

  info.piso = -2;
  info.cantSuben = 4;
  info.cantBajan = 5;

  agregarNodoListaDoble(ascensor, info);

  info.piso = -1;
  info.cantSuben = 0;
  info.cantBajan = 1;

  agregarNodoListaDoble(ascensor, info);

  info.piso = 0;
  info.cantSuben = 4;
  info.cantBajan = 2;

  agregarNodoListaDoble(ascensor, info);

  info.piso = 3;
  info.cantSuben = 7;
  info.cantBajan = 2;

  agregarNodoListaDoble(ascensor, info);

  info.piso = 5;
  info.cantSuben = 0;
  info.cantBajan = 4;

  agregarNodoListaDoble(ascensor, info);

  NodoAscensor *unPisoActual = ascensor->arriba->arriba->arriba->arriba; // ascensor en piso 3

  unsigned distanciaPisoMasAlto;
  unsigned distanciaPisoMasBajo;

  info.piso = 4;
  info.cantSuben = 0;
  info.cantBajan = 1;

  NodoAscensor *unNuevoPiso = new NodoAscensor();
  unNuevoPiso->info = info;
  unNuevoPiso->arriba = NULL;
  unNuevoPiso->abajo = NULL;

  unsigned distanciaPB;

  distanciaPB = InsertarPisoArribaDelActualYMedir(unNuevoPiso, unPisoActual, distanciaPisoMasAlto,
                                                  distanciaPisoMasBajo);

  cout << "Imprimo Ascensor" << endl;
  NodoAscensor *aux = ascensor;

  while (aux != NULL)
  {
    cout << aux->info.piso << endl;
    aux = aux->arriba;
  }

  cout << "Distancia al piso mas alto " << distanciaPisoMasAlto << endl;

  cout << "Distancia al piso mas bajo " << distanciaPisoMasBajo << endl;

  cout << "Distancia a la planta baja " << distanciaPB << endl;

  // Final - Listas doblemente enlazadas 2
  /*NodoAscensor* ascensor = NULL;
  infoAscensor info;

  info.piso = -3;
  info.cantSuben = 10;
  info.cantBajan = 7;

  agregarNodoListaDoble(ascensor, info);

  info.piso = -2;
  info.cantSuben = 4;
  info.cantBajan = 5;

  agregarNodoListaDoble(ascensor, info);

  info.piso = -1;
  info.cantSuben = 0;
  info.cantBajan = 1;

  agregarNodoListaDoble(ascensor, info);

  info.piso = 0;
  info.cantSuben = 4;
  info.cantBajan = 2;

  agregarNodoListaDoble(ascensor, info);

  info.piso = 3;
  info.cantSuben = 7;
  info.cantBajan = 2;

  agregarNodoListaDoble(ascensor, info);

  info.piso = 5;
  info.cantSuben = 0;
  info.cantBajan = 4;

  agregarNodoListaDoble(ascensor, info);

  NodoAscensor* unPisoActual = ascensor->arriba->arriba->arriba; //ascensor en piso 0

  FILE * arch = fopen("diferenciaDePisos.dat","wb+");

  unsigned cantPisosEliminados = EliminarLosPisosPrimosArribaDe(unPisoActual,arch);


  cout << "La cantidad de pisos eliminados fueron: " << cantPisosEliminados << endl;

  rewind(arch);

  difSubenYBajan reg;

  fread(&reg, sizeof(difSubenYBajan),1, arch);

  while(!feof(arch)){
      cout << "Piso: " << reg.piso << " diferencia: " << reg.diferencia << endl;
    fread(&reg, sizeof(difSubenYBajan),1, arch);
  }


  fclose(arch);
 */
}
