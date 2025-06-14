#include<stdio.h>

typedef int item;
const item indefinido = - 9999;

struct nodo
{
    item dato;
    nodo* siguiente;
}typedef nodo;

typedef struct
{
    nodo* cabecera;
    int altura;
}Pila;


Pila PilaVacia(){
    Pila P;
    P.cabecera = NULL;
    P.altura = 0;
    return P;
}

bool EsPilaVacia(Pila P){
    if(P.cabecera == NULL){
        return true;
    }else{
        return false;
    }
}

Pila Push(Pila P, item X){
    nodo* nuevo = new nodo;
    nuevo->dato = X;
    nuevo->siguiente = P.cabecera;
    P.cabecera = nuevo;
    P.altura++;
    return P;
}

Pila POP(Pila P){
    if(EsPilaVacia(P)){
        return PilaVacia();
    }else{
        nodo* aBorrar = P.cabecera;
        P.cabecera = P.cabecera->siguiente;
        delete aBorrar;
        P.altura--;
        return P;
    }
}

item TOP(Pila P){
    int X;
    if(EsPilaVacia(P)){
        return indefinido;
    }else{
        X = P.cabecera->dato;
    }
    return X;
}

item Fondo(Pila P){
    if(EsPilaVacia(P)){
        return indefinido;
    }else{
       nodo* aux = P.cabecera;
       while(aux->siguiente != NULL){
            aux = aux->siguiente;
       }
       return aux->dato;
    }
}

Pila POPF(Pila P){
    if(EsPilaVacia(P)){
        return PilaVacia();
    }else{
        if(P.altura == 1){
            return PilaVacia();
        }else{
            item X = TOP(P);
            P = POP(P);
            return Push(POPF(P),X);
        }
    }
}

bool EsSimetrica(Pila P) {
    if (EsPilaVacia(P) || EsPilaVacia(POP(P))) {
        return true;
    }
    if (Fondo(P) == TOP(P)) {
        P = POPF(P);
        P = POP(P);
        return EsSimetrica(P);
    }
    return false;
}