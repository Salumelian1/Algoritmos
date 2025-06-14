#include <stdio.h>
#include "Fila.h"
#include "Lista.h"

int main() {
    Fila j1 = FilaVacia();
    Fila j2 = FilaVacia();
    int nCartas;
    int mazo[24] = {7,8,5,9,7,5,9,9,8,7,6,4,7,4,5,6,8,4,8,5,9,6,4,6};

    do {
        printf("Ingrese el numero de cartas del mazo (par, max 24): ");
        scanf("%d", &nCartas);
    } while (nCartas > 24 || nCartas % 2 != 0);

    // Repartir alternadamente
    for (int i = 0; i < nCartas; i++) {
        if (i % 2 == 0)
            j1 = Enfila(j1, mazo[i]);
        else
            j2 = Enfila(j2, mazo[i]);
    }

    int ronda = 1;

    while (!EsFilaVacia(j1) && !EsFilaVacia(j2)) {
        printf("\n======== RONDA %d ========\n", ronda++);

        Lista guerra = crearLista();

        int carta1 = Frente(j1); j1 = Defila(j1);
        int carta2 = Frente(j2); j2 = Defila(j2);

        printf("Jugador 1 juega: %d\n", carta1);
        printf("Jugador 2 juega: %d\n", carta2);

        guerra = insertar(guerra, carta1);
        guerra = insertar(guerra, carta2);

        while (carta1 == carta2) {
            printf("¡Guerra!\n");

            if (j1.longitud < 2) {
                printf("Jugador 1 no tiene suficientes cartas para continuar. Gana Jugador 2.\n");
                return 0;
            }
            if (j2.longitud < 2) {
                printf("Jugador 2 no tiene suficientes cartas para continuar. Gana Jugador 1.\n");
                return 0;
            }

            // Cartas ocultas
            int oculta1 = Frente(j1); j1 = Defila(j1);
            int oculta2 = Frente(j2); j2 = Defila(j2);
            guerra = insertar(guerra, oculta1);
            guerra = insertar(guerra, oculta2);

            // Nuevas cartas visibles
            carta1 = Frente(j1); j1 = Defila(j1);
            carta2 = Frente(j2); j2 = Defila(j2);

            printf("Jugador 1 nueva carta visible: %d\n", carta1);
            printf("Jugador 2 nueva carta visible: %d\n", carta2);

            guerra = insertar(guerra, carta1);
            guerra = insertar(guerra, carta2);
        }

        // Mostrar guerra acumulada (reversa porque se inserta al inicio)
        printf("Cartas en juego: ");
        mostrar(guerra);

        Nodo* aux = guerra;
        if (carta1 > carta2) {
            printf("Jugador 1 gana la ronda\n");
            while (aux != NULL) {
                j1 = Enfila(j1, aux->dato);
                aux = aux->siguiente;
            }
        } else {
            printf("Jugador 2 gana la ronda\n");
            while (aux != NULL) {
                j2 = Enfila(j2, aux->dato);
                aux = aux->siguiente;
            }
        }

        printf("Mazo J1: ");
        MostrarFila(j1);
        printf("Mazo J2: ");
        MostrarFila(j2);
    }

    if (EsFilaVacia(j1))
        printf("\nGana el jugador 2 (J1 se quedó sin cartas)\n");
    else
        printf("\nGana el jugador 1 (J2 se quedó sin cartas)\n");

    return 0;
}
