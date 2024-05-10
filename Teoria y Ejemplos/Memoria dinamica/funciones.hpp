#include <string>
using namespace std;

struct info
{
    int id;
    string nombre;
    string apellido;
    int edad;
    int dni;
};
struct NodoPersona
{
    info dato;
    NodoPersona *sgte;
    NodoPersona *ant;
};

#ifndef funciones
#define funciones
// Listas
void agregarNodo(NodoPersona *&persona, info x);
void mostrar(NodoPersona *persona);
void liberar(NodoPersona *&persona);
#endif