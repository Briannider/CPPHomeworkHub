#include "funciones.hpp"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){

    Nodo *frte = NULL;
    Nodo *fin = NULL;
    encolar(frte, fin, 1);
    encolar(frte, fin, 2);
    encolar(frte, fin, 3);
    encolar(frte, fin, 4);
    encolar(frte, fin, 5);

    while (fin != NULL)
    {
        cout << desencolar(frte, fin) << endl;
    }
    return 0;
}
