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
	nuevo->sig = NULL;
	if (lista == NULL)
	{
		lista = nuevo;
	}
	else
	{
		Nodo *aux = lista;
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void mostrar(Nodo *lista)
{
	while (lista != NULL)
	{
		cout << lista->info << endl;
		lista = lista->sig;
	}
}

void liberar(Nodo *&lista)
{
	Nodo *aux;
	while (lista != NULL)
	{
		aux = lista;
		lista = lista->sig;
		delete aux;
	}
}

Nodo *buscar(Nodo *lista, int v)
{

	while (lista != NULL && lista->info != v)
	{
		lista = lista->sig;
	}

	return lista;
}

void eliminar(Nodo *&lista, int v)
{
	if (lista == NULL)
	{
		// La lista está vacía, no hay nada que eliminar
		return;
	}

	Nodo *aux = lista;
	Nodo *ant = NULL;

	while (aux != NULL && aux->info != v)
	{
		ant = aux;
		aux = aux->sig;
	}

	if (aux == NULL)
	{
		// No se encontró el elemento en la lista
		return;
	}

	if (ant != NULL)
	{
		// El elemento a eliminar no es el primero en la lista
		ant->sig = aux->sig;
	}
	else
	{
		// El elemento a eliminar es el primero en la lista
		lista = aux->sig;
	}

	delete aux;
}

int eliminarPrimerNodo(Nodo *&lista)
{
	int ret = lista->info;

	Nodo *aux = lista;
	lista = aux->sig;
	delete aux;

	return ret;
}

Nodo *insertarOrdenado(Nodo *&lista, int v)
{
	Nodo *nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;

	Nodo *aux = lista;
	Nodo *ant = NULL;

	while (aux != NULL && aux->info <= v)
	{
		ant = aux;
		aux = aux->sig;
	}

	if (ant == NULL)
	{
		lista = nuevo;
	}
	else
	{ // entró al while
		ant->sig = nuevo;
	}

	nuevo->sig = aux;

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
/*
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
*/

// pilas

void push(Nodo *&pila, int v)
{
	Nodo *nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = pila;
	pila = nuevo;
}

int pop(Nodo *&pila)
{
	int ret = pila->info;
	Nodo *aux = pila;
	pila = aux->sig;
	delete aux;
	return ret;
}

// Colas

void encolar(Nodo *&colafte, Nodo *&colafin, int v)
{
	Nodo *nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;

	if (colafte == NULL)
	{
		colafte = nuevo;
	}
	else
	{
		colafin->sig = nuevo;
	}

	colafin = nuevo;
}

int desencolar(Nodo *&colafte, Nodo *&colafin)
{
	int ret = colafte->info;
	Nodo *aux = colafte;
	colafte = colafte->sig;
	if (colafte == NULL)
	{
		colafin = NULL;
	}
	delete aux;
	return ret;
}

//! Examen Final - Criterio de Promocion!//
// Final PromociÃ³n
void agregarNodo(NodoNota *&lista, int x)
{

	NodoNota *nuevo = new NodoNota();
	nuevo->info = x;
	nuevo->sgte = NULL;
	if (lista == NULL)
	{
		lista = nuevo;
	}
	else
	{
		NodoNota *aux = lista;
		while (aux->sgte != NULL)
		{
			aux = aux->sgte;
		}
		aux->sgte = nuevo;
	}
};
NodoEstudiante *insertarOrdenado(NodoEstudiante *&lista, infoEstudiante v)
{
	NodoEstudiante *nuevo = new NodoEstudiante();
	nuevo->info = v;
	nuevo->sgte = NULL;

	NodoEstudiante *aux = lista;
	NodoEstudiante *ant = NULL;

	while (aux != NULL && aux->info.idEstudiante <= v.idEstudiante)
	{
		ant = aux;
		aux = aux->sgte;
	}

	if (ant == NULL)
	{
		lista = nuevo;
	}
	else
	{ // entrÃ³ al while
		ant->sgte = nuevo;
	}

	nuevo->sgte = aux;

	return nuevo;
}
NodoEstudiante *buscar(NodoEstudiante *lista, infoEstudiante v)
{

	while (lista != NULL && lista->info.idEstudiante != v.idEstudiante)
	{
		lista = lista->sgte;
	}

	return lista;
}
NodoEstudiante *buscaEInsertaOrdenado(NodoEstudiante *&lista, infoEstudiante v, bool &enc)
{
	NodoEstudiante *buscado = buscar(lista, v);

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
};

NodoCurso *insertarOrdenado(NodoCurso *&lista, infoCurso v)
{
	NodoCurso *nuevo = new NodoCurso();
	nuevo->info = v;
	nuevo->sgte = NULL;

	NodoCurso *aux = lista;
	NodoCurso *ant = NULL;

	while (aux != NULL && aux->info.idCurso <= v.idCurso)
	{
		ant = aux;
		aux = aux->sgte;
	}

	if (ant == NULL)
	{
		lista = nuevo;
	}
	else
	{ // entrÃ³ al while
		ant->sgte = nuevo;
	}

	nuevo->sgte = aux;

	return nuevo;
}
NodoCurso *buscar(NodoCurso *lista, infoCurso v)
{

	while (lista != NULL && lista->info.idCurso != v.idCurso)
	{
		lista = lista->sgte;
	}

	return lista;
}
NodoCurso *buscaEInsertaOrdenado(NodoCurso *&lista, infoCurso v, bool &enc)
{
	NodoCurso *buscado = buscar(lista, v);

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
};

void agregarNota(NodoCurso *&cursos, int idCurso, int idEstudiante, int nroEvaluacion, int nota)
{
	bool enc;
	infoCurso ic;
	ic.idCurso = idCurso;
	ic.promocionados = 0;
	ic.recursantes = 0;
	ic.regularizados = 0;
	ic.estudiantes = NULL;

	NodoCurso *cursoBuscado = buscaEInsertaOrdenado(cursos, ic, enc);

	infoEstudiante ie;
	ie.idEstudiante = idEstudiante;
	for (int i = 0; i < 4; i++)
	{
		ie.notas[i] = NULL;
	}

	NodoEstudiante *estudiante;

	if (!enc)
	{
		estudiante = insertarOrdenado(cursoBuscado->info.estudiantes, ie);
	}
	else
	{
		estudiante = buscaEInsertaOrdenado(cursoBuscado->info.estudiantes, ie, enc);
	}

	agregarNodo(estudiante->info.notas[nroEvaluacion - 1], nota);
};

void procesarNovedades(string nombreArchivo, NodoCurso *&cursos)
{
	FILE *arch = fopen("novedades.dat", "rb");
	novedad reg;

	fread(&reg, sizeof(novedad), 1, arch);

	while (!feof(arch))
	{
		agregarNota(cursos, reg.idCurso, reg.idEstudiante, reg.nroEvaluacion, reg.nota);
		fread(&reg, sizeof(novedad), 1, arch);
	}

	fclose(arch);
}

int getEstado(NodoNota *notas[])
{
	int promociona = 0;
	int regulariza = 0;
	int estado = 0;
	NodoNota *aux;

	for (int i = 0; i < 4; i++)
	{
		aux = notas[i];
		if (aux == NULL)
		{
			estado = 3;
			break;
		}
		while (aux->sgte != NULL)
		{
			aux = aux->sgte;
		}

		if (aux->info < 6)
		{
			estado = 3;
			break;
		}
		else if (aux->info >= 8)
		{
			promociona++;
		}
		else
		{
			regulariza++;
		}
	}

	if (estado != 3)
	{
		if (promociona == 4)
		{
			estado = 1;
		}
		else
		{
			estado = 2;
		}
	}

	return estado;
}

void calcularEstadisiticas(NodoCurso *&cursos)
{
	NodoCurso *auxC = cursos;
	NodoEstudiante *auxE;
	int estado;
	while (auxC != NULL)
	{
		auxE = auxC->info.estudiantes;
		while (auxE != NULL)
		{
			estado = getEstado(auxE->info.notas);
			switch (estado)
			{
			case 1:
				auxC->info.promocionados++;
				break;
			case 2:
				auxC->info.regularizados++;
				break;
			case 3:
				auxC->info.recursantes++;
				break;
			}
			auxE = auxE->sgte;
		}
		auxC = auxC->sgte;
	}
};
