#include<stdio.h>

typedef int item;
struct nodo{
    int dato;
    nodo* siguiente;
};typedef struct nodo* Lista;

//2) a)Crear una lista 
Lista craerLista (){
    Lista L;
    L = NULL;
    return L;
}

//b) Es lista vacia

bool esListaVacia(Lista L){
    if(L == NULL){
        return true;
    }else{
        return false;
    }
}

//c) mostrar lista
void mostrar(Lista L){
    nodo *actual = L;
    while (actual != NULL)
    {
        printf("%d-> ",actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


//D) insertar nodo 
Lista insertar(Lista *L, int valor){
    nodo *nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *L;
    *L = nuevo;
}

//Borrar el nodo del comienzo de la lista

void borrar( Lista *L){
    if(esListaVacia(*L))
}
