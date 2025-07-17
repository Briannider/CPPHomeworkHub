#include "LinkedList.hpp"
#include <iostream>
using namespace std;

bool EsPrimo(int num){
    if(num<=1)return false; //! 1 y 0 no son primos

    for(int i = 2; i<=num/2; i++){
        if (num % i == 0) return false; //! tiene un divisor → no es primo
    }

    return true; //! No encontro primos
}