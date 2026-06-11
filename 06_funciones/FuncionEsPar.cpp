#include <iostream>
using namespace std;
// Función para determinar si un número es par o impar
int esPar(int n) { 
    return n % 2 == 0; // % divide entre 2 y devuelve el resto, si el resto es 0, entonces es par
}

int main() {
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero; // solicita al usuario que ingrese un número

    if (esPar(numero))
        cout << "El numero " << numero << " es par." << endl; //
    else
        cout << "El numero " << numero << " es impar." << endl; 

    return 0;
}
