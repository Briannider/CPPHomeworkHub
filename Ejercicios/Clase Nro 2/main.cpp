#include "funciones.hpp"
#include <iostream>
using namespace std;

int main()
{
    //! Año bisiesto:
    // cout << "El proximo anio bisiesto es: " << proxbisiesto(2005) << endl;

    //! Apareo:
    // int a = 5;
    // int b = 5;
    // int lenC = 0;
    // int c = a + b;
    // int vecA[a] = {1, 3, 4, 6, 7};
    // int vecB[b] = {0, 2, 5, 7, 8};
    // int vecC[c];
    // inicializar(vecC, c);
    // apareo(vecA, vecB, vecC, lenC, a, b, c);
    // mostrar(vecC, c);
    int a = 5;
    int b = 5;
    int lenC = 0;
    int c = a + b;
    int vecA[a] = {0, 1, 3, 4, 8};
    int vecB[b] = {0, 2, 5, 7, 8};
    int vecC[c];
    inicializar(vecC, c);
    unirVec(vecA, vecB, vecC, lenC, a, b, c);
    mostrar(vecC, c);

    return 0;
}