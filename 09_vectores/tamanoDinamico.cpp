#include <iostream>
#include <vector>

using namespace std;

int main() {
	// Declaración e inicialización de un vector vacío
	vector<int> miVector = {};
	
	// Agregar elementos al vector
	miVector.push_back(10);
	miVector.push_back(20);
	miVector.push_back(30);
	
	// Imprimir el tamaño inicial del vector
	cout << "Tamaño inicial del vector: " << miVector.size() << endl;
	
	// Agregar más elementos al vector
	miVector.push_back(40);
	miVector.push_back(50);
	
	// Imprimir el tamaño actualizado del vector
	cout << "Tamaño actualizado del vector: " << miVector.size() << endl;
	
	// Eliminar el último elemento del vector
	miVector.pop_back();

    miVector.clear(); // Eliminar otro elemento

	if (miVector.empty()) {
		cout << "El vector esta vacío." << endl;
	} else {
		cout << "El vector no esta vacio." << endl;
	}

	// Imprimir el tamaño después de eliminar un elemento
	cout << "Tamaño después de eliminar un elemento: " << miVector.size() << endl;
	
	return 0;
}