#include <stdio.h>

typedef int item;
struct nodo{
    int dato;
    nodo* siguiente;
};typedef struct nodo* Lista;

Lista craerLista (){
    Lista L;
    L = NULL;
    return L;
}
/*
Lista craerLista (){
    return NULL;
}
*/
bool esListaVacia(Lista L){
    if(L == NULL){
        return true;
    }else{
        return false;
    }
}

Lista insertar(Lista L, int x){
    //1)Reserva de memoria dinamica para el nuevo nodo(new)
    //2)Agrego el dato x al nodo
    //3)Enlazar el nuevo nodo a la lista
        //a)El puntero siguiente del nuevo nodo apunta al primer nodo de la lista
        //b)Hacer que la cabecera apunte al nuevo nodo
}
/*
primero determinar si la lista esta vacia o no
1) declarar un puntero aux a nodo
2)Apunto el puntero aux al primer nodo de la lista
3)modificar la cabecera apunte al siguiente nod de la lista
4)Borrar el nodo aux
5)retornar la cabecera de la lista
*/

main (){
    Lista H;
    H = craerLista();
    esListaVacia(H);
}