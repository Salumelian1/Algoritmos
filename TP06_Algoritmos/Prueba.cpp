#include<stdio.h>
#include"Fila.h"
#include <iostream>
int main() {
    Fila F = FilaVacia();
    printf(" ¿Fila vacia? ");
    if (EsFilaVacia(F))
    {
        printf("\nEs fila vacia\n");
    }else{
        printf("\nNo es fila vacia\n");
    }
    

    // Enfilando elementos
    F = Enfila(F, 10);
    F = Enfila(F, 20);
    F = Enfila(F, 30);
    F = Enfila(F, 40);
    MostrarFila(F);

    // Frente
    printf("\nFrente: %d\n", Frente(F));

    // Defilando
    F = Defila(F);
    MostrarFila(F);
    printf("\nFrente: %d\n", Frente(F));

    // Más defilados
    F = Defila(F);
    F = Defila(F);
    MostrarFila(F);
    MostrarFila(F);
    printf("¿Fila vacia después de defilar todo?");
        if (EsFilaVacia(F))
    {
        printf("\nEs fila vacia\n");
    }else{
        printf("\nNo es fila vacia\n");
    }
    printf("Frente (esperado indefinido): %d\n", Frente(F));

    return 0;
}