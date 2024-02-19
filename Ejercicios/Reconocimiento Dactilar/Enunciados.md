Reconocimiento Dactilar:

Temas evaluados: Abstracción, flujos, estructuras de datos indexadas, resolución de problemas.
Definición del contexto

La dactiloscopia, como rama de la ciencia papiloscopica, permite el estudio de las huellas dactilares para 
establecer identidad física humana de manera categórica, fehaciente e indubitable. Juan Vucetich fue el pionero 
de esta ciencia a principios del siglo XX. Usted es miembro del equipo informatico de un organismo de 
seguridad nacional. Su equipo ha sido contratado para determinar quienes pueden ser eventuales sospechosos de 
cuestiones serias de seguridad

"Dinámica para la obtención de datos para consulta de eventuales sospechosos".

Para determinar plenamente la identificación de las personas se establecen cuatro tipos fundamentales: 

-1 Arco 
-2 Presilla Interna 
-3 Presilla Externa 
-4 Verticilo 

Cada uno de estos tipos presentan, a su vez, diferentes subtipos.
El tipo 1 siete subtipos identificados con letras en el rango ´a´..´g´.
Los tipos 2, 3 y 4 9 subtipos, en el rango ´a´..´i´.
Los dedos de las manos de cada persona se enumeran con números del 1 al 10.
Se comienza primero con la mano derecha 1..5 y luego con la izquierda 6..10. En cada mano, para la numeración se comienza con el dedo 
pulgar.
Las personas pueden tener idéntico tipo y subtipo en más de un dedo o pueden ser todos diferentes


Definición del Problema
Existe un archivo de personas que tienen antecedentes o prontuarios policiales de las cuales se tiene el tipo y 
subtipo de uno o varios de sus dedos y es la estructura de datos que primero se analiza cuando se encuentra una 
huella digital en un ambiente donde se perpetró un delito.

Este archivo esta desordenado y tiene el siguiente diseño:

DNI: Entero 
ApeNom: Cadena 50 car.
Dedo: Entero 
Tipo: Entero
Subtipo: Entero 

Según diferentes diligencias penales se puede pedir carga y/o búsquedas de distintos tipos.
Se pide:
1. Codifique o diagrame la función, cargarMatrizSospechosos que cargue los datos del archivo en 
una matriz (Tipo en las filas y Subtipo en las columnas) de punteros a una lista de sospechosos, 
ordenados alfabéticamente por nombre en forma creciente con una sublista al numero de dedo con ese 
tipo y subtipo.
2. Codifique o diagrame la función emitirSospechosos que con las estructuras cargadas en el 
punto anterior y dado un determinado tipo y subtipo, permita determinar e imprimir ordenado por 
apellido y nombre aquellas personas que coincidan en tipo y subtipo y el nombre del dedo y mano en la 
que coinciden.
3. Declare y defina todas las estructuras de datos que requiere el problema.
4. Responda justificando si son verdaderas o falsas las siguientes afirmaciones.
a. Las estructuras enlazadas pueden ser implementadas en vectores
b. El análisis de caso simple (if) solo evalua expresiones booleanas
