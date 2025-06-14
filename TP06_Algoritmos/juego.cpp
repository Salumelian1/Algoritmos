#include<stdio.h>
#include "Fila.h"
#include "Lista.h"

int main(){
    Fila j1 = FilaVacia();
    Fila j2 = FilaVacia();
    int nCartas;
    int mazo[24]={7,8,5,9,7,5,9,9,8,7,6,4,7,4,5,6,8,4,8,5,9,6,4,6};
    do{
        printf("Ingrese el numero de cartas del mazo: ");
        scanf("%d",&nCartas);
    }while(nCartas > 24 || nCartas % 2 != 0);
    for (int i = 0; i < nCartas; i++)
    {
        if(i %2 == 0){
            Enfila(j1,mazo[i]);
        }else{
            Enfila(j2,mazo[i]);
        }
    }
    while(!EsFilaVacia(j1) && EsFilaVacia(j2)){
        Lista guerra = crearLista();
        int carta1 = Frente(j1);
        int carta2 = Frente(j2);
        Defila(j1);
        Defila(j2);
        insertar(guerra,carta1);
        insertar(guerra,carta2);
        while (carta1 == carta2)
        {
            if(j1.longitud < 2){
                printf("\nGana el jugador 2");
                return 0;
            }else{
                printf("\nGana el jugador 1");
                return 0;
            }
            int cartaExtra1 = Frente(j1);
            int cartaExtra2 = Frente(j2);
            Defila(j1);
            Defila(j2);
            insertar(guerra,cartaExtra1);
            insertar(guerra,cartaExtra2);
            if (carta1 > carta2) {
            // j1 gana y se lleva todas las cartas
                while (!esListaVacia(guerra))
                {
                    Enfila(j1,primerElemento(guerra));
                    guerra = guerra->siguiente;
                }
                
            } else {
            // j2 gana y se lleva todas las cartas
                Enfila(j2,primerElemento(guerra));
                guerra = guerra->siguiente;
            }
        }
    }
    if (EsFilaVacia(j1))
        printf("Gana el jugador 2\n");
    else
        printf("Gana el jugador 1\n");

    return 0;
    
}