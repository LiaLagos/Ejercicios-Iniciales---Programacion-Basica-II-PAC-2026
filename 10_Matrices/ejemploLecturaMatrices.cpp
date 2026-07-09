/* Crear un programa en el cual se ingresen valores en una matriz  3 x3 para luego mostrarla en pantalla  */ 

#include <iostream>
using namespace std;

int main() {
    int matriz[3][3];

    // Ingresar valores en la matriz
    cout << "Ingrese los valores para la matriz 3x3:" << endl;
    for (int i = 0; i < 3; i++) { // Iterar sobre las filas
        for (int j = 0; j < 3; j++) { // Iterar sobre las columnas
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Mostrar la matriz en pantalla
    cout << "\nLa matriz ingresada es:" << endl;
    for (int i = 0; i < 3; i++) { // Iterar sobre las filas
        for (int j = 0; j < 3; j++) { // Iterar sobre las columnas
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

  //la diagonal proncipal de la matriz es:
cout << "\nLa diagonal principal es:" << endl;
    for (int i = 0; i < 3; i++) { // Iterar sobre las filas
        for (int j = 0; j < 3; j++) { // Iterar sobre las columnas
          
          if (i == j) { // Verificar si estamos en la diagonal principal
                cout << matriz[i][j] << " ";
            } 
          
      
        }
        //cout << endl;
    }





    return 0;
}