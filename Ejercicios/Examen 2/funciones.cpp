#include "funciones.hpp"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void agregar(int arr[], int n, int &len, int v)
{

  if (len == n)
  {
    cout << "El vector esta lleno" << endl;
  }
  else
  {
    arr[len] = v;
    len++;
  }

  return;
}

void mostrar(int arr[], int len)
{

  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << endl;
  }

  return;
}

int buscar(int arr[], int len, int v)
{
  int pos;
  int i = 0;

  while (i < len && arr[i] != v)
  {
    i++;
  }

  if (i == len)
  {
    pos = -1;
  }
  else
  {
    pos = i;
  }

  return pos;
}

void eliminar(int arr[], int &len, int pos)
{

  for (int i = pos; i < len - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  len--;

  return;
}

void insertar(int arr[], int &len, int v, int pos)
{

  for (int i = len - 1; i >= pos; i--)
  {
    arr[i + 1] = arr[i];
  }

  arr[pos] = v;
  len++;

  return;
}

int insertarOrdenado(int arr[], int &len, int v)
{
  int i = 0;

  while (i < len && arr[i] <= v)
  {
    i++;
  }

  insertar(arr, len, v, i);
  return i;
}

int buscaEInserta(int arr[], int &len, int v, bool &enc)
{
  int pos = buscar(arr, len, v);

  if (pos == -1)
  { // no esta
    enc = false;
    pos = insertarOrdenado(arr, len, v);
  }
  else
  {
    enc = true;
  }

  return pos;
}

void inicializar(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    arr[i] = 0;
  }
  return;
}

// burbuja
void burbujaAsc(int arr[], int len)
{
  int temp;
  bool huboIntercambio = true;

  for (int i = 0; i < len - 1 && huboIntercambio; i++)
  {

    huboIntercambio = false;

    for (int j = 0; j < len - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        huboIntercambio = true;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int busquedaBinaria(int arr[], int len,
                    int v)
{ // el vector tiene que estar ordenado
  int inicio = 0;
  int fin = len - 1;
  int medio = (inicio + fin) / 2;
  int pos;

  while (inicio <= fin)
  {
    if (arr[medio] == v)
    {
      break;
    }
    else if (v < arr[medio])
    {
      fin = medio - 1;
    }
    else
    { // v > arr[medio]
      inicio = medio + 1;
    }

    medio = (inicio + fin) / 2;
  }

  if (inicio > fin)
  {
    pos = -1;
  }
  else
  {
    pos = medio;
  }

  return pos;
}

// Listas
void agregarNodo(Nodo *&lista, int x)
{

  Nodo *nuevo = new Nodo();
  nuevo->info = x;
  nuevo->sgte = NULL;
  if (lista == NULL)
  {
    lista = nuevo;
  }
  else
  {
    Nodo *aux = lista;
    while (aux->sgte != NULL)
    {
      aux = aux->sgte;
    }
    aux->sgte = nuevo;
  }
}

void mostrar(Nodo *lista)
{
  while (lista != NULL)
  {
    cout << lista->info << endl;
    lista = lista->sgte;
  }
}

void liberar(Nodo *&lista)
{
  Nodo *aux;
  while (lista != NULL)
  {
    aux = lista;
    lista = lista->sgte;
    delete aux;
  }
}

Nodo *buscar(Nodo *lista, int v)
{

  while (lista != NULL && lista->info != v)
  {
    lista = lista->sgte;
  }

  return lista;
}

void eliminar(Nodo *&lista, int v)
{
  Nodo *aux = lista;
  Nodo *ant = NULL;
  while (aux != NULL && aux->info != v)
  {
    ant = aux;
    aux = aux->sgte;
  }

  if (ant != NULL)
  {
    ant->sgte = aux->sgte;
  }
  else
  {
    lista = aux->sgte;
  }

  delete aux;
}

int eliminarPrimerNodo(Nodo *&lista)
{
  int ret = lista->info;

  Nodo *aux = lista;
  lista = aux->sgte;
  delete aux;

  return ret;
}

Nodo *insertarOrdenado(Nodo *&lista, int v)
{
  Nodo *nuevo = new Nodo();
  nuevo->info = v;
  nuevo->sgte = NULL;

  Nodo *aux = lista;
  Nodo *ant = NULL;

  while (aux != NULL && aux->info <= v)
  {
    ant = aux;
    aux = aux->sgte;
  }

  if (ant == NULL)
  {
    lista = nuevo;
  }
  else
  { // entró al while
    ant->sgte = nuevo;
  }

  nuevo->sgte = aux;

  return nuevo;
}

void ordenar(Nodo *&lista)
{
  Nodo *listaAux = NULL;
  int v;
  while (lista != NULL)
  {
    v = eliminarPrimerNodo(lista);
    insertarOrdenado(listaAux, v);
  }
  lista = listaAux;
}

Nodo *buscaEInsertaOrdenado(Nodo *&lista, int v, bool &enc)
{
  Nodo *buscado = buscar(lista, v);

  if (buscado == NULL)
  { // no esta
    enc = false;
    buscado = insertarOrdenado(lista, v);
  }
  else
  {
    enc = true;
  }

  return buscado;
}

// pilas
void push(Nodo *&pila, int v)
{
  Nodo *nuevo = new Nodo();
  nuevo->info = v;
  nuevo->sgte = pila;
  pila = nuevo;
}

int pop(Nodo *&pila)
{
  int ret = pila->info;
  Nodo *aux = pila;
  pila = aux->sgte;
  delete aux;
  return ret;
}

// Colas
void encolar(Nodo *&colafte, Nodo *&colafin, int v)
{
  Nodo *nuevo = new Nodo();
  nuevo->info = v;
  nuevo->sgte = NULL;

  if (colafte == NULL)
  {
    colafte = nuevo;
  }
  else
  {
    colafin->sgte = nuevo;
  }

  colafin = nuevo;
}

int desencolar(Nodo *&colafte, Nodo *&colafin)
{
  int ret = colafte->info;
  Nodo *aux = colafte;
  colafte = colafte->sgte;
  if (colafte == NULL)
  {
    colafin = NULL;
  }
  delete aux;
  return ret;
}

//! Examen 2

//* Ejercicio 1

Nodo *Union(Nodo*& pila, Nodo*& colafrte, Nodo*& colafin){
  Nodo *lista = NULL;
  while(pila != NULL ){
        agregarNodo(lista, pop(pila));
        while(colafrte != NULL){
          agregarNodo(lista, desencolar(colafrte,colafin));
        }
  }
  ordenar(lista);
  return lista;
}
