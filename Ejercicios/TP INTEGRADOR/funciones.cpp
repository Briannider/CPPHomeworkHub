#include "funciones.hpp"
#include <string>
#include <string.h>
#include <iostream>
using namespace std;


void agregar(int arr[], int n, int& len, int v){
	
	if (len == n){
		cout << "El vector esta lleno" << endl;
	} else {
		arr[len] = v;
		len++;
	}
	
	return;
}

void mostrar(int arr[], int len){
	
	for(int i=0; i < len; i++){
		cout << arr[i] << endl;
	}
	
	return;
	
}

int buscar(int arr[], int len, int v){
	int pos;
	int i = 0;
	
	while (i < len && arr[i] != v) {
		i++;
	}
	
	if(i==len){
		pos = -1;
	} else {
		pos = i;
	}
	
	return pos;
}

void eliminar(int arr[], int& len, int pos){
	
	for(int i = pos; i < len - 1; i++){
		arr[i] = arr[i+1];
	}
	len--;
	
	return;
}

void insertar(int arr[], int& len, int v, int pos){
	
	for(int i = len-1; i >= pos ; i--){
		 arr[i+1] = arr[i];
	}
	
	arr[pos] = v;
	len++;
	
	return;
}

int insertarOrdenado(int arr[], int& len, int v){
	int i = 0;
	
	while( i < len && arr[i] <= v ){
		i++;
	}
	
	insertar(arr,len,v,i);
	return i;
}


int buscaEInserta(int arr[], int& len, int v, bool& enc){
	int pos = buscar(arr,len,v);
	
	if(pos == -1){ //no esta
		enc = false;
		pos = insertarOrdenado(arr,len,v);
	} else {
		enc = true;
	}
	
	return pos;
}

void inicializar(int arr[], int n){
	for(int i=0; i < n; i++){
		arr[i] = 0;
	}
	return;
}

//burbuja
void burbujaAsc(int arr[],int len){
	int temp;
	bool huboIntercambio = true;
	
	for(int i=0; i < len-1 && huboIntercambio; i++){
		
		huboIntercambio = false;
		
		for(int j=0; j < len-1-i; j++){		
			if(arr[j] > arr[j+1]){
				huboIntercambio = true;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}					
		}
	}
	
}

int busquedaBinaria(int arr[],int len, int v){//el vector tiene que estar ordenado
   int inicio = 0;
   int fin = len-1;
   int medio =  (inicio+fin)/2;
   int pos;
   
   while(inicio <= fin){
   		if(arr[medio] == v){
   			break;	
		} else if(v < arr[medio]){
			fin = medio - 1;
		} else {  // v > arr[medio]
			inicio = medio + 1;
		}
   		
   		medio = (inicio+fin)/2;
   }
   
   if(inicio > fin){
   		pos = -1;
   } else{
   	    pos = medio;
   }
   
   return pos;
}

//Listas
void agregarNodo(Nodo* &lista, int x){
     
     Nodo* nuevo = new Nodo();
     nuevo->info = x;
     nuevo->sgte = NULL;
	 if(lista==NULL){
	 	lista=nuevo;
	 } else{
	 	Nodo * aux = lista;
	 	while(aux->sgte != NULL){
	 		aux = aux->sgte;
		}
	 	aux->sgte = nuevo;
	 }	
}

void mostrar(Nodo* lista){
	while(lista != NULL){
		cout << lista->info << endl;
		lista = lista->sgte;
	}
}

void liberar(Nodo*& lista){	
	Nodo* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->sgte;
	    delete aux;
	}
}

Nodo* buscar(Nodo* lista, int v){
	
	while(lista != NULL && lista->info != v) {
		lista = lista->sgte;
	}
	
	return lista;
}

void eliminar(Nodo*& lista, int v){
	Nodo* aux = lista;
	Nodo* ant = NULL;
	while(aux != NULL && aux->info != v) {
		ant = aux;
		aux = aux->sgte;
	}
	
	if(ant != NULL){
		ant->sgte = aux->sgte;
	} else {
		lista = aux->sgte;
	}	
	
	delete aux;
}

int eliminarPrimerNodo(Nodo*&lista){
	int ret = lista->info;
	
	Nodo* aux = lista;
	lista = aux->sgte;
	delete aux;
	
	return ret;
}

