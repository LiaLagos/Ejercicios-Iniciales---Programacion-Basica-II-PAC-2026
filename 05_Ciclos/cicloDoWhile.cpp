#include <iostream>

using namespace std;

//REALIZAR UN PROGRAMA QUE MUESTRE LOS VALORES DEL 0 AL 10

int main()
{
    int contador = 0;

    do
    {
        cout << "Contador: " << contador << endl;
        contador = contador + 2; // Incrementamos el contador en 2
    } while (contador <= 10);

    return 0;
}