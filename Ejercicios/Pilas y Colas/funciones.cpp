#include <iostream>
using std::cin;
using std::cout;


struct Nodo{
    int info;
    Nodo* sgte;
};

void encolar( Nodo* frte, Nodo* fin, int v){
    Nodo* p = new Nodo();
    p->info = v;
    p->sgte = NULL;

    if(frte == NULL){
        frte = p;
    }else{
        fin = p;
    }
}

void desencolar(){
    
}