Nodo* insertarOrdenado(Nodo*& lista, int v){
	Nodo* nuevo = new Nodo(); 
	nuevo->info = v;
	nuevo->sgte = NULL;
	
	Nodo* aux = lista;
	Nodo* ant = NULL;
	
	while(aux != NULL && aux->info <= v){
		ant = aux;
		aux = aux->sgte;
	}

    
	if(ant == NULL){
		lista = nuevo;
	} else { //entró al while
		ant->sgte = nuevo;
	}
	
	
	nuevo->sgte = aux;
	
	return nuevo;
	
}

void ordenar(Nodo* &lista){
	Nodo* listaAux = NULL;
	int v;
	while(lista != NULL){
		v = eliminarPrimerNodo(lista);	
		insertarOrdenado(listaAux,v);
	}
	lista = listaAux;
}

Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc){
	Nodo* buscado = buscar(lista,v);
	
	if(buscado == NULL){ //no esta
		enc = false;
		buscado = insertarOrdenado(lista,v);
	} else {
		enc = true;
	}
	
	return buscado;
}

//pilas
void push(Nodo* & pila, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sgte = pila ;
	pila = nuevo;
}

int pop(Nodo*& pila){
	int ret = pila->info;
	Nodo* aux = pila;
	pila = aux->sgte;
	delete aux;
	return ret;
}

//Colas
void encolar(Nodo* &colafte, Nodo* &colafin, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sgte = NULL;
	
	if(colafte == NULL){
		colafte = nuevo;
	} else {
		colafin->sgte = nuevo;
	}
	
	colafin = nuevo;
}


int desencolar(Nodo* &colafte, Nodo* &colafin){
	int ret = colafte->info;
	Nodo* aux = colafte;
	colafte = colafte->sgte;
	if(colafte == NULL){
		colafin = NULL;
	}
	delete aux;
	return ret;
}

//TP 2 CUATRI
int AgregarMenu() {
	infoMenu infoM;
	cout << "Ingrese nombre de plato" << endl;
	cin >> infoM.nombre;
	cout << "Ingrese precio del plato" << endl;
	cin >> infoM.precio;
	cout << "Ingrese descripcion" << endl;
	cin.ignore();
	cin.getline(infoM.descripcion,sizeof(infoM.descripcion));
	FILE *F;
    F = fopen("Menu.dat", "ab");
    if(F == NULL){
    	cout << "Error al abrir el archivo" << endl;
	}else{
		fwrite(&infoM, sizeof(infoMenu), 1, F);
		cout << "Pedido guardado en el archivo Menu.dat"<< endl;
	}
	fclose(F);
	    
	return 0;
}

void MostrarMenu(){
	infoMenu infoM;
	FILE *F;
    F = fopen("Menu.dat", "ab+");
	rewind(F);
    fread(&infoM, sizeof(infoMenu), 1, F);
	if (F == NULL){
	    cout << "Error al abrir el archivo" << endl;
	}else{
		cout << "Platillos en el menu: " << endl;
		while (!feof(F)){
			cout << "------------------------------------------------" << endl;
	        cout << "Nombre Plato: " << infoM.nombre << endl;
	        cout << "Precio del plato: " << infoM.precio << endl;
	        cout << "Descripcion del plato: " << infoM.descripcion << endl;
	        cout << "------------------------------------------------" << endl;
	        cout << endl;
	        fread(&infoM, sizeof(infoMenu), 1, F);
	    }
	}
}

NodoMenu* buscar(NodoMenu* lista, const char* nombre){
		 NodoMenu* current = lista;
		while (current != NULL) {
        if (strcmp(current->infoM.nombre, nombre) == 0) {
            return current; // Se encontró el plato
        }
        current = current->sgte;
    }

    return NULL; 
		
	}
	
void agregarNodo(NodoMenu* &lista, infoMenu x){
     
     NodoMenu* nuevo = new NodoMenu();
     nuevo->infoM = x;
     nuevo->sgte = NULL;
	 if(lista==NULL){
	 	lista=nuevo;
	 } else{
	 	NodoMenu * aux = lista;
	 	while(aux->sgte != NULL){
	 		aux = aux->sgte;
		}
	 	aux->sgte = nuevo;
	 }	
}

