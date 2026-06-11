#include <iostream>

using namespace std;

int acumuladorGeneral = 0;
int acumulador;

int main()
{

    for (int i = 1; i < 5; i++)
    {

        cout << "Ingrese un valor, intento " << (i) << endl;
        cin >> acumulador;

        acumuladorGeneral = acumuladorGeneral + acumulador;

        cout << "Cantidad: " << acumuladorGeneral << endl;
    }
    return 0;
}

// contador i++ es equivalente a i = i + 1 o i += 1, lo que significa que el valor de i se incrementa en 1 en cada iteración del ciclo. El ciclo for se ejecutará mientras la condición i < 10 sea verdadera, lo que significa que el ciclo se ejecutará 10 veces, con i tomando los valores de 0 a 9.
// acumulador es una variable que se utiliza para almacenar un valor que se va actualizando a lo largo de las iteraciones de un ciclo. En este caso, el acumulador se incrementa en 1 en cada iteración del ciclo, lo que significa que al final del ciclo, el valor del acumulador será igual al número de iteraciones realizadas. Por ejemplo, si el ciclo se ejecuta 10 veces, el valor del acumulador será 10 al final del ciclo.