/* Crear un porgrama en el cual luego de ingresar 2 valores (inicial y final)
debe mostrar los correlativos existentes para posteriormente
mostrar los valores pares y los pavlores impares que existen entre los valores ingresados.*/

#include <iostream>
using namespace std;

int main()
{
    int par = 0, impar = 0; // Contadores para los valores pares e impares
    int inicio = 0, limite = 0;
    int datos[100];   // Arreglo para almacenar los correlativos
    int pares[100];   // Arreglo para almacenar los valores pares
    int impares[100]; // Arreglo para almacenar los valores impares
    int totalCorrelativos = 0;

    // Solicitar al usuario los valores inicial y final
    do
    {
        cout << "Ingrese el valor inicial: ";
        cin >> inicio;

        if(inicio < 0)
        {
            cout << "Error: El valor inicial no puede ser negativo." << endl;
            // Validar que el valor inicial no sea negativo
        }
        else if(inicio >= 100)
        {
            cout << "Error: El valor inicial no puede ser mayor o igual a 100." << endl;
            // Validar que el valor inicial no sea mayor a 100
        }

    } while (inicio < 0 || inicio >= 100);
    // Validar que el valor inicial esté entre 0 y 100

    // validar que no existan más de 100 correlativos entre los valores ingresados
    do
    {
        cout << "Ingrese el valor final: ";
        cin >> limite;

        if(limite < 0)
        {
            cout << "Error: El valor final no puede ser negativo." << endl;
            // Validar que el valor final no sea negativo
        }
        else if(limite > 100)
        {
            cout << "Error: El valor final no puede ser mayor a 100." << endl;
            // Validar que el valor final no sea mayor a 100
        }
        else if (limite <= inicio)
        {
            cout << "Error: El valor final no puede ser menor o igual al valor inicial." << endl;
            // Validar que el valor final no sea menor o igual al valor inicial
        }
        else
        {
            // mostrar la cantidads de correlativos entre los valores ingresados
            totalCorrelativos = limite - inicio;
            cout << "Cantidad de correlativos entre " << inicio << " y " << limite << ": " << totalCorrelativos << endl;

            if(totalCorrelativos > 100)
            {
            cout << "Error: La diferencia entre los valores ingresados no puede ser mayor a 100." << endl;
            // Validar que la diferencia entre los valores ingresados no sea mayor a 100
            }
        }

    } while (limite < 0 || limite > 100 || limite <= inicio|| totalCorrelativos > 100);
    // Validar que el valor final esté entre 0 y 100, que no sea menor al valor inicial y que la diferencia entre los valores ingresados no sea mayor a 100

    // ciclo para mostrar los correlativos entre los valores ingresados
    cout << "Correlativos entre " << inicio << " y " << limite << ":" << endl;
    for (int i = inicio; i <= limite; i++)
    {
        datos[i] = inicio++;     // Almacenar el valor en el arreglo
        cout << datos[i] << " "; // Mostrar el valor

        if (datos[i] % 2 == 0)
        {
            pares[par] = datos[i]; // Almacenar el valor par en el arreglo
            par++;                 // Incrementar el contador de valores pares
        }
        else
        {
            impares[impar] = datos[i]; // Almacenar el valor impar en el arreglo
            impar++;                   // Incrementar el contador de valores impares
        }
    }

    cout << endl;
    cout << "----------------------------------------" << endl;

    // Mostrar los valores pares
    cout << "\nValores pares " << ":" << endl;
    for (int i = 0; i < par; i++)
    {
        cout << pares[i] << " "; // Mostrar el valor par
    }

    cout << endl;
    cout << "----------------------------------------" << endl;
    // Mostrar los valores impares
    cout << "\nValores impares " << ":" << endl;
    for (int i = 0; i < impar; i++)
    {
        cout << impares[i] << " "; // Mostrar el valor impar
    }

    return 0;
}