
    for (int i = 0; i < nCartas; i++)
    {
        if(i %2 == 0){
            Enfila(j1,mazo[i]);
        }else{
            Enfila(j2,mazo[i]);
        }
    }
    while(!EsFilaVacia(j1) && EsFilaVacia(j2)){