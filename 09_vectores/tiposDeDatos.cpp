#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	// Declaración e inicialización de un vector que contiene elementos de diferentes tipos de datos
	vector<int> enteros = {46, 23, 12, 99, 82};
	vector<char> cadenas = {'h', 'o', 'l', 'a'};
	vector<float> decimales = {3.14, 2.12, 1.618};
	
	// Imprimir los elementos del vector de enteros
	cout << "Vector de enteros: ";
	for (const auto& num : enteros) {
		cout << num << " ";
	}

    cout << endl;
	
    //imprimir los elementos del vector enteros del ultimo al primero
    cout << "Vector de enteros (ultimo al primero): ";
    for (int i = enteros.size() - 1; i >= 0; --i) {
        cout << enteros[i] << " ";
    }

	cout << endl;
	
	// Imprimir los elementos del vector de cadenas
	cout << "Vector de cadenas: ";
	for (const auto& str : cadenas) {
		cout << str << " ";
	}
	cout << endl;

 for ( int i = 0; i < cadenas.size(); i=i+1) {
        cout << "Elemento en el indice " << i << ": " << cadenas[i] << endl;
    }


	// Imprimir los elementos del vector de decimales
	cout << "Vector de decimales: ";
	for (const auto& decimal : decimales) {
		cout << decimal << " ";
	}
	cout << endl;
	
	return 0;
}