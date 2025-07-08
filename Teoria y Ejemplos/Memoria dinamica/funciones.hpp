#include <string>
using namespace std;

struct inf
{
    int id;
    string firstname;
    string lastname;
    int age;
    int dni;
};
struct NodePerson
{
    inf data;
    NodePerson *next;
    NodePerson *prev;
};

#ifndef funciones
#define funciones
// Listas
void agregarNodo(NodePerson *&persona, inf x);
void mostrar(NodePerson *person);
void liberar(NodePerson *&person);
#endif