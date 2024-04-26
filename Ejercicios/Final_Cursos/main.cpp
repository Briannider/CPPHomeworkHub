#include "funciones.hpp"
#include <iostream>
using namespace std;

int main()
{

	// Final Promocion
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
	string file;
	cin >> file;
	procesarNovedades(file, cursos);
	calcularEstadisiticas(cursos);

	NodoCurso *auxC = cursos;
	NodoEstudiante *auxE;
	NodoNota *auxN;
	while (auxC != NULL)
	{
		cout << "Id Curso: " << auxC->info.idCurso << endl;
		cout << "Cantidad de Aprobados: " << auxC->info.promocionados << endl;
		cout << "Cantidad de Regularizados: " << auxC->info.regularizados << endl;
		cout << "Cantidad de Recursantes: " << auxC->info.recursantes << endl;
		auxE = auxC->info.estudiantes;
		while (auxE != NULL)
		{
			cout << "Id Estudiante: " << auxE->info.idEstudiante << endl;
			for (int i = 0; i < 4; i++)
			{
				cout << "Instancia de Evaluacion: " << i + 1 << endl;
				auxN = auxE->info.notas[i];
				while (auxN != NULL)
				{
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
