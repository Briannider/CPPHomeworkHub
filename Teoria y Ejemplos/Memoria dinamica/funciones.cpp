#include "funciones.hpp"
#include <iostream>
using namespace std;

// Listas
void agregarNodo(NodoPersona *&persona, info x)
{
    NodoPersona *nuevo = new NodoPersona();
    nuevo->dato = x;
    nuevo->sgte = NULL;
    nuevo->ant = NULL;

    if (persona == NULL)
    {
        persona = nuevo;
    }
    else
    {
        NodoPersona *aux = persona;
        while (aux->sgte != NULL)
        {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
        nuevo->ant = aux;
    }
}

void mostrar(NodoPersona *persona)
{
    while (persona != NULL)
    {
        cout << "Nombre: " << persona->dato.nombre << endl;
        cout << "Dni: " << persona->dato.dni << endl;
        cout << "Edad: " << persona->dato.edad << endl;
        cout << "ID: " << persona->dato.id << endl;
        cout << "---------------------------" << endl;
        persona = persona->sgte;
    }
}

void liberar(NodoPersona *&persona)
{
    NodoPersona *aux;
    while (persona != NULL)
    {
        aux = persona;
        persona = persona->sgte;
        persona->ant = NULL;
        delete aux;
    }
}