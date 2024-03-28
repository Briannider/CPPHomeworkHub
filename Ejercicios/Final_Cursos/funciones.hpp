#include <string>
#include <string.h>
using namespace std;

//! Ejercicio Nro. 1 - Listas
struct Libro
{
	string titulo;
	int anio;
};
struct NodoLibro
{
	Libro info;
	NodoLibro *sgte;
};

//!======================================!//
struct Nodo
{
	int info;
	Nodo *sgte;
};
struct NodoChar
{
	char info;
	NodoChar *sgte;
};

struct NodoString
{
	string info;
	NodoString *sgte;
};

struct infoEstudiante
{
	int legajo;
	string nya;
	int curso;
};

struct NodoEstudiante
{
	infoEstudiante info;
	NodoEstudiante *sgte;
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
// Listas - Ej 1
void agregarNodoLibro(NodoLibro *&lista, Libro x);
void mostrarLibros(NodoLibro *lista);
void liberarLista(NodoLibro *&lista);
/*
// Pilas - Ej 1
void colocarPrimero(Nodo *&pila, int v);
// Pilas - Ej 2
char colocarTercero(Nodo *&pila, int v);
// Pilas - Ej 3
char colocarXenPosicionY(Nodo *&pila, int x, int posY);
// Pilas - Ej 4
void modificarValorXporValorY(Nodo *&pila, int x, int y);
// Pilas - Ej 5
void pushchar(NodoChar *&pila, char v);
char popchar(NodoChar *&pila);
void encolarchar(NodoChar *&colafte, NodoChar *&colafin, char v);
char desencolarchar(NodoChar *&colafte, NodoChar *&colafin);
bool esInversa(NodoChar *&pila, NodoChar *&colafte, NodoChar *&colafin);
// Pilas - Ej 6
void pushstring(NodoString *&pila, string v);
string popstring(NodoString *&pila);
// Pila - Ej 7
void ordenarPila(Nodo *&pila);
// Colas - Ej 1
void encolarEst(NodoEstudiante *&colafte, NodoEstudiante *&colafin, infoEstudiante v);
infoEstudiante desencolarEst(NodoEstudiante *&colafte, NodoEstudiante *&colafin);
char eliminarDosNodos(NodoEstudiante *&colafte, NodoEstudiante *&colafin);
// Colas - Ej 2
int contarNodos(NodoEstudiante *&colafte, NodoEstudiante *&colafin);
// Colas - Ej 3
void unionColas(NodoEstudiante *&colafteA, NodoEstudiante *&colafinA,
				NodoEstudiante *&colafteB, NodoEstudiante *&colafinB,
				NodoEstudiante *&colafteC, NodoEstudiante *&colafinC);
// Colas - Ej 4
void pushEst(NodoEstudiante *&pila, infoEstudiante v);
infoEstudiante popEst(NodoEstudiante *&pila);
void imprimirCola(NodoEstudiante *&colafte, NodoEstudiante *&colafin);
*/
#endif