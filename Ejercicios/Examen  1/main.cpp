#include "funciones.hpp"
#include <iostream>
using namespace std;

int main() {
  /* Primer Punto: Desarrolle una función que dado un año (AAAA) que se pasa por
  parámetro determine cuál será el próximo año bisiesto. Un año es bisiesto si
  es divisible entre cuatro y, no es divisible entre 100 o es divisible entre
  400. En el programa principal permitir ingresar el año e imprimir "El próximo
  año bisiesto es
  XXXX".
  int AAAAMMDD=19000222;
  cout<<"Proximo año bisiesto: "<<Proxbisiesto(AAAAMMDD)<<endl;
  */

  /* Segundo Punto : Crear un procedimiento que dados dos vectores A y B (10
  elementos como máximo cada uno), llene un vector C con la unión (sin
  repetidos) de los vectores A y B. El vector C será utilizado en el programa
  principal.

  int A[10]={1,3,5,7,9,11,13,15,17,19};
  int B[10]={0,2,4,6,8,10,12,14,16,18};
  int C[20];
  inicializar(C,20);
  Apareo(A, B, C, 20);
  mostrar(C,20);
  */

  /* Tercer Punto : Se tienen dos archivos (“suc1.dat” y “suc2.dat” - máximo 50
  registros c/u) con los datos de las ventas de dos sucursales de la ferretería
  “El tornillo feliz”. Los archivos contienen el código del artículo, la
  descripción del artículo, la cantidad vendida y el precio unitario. Es posible
  que algunos artículos hayan sido vendidos en una sucursal y no en la otra. Se
  pide informar los 3 artículos más vendidos y cuál fue la sucursal que más
  dinero recaudó.
  */

  // Se volco el archivo de los articulos en un vector y se ordenaron por
  // cantidad de ventas
  /*
  regSuc suc1[10]{
      {1, "Articulo 1", 10, 534},  {2, "Articulo 2", 8, 731},
      {3, "Articulo 3", 15, 1133}, {4, "Articulo 4", 30, 2123},
      {5, "Articulo 5", 2, 200},   {6, "Articulo 6", 20, 224},
      {7, "Articulo 7", 50, 1554}, {8, "Articulo 8", 15, 231},
      {9, "Articulo 9", 13, 444},  {10, "Articulo 10", 0, 999},
  };
  regSuc suc2[10]{
      {2, "Articulo 2", 8, 731},   {5, "Articulo 5", 2, 200},
      {7, "Articulo 7", 50, 1554}, {3, "Articulo 3", 15, 1133},
      {6, "Articulo 6", 20, 224},  {8, "Articulo 8", 15, 231},
      {1, "Articulo 1", 10, 534},  {4, "Articulo 4", 30, 2123},
      {10, "Articulo 10", 0, 999}, {9, "Articulo 9", 13, 444},
  };

  burbujaDesc(suc1, 10);
  burbujaDesc(suc2, 10);
  cout << "Sucursal N1" << endl;
  cout << "-----------" << endl;
  MostrarMasVendidos(suc1);
  cout << endl;
  cout << "Sucursal N2" << endl;
  cout << "-----------" << endl;
  MostrarMasVendidos(suc2);
  MaxRecaudacion(suc1,suc2, 10);
  */

  // Cuarto Punto :
  /*
    Se tiene un archivo “notas.dat” (250 registros como máximo) que
    contiene los siguientes datos: número de legajo, nombre de materia, código
    de curso y nota (número decimal). El nombre de la materia aparece solo 1 vez
    por estudiante. El archivo se encuentra ordenado por legajo. Se pide
    calcular: a. Cuál es el promedio de cada estudiante e informar por pantalla.
    b. Cuál es el estudiante que tiene mejor promedio (sólo hay 1 estudiante
    que cumple con este punto) e informar por pantalla.
    c. Cuál fue el estudiante que obtuvo la peor nota (puede haber más de 1
    estudiante que cumple con este punto) e informar por pantalla.
    d. Cuáles son las materias donde el estudiante aprobó (nota >= 6) y
    grabarlo en un archivo “aprobados.dat”, conteniendo el número de
    legajo, materia y código de curso
  */
  
  regNotas Materias[25][10];
  int i = 0;
  
  regNotas legajo[100]{
    {0, "Ingles", 10, 5},
    {0, "Educacion", 10, 5},
    {0, "Etica", 10, 5},
    {0, "Biologia", 10, 5},
    {0, "Fisica", 10, 5},
    {0, "Geografia", 10, 5},
    {0, "Quimica", 10, 5},
    {0, "Historia", 10, 5},
    {0, "Matematicas", 10, 5},
    {0, "Artes", 10, 5},
    {1, "Artes", 1, 6},   
    {1, "Matematicas", 1, 6},   
    {1, "Fisica", 1, 6},      
    {1, "Quimica", 1, 6},     
    {1, "Ingles", 1, 6},
    {1, "Etica", 1, 6},       
    {1, "Biologia", 1, 6},    
    {1, "Educacion Fisica", 1, 6},
    {1, "Geografia", 1, 6},
    {1, "Historia", 1, 6},    
    {2, "Etica", 2, 7},
    {2, "Biologia", 2, 7},
    {2, "Quimica", 2, 7},
    {2, "Matematicas", 2, 7},
    {2, "Fisica", 2, 7},
    {2, "Ingles", 2, 7},
    {2, "Geografia", 2, 7},
    {2, "Historia", 2, 7},
    {2, "Artes", 2, 7},
    {2, "Educacion", 2, 7},
    {3, "Matematicas", 3, 8},
    {3, "Fisica", 3, 8},
    {3, "Quimica", 3, 8},  
    {3, "Ingles", 3, 8},
    {3, "Etica", 3, 8},   
    {3, "Biologia", 3, 8}, 
    {3, "Geografia", 3, 8},
    {3, "Historia", 3, 8},
    {3, "Educacion", 3, 8},   
    {3, "Artes", 3, 8},
    {4, "Matematicas", 4, 9},
    {4, "Fisica", 4, 9},
    {4, "Quimica", 4, 9},
    {4, "Ingles", 4, 9},
    {4, "Etica", 4, 9},
    {4, "Biologia", 4, 9},
    {4, "Geografia", 4, 9},
    {4, "Historia", 4, 9},
    {4, "Artes", 4, 9},
    {4, "Educacion", 4, 9},
    {5, "Matematicas", 5, 10},  
    {5, "Fisica", 5, 10},   
    {5, "Quimica", 5, 10},  
    {5, "Ingles", 5, 10}, 
    {5, "Etica", 5, 10}, 
    {5, "Geografia", 5, 10}, 
    {5, "Historia", 5, 10},
    {5, "Artes", 5, 10},     
    {5, "Educacion", 5, 10},
    {5, "Biologia", 5, 10},
    {6, "Matematicas", 6, 9},
    {6, "Fisica", 6, 9},
    {6, "Quimica", 6, 9},
    {6, "Ingles", 6, 9},
    {6, "Etica", 6, 9},
    {6, "Geografia", 6, 9},
    {6, "Historia", 6, 9},
    {6, "Artes", 6, 9},
    {6, "Educacion", 6, 9},
    {6, "Biologia", 6, 9},
    {7, "Matematicas", 7, 8},   
    {7, "Fisica", 7, 8},    
    {7, "Quimica", 7, 8}, 
    {7, "Ingles", 7, 8},    
    {7, "Etica", 7, 8},     
    {7, "Biologia", 7, 8},   
    {7, "Geografia", 7, 8},   
    {7, "Historia", 7, 8},   
    {7, "Artes", 7, 8},
    {7, "Educacion", 7, 8},  
    {8, "Matematicas", 8, 7},
    {8, "Fisica", 8, 7},
    {8, "Quimica", 8, 7},
    {8, "Ingles", 8, 7},
    {8, "Etica", 8, 7},
    {8, "Biologia", 8, 7},
    {8, "Geografia", 8, 7},
    {8, "Historia", 8, 7},
    {8, "Artes", 8, 7},
    {8, "Educacion", 8, 7},
    {9, "Matematicas", 9, 6},   
    {9, "Fisica", 9, 6},   
    {9, "Quimica", 9, 6},    
    {9, "Ingles", 9, 6},     
    {9, "Etica", 9, 6},     
    {9, "Biologia", 9, 6},  
    {9, "Geografia", 9, 6}, 
    {9, "Historia", 9, 6},   
    {9, "Artes", 9, 6},     
    {9, "Educacion", 9, 6}
  };
  
  char matAct[30+1];
  char matAnt[30+1];
  do {
  
    
  }while((strcmp(matAct,matAnt)==0) || i == 250);

  return 0;
}
