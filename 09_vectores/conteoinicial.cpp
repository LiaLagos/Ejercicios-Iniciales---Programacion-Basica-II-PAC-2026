#include <iostream>
#include <vector>

using namespace std;

int main() {
	// Declaración e inicialización de un vector de enteros
	vector<int> miVector = {1, 2, 3, 4, 5};
	
	// Accediendo e imprimiendo elementos del vector
	for (int i = 0; i < miVector.size(); ++i) {
		cout << "Elemento " << i << ": " << miVector[i] << std::endl;
	}
	
	return 0;
}