#include <iostream>
using namespace std;

// Declaración de la función
void sumar(int a, int b, int c) {
	cout << "La suma de " << a << " y " << b << " y " << c << " es: " << a + b + c << "\n";
}

int main(int argc, char *argv[]) {

		int num1 = 5;
		int num2 = 7;
        int num3 = 9;
		
		// Llamada a la función con argumentos
		sumar(num1, num2, num3);
		return 0;
}
