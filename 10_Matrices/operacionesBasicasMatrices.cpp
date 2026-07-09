/* Hacer un programa en el cual a partir de un menu con las 4 operaciones basicas
  (1. suma, 2. resta, 3. multiplicacion, 4. division)
  se ingresen diferentes valores en una matriz (CUADRADADA) definida por el usuario 
    NO MAYOR A 10 FILAS Y 10 COLUMNAS)
  
    EL REPORTE DE LOS RESULTADOS DEBE MOSTRARSE EN PANTALLA Y GUARDARSE EN UN ARCHIVO DE TEXTO
  */

#include <iostream>
#include <fstream> // Librería para manejo de archivos
using namespace std;

// Definir e inicializar las matrices
int filas, columnas;
double datos1[10][10];
double datos2[10][10];
double resultado[10][10];

// Función para llenar una matriz
void llenarMatriz(double matriz[10][10], int n, string nombre) {
    cout << "\nIngrese los valores de la matriz " << nombre << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << nombre << "[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

// Función para mostrar una matriz
void mostrarMatriz(double matriz[10][10], int n, string titulo) {
    cout << "\n" << titulo << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para guardar el reporte en archivo
void guardarArchivo(double m1[10][10], double m2[10][10], double res[10][10], int n, int opcion) {
    ofstream archivo("reporte_matrices.txt");

    if (!archivo) {
        cout << "\nError al crear el archivo.\n";
        return;
    }

    string operacion;
    switch (opcion) {
        case 1: operacion = "SUMA"; break;
        case 2: operacion = "RESTA"; break;
        case 3: operacion = "MULTIPLICACION"; break;
        case 4: operacion = "DIVISION"; break;
        default: operacion = "DESCONOCIDA";
    }

    archivo << "===== REPORTE DE OPERACIONES CON MATRICES =====\n";
    archivo << "Operacion realizada: " << operacion << "\n";
    archivo << "Dimension de la matriz: " << n << " x " << n << "\n\n";

    archivo << "MATRIZ 1:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            archivo << m1[i][j] << "\t";
        }
        archivo << endl;
    }

    archivo << "\nMATRIZ 2:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            archivo << m2[i][j] << "\t";
        }
        archivo << endl;
    }

    archivo << "\nRESULTADO:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            archivo << res[i][j] << "\t";
        }
        archivo << endl;
    }

    archivo.close();
    cout << "\nReporte guardado correctamente en 'reporte_matrices.txt'\n";
}

int main() {
    int opcion;

    cout << "===== OPERACIONES BASICAS CON MATRICES CUADRADAS =====\n";
    
    do {
        cout << "Ingrese el tamano de la matriz cuadrada (maximo 10): ";
        cin >> filas;

        if (filas < 1 || filas > 10) {
            cout << "Error. El tamano debe estar entre 1 y 10.\n";
        }

    } while (filas < 1 || filas > 10);

    columnas = filas; // porque es cuadrada

    // Llenar matrices
    llenarMatriz(datos1, filas, "Matriz1");
    llenarMatriz(datos2, filas, "Matriz2");

    // Mostrar menú
    cout << "\n===== MENU DE OPERACIONES =====\n";
    cout << "1. Suma\n";
    cout << "2. Resta\n";
    cout << "3. Multiplicacion\n";
    cout << "4. Division\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            // Suma
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    resultado[i][j] = datos1[i][j] + datos2[i][j];
                }
            }
            break;

        case 2:
            // Resta
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    resultado[i][j] = datos1[i][j] - datos2[i][j];
                }
            }
            break;

        case 3:
            // Multiplicación elemento por elemento
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    resultado[i][j] = datos1[i][j] * datos2[i][j];
                }
            }
            break;

        case 4:
            // División elemento por elemento
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    if (datos2[i][j] != 0) {
                        resultado[i][j] = datos1[i][j] / datos2[i][j];
                    } else {
                        resultado[i][j] = 0;
                        cout << "\nNo se puede dividir entre 0 en la posicion [" << i << "][" << j << "]. Se colocara 0.\n";
                    }
                }
            }
            break;

        default:
            cout << "\nOpcion invalida.\n";
            return 0;
    }

    // Mostrar matrices y resultado
    mostrarMatriz(datos1, filas, "Matriz 1");
    mostrarMatriz(datos2, filas, "Matriz 2");
    mostrarMatriz(resultado, filas, "Resultado");

    // Guardar en archivo
    guardarArchivo(datos1, datos2, resultado, filas, opcion);

    return 0;
}