#include <string>
#include <string.h>
using namespace std;


typedef struct
{
    unsigned sucursal;
    unsigned dia;
    unsigned venta;
} Venta;

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

//! Ejercicio 1 - Corte de control en vectores //
void llenar_vector_ventas(Venta ventas[], unsigned cantidad_maxima);
void mostrarAgrupado(Venta ventas[],unsigned cantidad_maxima);
#endif