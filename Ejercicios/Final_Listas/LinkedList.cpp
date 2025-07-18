#include "LinkedList.hpp"
#include <iostream>
using namespace std;

// Function to check if a number is prime
// Returns true if the number is prime, false otherwise
/*
bool IsPrime(int num){
    if(num<=1)return false; //! 1 and 0 are not prime

    for(int i = 2; i<=num/2; i++){
        if (num % i == 0) return false; //! it has a divisor → it is not prime
    }

    return true; //! There isn't any prime number
}
*/