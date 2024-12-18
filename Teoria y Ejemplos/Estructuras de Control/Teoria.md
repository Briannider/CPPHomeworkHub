Estructuras de Control

Veremos 3 estructuras que son las más útiles y algunas más que son menos comunes de ver.

Las útiles:
if()
El if(), es una estructura condicional que indica que camino recorrer si se cumple o no un estado o condición. 
Por ejemplo, “si el número es mayor a 6, sumale 5. Si no, restale 5”. 
Es un condicional, porque depende de la condición (que sea o no mayor a 6) tomo acciones distintas. 
Entonces esta condición pasa a tener un valor de verdad (Matemática Discreta), que es Verdadero o Falso.
Entonces tenemos que agregar ootro tipo de dato, los booleanos que solamente pueden tener dos valores: True o False. 
También se los puede representar con un 1 para True y un 0 para false.

Llevándolo a código, así nos quedaría nuestro if: 

#########################################################################################################

#include <iostream>

using namespace std;

int main(){
    if (condicion){
        hace esto;
    } else {
        hace esto otro;
    };

    return 0; // <- esto es una convencion ya que el main debe retornar/devolver el valor 0 si se ejecuto correctamente
}


##########################################################################################################


Si se cumple la condición, osea si la condición es True, realiza el “Hace esto”, si no se cumple, realiza el “Hace esto otro”.
Las condiciones pueden ser del estilo “Si un número es mayor/menor/igual a otro” o simplemente “Si un número es distinto a cero”. 
Ejemplos:
-Si un número es mayor a otro.

##########################################################################################################

#include <iostream>

using namespace std;

int main(){

int a=3, b=1;

    if (a>b){
        cout<< "a es mayor a b"; 
    } else {
        cout<< "b es mayor que a"; 
    };

    return 0;
}


##########################################################################################################


Obviamente, 3 es mayor a 1, asi que va a ir por la rama del True.

-Si un número es distinto a cero. En otras palabras, si un número existe

##########################################################################################################

#include <iostream>

using namespace std;

int main(){

int a=3, b=1;

    if (a){
        cout<< "a es distinto de cero"; 
    } else {
        cout<< "a es igual a 0"; 
    };

    return 0;
}


##########################################################################################################

Véase que al poner simplemente “if(a)”, ya C++ interpreta que lo que queremos decir es “if(a==0)”

while( )
Es una estructura de iteración, repetición. 
Realiza cierto bloque de código mientras ocurra una condición, es decir “mientras la condición sea verdadera, hace algo,
en el momento en que esta condición sea falsa, deja de hacerlo. 
Hay que tener en cuenta que es muy fácil caer en un bucle infinito si no se tiene cuidado.

Ejemplos de uso: 
Los ejemplos más comunes son “mientras un número sea menor a otro, realiza esta acción” o “mientras no encuentres este valor….” o 
“mientras tal cosa no sea True..”



Ejemplos en c++:
-Mientras un número sea menor a 6, sumale a otro numero 10.

Caso muy facil de que quede colgado en bucle infinito, es que nunca le sume a ‘i’, en la línea 11. Al nunca sumarle 1, i siempre vale 0, ergo nunca va a ser mayor a 6. Compilamos y… 

Recorrió el bucle 6 veces, por lo que le sumo 6 veces 10, osea 60.

for( )
El for() es parecido al while, quizás un poco más complicado de llamar, pero cumple casi con las mismas propiedades aunque sirve más para recorrer vectores ya que lo que esté dentro del for es propio de él, actuando así como una función. 
Tiene un inicio, una condición y una post-condicion. Hagamos el mismo ejemplo que el de “Mientras un número sea menor a 6, sumale a otro numero 10.”




Veamos que nos da el mismo resultado. 
En el for, esta el contador(la ‘i’), la condición de corte (i<6) y la pseudo post condición, que normalmente es la i++, para que en algún momento corte.

Cosas a tener en cuenta:
Siempre inicializar las variables sino nos va a mandar fruta.


Estructuras de control no tan útiles en la materia:

Do While().
¿Que diferencia hay con el while()? Que el do while hace primero el bloque de código y despues pregunta la condición. El while primero pregunta la condición y despues ejecuta.
En otras palabras, el Do While ejecuta al menos una vez.

Ejemplo:


Veamos que la variable i, ya es menor a cero desde el principio, pero el do-while hizo primero una vez el código, y recién después hizo la pregunta de “Es i menor a cero”?. Esto sirve para el caso en que necesitas que si o si, se haga una vez un bloque de código, y después que se fije si continuar o no.

Switch case.
El case es un poco más complicado de utilizar, hay que tener bien puestos los ojos en el código y ya entender rápido lo que está pasando. 
¿Que hace el case? Pregunta el valor de una variable, y dependiendo el valor, hace distintas acciones. Es como menú de opciones, por decir algo.

Ejemplo:


Primero se hace el Switch ( variable ), con la cual vamos a determinar qué valor le pasamos. Luego los case,casos o escenarios donde ejecuta un bloque de código distinto. Nuestro caso va a entrar por el case 3. 

Efectivamente imprimió lo que tenia que imprimir.
