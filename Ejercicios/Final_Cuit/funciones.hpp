#include <string>
#include <string.h>
using namespace std;

typedef string Sexo;

struct Nodo
{
  int info;
  Nodo *sgte;
};

struct Cuil
{
  Sexo sexo;
  unsigned dni[8];
  int cuil[11];
};

#ifndef funciones
#define funciones

void agregar(int arr[], int n, int &len, int v);
void mostrar(int arr[], int len);
int buscar(int arr[], int len, int v);
void eliminar(int arr[], int &len, int pos);
void insertar(int arr[], int &len, int v, int pos);
int insertarOrdenado(int arr[], int &len, int v);
int buscaEInserta(int arr[], int &len, int v, bool &enc);
void inicializar(int arr[], int n);
void burbujaAsc(int arr[], int len);
int busquedaBinaria(int arr[], int len, int v); // el vector tiene que estar ordenado
// Listas
void agregarNodo(Nodo *&lista, int x);
void mostrar(Nodo *lista);
void liberar(Nodo *&lista);
Nodo *buscar(Nodo *lista, int v);
void eliminar(Nodo *&lista, int v);
int eliminarPrimerNodo(Nodo *&lista);
Nodo *insertarOrdenado(Nodo *&lista, int v);
void ordenar(Nodo *&lista);
Nodo *buscaEInsertaOrdenado(Nodo *&lista, int v, bool &enc);
// Pilas
void push(Nodo *&pila, int v);
int pop(Nodo *&pila);
// Colas
void encolar(Nodo *&colafte, Nodo *&colafin, int v);
int desencolar(Nodo *&colafte, Nodo *&colafin);
//! Final - Generacion de CUIL
void cargarDNI(unsigned dni[]);
Cuil GetCuil(Sexo unSexo, const unsigned unDni[]);

#endif
