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
int busquedaBinaria(int arr[], int len, int v)
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
//! Final - cuil
void cargarDNI(unsigned dni[])
{
  for (int i = 0; i < 8; i++)
  {
    cout << "Ingrese el digito " << i + 1 << " del DNI: ";
    cin >> dni[i];
  }
}

//! Generacion Cuil
/*
EJEMPLO DNI 08424054, (0*3+8*2+4*7+2*6+4*5+0*4+5*3+4*2=99 -> (99+10)%11=10
El resto es 10 Sufijo=11-10 = 1, entonces, sufijo 1, como sexo varón prefijo 20, por tanto su CUIL es 20-08424054-1
*/
Cuil GetCuil(Sexo unSexo, const unsigned unDni[])
{

  Cuil aux;
  aux.sexo = unSexo;
  const unsigned factores[] = {3, 2, 7, 6, 5, 4, 3, 2};
  unsigned resultado = 0;
  int prefijo = 0;
  int sufijo;

  //* Paso 1 (multiplicacion de factores)
  for (int i = 0; i < 7; i++)
  {
    resultado += (unDni[i] * factores[i]);
  }
  //* Paso 2 (A la suma anterior se le suma 10 si es varón o 38 si es mujer)
  if (aux.sexo == "M")
  {
    resultado += 10;
  }
  else if (aux.sexo == "F")
  {
    resultado += 38;
  }
  //* Paso 3 (Se divide el resultado anterior entre 11 y se obtiene el resto)
  resultado = resultado % 11;

  if (resultado == 1 && aux.sexo == "M") //* Paso 4 (Si el resto es uno, entonces el prefijo es 23, y el sufijo es 9 para varón y 4 para mujer.)
  {
    prefijo = 23;
    sufijo = 9;
  }
  else if (resultado == 1 && aux.sexo == "F")
  {
    prefijo = 23;
    sufijo = 4;
  }
  else if (resultado == 0 && aux.sexo == "M") //* Paso 5 (Si el resto es cero, entonces el prefijo es 20 para varón y 27 para mujer, y el sufijo es cero.)
  {
    prefijo = 20;
    sufijo = 0;
  }
  else if (resultado == 0 && aux.sexo == "F") //* En cualquier otro caso el prefijo es 20 para varón y 27 para mujer, y el sufijo es 11 menos el resto.
  {
    prefijo = 27;
    sufijo = 0;
  }
  else
  {
    if (aux.sexo == "M")
    {
      prefijo = 20;
    }
    else
    {
      prefijo = 27;
    }
    sufijo = 11 - resultado;
  }

  aux.cuil[0] = prefijo / 10;
  aux.cuil[1] = prefijo % 10;

  for (int i = 2; i < 10; i++)
  {
    aux.cuil[i] = unDni[i - 2];
  }
  aux.cuil[10] = sufijo;

  cout << "prefijo: " << prefijo << endl;
  cout << "sufijo: " << sufijo << endl;
  return aux;
}
