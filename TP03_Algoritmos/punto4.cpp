#include<stdio.h>
#include<string.h>

bool palabraPalindrome(char palabra[50], int inicio, int fin);

int main (){
    int inicio = 0, fin = 0;
    char palabra[50];
    bool palindrome;
    printf("Ingresar la palabra: ");
    gets(palabra);
    fin = strlen(palabra) -1;
    palindrome = palabraPalindrome(palabra,inicio,fin);
    if(palindrome){
        printf("La palabra es palindrome");
    }else{
        printf("La palabra no es palindrome");
    }
    return 0;
}

bool palabraPalindrome(char palabra[50], int inicio, int fin){
    if(fin <= inicio){
        return true;
    }else{
        if(palabra[inicio] != palabra[fin]){
            return false;
        }else{
            palabraPalindrome(palabra,inicio +1, fin - 1);
        }
    }
}