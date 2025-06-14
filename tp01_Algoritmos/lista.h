#include<stdio.h>
#include <stdlib.h>

typedef int item;
struct nodo{
    int dato;
    nodo* siguiente;
};typedef struct nodo* Lista;

//2) a)Crear una lista 
Lista crearLista (){
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
    while (!esListaVacia(L)) {
        printf("%d -> ", L->dato);
        L = L->siguiente;
    }
    printf("NULL\n");
}

//D Mustrar primer elemento de la lista
int PrimerElemento(Lista L){
    if(esListaVacia(L)){
        return (-9999);
    }else{
        return L->dato;
    }
}


//E) insertar nodo 
Lista insertar(Lista *L, int valor){
    nodo *nuevo = new nodo;
    nuevo->dato = valor;
    nuevo->siguiente = *L;
    *L = nuevo;
    return *L;
}

//f) Borrar el nodo del comienzo de la lista

Lista borrar( Lista *L){
    nodo *aux = *L;
    *L = (*L)->siguiente;
    delete aux;
    return *L;
}

//G) Longitud de la lista
int longitud(Lista L) {
    int contador = 0;
    while (L != NULL) {
        contador++;
        L = L->siguiente;
    }
    return contador;
}

//H) Determinar si un valor pertenece a la lista
bool pertenece(Lista L, item valor) {
    while (L != NULL) {
        if (L->dato == valor) {
            return true;
        }
        L = L->siguiente;
    }
    return false;
}

//i) borrar el ultimo nodo

Lista eliminarUltimo (Lista *L){
    nodo *aux = *L;
    while (aux->siguiente->siguiente != NULL)
    {
        aux = aux->siguiente;
    }
    delete aux->siguiente;
    aux->siguiente = NULL;
    return *L;
}

bool iguales(Lista L1, Lista L2){
    while (!esListaVacia(L1) && !esListaVacia(L2)){
        if (PrimerElemento(L1) != PrimerElemento(L2)){
            return false;
        }
        L1 = L1->siguiente;
        L2 = L2->siguiente;
    }
    return esListaVacia(L1) && esListaVacia(L2);
}