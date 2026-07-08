#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Declaración e inicialización de un vector de nombres
	vector<string> nombres = {"Ana", "Juan", "Maria", "Pedro"};
	
	// Agregar un nuevo nombre al vector
	nombres.push_back("Luis");
	
	// Imprimir todos los nombres en el vector
	for (const auto& nombre : nombres) {
		cout << nombre << std::endl;
	}
	
	return 0;
}