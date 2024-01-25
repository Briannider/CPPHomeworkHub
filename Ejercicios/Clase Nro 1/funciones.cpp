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

//!======================================!//
int sumar(int a, int b)
{
    return a + b;
}

int restar(int a, int b)
{
    if (a < b)
    {
        return a - b;
    }
    else
    {
        return b - a;
    }
}

int multiplicar(int a, int b)
{
    return a * b;
}