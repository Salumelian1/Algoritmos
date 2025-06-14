#include<stdio.h>

typedef int item; // tipo de dato que contiene la fila
const int indefinido = -9999;
struct NodoFila
{
    item dato;
    struct NodoFila* sig;
};

struct Fila
{
    NodoFila* frente;
    NodoFila* final;
    int longitud;
};

Fila FilaVacia(){
    Fila F;
    F.frente = NULL;
    F.final = NULL;
    F.longitud = 0;
    return F;
}

bool EsFilaVacia(Fila F){
    if(F.longitud == 0){
        return true;
    }else{
        return false;
    }
}

Fila Enfila(Fila F,item x){
    NodoFila* aux = new NodoFila;
    aux->dato = x;
    aux->sig = NULL;
    if(EsFilaVacia(F)){
        F.frente = aux;
        F.final = aux;
    }else{
        F.final->sig = aux;
        F.final = aux;
    }
    F.longitud += 1;
    return F;
}


item Frente(Fila F){
    if(EsFilaVacia(F)){
        return indefinido;
    }else{
        return F.frente->dato;
    }
}

Fila Defila(Fila F){
    if (EsFilaVacia(F))
    {
        return F;
    }else{
        NodoFila* aux = new NodoFila;
        aux = F.frente;
        if(F.longitud == 1){
            F.final = NULL;
            F.frente = NULL;
        }else{
            F.frente = F.frente->sig;
        }
        delete(aux);
        F.longitud -= 1;
    }
    return F;
}

void MostrarFila(Fila F) {
    NodoFila* aux = new NodoFila;
    aux = F.frente;
    printf("Fila: ");
    while (aux != NULL) {
        printf("%d ",aux->dato);
        aux = aux->sig;
    }
}