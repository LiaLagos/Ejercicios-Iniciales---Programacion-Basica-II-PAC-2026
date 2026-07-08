#include <iostream>
#include <vector>

int main() {
	// Declaración e inicialización de un vector de enteros
	vector<int> miVector = {1, 2, 3, 4, 5};
	
	// Utilizando un iterador para recorrer y imprimir los elementos del vector
	cout << "Elementos del vector: ";
	for (auto it = miVector.begin(); it != miVector.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	

int main() {
    // Declaración e inicialización de un vector de estudiantes
    std::vector<estudiante> estudiantes = {
        {"Alice", 20},
        {"Bob", 22},
        {"Charlie", 21}
    };

    // Utilizando un iterador para recorrer y imprimir los elementos del vector
    std::cout << "Estudiantes:" << std::endl;
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        std::cout << "Nombre: " << it->nombre << ", Edad: " << it->edad << std::endl;
    }

    return 0;
}





/* miVector.begin() devuelve un iterador que apunta al primer elemento del vector, 

mientras que miVector.end() devuelve un iterador que apunta al elemento después del último elemento del vector.

Usamos un bucle for para recorrer el vector utilizando estos iteradores. 

El bucle continúa mientras el iterador no alcanza el final del vector (it != miVector.end()).

En cada iteración, accedemos al valor al que apunta el iterador utilizando *it y lo imprimimos.*/