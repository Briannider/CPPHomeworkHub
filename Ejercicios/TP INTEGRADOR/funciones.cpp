#include "funciones.hpp"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void agregar(int arr[], int n, int &len, int v) {

  if (len == n) {
    cout << "El vector esta lleno" << endl;
  } else {
    arr[len] = v;
    len++;
  }

  return;
}

void mostrar(int arr[], int len) {

  for (int i = 0; i < len; i++) {
    cout << arr[i] << endl;
  }

  return;
}

int buscar(int arr[], int len, int v) {
  int pos;
  int i = 0;

  while (i < len && arr[i] != v) {
    i++;
  }

  if (i == len) {
    pos = -1;
  } else {
    pos = i;
  }

  return pos;
}

void eliminar(int arr[], int &len, int pos) {

  for (int i = pos; i < len - 1; i++) {
    arr[i] = arr[i + 1];
  }
  len--;

  return;
}

void insertar(int arr[], int &len, int v, int pos) {

  for (int i = len - 1; i >= pos; i--) {
    arr[i + 1] = arr[i];
  }

  arr[pos] = v;
  len++;

  return;
}

int insertarOrdenado(int arr[], int &len, int v) {
  int i = 0;

  while (i < len && arr[i] <= v) {
    i++;
  }

  insertar(arr, len, v, i);
  return i;
}

int buscaEInserta(int arr[], int &len, int v, bool &enc) {
  int pos = buscar(arr, len, v);

  if (pos == -1) { // no esta
    enc = false;
    pos = insertarOrdenado(arr, len, v);
  } else {
    enc = true;
  }

  return pos;
}

void inicializar(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }
  return;
}

