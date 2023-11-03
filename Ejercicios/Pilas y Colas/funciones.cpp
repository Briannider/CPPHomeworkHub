#include <string>
#include <string.h>
#include <iostream>

struct Nodo
{
    int info;
    Nodo *sgte;
};

void encolar(Nodo *&frte, Nodo *&fin, int v)
{
    Nodo *nuevo = new Nodo();
    nuevo->info = v;
    nuevo->sgte = NULL;

    if (frte == NULL)
    {
        frte = nuevo;
    }
    else
    {
        fin->sgte = nuevo;
    };
    fin = nuevo;
}

int desencolar(Nodo *&frte, Nodo *&fin)
{
    int ret = frte->info;
    Nodo *aux = frte;
    frte = frte->sgte;
    if (frte == NULL)
    {
        fin = NULL;
    };
    delete aux;
    return ret;
}