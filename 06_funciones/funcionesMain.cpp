//ejemplo de una función pasando un parámetro por valor
#include <iostream>

using namespace std;

void multiplicarPorDos(int numero) {
	numero *= 2; // Multiplica el número por 2
	cout << "Dentro de la funcion: " << numero << "\n";
}

int main(int argc, char *argv[]) {
	
	int valor = 5;
	
	cout << "Antes de llamar a la funcion: " << valor << "\n";
	
	// Llamada a la función con un parámetro por valor
	multiplicarPorDos(valor);
	
	cout << "Despues de llamar a la funcion: " << valor << "\n";
	
	return 0;
}