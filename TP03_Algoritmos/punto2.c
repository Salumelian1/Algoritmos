#include<stdio.h>
void inverso(int n);

int main(){
    int n, x;
    printf("ingresar n: ");
    scanf("%d",&n);
    inverso(n);
    return 0;
}

void inverso(int n){
    int x = 0;
        if(n < 10){
            printf("%d", n);
        }else{
            x = n % 10;
            printf("%d ",x);
            n = n /10;
            inverso(n);
        }
}