#include<stdio.h>

#define indefinido -99999

//tipificación 
typedef int item;

typedef struct Nodo {
    item dato;
    Nodo* siguiente;
} Nodo;


typedef Nodo* Lista;

//Funciones basicas

Lista crearLista(){
    return NULL;
}

bool esListaVacia(Lista L){
    if(L == NULL){
        return true;
    }else{
        return false;
    }
}

void mostrar(Lista L){
    while (!esListaVacia(L))
    {
        printf("%d ",L->dato);
        L = L->siguiente;
    }
    
}

item primerElemento(Lista L){
    if(esListaVacia(L)){
        return indefinido;
    }else{
        return L->dato;
    }
}

Lista insertar(Lista L, item x){
    Nodo* aux;
    aux = new Nodo;
    aux->dato = x;
    aux->siguiente = L;
    L = aux;
    return L;
}

Lista borrar(Lista L){
    if(esListaVacia(L)){
        return L;
    }else{
        Nodo* aux;
        aux = L;
        L = L->siguiente;
        delete(aux);
        return L;
    }
}

int longitud(Lista L){
    int longitud = 0;
    if (esListaVacia(L))
    {
        return longitud;
    }else{
        while(L != NULL){
            longitud ++;
            L = L->siguiente;
        }
    }
    return longitud;
}

bool pertenece(Lista L, item x){
    if(esListaVacia(L)){
        return false;
    }else{
        while(L != NULL){
            if(L->dato == x){
                return true;
            }
            L = L->siguiente;
        }
        return false;
    }
}

Lista borrarUltimo(Lista L){
    if (esListaVacia(L))
    {
        return L;
    }
    if(L->siguiente == NULL){
        delete L;
        return NULL;
    }
    Nodo* aux = L;
    while (aux->siguiente->siguiente != NULL)
    {
        aux = aux->siguiente;
    }
    delete aux->siguiente;
    aux->siguiente = NULL;
    return L;
}

bool iguales(Lista L1, Lista L2){
    if(esListaVacia(L1) || esListaVacia(L2)){
        return false;
    }
    if(longitud(L1) != longitud(L2)){
        return false;
    }
    while(L1 != NULL && L2 != NULL){
        if(L1->dato != L2->dato){
            return false;
        }
        L1 = L1->siguiente;
        L2 = L2->siguiente;
    }
    return true;
}