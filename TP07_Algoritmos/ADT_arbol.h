#include<iostream>
#include "pila.h"

typedef char itemAB;

struct nodoAB{
    itemAB raiz;
    struct nodoAB *izq;
    struct nodoAB *der;
};
typedef struct nodoAB *AB;

AB ABvacio(){
    nodoAB* T;
    T = NULL;
    return T;
}

AB armarAb(AB i, itemAB r, AB d){
    nodoAB* T = new nodoAB;
    T->raiz = r;
    T->izq = i;
    T->der = d;
    return T;
}

AB izquierdo(AB T){
    if(esvacio(T)){
        return ABvacio();
    }else{
        return T->izq;
    }
}

AB derecho(AB T){
    if(esvacio(T)){
        return ABvacio();
    }else{
        return T->der;
    }
}

bool esvacio(AB T){
   if(T  == NULL){
        return true;
   }else{
        return false;
   }
}

bool pertenece(AB T, itemAB X){
    if(esvacio(T)){
        return false;
    }else{
        if(T->raiz == X){
            return true;
        }else{
            return pertenece(izquierdo(T),X) || pertenece(derecho(T),X);
        }
        
    }
}

AB Arbol_de_expresion(char posfija[50]){
    Pila aux = PilaVacia();
}

