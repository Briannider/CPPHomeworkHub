#include <string>
#include <string.h>
using namespace std;

struct Nodo
{
	int info;
	Nodo *sgte;
};


// Ejercicio Huellas Sospechoso
struct huella
{
	int dni;
	char apeNom[50];
	int dedo;
	int tipo;
	int subtipo;
};

struct NodoDedo
{
	int dedo;
	NodoDedo *sgte;
};

struct infoSospe
{
	int dni;
	char apeNom[50];
	NodoDedo *dedos;
};

struct NodoSospechoso
{
	infoSospe info;
	NodoSospechoso *sgte;
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
// Arboles
void insertarNodoEnArbol(NodoArbol *&raiz, int valor);
void preOrden(NodoArbol *raiz);
void InOrden(NodoArbol *raiz);
void postOrden(NodoArbol *raiz);
// Lista Circular
void agregarEnListaCircular(Nodo *&lista, int valor);
void recorrerListaCircular(Nodo *lista);
// Final Sospechosos
void cargarMatrizSospechosos(FILE *arch, NodoSospechoso *matriz[4][9]);
void emitirSospechosos(NodoSospechoso *matriz[4][9], int tipo, char subtipo);
NodoSospechoso *insertarOrdenado(NodoSospechoso *&lista, infoSospe v);
NodoSospechoso *buscar(NodoSospechoso *lista, infoSospe v);
NodoSospechoso *buscaEInsertaOrdenado(NodoSospechoso *&lista, infoSospe v, bool &enc);
NodoDedo *insertarOrdenado(NodoDedo *&lista, int v);
#endif