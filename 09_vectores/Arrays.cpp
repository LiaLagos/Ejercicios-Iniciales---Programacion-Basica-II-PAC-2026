#include <iostream>
#include <vector>


using namespace std;

int main() {
	// Declaración e inicialización de un vector de enteros
	vector<int> miVector = {10, 20, 30, 40, 50};
	
	// Acceso eficiente a los elementos del vector mediante índices
	cout << "Primer elemento del vector: " << miVector[0] << endl;
	cout << "Tercer elemento del vector: " << miVector[2] << endl;
	
	// Modificación de un elemento del vector
	miVector[1] = 25;
	
	// Imprimir el vector actualizado
	cout << "Vector actualizado: ";
	for (int i = 3; i < miVector.size(); ++i) {
		cout << miVector[i] << " ";
	}
	cout << endl;
	
	return 0;
}