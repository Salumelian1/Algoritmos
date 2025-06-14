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

Lista crearLista(){ //O(1)
    return NULL; // O(1)
}

bool esListaVacia(Lista L){ //O(1)
    if(L == NULL){//O(1)
        return true; //O(1)
    }else{
        return false;//O(1)
    }
}

void mostrar(Lista L){// O(1)
    while (!esListaVacia(L))// O(1)
    {
        printf("%d ",L->dato); // O(1)
        L = L->siguiente;// O(1)
    }
    
}

item primerElemento(Lista L){// O(1)
    if(esListaVacia(L)){// O(1)
        return indefinido;// O(1)
    }else{
        return L->dato;// O(1)
    }
}

Lista insertar(Lista L, item x){// O(1)
    Nodo* aux;// O(1)
    aux = new Nodo;// O(1)
    aux->dato = x;// O(1)
    aux->siguiente = L;// O(1)
    L = aux;// O(1)
    return L;// O(1)
}

Lista borrar(Lista L){// O(1)
    if(esListaVacia(L)){// O(1)
        return L;// O(1)
    }else{
        Nodo* aux;// O(1)
        aux = L;// O(1)
        L = L->siguiente;// O(1)
        delete(aux);// O(1)
        return L;// O(1)
    }
}

int longitud(Lista L){
    int longitud = 0;// O(n)
    if (esListaVacia(L))
    {
        return longitud;// O(1)
    }else{
        while(L != NULL){// O(n)
            longitud ++;// O(1)
            L = L->siguiente;// O(1)
        }
    }
    return longitud;
}

bool pertenece(Lista L, item x){// O(n)
    if(esListaVacia(L)){// O(n)
        return false;// O(1)
    }else{
        while(L != NULL){ //O(n)
            if(L->dato == x){// O(1)
                return true;// O(1)
            }
            L = L->siguiente;// O(1)
        }
        return false;
    }
}

Lista borrarUltimo(Lista L){// O(n)
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