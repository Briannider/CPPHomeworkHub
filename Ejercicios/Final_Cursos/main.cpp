#include "funciones.hpp"
#include <iostream>
using namespace std;

int main()
{

	// Final PromociÃ³n
	// Leo el contenido
	FILE *arch = fopen("novedades.dat", "rb");
	novedad reg;

	fread(&reg, sizeof(novedad), 1, arch);

	while (!feof(arch))
	{
		cout << reg.idCurso << " " << reg.idEstudiante << " " << reg.nroEvaluacion << " " << reg.nota << endl;
		fread(&reg, sizeof(novedad), 1, arch);
	}

	fclose(arch);

	NodoCurso *cursos = NULL;
	// Proceso los datos
	/*
	int opcion = -1;
	do
	{
		cout << "1. Procesar novedades" << endl;
		cout << "2. Agregar estudiante" << endl;
		cout << "3. Agregar nota" << endl;
		cout << "4. Calcular estadisticas" << endl;
		cout << "0. Salir" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			procesarNovedades("novedades.dat", cursos);
			break;
		case 2:
			// agregarEstudiante(cursos);
			break;
		case 3:
			// agregarNota(cursos);
			break;
		case 4:
			calcularEstadisiticas(cursos);
			break;
		default:
			break;
		}

	} while (opcion != 0);

	if (cursos != NULL)
	{
		liberar(cursos);
	}
	*/

	procesarNovedades("novedades.dat", cursos);
	calcularEstadisiticas(cursos);
	
	NodoCurso* auxC = cursos;
	NodoEstudiante * auxE;
	NodoNota* auxN;
	while(auxC != NULL){
		cout << "Id Curso: " << auxC->info.idCurso << endl;
		cout << "Cantidad de Aprobados: " << auxC->info.promocionados << endl;
		cout << "Cantidad de Regularizados: " << auxC->info.regularizados << endl;
		cout << "Cantidad de Recursantes: " << auxC->info.recursantes << endl;
		auxE = auxC->info.estudiantes;
		while(auxE != NULL){
			cout << "Id Estudiante: " << auxE->info.idEstudiante << endl;
			for(int i=0; i<4; i++){
				cout << "Instancia de Evaluacion: " << i+1 << endl;
				auxN = auxE->info.notas[i];
				while(auxN != NULL){
					cout << "Nota: " << auxN->info << endl;
					auxN = auxN->sgte;
				}
			}
			auxE = auxE->sgte;
		}
		auxC = auxC->sgte;
	}
	return 0;
}
