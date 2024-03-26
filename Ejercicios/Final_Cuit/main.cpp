#include <iostream>
#include "funciones.hpp"
#include <string>
using namespace std;

int main()
{
    Cuil miCuil;
    cargarDNI(miCuil.dni);
    cout << "Ingrese el sexo ('F': femenino o 'M': masculino)" << endl;
    cin >> miCuil.sexo;
    miCuil = GetCuil(miCuil.sexo, miCuil.dni);
    cout << "El CUIL es: ";

    cout << miCuil.cuil[0] << miCuil.cuil[1] << "-";
    for (int i = 2; i < 10; i++)
    {
        cout << miCuil.cuil[i];
    }
    cout << "-" << miCuil.cuil[10] << endl;

    return 0;
}
