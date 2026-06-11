/*  Elaborar un programa que realice operaciones aritméticas básicas (suma, resta, multiplicación, división) utilizando estructuras de control

Menu con switch para seleccionar la operación, y if para validar la entrada de datos (evitar división por cero). El programa debe solicitar al usuario dos números y la operación a realizar, luego mostrar el resultado.

*/

#include <iostream> // Incluimos la biblioteca iostream para poder usar cout y cin
#include <string>   // Incluimos la biblioteca string para poder usar el tipo de dato string si es necesario
#include <conio.h>  // Incluimos la biblioteca limits para poder usar numeric_limits si es necesario
#include <stdlib.h> // Librería para funciones de utilidad general

using namespace std; // Usamos el espacio de nombres std para evitar escribir std:: antes de cada uso de cout y cin

int main()
{
    double num1, num2, resultado;
    int opcion;

    do
    {

        cout << "--- CALCULADORA ---" << endl;
        cout << "\nSeleccione la operacion:" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. SALIR " << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\nBienvenidos a la suma de valores" << endl;

            /*   validar el ingreso de numeros mayores o iguales a 50*/
            cout << "Ingrese el primer numero: (no menor a 50) ";
            cin >> num1;
            while (num1 < 50)
            {
                cout << "Error: El numero debe ser mayor o igual a 50" << endl;
                cout << "Ingrese el primer numero: (no menor a 50) ";
                cin >> num1;
            }

            cout << " " << endl;
            cout << " " << endl;
            cout << "Ingrese el segundo numero: (no menor a 50) ";
            cin >> num2;
            while (num2 < 50)
            {
                cout << "Error: El numero debe ser mayor o igual a 50" << endl;
                cout << "Ingrese el segundo numero: (no menor a 50) ";
                cin >> num2;
                // return 1; // Salimos del programa con un código de error
            }

            resultado = num1 + num2;
            cout << "Resultado: " << num1 << " + " << num2 << " = " << resultado << endl;

            break;
        case 2:

            cout << "\nBienvenidos a la resta de valores" << endl;

            cout << "Ingrese el primer numero:  ";
            cin >> num1;

            cout << "Ingrese el segundo numero: ";
            cin >> num2;

            while (num1 < num2)
            {
                cout << "Error: El resultado de la resta no puede ser un valor negativo" << endl;
                cout << "Ingrese una valor menor o igual que " << num1 << endl;
                cout << "Ingrese el segundo numero:  ";
                cin >> num2;
            }

            /*
            Validar que la respueta NO sea un valor negativo
            */
            resultado = num1 - num2;
            cout << "Resultado: " << num1 << " - " << num2 << " = " << resultado << endl;
            break;

        case 3:
            cout << "\nBienvenidos a la multiplicacion de valores" << endl;
            cout << "Ingrese el primer numero:  ";
            cin >> num1;
            cout << "Ingrese el segundo numero: ";
            cin >> num2;

            resultado = num1 * num2;
            cout << "Resultado: " << num1 << " * " << num2 << " = " << resultado << endl;

            /* si el resultado esta entre 0 y 100 , colocar 'GRUPO A'
            si el resultado esta entre 101 y 500 , colocar 'GRUPO B'
            si el resultado es mayor a 500 , colocar 'GRUPO C'
            */
            if (resultado >= 0 && resultado <= 100)
            {
                cout << "GRUPO A" << endl;
            }
            else if (resultado > 100 && resultado <= 500)
            {
                cout << "GRUPO B" << endl;
            }
            else if (resultado > 500)
            {
                cout << "GRUPO C" << endl;
            }
            break;

        case 4:
            cout << "\nBienvenidos a la division de valores" << endl;
            cout << "Ingrese el primer numero:  ";
            cin >> num1;
            cout << "Ingrese el segundo numero: ";
            cin >> num2;
            if (num2 != 0)
            {
                resultado = num1 / num2;
                cout << "Resultado: " << num1 << " / " << num2 << " = " << resultado << endl;
            }
            else
            {
                cout << "Error: No se puede dividir entre cero" << endl;
            }
            break;

        case 5:
            cout << "Gracias por usar el programa..." << endl;
            break;

        default:
            cout << "Opción no válida" << endl;
        }

    } while (opcion != 5);

    return 0; // Retornamos 0 para indicar que el programa terminó correctamente
}
