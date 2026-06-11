#include <iostream>
#include <string>


int main() {
    int entero = 5;
    float flotante = 3.14f;
    double doble = 2.71828;
    char caracter = 'M';
    bool booleano = false;
    long enteroLargo = 1234567890L;
    short enteroCorto = 100;
    unsigned int sinSigno = 20u;
    wchar_t caracterAncho = L'Ñ';
   // string nombreEstudiante;


    std::cout << "Tipos de variables en C++ con un ejemplo:\n";
    std::cout << "int: " << entero << "\n";
    std::cout << "float: " << flotante << "\n";
    std::cout << "double: " << doble << "\n";
    std::cout << "char: " << caracter << "\n";
    std::cout << "bool: " << std::boolalpha << booleano << "\n";
    std::cout << "long: " << enteroLargo << "\n";
    std::cout << "short: " << enteroCorto << "\n";
    std::cout << "unsigned: " << sinSigno << "\n";
    std::cout << "wchar_t: " << static_cast<char>(caracterAncho) << "\n";
    return 0;
}
