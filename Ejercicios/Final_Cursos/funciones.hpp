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

//Final PromociÃ³n
//Archivo
struct novedad {
	int idCurso;
	int idEstudiante;
	int nroEvaluacion;
	int nota;
};

struct NodoNota {
	int info;
	NodoNota* sgte;
};

struct infoEstudiante {
	int idEstudiante;
	NodoNota* notas[4];
};

struct NodoEstudiante {
	infoEstudiante info;
	NodoEstudiante* sgte;
};

struct infoCurso {
	int idCurso;
	int promocionados;
	int regularizados;
	int recursantes;
    NodoEstudiante* estudiantes;
};

struct NodoCurso {
	infoCurso info;
	NodoCurso* sgte;
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
void procesarNovedades(string nombreArchivo, NodoCurso* &cursos);
void agregarNota(NodoCurso* &cursos,int idCurso,int idEstudiante,int nroEvaluacion,int nota);
NodoCurso* buscaEInsertaOrdenado(NodoCurso*& lista, infoCurso v, bool& enc);
NodoCurso* buscar(NodoCurso* lista, infoCurso v);
NodoCurso* insertarOrdenado(NodoCurso*& lista, infoCurso v);
NodoEstudiante* buscaEInsertaOrdenado(NodoEstudiante*& lista, infoEstudiante v, bool& enc);
NodoEstudiante* buscar(NodoEstudiante* lista, infoEstudiante v);
NodoEstudiante* insertarOrdenado(NodoEstudiante*& lista, infoEstudiante v);
void agregarNodo(NodoNota* &lista, int x);
void calcularEstadisiticas(NodoCurso* &cursos);
int getEstado(NodoNota* notas[]);
#endif