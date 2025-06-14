#include <stdio.h>
#include "lista.h"

bool iguales (Lista L1, Lista L2);

bool iguales (Lista L1, Lista L2){
    while (!esListaVacia(L1) && !esListaVacia(L2))
    {
        if(PrimerElemento(L1) != PrimerElemento (L2)){
            return false;
        }
        L1 = borrar(&L1);
        L2 = borrar(&L2);
    }
    return true;
}