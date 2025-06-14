#include<stdio.h>

int sumaDeDig(int n);

int main (){
    int n, suma = 0;
    printf("ingresar el numero: ");
    scanf("%d",&n);
    suma = sumaDeDig(n);
    printf("%d",suma);
    getchar();
    return 0;
}

int sumaDeDig(int n){
    int x = 0, suma =0;
    if(n < 10){
        return n;
    }else{
        return (n % 10 + sumaDeDig(n/10));
    }
}