#include <iostream>
#include "funciones.hpp"
using namespace std; //El usar el espacio de nombres std hace que evites tener que usar el std::cout o std::cin utilizando solo cout y cin

int main()
{
     /*
     TIPOS DE APERTURA DE ARCHIVOS UTILIZANDO fopen() :

     w   ==> Crea un fichero de escritura. Si ya existe lo crea de nuevo. 
     w+  ==> Crea un fichero de lectura y escritura. Si ya existe lo crea de nuevo. 
     a   ==> Abre o crea un fichero para añadir datos al final del mismo.
     a+  ==> Abre o crea un fichero para leer y añadir datos al final del mismo.
     r   ==> Abre un fichero de lectura.
     r+  ==> Abre un fichero de lectura y escritura. 

     */




    /* ----------------------------LECTURA DE ARCHIVOS------------------------------ */

    FILE *arch; //Asignamos un puntero del tipo FILE
    arch = fopen("Alumno.dat", "rb+"); //A traves de la funcion fopen, ingresamos como parametro ("Ubicacion del archivo", "Tipo de apertura" )
    char nombre[21]; //Declaramos el tipo de dato que estamos queriendo leer del archivo 
                    //"El dato ya debe estar en el archivo almacenado con anterioridad para su lectura"

    // LEER EL ARCHIVO
    cout<<"Lista de nombres dentro de un archivo: "<<endl;
    cout<<""<<endl;
    while (!feof(arch)) //feof() es una funcion propia de C al igual que fopen() y otras. Su principal funcion es indicar el final del archivo.
    {
        fread(&nombre, sizeof(nombre), 1, arch); //fread() esta funcion se encarga de leer el archivo los parametros son los siguientes:
        //fread(&TipodeDato, Tamañodeldato,cantidadDatos,PunteroalArchivo);
        cout << nombre << endl;
        cout << "------" << endl;
    }
    fclose(arch); //Siempre tenemos que cerrar el archivo cuando terminamos de usarlo.

    return 0;
}