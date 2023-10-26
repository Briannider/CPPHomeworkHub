#include "funciones.hpp"
#include <iostream>
using namespace std;



 

void leerArch(FILE *arch, char nombre[21]){
    char caracter;
    arch = fopen("Alumno.dat", "rb");
    // Leer
    fread(&nombre, sizeof(nombre), 1, arch);


    while (!feof(arch))
    {
        cout << "El nombre es: " << nombre << endl;
        fread(&nombre, sizeof(nombre), 1, arch);
    }

    if (fclose(arch))
    {
        cout << "Hubo un error" << endl;
    }
    else
    {
        cout << "Se cerro correctamente" << endl;
    };
}