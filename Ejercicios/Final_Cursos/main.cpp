#include "funciones.hpp"
#include <iostream>
using namespace std;

int main()
{
	regCurso archData;
	curso *cursos;
	FILE *arch;
	//! Creamos el file con datos para procesar
	arch = fopen("datos.dat", "wb");
	archData.idCurso = 1;
	archData.idEstudiante = 1;
	archData.nota = 7;
	archData.parcial = 2;
	//! Creamos los cursos
	fwrite(&archData, sizeof(archData), 1, arch);
	fclose(arch);

	int opcion = -1;
	do
	{
		cout << "1. Procesar novedades" << endl;
		cout << "2. Agregar estudiante" << endl;
		cout << "3. Agregar nota" << endl;
		cout << "4. Mostrar cursos" << endl;

		cin >> opcion;
		switch (opcion)
		{
		case 1:
			ProcesarNovedades(arch, cursos);
			break;

		default:
			break;
		}

	} while (opcion != 0);

	return 0;
}
