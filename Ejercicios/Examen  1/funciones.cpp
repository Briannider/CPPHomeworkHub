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

// * Primer Parcial
// *! Primer Punto
/*
int Proxbisiesto(int fecha){
  fecha /= 10000;
  while((fecha)%4!=0 && (fecha)%100==0 || (fecha%400)!=0){
    fecha++;
  }
  return fecha;
}
*/

// *! Segundo Punto
/*
void Apareo(int A[], int B[], int C[], int n) {
  int len = 0;
  for(int i = 0; i<10; i++){
    agregar(C, n, len, B[i]);
    agregar(C, n, len, A[i]);
  }
}
*/

// *! Tercer Punto
/*
void burbujaDesc(regSuc arr[], int n) {
  regSuc temp;
  bool huboIntercambio = true;

  for (int i = 0; i < n - 1 && huboIntercambio; i++) {

    huboIntercambio = false;

    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j].cantVendida < arr[j + 1].cantVendida) {
        huboIntercambio = true;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void MostrarMasVendidos(regSuc arr[]) {

    cout<<"Los productos mas vendidos son: "<<endl;
    for (int i = 0; i < 3; i++) {
    cout << "------------------------------" << endl;
    cout << "Cod art: " << arr[i].codArt << endl;
    cout << "Producto: " << arr[i].descripcionArt << endl;
    cout << "Precio Unitario: " << arr[i].PrecioUnit << endl;
    cout << "Cantidad Vendida: " << arr[i].cantVendida << endl;
    cout << "------------------------------" << endl;
  }

  return;
}

void MaxRecaudacion(regSuc suc1[], regSuc suc2[], int n){
  int recaudacion1 = 0;
  int recaudacion2 = 0;
  for(int i = 0; i < n; i++){
  recaudacion1 += suc1[i].PrecioUnit * suc1[i].cantVendida;
  recaudacion2 += suc2[i].PrecioUnit * suc2[i].cantVendida;
  }
  if(recaudacion1 > recaudacion2){
  cout<<"La sucursal con mayor recaudacion es la sucursal N1 "<<endl;
  cout<<"Habiendo recaudado: "<<recaudacion1<<endl;
  }else{
  cout<<"La sucursal con mayor recaudacion es la sucursal N2 "<<endl;
  cout<<"Habiendo recaudado: S"<<recaudacion2<<endl;
  }
}
*/

// *! Cuarto Punto
void mostrarpromedio(regNotas Materias[][10], int filas, int columnas)
{
  float sum = 0;
  int pos = 0;
  for (int j = 0; j < columnas; j++)
  {
    for (int i = 0; i < filas; i++)
    {
      sum += Materias[i][j].nota;
      pos = i;
    }
    cout << "El promedio del estudiante con numero de legajo: " << Materias[pos][j].numLegajo << endl;
    cout << " es de:" << sum / 10 << endl;
    sum = 0;
  }
}

void mostrarmaxpromedio(regNotas Materias[][10], int filas, int columnas)
{
  int max = -1;
  int posc = 0;
  int posf = 0;
  float sum = 0;

  for (int j = 0; j < columnas; j++)
  {
    for (int i = 0; i < filas; i++)
    {
      sum += Materias[i][j].nota;
      if (max < sum / 10)
        max = sum/10;
        posc = j;
        posf = i;
    }
    sum = 0;
  }

  cout<<"El estudiante con el legajo:  "<<Materias[posf][posc].numLegajo;
  cout<<" obtuvo el mayor promedio con:  "<<max<<endl;

}

void mostrarminpromedio(regNotas Materias[][10], int filas, int columnas)
{
}