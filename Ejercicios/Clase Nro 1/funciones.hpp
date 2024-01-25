#include <string>
#include <string.h>
using namespace std;

//! Ejercicio Nro. 1 - Suma, multiplicacion y resta

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

//! Ejercicio 1 - Suma, multiplicacion y resta! //
int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);

#endif