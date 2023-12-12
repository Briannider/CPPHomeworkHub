#include <string>
#include <string.h>
using namespace std;

struct Nodo
{
  int info;
  Nodo *sgte;
};

// Ejercicio 3
/*
struct regSuc{
int codArt;
char descripcionArt[30+1];
int cantVendida;
int PrecioUnit;
};
*/

// Ejercicio 4
struct regNotas
{
  int numLegajo;
  char nombreMateria[30 + 1];
  int codCurso;
  float nota;
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

// * PRIMER PARCIAL

// *! Primer Punto
/*int Proxbisiesto(int fecha);*/
// *! Segundo Punto
// void Apareo(int A[], int B[], int C[], int n);
// *! Tercer Punto
/*
void burbujaDesc(regSuc arr[],int n); //Pequeñas modificaciones
void MostrarMasVendidos(regSuc arr[]); //Pequeñas modificaciones
void MaxRecaudacion(regSuc suc1[],regSuc suc2[], int n);
*/
// *! Cuarto Punto
void mostrarpromedio(regNotas Materias[][10], int filas, int columnas);
void mostrarmaxpromedio(regNotas Materias[][10], int filas, int columnas);
void mostrarminpromedio(regNotas Materias[][10], int filas, int columnas);
#endif