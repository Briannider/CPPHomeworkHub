#include <string>
#include <string.h>
using namespace std;

struct Nodo {
	int info;
	Nodo* sgte;	
};

struct infoMenu{
	char nombre[100];
	float precio;
	char descripcion[50];
};

struct NodoMenu{
	infoMenu infoM;
	NodoMenu* sgte;	
};
struct infoPedidos {
	int cantidadPorciones;
	char Descrip[50];
	

};
struct 	NodoPedidos {
	infoPedidos info;
	NodoPedidos* sgte;
	
};
struct 	NodoPedidosCola {
	infoPedidos info;
	NodoPedidos* ColaFin;
	NodoPedidos* ColaFte;
	
};

struct InfoCliente {
	char Nombre[50+1];
	char Direccion [50+1];
  int telefono;
	NodoPedidos* pedidosAnt;
	
};

struct NodoCliente {
	InfoCliente info;
	NodoCliente* sgte;
};

#ifndef funciones
#define funciones

void agregar(int arr[], int n, int& len, int v);
void mostrar(int arr[], int len); 
int buscar(int arr[], int len, int v); 
void eliminar(int arr[], int& len, int pos);
void insertar(int arr[], int& len, int v, int pos); 
int insertarOrdenado(int arr[], int& len, int v); 
int buscaEInserta(int arr[], int& len, int v, bool& enc); 
void inicializar(int arr[], int n);
void burbujaAsc(int arr[],int len);
int busquedaBinaria(int arr[],int len, int v); //el vector tiene que estar ordenado
//Listas
void agregarNodo(Nodo* &lista, int x);
void mostrar(Nodo* lista);
void liberar(Nodo*&lista);
Nodo* buscar(Nodo* lista, int v);
void eliminar(Nodo*& lista, int v);
int eliminarPrimerNodo(Nodo*&lista);
Nodo* insertarOrdenado(Nodo*& lista, int v);
void ordenar(Nodo* &lista);
Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc);
//Pilas
void push(Nodo* & pila, int v);
int pop(Nodo*& pila);
//Colas
void encolar(Nodo* &colafte, Nodo* &colafin, int v);
int desencolar(Nodo* &colafte, Nodo* &colafin);
//TP 2 CUATRI
int AgregarMenu();
int AgregarCliente();
void MostrarMenu();
void GestionDeMenu(NodoMenu*& Menu, FILE*arch);
void OpcionesPrincipales(NodoMenu*& Menu,FILE*F);
void GestionDeClientes(NodoMenu*& Menu,FILE*arch);
void GestionDePedidos(NodoMenu*& Menu,FILE*arch);
void Facturacion(NodoMenu*& Menu,FILE*arch);
NodoMenu* buscar(NodoMenu* lista, infoMenu v);
void eliminar(NodoMenu*& lista, infoMenu v);
void agregarNodo(NodoMenu* &lista, infoMenu x);
int eliminarMenu(NodoMenu*& Menu);
#endif
