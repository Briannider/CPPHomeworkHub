#include <iostream>
#include "funciones.hpp"
using namespace std;

int main()
{
    // Initialize a pointer to a NodoPersona object, initially set to NULL
    NodoPersona *persona = NULL;

    // Define an info struct with the following fields: nombre, dni, edad, and id
    info dato;

    // Assign values to the fields of the info struct
    dato.nombre = "Moises";
    dato.dni = 30;
    dato.edad = 38;
    dato.id = 1;

    // Call the agregarNodo function, passing in the persona pointer and the info struct as arguments
    agregarNodo(persona, dato);

    // Update the values of the info struct
    dato.nombre = "Abraham";
    dato.dni = 0;
    dato.edad = 80;
    dato.id = 0;

    // Call the agregarNodo function again, passing in the same persona pointer and the updated info struct
    agregarNodo(persona, dato);

    // Repeat the process of updating the info struct and calling agregarNodo for the following names: Moises, David, Jesus
    dato.nombre = "Samuel";
    dato.dni = 20;
    dato.edad = 40;
    dato.id = 2;
    agregarNodo(persona, dato);

    dato.nombre = "David";
    dato.dni = 60;
    dato.edad = 40;
    dato.id = 4;
    agregarNodo(persona, dato);

    dato.nombre = "Jesus";
    dato.dni = 777777;
    dato.edad = 30;
    dato.id = 7;
    agregarNodo(persona, dato);

    // Call the mostrar function, passing in the persona pointer as an argument
    mostrar(persona);
    // Free the memory allocated for the persona pointer
    liberar(persona);

    // Return 0 from the main function
    return 0;
}