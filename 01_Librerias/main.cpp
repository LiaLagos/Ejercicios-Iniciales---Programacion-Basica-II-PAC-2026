#include <iostream> // Librería para entrada y salida de datos
#include <math.h> // Librería para funciones matemáticas
#include <stdio.h> // Librería para funciones de entrada y salida estándar
#include <stdlib.h> // Librería para funciones de utilidad general
#include <string> // Librería para manipulación de cadenas de texto
 

using namespace std;

string nombreEstudiante;
string apellidoEstudiante;

int main() {
  
cout<<"Ingrese su nombre: "; // salida de texto   
cin>>nombreEstudiante; // entrada de valores
cout<<"Hola "<<nombreEstudiante<<"!"<<endl; // salida de valores

printf  ("Esta es la clase de programacion basica" ); // salida de valores con formato
//scanf  ("", & apellidoEstudiante); // entrada de valores con formato

cout<<" "<<endl; // salida de texto   
rand(); // función para generar un número aleatorio

system("pause"); // función para pausar la ejecución del programa


return 0;
}

