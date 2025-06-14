#include<stdio.h>
bool oredenado(int num);

int main (){
    int num;
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    if(oredenado(num)){
        printf("\nEl numero esta ordenado.");
    }else{
        printf("\nEl numero no esta ordenado");
    }
    return 0;
}

bool oredenado(int num){
    int aux, ant;
    if(num < 10){
        return true;
    }else{
        aux = num % 10;
        ant = (num /10 )%10;
        if(ant <= aux){
            oredenado(num /10);
        }else{
            return false;
        }
    }
}