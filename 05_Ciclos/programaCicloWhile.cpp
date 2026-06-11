#include <iostream>

using namespace std;

/*REALIZAR UN PROGRAMA que solicite un valor inicial y un valor final, y muestre los valores entre
ellos utilizando un ciclo while
5 , 10
5, 6, 7, 8, 9, 10

10, 5
10, 9, 8, 7, 6, 5
*/

int main()
{
    int inicial, final;

    cout << "Ingrese el valor inicial: ";
    cin >> inicial;
    cout << "Ingrese el valor final: ";
    cin >> final;

    // validar que sean datos diferentes
    while (inicial == final)
    {
        cout << "Error: El valor inicial y el valor final deben ser diferentes" << endl;
        cout << "Ingrese el valor inicial: ";
        cin >> inicial;
        cout << "Ingrese el valor final: ";
        cin >> final;
    }

    // Validar que tenga por lo menos una diferencia de 1 entre el valor inicial y el valor final
    int diferencia = 0;

    if (inicial < final)
    {
        diferencia = final - inicial;

        //  cout << "No se puede mostrar la secuencia cuando el valor es: " << diferencia << endl;
    }
    else
    {
        diferencia = inicial - final;
        cout << "La diferencia entre el valor inicial y el valor final es: " << diferencia << endl;
    }

    // validar que la diferencia sea mayor  a 1

    if (diferencia > 2)
    {

        // Datos ascendentes
        if (inicial < final)
        {
            while (inicial < final)
            {

                inicial = inicial + 1; // Incrementamos el valor inicial en 1 para mostrar el siguiente valor

                cout << inicial << " ";
            }
        }
    }
    else
    {

        while (inicial >= final)
        {
            cout << inicial << " ";
            inicial = inicial - 1; // Decrementamos el valor inicial en 1 para mostrar el siguiente valor
        }
    }

    return 0;
}