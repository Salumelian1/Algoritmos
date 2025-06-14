#include<stdio.h>
#define MAX 50

bool ArregloOrdenado(int arreglo[50], int inicio, int fin);

int main(){
    int inicio = 0, fin, arreglo[MAX];
    bool ordenado;
    printf("Ingresar el orden del arreglo: ");
    scanf("%d",&fin);
    for(int i = 0; i < fin; i++){
        printf("\nIngrese el elemento %d del arreglo: ",i+1);
        scanf("%d",&arreglo[i]);
    }
    ordenado = ArregloOrdenado(arreglo,inicio,fin);
    if(ordenado){
        printf("\nEl arreglo esta ordenao");
    }else{
        printf("\nEl arreglo no esta ordenado");
    }
    return 0;
}

bool ArregloOrdenado(int arreglo[50], int inicio, int fin){
    if(fin <= inicio){
        return true;
    }else{
        if(arreglo[inicio] >= arreglo[inicio + 1]){
            return false;
        }else{
            return ArregloOrdenado(arreglo,inicio +1,fin);
        }
    }
}