#include "funciones.hpp"
#include <string>
#include <string.h>
#include <iostream>
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

// Pilas - Ej 1
void colocarPrimero(Nodo *&pila, int v)
{
	Nodo *pilaAux = NULL;

	while (pila != NULL)
	{
		push(pilaAux, pop(pila));
	}

	pop(pilaAux);
	pop(pilaAux);

	push(pila, v);

	while (pilaAux != NULL)
	{
		push(pila, pop(pilaAux));
	}
}

// Pilas - Ej 2
char colocarTercero(Nodo *&pila, int v)
{
	char ret;
	Nodo *pilaAux = NULL;

	while (pila != NULL)
	{
		push(pilaAux, pop(pila));
	}

	int contador = 0;

	while (contador < 2 && pilaAux != NULL)
	{
		push(pila, pop(pilaAux));
		contador++;
	}

	if (contador == 2)
	{
		ret = 'S';
		push(pila, v);
		while (pilaAux != NULL)
		{
			push(pila, pop(pilaAux));
		}
	}
	else
	{
		ret = 'N';
	}

	return ret;
}

// Pilas- Ej 3
char colocarXenPosicionY(Nodo *&pila, int x, int posY)
{
	char ret;
	Nodo *pilaAux = NULL;

	while (pila != NULL)
	{
		push(pilaAux, pop(pila));
	}

	int contador = 0;

	while (contador < (posY - 1) && pilaAux != NULL)
	{
		push(pila, pop(pilaAux));
		contador++;
	}

	if (contador == (posY - 1))
	{
		ret = 'S';
		push(pila, x);
		while (pilaAux != NULL)
		{
			push(pila, pop(pilaAux));
		}
	}
	else
	{
		ret = 'N';
	}

	return ret;
}

// Pilas- Ej 4
void modificarValorXporValorY(Nodo *&pila, int x, int y)
{
	Nodo *pilaAux = NULL;
	int valor;

	while (pila != NULL)
	{
		push(pilaAux, pop(pila));
	}

	while (pilaAux != NULL)
	{
		valor = pop(pilaAux);
		if (valor == x)
		{
			valor = y;
		}
		push(pila, valor);
	}
}

// Pilas- Ej 5
void push(NodoChar *&pila, char v)
{
	NodoChar *nuevo = new NodoChar();
	nuevo->info = v;
	nuevo->sgte = pila;
	pila = nuevo;
}

char pop(NodoChar *&pila)
{
	char ret = pila->info;
	NodoChar *aux = pila;
	pila = aux->sgte;
	delete aux;
	return ret;
}

void encolar(NodoChar *&colafte, NodoChar *&colafin, char v)
{
	NodoChar *nuevo = new NodoChar();
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

char desencolar(NodoChar *&colafte, NodoChar *&colafin)
{
	char ret = colafte->info;
	NodoChar *aux = colafte;
	colafte = colafte->sgte;
	if (colafte == NULL)
	{
		colafin = NULL;
	}
	delete aux;
	return ret;
}
bool esInversa(NodoChar *&pila, NodoChar *&colafte, NodoChar *&colafin)
{
	bool inversa = true;

	while (pila != NULL && colafte != NULL)
	{
		if (pop(pila) != desencolar(colafte, colafin))
		{
			inversa = false;
		}
	}

	if (pila != NULL || colafte != NULL)
	{
		inversa = false;
	}

	return inversa;
}

// Pilas- Ej 6
void push(NodoString *&pila, string v)
{
	NodoString *nuevo = new NodoString();
	nuevo->info = v;
	nuevo->sgte = pila;
	pila = nuevo;
}

string pop(NodoString *&pila)
{
	string ret = pila->info;
	NodoString *aux = pila;
	pila = aux->sgte;
	delete aux;
	return ret;
}

// Pila- Ej 7
void ordenarPila(Nodo *&pila)
{
	Nodo *listaAux = NULL;

	while (pila != NULL)
	{
		insertarOrdenado(listaAux, pop(pila));
	}

	while (listaAux != NULL)
	{
		push(pila, eliminarPrimerNodo(listaAux));
	}
}

// Colas - Ej 1
void encolar(NodoEstudiante *&colafte, NodoEstudiante *&colafin, infoEstudiante v)
{
	NodoEstudiante *nuevo = new NodoEstudiante();
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
infoEstudiante desencolar(NodoEstudiante *&colafte, NodoEstudiante *&colafin)
{
	infoEstudiante ret = colafte->info;
	NodoEstudiante *aux = colafte;
	colafte = colafte->sgte;
	if (colafte == NULL)
	{
		colafin = NULL;
	}
	delete aux;
	return ret;
}

char eliminarDosNodos(NodoEstudiante *&colafte, NodoEstudiante *&colafin)
{
	char ret;
	int contador = 0;

	while (contador < 2 && colafte != NULL)
	{
		desencolar(colafte, colafin);
		contador++;
	}

	if (contador == 2)
	{
		ret = 'S';
	}
	else
	{
		ret = 'N';
	}

	return ret;
}

// Colas - Ej 2
int contarNodos(NodoEstudiante *&colafte, NodoEstudiante *&colafin)
{
	NodoEstudiante *colafteAUX = NULL;
	NodoEstudiante *colafinAUX = NULL;

	int contador = 0;

	while (colafte != NULL)
	{
		encolar(colafteAUX, colafinAUX, desencolar(colafte, colafin));
		contador++;
	}

	colafte = colafteAUX;
	colafin = colafinAUX;

	return contador;
}

// Colas - Ej 2
void unionColas(NodoEstudiante *&colafteA, NodoEstudiante *&colafinA,
				NodoEstudiante *&colafteB, NodoEstudiante *&colafinB,
				NodoEstudiante *&colafteC, NodoEstudiante *&colafinC)
{

	NodoEstudiante *colafteAUXA = NULL;
	NodoEstudiante *colafinAUXA = NULL;
	NodoEstudiante *colafteAUXB = NULL;
	NodoEstudiante *colafinAUXB = NULL;

	infoEstudiante est;

	while (colafteA != NULL)
	{
		est = desencolar(colafteA, colafinA);
		encolar(colafteC, colafinC, est);
		encolar(colafteAUXA, colafinAUXA, est);
	}

	colafteA = colafteAUXA;
	colafinA = colafinAUXA;

	while (colafteB != NULL)
	{
		est = desencolar(colafteB, colafinB);
		encolar(colafteC, colafinC, est);
		encolar(colafteAUXB, colafinAUXB, est);
	}

	colafteB = colafteAUXB;
	colafinB = colafinAUXB;
}

// Colas - Ej 4
void push(NodoEstudiante *&pila, infoEstudiante v)
{
	NodoEstudiante *nuevo = new NodoEstudiante();
	nuevo->info = v;
	nuevo->sgte = pila;
	pila = nuevo;
}

infoEstudiante pop(NodoEstudiante *&pila)
{
	infoEstudiante ret = pila->info;
	NodoEstudiante *aux = pila;
	pila = aux->sgte;
	delete aux;
	return ret;
}
void imprimirCola(NodoEstudiante *&colafte, NodoEstudiante *&colafin)
{
	int cantNodos = contarNodos(colafte, colafin);
	infoEstudiante est;
	NodoEstudiante *pila = NULL;
	NodoEstudiante *colafteAUX = NULL;
	NodoEstudiante *colafinAUX = NULL;

	while (colafte != NULL)
	{
		est = desencolar(colafte, colafin);
		encolar(colafteAUX, colafinAUX, est);
		if (cantNodos > 3)
		{ // 100
			cout << est.nya << endl;
		}
		else
		{
			push(pila, est);
		}
	}

	while (pila != NULL)
	{
		est = pop(pila);
		cout << est.nya << endl;
	}

	colafte = colafteAUX;
	colafin = colafinAUX;
}