#include <iostream>
#include <vector>

using namespace std;

int main() {
	// Declaración e inicialización de un vector de enteros
	vector<int> numeros = {10, 20, 30, 40, 50};
	
	// Accediendo e imprimiendo el primer elemento del vector
	cout << "Primer elemento del vector: " << numeros[0] << endl;
	
	// Accediendo e imprimiendo el tercer elemento del vector
	cout << "Tercer elemento del vector: " << numeros[2] << endl;
	
	// Asignando un nuevo valor al segundo elemento del vector
	numeros[1] = 25;
	
	// Imprimiendo el vector actualizado
	std::cout << "Vector actualizado: ";
	for (int i = 0; i < numeros.size(); ++i) {
		std::cout << numeros[i] << " ";
	}
	cout << endl;
	
	return 0;
}