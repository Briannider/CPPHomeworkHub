#include <iostream>
#include "funciones.hpp"

int main(){
    Venta ventas[40];
    llenar_vector_ventas(ventas,40);
    mostrarAgrupado(ventas,40); //* Aqui se procesa el corte de control

    return 0;
}
