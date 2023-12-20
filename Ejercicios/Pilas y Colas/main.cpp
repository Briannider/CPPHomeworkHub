#include "funciones.hpp"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	/*Nodo* pila = NULL;
	push(pila,4);
	push(pila,5);
	push(pila,7);

	while(pila != NULL){
	   cout << pop(pila) << endl;
	}
	*/

	/*Nodo* colafte = NULL;
	Nodo* colafin = NULL;

	encolar(colafte,colafin,4);
	encolar(colafte,colafin,5);
	encolar(colafte,colafin,7);

	while(colafte != NULL){
	   cout << desencolar(colafte, colafin) << endl;
	}
	*/

	// Pilas - Ej 1
	/*Nodo * pila = NULL;
	push(pila,4);
	push(pila,3);
	push(pila,5);
	push(pila,6);
	push(pila,7);
	colocarPrimero(pila,10);

	while(pila != NULL){
	  cout << pop(pila) << endl;
	}
	*/

	// Pilas - Ej 2
	/*	Nodo* pila = NULL;
	  push(pila,4);
	  push(pila,3);
	  push(pila,5);
	  push(pila,6);
	  push(pila,7);

	  char fueExitoso = colocarTercero(pila,10);

	  cout << "El proceso fue existoso: " << fueExitoso << endl;

	  while(pila != NULL){
		  cout << pop(pila) << endl;
	  }
	  */

	// Pilas - Ej 3
	/*Nodo* pila = NULL;
	push(pila,4);
	push(pila,3);
	push(pila,5);
	push(pila,6);
	push(pila,7);

	char fueExitoso = colocarXenPosicionY(pila,10,5);
	cout << "El proceso fue existoso: " << fueExitoso << endl;

	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/
	// Pilas - Ej 4
	/*Nodo* pila = NULL;
	push(pila,10);
	push(pila,3);
	push(pila,10);
	push(pila,6);
	push(pila,10);
	push(pila,7);

	modificarValorXporValorY(pila,30,20);

	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/
	// Pilas - Ej 5
	/*
	NodoChar* pila = NULL;
	NodoChar* colafte = NULL;
	NodoChar* colafin = NULL;
	char letra;
	bool segundaParte = false;

	cout << "Ingresar por teclado una letra y apretar * para salir" << endl;
	cin >> letra;

	while(letra != '*'){

		if(letra == '.'){
			segundaParte = true;
		} else {
			if(segundaParte){
				encolar(colafte,colafin,letra);
			} else {
				push(pila,letra);
			}
		}

		cout << "Ingresar por teclado una letra y apretar * para salir" << endl;
		cin >> letra;
	}

	if(esInversa(pila,colafte,colafin)){
		cout << "Los conjuntos son inversos" << endl;
	} else {
		cout << "Los conjuntos no son inversos" << endl;
	}

	*/
	// Pilas - Ej 6
	/*

	NodoString* pila = NULL;
	string apellido;
	cout << "Ingresar un apellido, presione * para salir" << endl;
	cin >> apellido;

	while (apellido != "*"){
		push(pila,apellido);

		cout << "Ingresar un apellido, presione * para salir" << endl;
		cin >> apellido;
	}

	while(pila != NULL){
		cout << pop(pila) << endl;
	}
	*/

	// Pilas - Ej 7
	/*Nodo* pila = NULL;
	push(pila,20);
	push(pila,3);
	push(pila,9);
	push(pila,6);
	push(pila,35);
	push(pila,12);

	ordenarPila(pila);

	while(pila != NULL){
		cout << pop(pila) << endl;
	}
  */

	// Colas - Ejercicio 1
	/*NodoEstudiante* colafte = NULL;
	NodoEstudiante* colafin = NULL;

	infoEstudiante est;

	est.legajo = 24423;
	est.nya = "perez";
	est.curso = 1054;

	encolar(colafte,colafin,est);

	est.legajo = 46473;
	est.nya = "lopez";
	est.curso = 1053;

	encolar(colafte,colafin,est);

	char fueExitoso = eliminarDosNodos(colafte,colafin);
	cout << "El proceso fue existoso: " << fueExitoso << endl;
	*/
	// Colas - Ejercicio 2
	/*NodoEstudiante* colafte = NULL;
	NodoEstudiante* colafin = NULL;

	infoEstudiante est;

	est.legajo = 24423;
	est.nya = "perez";
	est.curso = 1054;

	encolar(colafte,colafin,est);

	est.legajo = 46473;
	est.nya = "lopez";
	est.curso = 1053;

	encolar(colafte,colafin,est);

	int cantNodos = contarNodos(colafte,colafin);
	cout << "La cola tiene: " << cantNodos << " nodos " << endl;
	*/
	// Colas - Ejercicio 3
	/*
	NodoEstudiante* colafteA = NULL;
	NodoEstudiante* colafinA = NULL;

	infoEstudiante est;

	est.legajo = 24423;
	est.nya = "perez";
	est.curso = 1054;

	encolar(colafteA,colafinA,est);

	est.legajo = 46473;
	est.nya = "lopez";
	est.curso = 1053;

	encolar(colafteA,colafinA,est);

	NodoEstudiante* colafteB = NULL;
	NodoEstudiante* colafinB = NULL;

	est.legajo = 23523;
	est.nya = "diaz";
	est.curso = 1054;

	encolar(colafteB,colafinB,est);

	est.legajo = 34473;
	est.nya = "dieguez";
	est.curso = 1053;

	encolar(colafteB,colafinB,est);

	NodoEstudiante* colafteC = NULL;
	NodoEstudiante* colafinC = NULL;

	unionColas(colafteA,colafinA,colafteB,colafinB,colafteC,colafinC);

	while(colafteC != NULL){
	  est = desencolar(colafteC,colafinC);
	  cout << est.nya << endl;
	}
	cout << "Cola A" << endl;
	while(colafteA != NULL){
	  est = desencolar(colafteA,colafinA);
	  cout << est.nya << endl;
	}

	*/
	// Colas - Ejercicio 4
	/*
	NodoEstudiante* colafte = NULL;
	NodoEstudiante* colafin = NULL;

   infoEstudiante est;

	est.legajo = 24423;
	est.nya = "perez";
	est.curso = 1054;

	encolar(colafte,colafin,est);

	est.legajo = 46473;
	est.nya = "lopez";
	est.curso = 1053;

	encolar(colafte,colafin,est);

	est.legajo = 23523;
	est.nya = "diaz";
	est.curso = 1054;

	encolar(colafte,colafin,est);

	est.legajo = 34473;
	est.nya = "dieguez";
	est.curso = 1053;

	encolar(colafte,colafin,est);
	imprimirCola(colafte,colafin);
	*/
}
