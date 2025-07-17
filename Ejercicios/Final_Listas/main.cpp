#include "LinkedList.hpp"
#include <iostream>
using namespace std;

int main()
{   
    int num;
    cout<<"Ingrese el numero primo "<<endl;
    cin>>num;
    if(EsPrimo(num)){
        cout<<"Es primo"<<endl;
    }else{
        cout<<"No es primo"<<endl;
    }
    
    return 0;
}
