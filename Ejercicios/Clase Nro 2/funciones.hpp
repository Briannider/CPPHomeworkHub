#include <string>
#include <string.h>
using namespace std;

//! Ejercicio Nro. 1 - Suma, multiplicacion y resta

//!======================================!//

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
//! Ejercicio 2 - Apareo de vectores y union//
void apareo(int vecA[], int vecB[], int vecC[], int &lenC, int a, int b, int c);
void unionVec(int vecA[], int vecB[], int vecC[], int &lenC, int a, int b, int c);
//! Ejercicio 3 - Año bisiesto! //
int proxbisiesto(int AAAA);
//! Ejercicio 4 - Año bisiesto! //
void unirVec(int vecA[], int vecB[], int vecC[], int &lenC, int a, int b, int c);
#endif