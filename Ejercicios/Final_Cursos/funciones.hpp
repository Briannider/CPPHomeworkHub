#include <string>
#include <string.h>
using namespace std;

//!======================================!//
struct Nodo
{
	int info;
	Nodo *sig;
};

//! Examen Final - Criterio de Promocion!//

struct evaluacion
{
	unsigned nota;
	evaluacion *sig;
};
struct estudiante
{
	unsigned id;
	evaluacion notas[4];
	estudiante *sig;
};

struct curso
{
	unsigned id;
	unsigned promocionados;
	unsigned regularizados;
	unsigned recursantes;
	estudiante estudiantes;
	curso *sig;
};

struct regCurso
{
	unsigned idCurso;
	unsigned idEstudiante;
	unsigned parcial;
	unsigned nota;
};

#ifndef funciones
#define funciones

void agregar(int arr[], int n, int &len, int v);
void mostrar(int arr[], int len);
// int buscar(int arr[], int len, int v);
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
// Nodo *buscar(Nodo *lista, int v);
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

//! Examen Final - Criterio de Promocion!//
void agregarCurso(curso *&cursos, regCurso auxcurso);
void ProcesarNovedades(FILE *arch, curso *cursos);

#endif