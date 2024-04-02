#include "funciones.hpp"
#include <iostream>
using namespace std;

int main()
{
	cursos curso;
	FILE * arch;
	ProcesarNovedades(arch,curso);
	int opcion = -1;
	do{
		cout<<"1. Procesar novedades"<<endl;
		cout<<"2. Agregar estudiante"<<endl;
		cout<<"3. Agregar nota"<<endl;
		cout<<"4. Mostrar cursos"<<endl;

		cin>>opcion;
		switch (opcion)
		{
		case 1:
			
			break;
		
		default:
			break;
		}

	}while(opcion != 0);

	return 0;
}
