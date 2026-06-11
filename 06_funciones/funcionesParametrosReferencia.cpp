#include <iostream>
using namespace std;

void intercambiar(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


int main(int argc, char *argv[]) {
	
	int x = 5;
	int y = 10;
	
	cout << "Antes del intercambio: x = " << x << ", y = " << y << "\n";
	
	// Llamada a la función con argumentos por referencia
	intercambiar(x, y);
	
	cout << "Después del intercambio: x = " << x << ", y = " << y << "\n";
	
	return 0;
}