int modificarMenu(NodoMenu*& Menu) {
    // Abre el archivo en modo lectura
    FILE* arch = fopen("Menu.dat", "rb+");
	NodoMenu* lista= NULL;
	    infoMenu infoM;
    if (arch == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    fread(&infoM,sizeof(infoMenu),1,arch);
	while(!feof(arch)){
		agregarNodo(lista,infoM);
		fread(&infoM,sizeof(infoMenu),1,arch);
	}
    char platoAModificar[100];
    
    cout << "Ingrese el plato a modificar: ";
    cin >> platoAModificar;
    
    NodoMenu* nodoAModificar = buscar(lista, platoAModificar);
     
    if (nodoAModificar != NULL) {
        cout << "Ingrese nuevo nombre del plato: ";
        cin >> nodoAModificar->infoM.nombre;
        cout << "Ingrese nuevo precio del plato: ";
        cin >> nodoAModificar->infoM.precio;
        cout << "Ingrese nueva descripcion: ";
        cin.ignore();
        cin.getline(nodoAModificar->infoM.descripcion, sizeof(nodoAModificar->infoM.descripcion));

        // Reabre el archivo en modo escritura (borrando el contenido anterior)
        arch = fopen("Menu.dat", "rb+");
        
        if (arch == NULL) {
            cout << "Error al abrir el archivo" << endl;
            return -1;
        }

        NodoMenu* current = Menu;
        
        while (current != NULL) {
            fwrite(&(current->infoM), sizeof(infoMenu), 1, arch);
            current = current->sgte;
        }
        
        fclose(arch);
        cout << "Plato modificado y guardado en el archivo Menu.dat" << endl;
    } else {
        cout << "Plato no encontrado en el menu." << endl;
    }

    return 0;
}      
	void GestionDeMenu(NodoMenu*& Menu,FILE*arch){
	infoMenu reg;
	fread (&reg, sizeof(infoMenu),1,arch);
	int Salir;
	int opcion;
	
		while (opcion!=4)	{
			cout << "Ingrese 1 para cargar el menu" << endl;
			cout << "Ingrese 2 para modificar el menu " << endl;
			cout << "Ingrese 3 para mostrar el menu " << endl;
			cout << "Ingrese 4 para eliminar el menu" << endl;
			cout << "Ingrese 5 para salir" << endl;
			cin >> opcion;
			switch(opcion)
				{
			    case 1: 
				cout << "Usted ha seleccionado cargar el menu" << endl;
					AgregarMenu();
			    	break;
			    case 2: 
				cout << "Usted ha seleccionado modificar el menu" << endl;
					modificarMenu(Menu);
			    	break;
			    case 3: 
				cout << "Usted ha seleccionado mostrar el menu" << endl;
					MostrarMenu();
			    	break;
			    case 4: 
				cout << "Usted ha seleccionado eliminar el menu" << endl;
				eliminarMenu(Menu);
			    	break;
			    case 5: 
				cout << "Usted ha seleccionado salir" << endl;
			    break;
			    default: 
				cout << "OPCION INCORRECTA" << endl;
				
		}
	}
}

void eliminar(NodoMenu*& lista, const char* nombre){
	NodoMenu* aux = lista;
	NodoMenu* ant = NULL;
	while(aux != NULL && strcmp(lista->infoM.nombre, nombre) != 0) {
		ant = aux;
		aux = aux->sgte;
	}
	
	if(ant != NULL){
		ant->sgte = aux->sgte;
	} else {
		lista = aux->sgte;
	}	
	
	delete aux;
}
int eliminarMenu(NodoMenu*& Menu){
 FILE* arch = fopen("Menu.dat", "rb+");
	NodoMenu* lista= NULL;
	    infoMenu infoM;
    if (arch == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    fread(&infoM,sizeof(infoMenu),1,arch);
	while(!feof(arch)){
		agregarNodo(lista,infoM);
		fread(&infoM,sizeof(infoMenu),1,arch);
	}
    char platoAEliminar[100];
    
    cout << "Ingrese el plato a eliminar: ";
    cin >> platoAEliminar;
    
    NodoMenu* nodoAEliminar = buscar(lista, platoAEliminar);
    
    if(nodoAEliminar!=NULL){
    	eliminar(lista,platoAEliminar);
    	cout << "plato eliminado"<< endl;
	}else{
		cout << "no se encontro el plato a eliminar" << endl;
	}
	}
	
/*	void GestionDePedidos(NodoMenu*& Menu,FILE*arch){
	
	}
	
	void Facturacion(NodoMenu*& Menu,FILE*arch){
	
	}
	*/
	void GestionDeClientes(NodoMenu*& Menu,FILE*arch){
	infoMenu reg;
	fread (&reg, sizeof(infoMenu),1,arch);
	int Salir;
	int opcion;
	
		while (opcion!=4)
		{
			cout << "Ingrese 1 para agregar un cliente" << endl;
			cout << "Ingrese 2 para modificar informacion de un cliente " << endl;
			cout << "Ingrese 3 para eliminar un cliente" << endl;
			cout << "Ingrese 4 para salir" << endl;
			cin >> opcion;
			switch(opcion)
				{
			    case 1: 
				cout << "Usted ha seleccionado agregar un cliente" << endl;
					AgregarCliente();
			    	break;
			    case 2: 
				cout << "Usted ha seleccionado modificar informacion de un cliente" << endl;
					//Modificar();
			    	break;
			    case 3: 
				cout << "Usted ha seleccionado eliminar un cliente" << endl;
					//CerrarCaja();
			    	break;
			    case 4: 
				cout << "Usted ha seleccionado salir" << endl;
			    break;
			    default: 
				cout << "OPCION INCORRECTA" << endl;
				}
		}
	}
	
	void OpcionesPrincipales(NodoMenu*& Menu,FILE*F){
	int Salir;
	int opcion;
	
		while (opcion!=5)
		{
			cout << "Ingrese 1 para Gestion de menus" << endl;
			cout << "Ingrese 2 para Gestion de clientes " << endl;
			cout << "Ingrese 3 para Gestion de pedidos" << endl;
			cout << "Ingrese 4 para Facturacion" << endl;
			cout << "Ingrese 5 para salir" << endl;
			cin >> opcion;
			switch(opcion)
				{
			    case 1: 
				cout << "Usted ha seleccionado Gestion de menus" << endl;
					GestionDeMenu(Menu,F);
			    	break;
			    case 2: 
				cout << "Usted ha seleccionado Gestion de clientes" << endl;
					GestionDeClientes(Menu,F);
			    	break;
			    case 3: 
				cout << "Usted ha seleccionado Gestion de pedidos" << endl;
				//	GestionDePedidos(Menu,F);
			    	break;
			 	case 4: 
				cout << "Usted ha seleccionado Facturacion" << endl;
				//	Facturacion(Menu,F);
			    	break;
			    case 5: 
				cout << "Usted ha seleccionado salir" << endl;
			    break;
			    default: 
				cout << "OPCION INCORRECTA" << endl;
				}
		}
	}
		int AgregarCliente() {
		InfoCliente infoC;
		cout << "Ingrese nombre del cliente" << endl;
		cin >> infoC.Nombre;
		cout << "Ingrese Direccion del cliente" << endl;
		cin.ignore();
		cin.getline(infoC.Direccion,sizeof(infoC.Direccion));
		cout << "Ingrese Numero de telefono" << endl;
		cin >> infoC.telefono;
		FILE *F;
        F = fopen("Clientes.dat", "wb+");
		fwrite(&infoC, sizeof(InfoCliente), 1, F);
		fclose(F);
		cout << "Pedido guardado en el archivo Clientes.dat"<< endl;
        F = fopen("Clientes.dat", "rb");
        fread(&infoC, sizeof(InfoCliente), 1, F);
	    if (F == NULL) 
		{
	        cout << "Error al abrir el archivo" << endl;
		}
	
	    while (!feof(F)) 
		{
	        cout << "nombre del cliente: " << infoC.Nombre << endl;
	        cout << "Direccion del cliente: " << infoC.Direccion << endl;
	        cout << "Numero de telefono: " << infoC.telefono << endl;
	        cout << endl;
	           fread(&infoC, sizeof(InfoCliente), 1, F);
	    }
		return 0;
	}

	

