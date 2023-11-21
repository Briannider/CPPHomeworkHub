#include <string>
#include <string.h>
using namespace std;

struct Nodo {
  int info;
  Nodo* sgte;	
};

struct infoMenu{
  char nombre[50];
  float precio;
  char descripcion[100];
};

struct NodoMenu{
  infoMenu infoM;
  NodoMenu* sgte;	
};


struct infoPedidos{
  char menuSolicitado[50];
  float precio;
  int cantidadPorciones;
  char cliente[50+1];
};
struct NodoPedidosSolicitados {
  infoPedidos info;
  NodoPedidosSolicitados* sgte;

};
struct NodoPedidosPendientes {
  infoPedidos info;
  NodoPedidosPendientes* sgte;
};
struct NodoPedidosCompletados{
  infoPedidos info;
  NodoPedidosCompletados* sgte;
};
struct infoCliente {
  char Nombre[100];
  char Direccion [50+1];
  int telefono;
  NodoPedidosSolicitados* pedidosAnt;	
};

struct NodoCliente {
  infoCliente infoC;
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

// INTERFAZ:
void OpcionesPrincipales(NodoMenu*& Menu,NodoCliente*& Cliente, FILE*F);

// MENU:
void GestionDeMenu(NodoMenu*& Menu, FILE *F);
void AgregarMenu(FILE * F);
NodoMenu* buscar(NodoMenu* lista, infoMenu v);
void agregarNodoMenu(NodoMenu *&lista, infoMenu x);
void liberarLista(NodoMenu* lista);
void modificarMenu(NodoMenu*& Menu, FILE *F);
void MostrarMenu(infoMenu infoM, FILE *F);
void eliminar(NodoMenu*& lista, infoMenu v);
void eliminarMenu(NodoMenu*& Menu, FILE *F);

// CLIENTES:
void GestionDeClientes(NodoCliente*& Cliente,FILE*F);
void AgregarCliente(FILE * F);
void MostrarCliente(FILE * F);
NodoCliente* buscar(NodoCliente* lista, infoCliente v);
void agregarNodoCliente(NodoCliente* &lista, infoCliente x);
void liberarLista(NodoCliente* lista);
void ActualizarCliente(NodoCliente* &Cliente, FILE *F);
void eliminar(NodoCliente*& lista, infoCliente v);
void eliminarCliente(NodoCliente*& Cliente,FILE * F);

// PEDIDOS:
void GestionDePedidos(NodoMenu*& Menu,NodoCliente*& Cliente, FILE*arch,NodoPedidosCompletados *&pedidoCompletado,NodoPedidosPendientes *&colafte,NodoPedidosPendientes *&colafin);
void agregarNodo(NodoPedidosSolicitados* &lista, infoPedidos x);
void registrarPedido(NodoMenu *Menu, NodoCliente *Cliente, NodoPedidosPendientes *&colafte, NodoPedidosPendientes *&colafin);
NodoCliente* buscarCliente(NodoCliente* lista, const char* nombre);
NodoMenu* buscarMenu(NodoMenu* lista,  const char* nombre);
void marcarPedidoCompletado(NodoPedidosPendientes *&colafte, NodoPedidosPendientes *&colafin,NodoPedidosCompletados*& pedidosCompletados);
void push(NodoPedidosCompletados *&pila, infoPedidos pedido);
infoPedidos pop(NodoPedidosCompletados *&pila);
void encolarPedido(NodoPedidosPendientes*& colafte, NodoPedidosPendientes*& colafin, infoPedidos pedido);
infoPedidos desencolarPedido(NodoPedidosPendientes*& ColaFte, NodoPedidosPendientes*& ColaFin);
void mostrarPedidosPendientes(NodoPedidosPendientes *&colafte,NodoPedidosPendientes *&colafin);
void mostrarPedidosCompletados(NodoPedidosCompletados *&pedidoCompletado);
void agregarNodoCompletado(NodoPedidosCompletados *&lista, infoPedidos x);
void Facturacion(FILE*arch,NodoPedidosCompletados *&pedidoCompletado);
void FacturacionTotalClientes(FILE *F, NodoPedidosCompletados *&pedidoCompletado);
void FacturacionPorCliente(FILE *F, NodoPedidosCompletados *&pedidoCompletado) ;
#endif
