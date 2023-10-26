#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include "funciones.hpp"
using namespace std;

int main()
{
    FILE *arch;
    arch = fopen("Alumno.dat", "rb+");
    char nombre[21];

    // LEER EL ARCHIVO
    cout<<"Lista de nombres dentro de un archivo: "<<endl;
    cout<<""<<endl;
    while (!feof(arch))
    {
        fread(&nombre, sizeof(nombre), 1, arch);
        cout << nombre << endl;
        cout << "------" << endl;
    }

    // ESCRIBIR EL ARCHIVO
           return 0;
}