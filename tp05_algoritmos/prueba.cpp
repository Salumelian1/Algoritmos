#include <iostream>
#include "Pila.h"
using namespace std;

// Insertar aquí el código de la implementación completa de pila y funciones

int main() {
    Pila P = PilaVacia();
    // Insertamos elementos para formar una pila simétrica: 1, 2, 3, 2, 1
    P = Push(P, 1);
    P = Push(P, 2);
    P = Push(P, 3);
    P = Push(P, 2);
    P = Push(P, 1);

    cout << "Altura de la pila: " << P.altura << endl;
    cout << "Elemento en el tope: " << TOP(P) << endl;
    cout << "Elemento en el fondo: " << Fondo(P) << endl;

    if (EsSimetrica(P)) {
        cout << "La pila es simetrica." << endl;
    } else {
        cout << "La pila NO es simetrica." << endl;
    }

    // Probamos POPF: quitar el fondo
    P = POPF(P);
    cout << "\nLuego de POPF, fondo = " << Fondo(P) << endl;
    cout << "Nuevo tope = " << TOP(P) << endl;

    // Probamos POP: quitar el tope
    P = POP(P);
    cout << "\nLuego de POP, nuevo tope = " << TOP(P) << endl;

    // Mostramos todos los elementos restantes
    cout << "\nElementos restantes en la pila: ";
    while (!EsPilaVacia(P)) {
        cout << TOP(P) << " ";
        P = POP(P);
    }
    cout << endl;

    return 0;
}
