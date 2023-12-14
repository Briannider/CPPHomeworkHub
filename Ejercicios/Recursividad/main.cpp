#include "funciones.hpp"
#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int resultado = sum(arr, 5);

    cout << "resultado: " << resultado << endl;

    return 0;
}