// burbuja
void burbujaAsc(int arr[], int len) {
  int temp;
  bool huboIntercambio = true;

  for (int i = 0; i < len - 1 && huboIntercambio; i++) {

    huboIntercambio = false;

    for (int j = 0; j < len - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        huboIntercambio = true;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int busquedaBinaria(int arr[], int len,
                    int v) { // el vector tiene que estar ordenado
  int inicio = 0;
  int fin = len - 1;
  int medio = (inicio + fin) / 2;
  int pos;

  while (inicio <= fin) {
    if (arr[medio] == v) {
      break;
    } else if (v < arr[medio]) {
      fin = medio - 1;
    } else { // v > arr[medio]
      inicio = medio + 1;
    }

    medio = (inicio + fin) / 2;
  }

  if (inicio > fin) {
    pos = -1;
  } else {
    pos = medio;
  }

  return pos;
}

// Listas
void agregarNodoMenu(NodoMenu *&lista, infoMenu x) {

  NodoMenu *nuevo = new NodoMenu();
  nuevo->infoM = x;
  nuevo->sgte = NULL;
  if (lista == NULL) {
    lista = nuevo;
  } else {
    NodoMenu *aux = lista;
    while (aux->sgte != NULL) {
      aux = aux->sgte;
    }
    aux->sgte = nuevo;
  }
}

void mostrar(Nodo *lista) {
  while (lista != NULL) {
    cout << lista->info << endl;
    lista = lista->sgte;
  }
}

void liberar(Nodo *&lista) {
  Nodo *aux;
  while (lista != NULL) {
    aux = lista;
    lista = lista->sgte;
    delete aux;
  }
}

Nodo *buscar(Nodo *lista, int v) {

  while (lista != NULL && lista->info != v) {
    lista = lista->sgte;
  }

  return lista;
}

void eliminarMenu(Nodo *&lista, int v) {
  Nodo *aux = lista;
  Nodo *ant = NULL;
  while (aux != NULL && aux->info != v) {
    ant = aux;
    aux = aux->sgte;
  }

  if (ant != NULL) {
    ant->sgte = aux->sgte;
  } else {
    lista = aux->sgte;
  }

  delete aux;
}

int eliminarPrimerNodo(Nodo *&lista) {
  int ret = lista->info;

  Nodo *aux = lista;
  lista = aux->sgte;
  delete aux;

  return ret;
}

Nodo *insertarOrdenado(Nodo *&lista, int v) {
  Nodo *nuevo = new Nodo();
  nuevo->info = v;
  nuevo->sgte = NULL;

  Nodo *aux = lista;
  Nodo *ant = NULL;

  while (aux != NULL && aux->info <= v) {
    ant = aux;
    aux = aux->sgte;
  }

  if (ant == NULL) {
    lista = nuevo;
  } else { // entró al while
    ant->sgte = nuevo;
  }

  nuevo->sgte = aux;

  return nuevo;
}

void ordenar(Nodo *&lista) {
  Nodo *listaAux = NULL;
  int v;
  while (lista != NULL) {
    v = eliminarPrimerNodo(lista);
    insertarOrdenado(listaAux, v);
  }
  lista = listaAux;
}

Nodo *buscaEInsertaOrdenado(Nodo *&lista, int v, bool &enc) {
  Nodo *buscado = buscar(lista, v);

  if (buscado == NULL) { // no esta
    enc = false;
    buscado = insertarOrdenado(lista, v);
  } else {
    enc = true;
  }

  return buscado;
}

// pilas
void push(Nodo *&pila, int v) {
  Nodo *nuevo = new Nodo();
  nuevo->info = v;
  nuevo->sgte = pila;
  pila = nuevo;
}

int pop(Nodo *&pila) {
  int ret = pila->info;
  Nodo *aux = pila;
  pila = aux->sgte;
  delete aux;
  return ret;
}

// Colas
void encolar(Nodo *&colafte, Nodo *&colafin, int v) {
  Nodo *nuevo = new Nodo();
  nuevo->info = v;
  nuevo->sgte = NULL;

  if (colafte == NULL) {
    colafte = nuevo;
  } else {
    colafin->sgte = nuevo;
  }

  colafin = nuevo;
}

int desencolar(Nodo *&colafte, Nodo *&colafin) {
  int ret = colafte->info;
  Nodo *aux = colafte;
  colafte = colafte->sgte;
  if (colafte == NULL) {
    colafin = NULL;
  }
  delete aux;
  return ret;
}

// TP 2 CUATRI

// INTERFAZ:
void OpcionesPrincipales(NodoMenu *&Menu, NodoCliente *&Cliente, FILE *F) {
  int opcion = 0;
  NodoPedidosCompletados *pedidosCompletados = NULL;
  NodoPedidosPendientes *colafte = NULL;
  NodoPedidosPendientes *colafin = NULL;

  do {
    cout << "Ingrese 1 para Gestion de menus" << endl;
    cout << "Ingrese 2 para Gestion de clientes " << endl;
    cout << "Ingrese 3 para Gestion de pedidos" << endl;
    cout << "Ingrese 4 para Facturacion" << endl;
    cout << "Ingrese 5 para salir" << endl;
    cin >> opcion;
    switch (opcion) {
    case 1:
      cout << "Usted ha seleccionado Gestion de menus" << endl;
      GestionDeMenu(Menu, F);
      break;
    case 2:
      cout << "Usted ha seleccionado Gestion de clientes" << endl;
      GestionDeClientes(Cliente, F);
      break;
    case 3:
      cout << "Usted ha seleccionado Gestion de pedidos" << endl;
      GestionDePedidos(Menu, Cliente, F, pedidosCompletados, colafte, colafin);
      break;
    case 4:
      cout << "Usted ha seleccionado Facturacion" << endl;
      Facturacion(F, pedidosCompletados);
      break;
    case 5:
      cout << "Usted ha seleccionado salir" << endl;
      break;
    default:
      cout << "OPCION INCORRECTA" << endl;
    }
  } while (opcion != 5);
}

// ------------------------------------------------------------ GESTION DE MENU:
// ------------------------------------------------------------

void GestionDeMenu(NodoMenu *&Menu, FILE *F) {
  infoMenu reg;
  int opcion;
  do {
    cout << "Ingrese 1 para cargar el menu" << endl;
    cout << "Ingrese 2 para mostrar el menu" << endl;
    cout << "Ingrese 3 para eliminar el menu" << endl;
    cout << "Ingrese 4 para modificar el menu " << endl;
    cout << "Ingrese 5 para salir" << endl;
    cin >> opcion;
    switch (opcion) {
    case 1:
      cout << "Usted ha seleccionado cargar el menu" << endl;
      AgregarMenu(F);
      break;
    case 2:
      cout << "Mostrar menu" << endl;
      MostrarMenu(reg, F);
      break;
    case 3:
      cout << "Usted ha seleccionado eliminar el menu" << endl;
      eliminarMenu(Menu, F);
      break;
    case 4:
      cout << "Usted ha seleccionado modificar el menu" << endl;
      modificarMenu(Menu, F);
      break;
    case 5:
      cout << "Usted ha seleccionado salir" << endl;
      break;
    default:
      cout << "OPCION INCORRECTA" << endl;
    }
  } while (opcion != 5);
}

// Agregar platillo al Menu
void AgregarMenu(FILE *F) {
  infoMenu infoM;
  cout << "Ingrese nombre de plato" << endl;
  cin.ignore();
  cin.getline(infoM.nombre, sizeof(infoM.nombre));
  cout << "Ingrese precio del plato" << endl;
  cin >> infoM.precio;
  cout << "Ingrese descripcion" << endl;
  cin.ignore();
  cin.getline(infoM.descripcion, sizeof(infoM.descripcion));
  F = fopen("Menu.dat", "ab+");
  if (F == NULL) {
    cout << "Error al abrir el archivo " << endl;
  } else {
    fwrite(&infoM, sizeof(infoMenu), 1, F);
    cout << "Pedido guardado en el archivo Menu.dat" << endl;
    fclose(F);
  }
}

// Muestra todos los platillos dentro de Menu.dat
void MostrarMenu(infoMenu infoM, FILE *F) {
  F = fopen("Menu.dat", "rb");
  if (F == NULL) {
    cout << "Error al abrir el archivo" << endl;
  } else {
    cout << "" << endl;
    cout << "Platillos en el menu: " << endl;
    cout << "" << endl;
    while (fread(&infoM, sizeof(infoMenu), 1, F) == 1) {
      cout << "------------------------------------------------" << endl;
      cout << "Nombre Plato: " << infoM.nombre << endl;
      cout << "Precio del plato: " << infoM.precio << endl;
      cout << "Descripcion del plato: " << infoM.descripcion << endl;
      cout << "------------------------------------------------" << endl;
      cout << endl;
    }
    fclose(F);
  }
}

// modificar platillo del menu
NodoMenu *buscar(NodoMenu *lista, const char *nombre) {
  NodoMenu *current = lista;
  while (current != NULL) {
    if (strcmp(current->infoM.nombre, nombre) == 0) {
      return current; // Se encontró el plato
    }
    current = current->sgte;
  }

  return NULL;
}

// Lista de platillos: Esta es utilizada para almacenar todos los platos dentro
// del archivo y asi modificar el plato indicado
void agregarNodo(NodoMenu *&lista, infoMenu x) {

  NodoMenu *nuevo = new NodoMenu();
  nuevo->infoM = x;
  nuevo->sgte = NULL;
  if (lista == NULL) {
    lista = nuevo;
  } else {
    NodoMenu *aux = lista;
    while (aux->sgte != NULL) {
      aux = aux->sgte;
    }
    aux->sgte = nuevo;
  }
}

// Liberar lista de platillos
void liberarLista(NodoMenu *lista) {
  NodoMenu *actual = lista;
  NodoMenu *siguiente;

  while (actual != NULL) {
    siguiente = actual->sgte;
    delete actual; // Suponiendo que NodoMenu se crea con new
    actual = siguiente;
  }
}

// Rescribe el archivo Menu.dat con el platillo modificado
void modificarMenu(NodoMenu *&Menu, FILE *F) {
  // Abre el archivo en modo lectura
  F = fopen("Menu.dat", "rb");
  NodoMenu *lista = NULL;
  infoMenu infoM;

  if (F == NULL) {
    cout << "Error al abrir el archivo" << endl;
  } else {
    fread(&infoM, sizeof(infoMenu), 1, F);
    while (!feof(F)) {
      agregarNodoMenu(lista, infoM);
      fread(&infoM, sizeof(infoMenu), 1, F);
    }
    fclose(F);
    char platoAModificar[100];

    cout << "Ingrese el plato a modificar: ";
    cin >> platoAModificar;

    NodoMenu *nodoAModificar = buscar(lista, platoAModificar);

    if (nodoAModificar != NULL) {
      cout << "Ingrese nuevo nombre del plato: ";
      cin >> nodoAModificar->infoM.nombre;
      cout << "Ingrese nuevo precio del plato: ";
      cin >> nodoAModificar->infoM.precio;
      cout << "Ingrese nueva descripcion: ";
      cin.ignore();
      cin.getline(nodoAModificar->infoM.descripcion,
                  sizeof(nodoAModificar->infoM.descripcion));

      // Reabre el archivo en modo escritura (borrando el contenido anterior)
      F = fopen("Menu.dat", "wb");

      if (F == NULL) {
        cout << "Error al abrir el archivo" << endl;
      } else {
        NodoMenu *actual = lista; // Utiliza la lista temporal

        while (actual != NULL) {
          fwrite(&(actual->infoM), sizeof(infoMenu), 1, F);
          actual = actual->sgte;
        }

        fclose(F);
        cout << "Plato modificado y guardado en el archivo Menu.dat" << endl;

        // Liberar la memoria de la lista temporal después de usarla
        liberarLista(lista);
        // Liberar la memoria de la lista original después de escribir en el
        // archivo
        liberarLista(Menu);
      }

    } else {
      cout << "Plato no encontrado en el menu." << endl;
    }
  }
}
NodoMenu *buscarMenu(NodoMenu *lista, const char *nombre) {
  NodoMenu *current = lista;
  while (current != NULL) {
    if (strcmp(current->infoM.nombre, nombre) == 0) {
      return current; // Se encontró el menú
    }
    current = current->sgte;
  }
  return NULL;
}
// Complemento de la funcion "eliminarMenu()": Se encarga de crear una lista de
// todos los platillos menos el plato eliminado
void eliminar(NodoMenu *&lista, const char *nombre) {
  NodoMenu *aux = lista;
  NodoMenu *ant = NULL;

  while (aux != NULL && strcmp(aux->infoM.nombre, nombre) != 0) {
    ant = aux;
    aux = aux->sgte;
  }

  if (ant != NULL) {
    ant->sgte = aux->sgte;
  } else {
    lista = aux->sgte;
  }

  delete aux;
}

// Aca se reescribe el archivo con la lista de platillos de la funcion
// eliminar()
void eliminarMenu(NodoMenu *&Menu, FILE *F) {
  F = fopen("Menu.dat", "rb");
  fseek(F, 0, SEEK_SET);
  NodoMenu *listaMenu = NULL;
  infoMenu infoM;
  if (F == NULL) {
    cout << "Error al abrir el archivo" << endl;
  } else {
    fread(&infoM, sizeof(infoMenu), 1, F);
    while (!feof(F)) {
      agregarNodoMenu(listaMenu, infoM);
      fread(&infoM, sizeof(infoMenu), 1, F);
    }
  }
  char platoAEliminar[100];

  cout << "Ingrese el plato a eliminar: ";
  cin >> platoAEliminar;

  NodoMenu *nodoAEliminar = buscar(listaMenu, platoAEliminar);

  if (nodoAEliminar != NULL) {
    eliminar(listaMenu, platoAEliminar);
    cout << "plato eliminado" << endl;
    // Reabre el archivo en modo escritura (borrando el contenido anterior)
    FILE *F = fopen("Menu.dat", "wb");

    if (F == NULL) {
      cout << "Error al abrir el archivo" << endl;
    }

    NodoMenu *actual = listaMenu;

    while (actual != NULL) {
      fwrite(&(actual->infoM), sizeof(infoMenu), 1, F);
      actual = actual->sgte;
    }

    fclose(F);
    cout << "Actualizacion guardada en el archivo Menu.dat" << endl;

    // Liberar la memoria de la lista después de usarla
    liberarLista(listaMenu);

  } else {
    cout << "no se encontro el plato a eliminar" << endl;
  }
}

// --------------------------------------------------------- GESTION DE
// CLIENTES: ---------------------------------------------------------

void GestionDeClientes(NodoCliente *&Cliente, FILE *F) {
  infoCliente reg;
  int opcion;
  do {
    cout << "Ingrese 1 para agregar un cliente" << endl;
    cout << "Ingrese 2 para modificar informacion de un cliente " << endl;
    cout << "Ingrese 3 para eliminar un cliente" << endl;
    cout << "Ingrese 4 para mostrar el listado de clientes" << endl;
    cout << "Ingrese 5 para salir" << endl;
    cin >> opcion;
    switch (opcion) {
    case 1:
      cout << "Usted ha seleccionado agregar un cliente" << endl;
      AgregarCliente(F);
      break;
    case 2:
      cout << "Usted ha seleccionado modificar informacion de un cliente"
           << endl;
      ActualizarCliente(Cliente, F);
      break;
    case 3:
      cout << "Usted ha seleccionado eliminar un cliente" << endl;
      eliminarCliente(Cliente, F);
      break;
    case 4:
      cout << "Mostrar lista de clientes" << endl;
      MostrarCliente(F);
      break;
    case 5:
      cout << "Usted ha seleccionado salir" << endl;
      break;
    default:
      cout << "OPCION INCORRECTA" << endl;
    }
  } while (opcion != 5);
}
// agregar clientes
void AgregarCliente(FILE *F) {
  infoCliente infoC;
  NodoPedidosSolicitados *pedidosAnt;
  cout << "Ingrese nombre del cliente" << endl;
  cin.getline(infoC.Nombre, sizeof(infoC.Nombre));

  cout << "Ingrese direccion del Cliente" << endl;
  cin.ignore();
  cin.getline(infoC.Direccion, sizeof(infoC.Direccion));

  cout << "Ingrese numero de Telefono" << endl;
  cin >> infoC.telefono;
  infoC.pedidosAnt = NULL;
  F = fopen("Clientes.dat", "ab+");

  fwrite(&infoC, sizeof(infoCliente), 1, F);
  fclose(F);
  cout << "Cliente guardado en el archivo Clientes.dat" << endl;
  F = fopen("Clientes.dat", "rb");
  fread(&infoC, sizeof(infoCliente), 1, F);
  if (F == NULL) {
    cout << "Error al abrir el archivo" << endl;
  }

  while (!feof(F)) {
    cout << "Nombre Cliente: " << infoC.Nombre << endl;
    cout << "Direccion del cliente: " << infoC.Direccion << endl;
    cout << "numero de telefono: " << infoC.telefono << endl;
    cout << endl;
    fread(&infoC, sizeof(infoCliente), 1, F);
  }
}

NodoCliente *buscarCliente(NodoCliente *lista, const char *nombre) {
  NodoCliente *current2 = lista;
  while (current2 != NULL) {
    if (strcmp(current2->infoC.Nombre, nombre) == 0) {
      return current2; // Se encontró el cliente
    }
    current2 = current2->sgte;
  }
  return NULL;
}

NodoPedidosCompletados *buscarPedido(NodoPedidosCompletados *lista,
                                     const char *nombre) {
  NodoPedidosCompletados *current2 = lista;
  while (current2 != NULL) {
    if (strcmp(current2->info.cliente, nombre) == 0) {
      return current2; // Se encontró el cliente
    }
    current2 = current2->sgte;
  }
  return NULL;
}

void MostrarCliente(FILE *F) {
  infoCliente infoC;
  F = fopen("Clientes.dat", "rb");

  if (F == NULL) {
    cout << "Error al abrir el archivo" << endl;
  } else {
    cout << "listado del cliente: " << endl;
    fread(&infoC, sizeof(infoCliente), 1, F);
    while (!feof(F)) {
      cout << "------------------------------------------------" << endl;
      cout << "Nombre: " << infoC.Nombre << endl;
      cout << "Dereccion: " << infoC.Direccion << endl;
      cout << "Telefono: " << infoC.telefono << endl;
      if (infoC.pedidosAnt == NULL) {
        cout << "Pedidos:"
             << " sin pedidos" << endl;
      } else {
        cout << "tiene pedidos: "
             << endl; // => faltaria ver como pasamos los pedidos al agregarlos
                      // en la gestion de pedidos
      }
      cout << "------------------------------------------------" << endl;
      cout << endl;
      fread(&infoC, sizeof(infoCliente), 1, F);
    }

    fclose(F);
  }
}

// actualizar los clientes
NodoCliente *buscar(NodoCliente *lista, const char *nombre) {
  NodoCliente *current2 = lista;
  while (current2 != NULL) {
    if (strcmp(current2->infoC.Nombre, nombre) == 0) {
      return current2; // Se encontró el cliente
    }
    current2 = current2->sgte;
  }
  return NULL;
}

void agregarNodoCliente(NodoCliente *&lista, infoCliente x) {

  NodoCliente *nuevo = new NodoCliente();
  nuevo->infoC = x;
  nuevo->sgte = NULL;
  if (lista == NULL) {
    lista = nuevo;
  } else {
    NodoCliente *aux = lista;
    while (aux->sgte != NULL) {
      aux = aux->sgte;
    }
    aux->sgte = nuevo;
  }
}

void liberarLista(NodoCliente *lista) {
  NodoCliente *actual = lista;
  NodoCliente *siguiente;

  while (actual != NULL) {
    siguiente = actual->sgte;
    delete actual; // Suponiendo que NodoMenu se crea con new
    actual = siguiente;
  }
}

void ActualizarCliente(NodoCliente *&Cliente, FILE *F) {
  // Abre el archivo en modo lectura
  F = fopen("Clientes.dat", "rb");
  NodoCliente *listaClientes = NULL;
  infoCliente infoC;
  if (F == NULL) {
    cout << "Error al abrir el archivo" << endl;
  }
  fread(&infoC, sizeof(infoCliente), 1, F);
  while (!feof(F)) {
    agregarNodoCliente(listaClientes, infoC);
    fread(&infoC, sizeof(infoCliente), 1, F);
  }
  fclose(F);
  char clienteAActualizar[100];

  cout << "Ingrese el cliente a actualizar: " << endl;
  cin >> clienteAActualizar;

  NodoCliente *nodoAActualizar = buscar(listaClientes, clienteAActualizar);

  if (nodoAActualizar != NULL) {
    cout << "Ingrese nuevo nombre del cliente: ";
    cin >> nodoAActualizar->infoC.Nombre;
    cout << "Ingrese nueva direccion del Cliente: ";
    cin.ignore();
    cin.getline(nodoAActualizar->infoC.Direccion,
                sizeof(nodoAActualizar->infoC.Direccion));
    cout << "Ingrese nuevo telefono del cliente: ";
    cin >> nodoAActualizar->infoC.telefono;

    // Reabre el archivo en modo escritura (borrando el contenido anterior)
    F = fopen("Clientes.dat", "wb");

    if (F == NULL) {
      cout << "Error al abrir el archivo" << endl;
    }

    NodoCliente *actual = listaClientes;

    while (actual != NULL) {
      fwrite(&(actual->infoC), sizeof(infoCliente), 1, F);
      actual = actual->sgte;
    }

    fclose(F);
    cout << "Cliente modificado y guardado en el archivo Cliente.dat" << endl;
    liberarLista(listaClientes);
    liberarLista(Cliente);
  } else {
    cout << "Cliente no encontrado en el archivo" << endl;
  }
}

// eliminar el cliente
void eliminar(NodoCliente *&lista, const char *nombre) {
  NodoCliente *aux = lista;
  NodoCliente *ant = NULL;

  while (aux != NULL && strcmp(aux->infoC.Nombre, nombre) != 0) {
    ant = aux;
    aux = aux->sgte;
  }

  if (ant != NULL) {
    ant->sgte = aux->sgte;
  } else {
    lista = aux->sgte;
  }

  delete aux;
}

void eliminarCliente(NodoCliente *&Cliente, FILE *F) {
  F = fopen("Clientes.dat", "rb+");
  fseek(F, 0, SEEK_SET);
  NodoCliente *listaCliente = NULL;
  infoCliente infoC;
  if (F == NULL) {
    cout << "Error al abrir el archivo" << endl;
  } else {
    fread(&infoC, sizeof(infoCliente), 1, F);
    while (!feof(F)) {
      agregarNodoCliente(listaCliente, infoC);
      fread(&infoC, sizeof(infoCliente), 1, F);
    }
  }

  char clienteAEliminar[100];
  cout << "Ingrese el cliente a eliminar: ";
  cin >> clienteAEliminar;

  NodoCliente *nodoAEliminar = buscar(listaCliente, clienteAEliminar);

  if (nodoAEliminar != NULL) {
    eliminar(listaCliente, clienteAEliminar);
    cout << "cliente eliminado" << endl;
    // Reabre el archivo en modo escritura (borrando el contenido anterior)
    F = fopen("Clientes.dat", "wb");

    if (F == NULL) {
      cout << "Error al abrir el archivo" << endl;
    }

    NodoCliente *actual = listaCliente;

    while (actual != NULL) {
      fwrite(&(actual->infoC), sizeof(infoCliente), 1, F);
      actual = actual->sgte;
    }

    fclose(F);
    cout << "Actualizacion guardada en el archivo Clientes.dat" << endl;

    // Liberar la memoria de la lista después de usarla
    liberarLista(listaCliente);

  } else {
    cout << "no se encontro el cliente a eliminar" << endl;
  }
}

// ---------------------------------------------------------- GESTION DE
// PEDIDOS: ----------------------------------------------------------

void GestionDePedidos(NodoMenu *&Menu, NodoCliente *&Cliente, FILE *F,
                      NodoPedidosCompletados *&pedidosCompletados,NodoPedidosPendientes *&colafte,NodoPedidosPendientes *&colafin) {

  int opcion;
  do {
    cout << "Ingrese 1 para registrar un nuevo pedido" << endl;
    cout << "Ingrese 2 para marcar pedido como completado" << endl;
    cout << "Ingrese 3 mostrar pedidos pendientes" << endl;
    cout << "Ingrese 4 mostrar pedidos completados" << endl;
    cout << "Ingrese 5 para salir" << endl;
    cin >> opcion;
    switch (opcion) {
    case 1:
      registrarPedido(Menu, Cliente, colafte, colafin);
      break;
    case 2:
      marcarPedidoCompletado(colafte, colafin, pedidosCompletados);
      break;
    case 3:
      mostrarPedidosPendientes(colafte, colafin);
      break;
    case 4:
      mostrarPedidosCompletados(pedidosCompletados);
      break;
    case 5:
      break;
    default:
      cout << "opcion no valida. intente de nuevo" << endl;
    }
  } while (opcion != 5);
}

void agregarNodoPedidos(NodoPedidosSolicitados *&lista, infoPedidos x) {

  NodoPedidosSolicitados *nuevo = new NodoPedidosSolicitados();
  nuevo->info = x;
  nuevo->sgte = NULL;
  if (lista == NULL) {
    lista = nuevo;
  } else {
    NodoPedidosSolicitados *aux = lista;
    while (aux->sgte != NULL) {
      aux = aux->sgte;
    }
    aux->sgte = nuevo;
  }
}

void registrarPedido(NodoMenu *Menu, NodoCliente *Cliente,
                     NodoPedidosPendientes *&colafte,
                     NodoPedidosPendientes *&colafin) {
  // abrimos el archivo de menu
  FILE *F;
  infoMenu infoM;
  MostrarMenu(infoM, F);
  NodoMenu *listaMenu = NULL;

  F = fopen("Menu.dat", "rb");
  if (F == NULL) {
    cout << "Error al abrir el archivo" << endl;
  } else {
    fread(&infoM, sizeof(infoMenu), 1, F);

    while (!feof(F)) {
      agregarNodoMenu(listaMenu, infoM);
      fread(&infoM, sizeof(infoMenu), 1, F);
    }
    fclose(F);
  }

  // Abrimos el archivo de clientes
  F = fopen("Clientes.dat", "rb");
  NodoCliente *listaClientes = NULL;
  infoCliente infoCli;
  if (F == NULL) {
    cout << "Error al abrir el archivo" << endl;
  } else {
    fread(&infoCli, sizeof(infoCliente), 1, F);
    while (!feof(F)) {
      agregarNodoCliente(listaClientes, infoCli);
      fread(&infoCli, sizeof(infoCliente), 1, F);
    }
    fclose(F);
  }

  infoPedidos nuevoPedido;
  cout << "Ingrese el platillo solicitado" << endl;
  cin.ignore();
  cin.getline(nuevoPedido.menuSolicitado, sizeof(nuevoPedido.menuSolicitado));
  NodoMenu *nodoMenu = buscarMenu(listaMenu, nuevoPedido.menuSolicitado);
  if (nodoMenu != NULL) {
    cout << "Ingrese la cantidad solicitada" << endl;
    cin >> nuevoPedido.cantidadPorciones;
    cout << "Ingrese el nombre del cliente" << endl;
    cin.ignore();
    cin.getline(nuevoPedido.cliente, sizeof(nuevoPedido.cliente));
    nuevoPedido.precio = nodoMenu->infoM.precio;
    NodoCliente *nodoCliente =
        buscarCliente(listaClientes, nuevoPedido.cliente);
    if (nodoCliente != NULL) { // agregarlo encolar
      encolarPedido(colafte, colafin, nuevoPedido);
      cout << "pedido registrado con exito" << endl;
    } else {
      cout << "Cliente no registrado. Registre al cliente" << endl;
      AgregarCliente(F);
    }
  } else {
    cout << "El platillo no existe" << endl;
  }
}

// Colocamos en una cola los pedidos que vayan ingresando del cliente, los
// cuales una vez completados pasaran a la pila de pedidos solicitados.
void encolarPedido(NodoPedidosPendientes *&colafte,
                   NodoPedidosPendientes *&colafin, infoPedidos v) {
  NodoPedidosPendientes *nuevo = new NodoPedidosPendientes();
  nuevo->info = v;
  nuevo->sgte = NULL;

  if (colafte == NULL) {
    colafte = nuevo;
  } else {
    colafin->sgte = nuevo;
  }

  colafin = nuevo;
}

infoPedidos desencolarPedido(NodoPedidosPendientes *&colafte,
                             NodoPedidosPendientes *&colafin) {
  infoPedidos ret = colafte->info;
  NodoPedidosPendientes *aux = colafte;
  colafte = colafte->sgte;
  if (colafte == NULL) {
    colafin = NULL;
  }
  delete aux;
  return ret;
}

void push(NodoPedidosCompletados *&pila, infoPedidos pedido) {
  NodoPedidosCompletados *nuevo = new NodoPedidosCompletados();
  nuevo->info = pedido;
  nuevo->sgte = pila;
  pila = nuevo;
}

void marcarPedidoCompletado(NodoPedidosPendientes *&colafte,
                            NodoPedidosPendientes *&colafin,
                            NodoPedidosCompletados *&pedidosCompletados) {
  if (colafte == NULL) {
    cout << "No hay pedidos pendientes para completar." << endl;
    return;
  } else {
    infoPedidos ip = desencolarPedido(colafte, colafin);
    cout << "Pedido completado con exito: " << ip.menuSolicitado << endl;
    push(pedidosCompletados, ip);
  }
}

void mostrarPedidosPendientes(NodoPedidosPendientes *&colafte,
                              NodoPedidosPendientes *&colafin) {
  NodoPedidosPendientes *auxfte = NULL;
  NodoPedidosPendientes *auxfin = NULL;

  infoPedidos ip;
  while (colafte != NULL) {
    ip = desencolarPedido(colafte, colafin);
    cout << ip.cliente << " " << ip.menuSolicitado << " " << endl;
    encolarPedido(auxfte, auxfin, ip);
  }
  while (auxfte != NULL) {
    ip = desencolarPedido(auxfte, auxfin);
    encolarPedido(colafte, colafin, ip);
  }
}

void mostrarPedidosCompletados(NodoPedidosCompletados *&pedidoCompletado) {
  infoPedidos ip;
  NodoPedidosCompletados *aux = NULL;
  while (pedidoCompletado != NULL) {
    ip = pop(pedidoCompletado);
    cout << ip.cliente << ": " << ip.menuSolicitado << " " << endl;
    push(aux, ip);
  }

  while (aux != NULL) {
    ip = pop(aux);
    push(pedidoCompletado, ip);
  }
}

infoPedidos pop(NodoPedidosCompletados *&pila) {
  infoPedidos ret = pila->info;
  NodoPedidosCompletados *aux = pila;
  pila = aux->sgte;
  delete aux;
  return ret;
}

// ---------------------------------------------------------- GESTION DE
// FACTURAS: ----------------------------------------------------------

void Facturacion(FILE *F, NodoPedidosCompletados *&pedidoCompletado) {

  int opcion;
  do {
    cout << "Ingrese 1 para el total de un cliente a especificar" << endl;
    cout << "Ingrese 2 para mostrar el total de facturacion del dia" << endl;
    cout << "Ingrese 3 para salir" << endl;
    cin >> opcion;
    switch (opcion) {
    case 1:
      FacturacionPorCliente(F, pedidoCompletado);
      break;
    case 2:
      FacturacionTotalClientes(F, pedidoCompletado);
      break;
    case 3:
      break;
    default:
      cout << "opcion no valida. intente de nuevo" << endl;
      break;
    }
  } while (opcion != 3);
}

void FacturacionPorCliente(FILE *F, NodoPedidosCompletados *&pedidoCompletado) {
  NodoPedidosCompletados *aux = NULL;
  infoPedidos ip;
  char cliente[50 + 1];
  cout << "Ingresar nombre del cliente a facturar: " << endl;
  cin.ignore();
  cin.getline(cliente, sizeof(cliente));

  int montoTotalCli = 0;
  cout << "Informe de Facturacion del cliente: " << cliente << endl;
  cout << "----------------------------------------- " << endl;
  // del mostrar completados
  while (pedidoCompletado != NULL) {
    ip = pop(pedidoCompletado);
    if (strcmp(ip.cliente, cliente) == 0) {
      montoTotalCli += (ip.cantidadPorciones * ip.precio);
      cout << "Pedidos: " << ip.menuSolicitado << endl;
      cout << " Cant: " << ip.cantidadPorciones << endl;
      cout << " $" << ip.precio << endl;
    }
    push(aux, ip);
  }
  cout << "Monto total: $" << montoTotalCli << endl;
  while (aux != NULL) {
    ip = pop(aux);
    push(pedidoCompletado, ip);
  }
}

void FacturacionTotalClientes(FILE *F,
                              NodoPedidosCompletados *&pedidoCompletado) {
  NodoPedidosCompletados *aux = NULL;
  infoPedidos ip;
  int montoTotalCli = 0;
  cout << "Informe de Facturacion " << endl;
  cout << "----------------------------------------- " << endl;
  // del mostrar completados

  while (pedidoCompletado != NULL) {
    ip = pop(pedidoCompletado);
    montoTotalCli += (ip.cantidadPorciones * ip.precio);
    cout << "----------------------------------------- " << endl;
    cout << "Cliente: " << ip.cliente << endl;
    cout << "----------------------------------------- " << endl;
    cout << "Pedidos: " <<  ip.menuSolicitado << endl;
    cout << " Cant: " << ip.cantidadPorciones << endl;
    cout << " $" << ip.precio << endl;
    cout << "----------------------------------------- " << endl;
    push(aux, ip);
  }
  cout << "Monto total: $" << montoTotalCli << endl;
  while (aux != NULL) {
    ip = pop(aux);
    push(pedidoCompletado, ip);
  }
}

infoPedidos eliminarPrimerNodoPedidoCompletado(NodoPedidosCompletados *&lista) {
  infoPedidos ret = lista->info;

  NodoPedidosCompletados *aux = lista;
  lista = aux->sgte;
  delete aux;

  return ret;
}

NodoPedidosCompletados *
insertarOrdenadoPedidoCompletado(NodoPedidosCompletados *&lista,
                                 infoPedidos v) {
  NodoPedidosCompletados *nuevo = new NodoPedidosCompletados();
  nuevo->info = v;
  nuevo->sgte = NULL;

  NodoPedidosCompletados *aux = lista;
  NodoPedidosCompletados *ant = NULL;

  while (aux != NULL && aux->info.cliente <= v.cliente) {
    ant = aux;
    aux = aux->sgte;
  }

  if (ant == NULL) {
    lista = nuevo;
  } else { // entró al while
    ant->sgte = nuevo;
  }

  nuevo->sgte = aux;

  return nuevo;
}

void ordenarPedidoCompletado(NodoPedidosCompletados *&lista) {
  NodoPedidosCompletados *listaAux = NULL;
  infoPedidos v;
  while (lista != NULL) {
    v = eliminarPrimerNodoPedidoCompletado(lista);
    insertarOrdenadoPedidoCompletado(listaAux, v);
  }
  lista = listaAux;
}