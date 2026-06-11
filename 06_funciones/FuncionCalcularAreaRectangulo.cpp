#include <iostream>
using namespace std;
int calcularAreaRectangulo(int base, int altura) { // esta función recibe dos parámetros enteros, base y altura, y devuelve un entero que es el área del rectángulo
    return base * altura;
}

int main() {
    int base = 0;
    int altura = 0;

    cout << "Ingrese la base del rectangulo: ";
    cin >> base;
    cout << "Ingrese la altura del rectangulo: ";
    cin >> altura;

    int area = calcularAreaRectangulo(base, altura);
    cout << "El area del rectangulo es: " << area << endl;

    return 0;
}