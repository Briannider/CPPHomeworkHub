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
//! Ejercicio 1!//
void llenar_vector_ventas(Venta ventas[], unsigned cantidad_maxima)
{
    srand(time(NULL)); // Inicializar generador de números aleatorios

    for (unsigned i = 0; i < (cantidad_maxima / 4); i++)
    {
        ventas[i].sucursal = 1;               // Sucursales 1
        ventas[i].dia = rand() % 31 + 1;      // Días entre 1 y 31
        ventas[i].venta = rand() % 10000 + 1; // Ventas entre 1 y 10000
    }
    for (unsigned i = 10; i < (cantidad_maxima / 2); i++)
    {
        ventas[i].sucursal = 2;               // Sucursales 2
        ventas[i].dia = rand() % 31 + 1;      // Días entre 1 y 31
        ventas[i].venta = rand() % 10000 + 1; // Ventas entre 1 y 10000
    }
    for (unsigned i = 20; i < (cantidad_maxima - 10); i++)
    {
        ventas[i].sucursal = 3;               // Sucursales 3
        ventas[i].dia = rand() % 31 + 1;      // Días entre 1 y 31
        ventas[i].venta = rand() % 10000 + 1; // Ventas entre 1 y 10000
    }
    for (unsigned i = 30; i < (cantidad_maxima); i++)
    {
        ventas[i].sucursal = 4;               // Sucursales 4
        ventas[i].dia = rand() % 31 + 1;      // Días entre 1 y 31
        ventas[i].venta = rand() % 10000 + 1; // Ventas entre 1 y 10000
    }
}

void mostrarAgrupado(Venta ventas[], unsigned cantidad_maxima)
{
    unsigned maxRecxSuc = 0;
    unsigned mayorVentaxSuc = 0;
    unsigned diaMayorVenta = 0;
    unsigned sucMenorRec = 0;
    unsigned menorRec = 10000000;
    unsigned sucAct = 0;
    unsigned i = 0;

    while (i != cantidad_maxima)
    {
        sucAct = ventas[i].sucursal;
        mayorVentaxSuc = 0;
        maxRecxSuc = 0;
        while (i != cantidad_maxima && ventas[i].sucursal == sucAct)
        {
            if (ventas[i].venta >= mayorVentaxSuc) //* Aqui se guarda la mayor venta del mes por dia
            {
                mayorVentaxSuc = ventas[i].venta;
                diaMayorVenta = ventas[i].dia;
            }

            maxRecxSuc += ventas[i].venta; //* Se incrementa el dinero recaudado por la sucursal
            i++;
        }
        cout << "La sucursal " << ventas[i - 1].sucursal << endl;
        cout << "Recaudo: $" << maxRecxSuc << endl;
        cout << "El dia de mayor recaudacion fue el " << diaMayorVenta;
        cout << " con el monto de: $" << mayorVentaxSuc << endl;
        if (menorRec >= maxRecxSuc)
        {
            menorRec = maxRecxSuc;
            sucMenorRec = ventas[i - 1].sucursal;
        }
    }
    cout << "La sucursal " << sucMenorRec << endl;
    cout << " fue la que menos recaudo con el total de: $" << menorRec << endl;
}