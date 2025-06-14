#include<stdio.h>

#define indefinido -99999

typedef int Dinero;

typedef struct Nodo {
    Dinero dato;
    Nodo* siguiente;
} Nodo;

typedef Nodo *Cuenta;

Cuenta cuentaVacia(){
    return NULL;
}

Cuenta Depositar(Cuenta C, Dinero x){
    Nodo *aux;
    aux = new Nodo;
    aux->dato = x;
    aux->siguiente = C;
    C = aux;
    return C;
}

bool estaVacia(Cuenta C){
    if(C == NULL){
        return true;
    }else{
        return false;
    }
}

int Saldo(Cuenta C){
    Dinero Saldo = 0;
    Nodo* aux = C;
    while(aux != NULL){
        Saldo += aux->dato;
        aux = aux->siguiente;
    }
    return Saldo;
}

Cuenta Extraer(Cuenta C, Dinero extraer){
    if (estaVacia(C))
    {
        return cuentaVacia();
    }
    else{
        if(Saldo(C)>= extraer){
            return Depositar(C,(-extraer));
        }else{
            return Depositar(C,0);
        }
    }
}

bool tieneSaldo(Cuenta C){
    if(estaVacia(C)){
        return false;
    }else{
        if(Saldo(C) > 0){
            return true;
        }
    }
}

Dinero Ultima(Cuenta C){
    Nodo* aux = C;
    if(estaVacia(C)){
        return indefinido;
    }else{
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        return aux->dato;
    }
}

Cuenta Deshacer(Cuenta C){
    if (estaVacia(C))
    {
        return cuentaVacia();
    }
    if(C->siguiente == NULL){
        delete C;
        return NULL;
    }
    Nodo* aux = C;
    while (aux->siguiente->siguiente != NULL)
    {
        aux = aux->siguiente;
    }
    delete aux->siguiente;
    aux->siguiente = NULL;
    return C;
}

bool Contiene(Cuenta C, Dinero x){
    if(estaVacia(C)){
        return false;
    }else{
        while(C != NULL){
            if(C->dato == x){
                return true;
            }
            C =C->siguiente;
        }
        return false;
    }
}

int cantidad(Cuenta C){
    int cantidad = 0;
    Nodo *aux;
    aux = C;
    if(estaVacia(C)){
        return cantidad;
    }else{
        while(aux != NULL){
            cantidad ++;
            aux = aux->siguiente;
        }
        return cantidad;
    }
}