#include <iostream>
#include "cuenta.h"

using namespace std;

int main() {
    Cuenta miCuenta = cuentaVacia();
    
    cout << "¿La cuenta está vacía? " << (estaVacia(miCuenta) ? "Si" : "No") << endl;

    // Depositar dinero
    miCuenta = Depositar(miCuenta, 100);
    miCuenta = Depositar(miCuenta, 50);
    miCuenta = Depositar(miCuenta, 25);

    cout << "Saldo actual: " << Saldo(miCuenta) << endl;
    cout << "Cantidad de operaciones: " << cantidad(miCuenta) << endl;
    cout << "¿Contiene 50? " << (Contiene(miCuenta, 50) ? "Sí" : "No") << endl;
    cout << "¿Contiene 999? " << (Contiene(miCuenta, 999) ? "Sí" : "No") << endl;
    cout << "Último movimiento: " << Ultima(miCuenta) << endl;
    cout << "¿Tiene saldo? " << (tieneSaldo(miCuenta) ? "Sí" : "No") << endl;

    // Extraer una cantidad válida
    miCuenta = Extraer(miCuenta, 80);
    cout << "Saldo tras extraer 80: " << Saldo(miCuenta) << endl;

    // Extraer una cantidad mayor al saldo
    miCuenta = Extraer(miCuenta, 500);
    cout << "Saldo tras intentar extraer 500: " << Saldo(miCuenta) << endl;

    // Deshacer última operación
    miCuenta = Deshacer(miCuenta);
    cout << "Saldo tras deshacer última operación: " << Saldo(miCuenta) << endl;

    return 0;
}
