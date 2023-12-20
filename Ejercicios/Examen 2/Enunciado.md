## _Enunciado_

============

### _Ejercicio 1_ (2 Puntos)

#### _desarrolle los siguientes Subprogramas_:

1. Una funcion que retorne una lista _ordenada_ a partir de la union de una pila y una cola.
2. Un procedimiento que genere una lista _sin orden_ a partir de de la _INTERSECCIÓN_ de 2 listas.

> Defina usted las precondiciones y estructuras de los nodos de la manera que considere mas conveniente y detallar.

### _Ejercicio 2_ (3 Puntos)

Se tiene un vector de Reservas de hoteles en Pinamar para el verano de 2024, que contiene el detalle de las reservas de cada hotel con los siguientes campos:

- Codigo de Hotel
- Cantidad de Reservas
- Cantidad de _dias disponibles_ en la temporada

Ademas se cuenta con una lista ordenada que contiene las ultimas reservas realizadas por un sitio web de viajes, cada nodo de la lista contiene:

- Codigo de Hotel
- cantidad de _dias reservados_

_Se pide,_ actualizar el vector Reservas con la informacion que hay en la lista, incrementando la cantidad de reservas por cada una que aparezca en la lista, como así actualizando la cantidad de dias disponibles, en base a los dias reservados. _Ejemplo:_ Si en la lista el hotel 23 tiene 2 dias reservados, esos 2 dias se deben _restar_ en el campo de Cantidad de dias disponibles en el Vector. Se sabe que como _Maximo hay 50 hoteles._

- _1 Punto extra:_ En base a la estrategia que propuso, explique por que cree que es la mas eficiente en terminos de recursos, ¿Considera que hay otra alternativa?¿que beneficios o limitaciones tiene una vs la otra?

### _Ejercicio 3_ (3 Puntos)

Se tiene un archivo de registros de bultos de productos almacenados en un deposito, con el nombre STOCK.DAT (sin orden), que posee el siguiente formato:

- Codigo de producto: 9999999999
- Peso de bulto: 9999 kg
- Tipo 'A' ó 'B' (Alimentos o Bebidas)
- Cantidad de bultos en stock: 9999999999

#### Se pide:

1. Ordenar el archivo STOCK.DAT por codigo de Producto.
2. Generar dos listas y mostrarlas por pantalla:
   - La primera con los productos que _no tienen unidades en Stock_
   - La segunda con los productos PESADOS (peso mayor a 100k.) y Bebidas ('B').

> _NOTA: El archivo sólo puede recorrerse 1 vez._

- _1 Punto extra:_ En base a la estrategia propuesta de resolucion, ¿considera que podria haber utilizado otra/s estructura/s para resolver los problemas? ¿Cuales podrian haber sido y bajo que condiciones?

> _Puede utilizar los procedimientos y funciones vistos en la catedra. Cualquier cambio al funcionamiento original implica que debe desarrollarlo._
