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

// Lista Circular
void agregarEnListaCircular(Nodo *&lista, int valor)
{
	Nodo *nuevo = new Nodo();
	nuevo->info = valor;
	nuevo->sgte = NULL;
	if (lista == NULL)
	{
		lista = nuevo;
		nuevo->sgte = lista;
	}
	else
	{
		Nodo *aux = lista;
		while (aux->sgte != lista)
		{
			aux = aux->sgte;
		}
		aux->sgte = nuevo;
		nuevo->sgte = lista;
	}
}

void recorrerListaCircular(Nodo *lista)
{
	Nodo *aux = lista;
	if (aux == NULL)
	{
		return;
	}

	do
	{
		cout << aux->info << endl;
		aux = aux->sgte;
	} while (aux != lista);
}

// Final Sospechosos
void cargarMatrizSospechosos(FILE *arch, NodoSospechoso *matriz[4][9])
{
	huella reg;
	infoSospe is;
	NodoSospechoso *sospebuscado;
	bool enc;

	fread(&reg, sizeof(huella), 1, arch);

	while (!feof(arch))
	{
		strcpy(is.apeNom, reg.apeNom);
		is.dni = reg.dni;
		is.dedos = NULL;

		sospebuscado = buscaEInsertaOrdenado(matriz[reg.tipo - 1][reg.subtipo - 1], is, enc);
		insertarOrdenado(sospebuscado->info.dedos, reg.dedo);

		fread(&reg, sizeof(huella), 1, arch);
	}

	fclose(arch);
}

void emitirSospechosos(NodoSospechoso *matriz[4][9], int tipo, char subtipo)
{
	NodoSospechoso *lista = matriz[tipo - 1][subtipo - 'a'];

	NodoDedo *sublista;

	while (lista != NULL)
	{
		cout << lista->info.dni << "  " << lista->info.apeNom << endl;

		sublista = lista->info.dedos;

		while (sublista != NULL)
		{
			switch (sublista->dedo)
			{
			case 1:
				cout << "pulgar mano derecha" << endl;
				break;
			case 2:
				cout << "indice mano derecha" << endl;
				break;
			case 3:
				cout << "medio mano derecha" << endl;
				break;
			case 4:
				cout << "anular mano derecha" << endl;
				break;
			case 5:
				cout << "menique mano derecha" << endl;
				break;
			case 6:
				cout << "pulgar mano izquierda" << endl;
				break;
			case 7:
				cout << "indice mano izquierda" << endl;
				break;
			case 8:
				cout << "medio mano izquierda" << endl;
				break;
			case 9:
				cout << "anular mano izquierda" << endl;
				break;
			case 10:
				cout << "menique mano izquierda" << endl;
				break;
			default:
				cout << "dedo erroneo" << endl;
				break;
			}

			sublista = sublista->sgte;
		}

		lista = lista->sgte;
	}
}

NodoSospechoso *buscaEInsertaOrdenado(NodoSospechoso *&lista, infoSospe v, bool &enc)
{
	NodoSospechoso *buscado = buscar(lista, v);

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

NodoSospechoso *buscar(NodoSospechoso *lista, infoSospe v)
{

	while (lista != NULL && lista->info.dni != v.dni)
	{
		lista = lista->sgte;
	}

	return lista;
}

NodoSospechoso *insertarOrdenado(NodoSospechoso *&lista, infoSospe v)
{
	NodoSospechoso *nuevo = new NodoSospechoso();
	nuevo->info = v;
	nuevo->sgte = NULL;

	NodoSospechoso *aux = lista;
	NodoSospechoso *ant = NULL;

	while (aux != NULL && strcmp(aux->info.apeNom, v.apeNom) <= 0)
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

NodoDedo *insertarOrdenado(NodoDedo *&lista, int v)
{
	NodoDedo *nuevo = new NodoDedo();
	nuevo->dedo = v;
	nuevo->sgte = NULL;

	NodoDedo *aux = lista;
	NodoDedo *ant = NULL;

	while (aux != NULL && aux->dedo <= v)
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


void agregar(int matriz[][10], int n, int &len, int v)
{

	if (len == n)
	{
		cout << "El vector esta lleno" << endl;
	}
	else
	{
		arr[len][] = v;
		len++;
	}

	return;
}