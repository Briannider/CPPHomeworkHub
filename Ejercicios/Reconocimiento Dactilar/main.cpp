#include "funciones.hpp"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(int argc, char **argv)
{
    FILE *arch = fopen("huellas.dat", "rb");
    NodoSospechoso *matriz[4][9];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            matriz[i][j] = NULL;
        }
    }

    cargarMatrizSospechosos(arch, matriz);
    emitirSospechosos(matriz, 3, 'c');
}
