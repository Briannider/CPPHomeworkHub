# Examen Cursos

## FUNCIONES DE LISTAS

<void agregarNodo(Nodo\*& p, int x);>
La función agregar agrega un nuevo nodo con el valor x al final de la lista referenciada
por p.

<void mostrar(Nodo\* p);>

La función mostrar recorre la lista p y muestra por pantalla el valor que contienen cada
uno de sus nodos.

<void liberar(Nodo\*& p);>
La función liberar recorre la lista p liberando la memoria que ocupan cada uno de sus
nodos.

<Nodo* buscar(Nodo* p, int v);>
La función buscar permite determinar si alguno de los nodos de la lista p contiene el
valor v.
Retorna un puntero al nodo que contiene dicho valor o NULL si ninguno de los nodos
lo contiene.

<void eliminar(Nodo\*& p, int v);>
La función eliminar permite eliminar de la lista p al nodo que contiene el valor v.

<int eliminarPrimerNodo(Nodo\*& p);>
La función eliminarPrimerNodo elimina el primer nodo de la lista y retorna el valor que
este contenía.

<Nodo* insertarOrdenado(Nodo*& p, int v);>
La función insertarOrdenado permite insertar el valor v respetando el criterio de
ordenamiento de la lista p;

- Se presume que la lista está ordenada o vacía.
- Retorna la dirección de memoria del nodo insertado.

<void ordenar(Nodo\*& p);>
La función ordenar ordena la lista direccionada por p. La estrategia consiste en
eliminar uno a uno los nodos de la lista e insertarlos en orden en una lista nueva;
finalmente hacer que p apunte a la nueva lista.

<Nodo* buscaEInsertaOrdenado(Nodo*& p, int v, bool& enc);>
La función buscaEInsertaOrdenado busca el valor v en la lista p. Si no lo encuentra
entonces lo inserta respetando el criterio de ordenamiento. Retorna un puntero al
nodo encontrado o insertado y asigna el valor true o false al parámetro enc según
corresponda.

# Listas

## Ejercicio Nro. 1:
