#include <iostream>
// Función para determinar si un número es par o impar
int esPar(int n) { 
    return n % 2 == 0; // % divide entre 2 y devuelve el resto, si el resto es 0, entonces es par
}

int main() {
    int numero;
    std::cout << "Ingrese un numero: ";
    if (!(std::cin >> numero)) return 1;

    if (esPar(numero))
        std::cout << "El numero " << numero << " es par." << std::endl;
    else
        std::cout << "El numero " << numero << " es impar." << std::endl; 

    return 0;
}
