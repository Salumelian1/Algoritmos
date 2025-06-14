#include<stdio.h>
#include "Pila.h"
#include "Lista.h"

//funcion que devuelve la prioridad de un operador
int prioridad(char operador);
void Convertir(char expresion[100]);

int main (){
    char expresion[100];
    printf("Ingrese la expresion a convertir: ");
    gets(expresion);
    Convertir(expresion);
    return 0;
}

int prioridad(char operador){
    switch (operador)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '~':
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

void Convertir(char expresion[100]){
    int i = 0;
    char aux;
    Lista Postfija = crearLista();
    Pila P = PilaVacia();
    while (expresion[i] != '=')
    {
        switch (expresion[i])
        {
        case '(':
                Push(P,expresion[i]);
            break;
        case ')':
            while(TOP(P) != '('){
                aux = TOP(P);
                POP(P);
                insertar(Postfija,aux);
            }
            POP(P);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '~':
            while (prioridad(expresion[i]) <= prioridad(TOP(P)))
            {
                aux = TOP(P);
                POP(P);
                insertar(Postfija,aux);
            }
            Push(P,expresion[i]);
            break;
        default:
            insertar(Postfija, expresion[i]);
            break;
        }
        i++;
    }
    while (!EsPilaVacia(P)){
        aux = TOP(P);
        P = POP(P);
        insertar(Postfija, aux);
    }
    mostrar(Postfija);
}