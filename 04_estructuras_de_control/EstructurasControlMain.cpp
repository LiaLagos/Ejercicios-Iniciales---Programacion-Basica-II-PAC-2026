#include <iostream>

int main() {
    std::cout << "Estructuras de control en C++:\n";
    std::cout << "1. if / else / else if\n";
    std::cout << "2. switch\n";
    std::cout << "3. for\n";
    std::cout << "4. while\n";
    std::cout << "5. do-while\n";
    std::cout << "6. break / continue\n";
    std::cout << "7. operador ternario ?:\n\n";

    int numero = 2;

    //DECISION SIMPLE
    if (numero > 0) {
        std::cout << "if: el numero es positivo\n";
    } else if (numero < 0) {
        std::cout << "if: el numero es negativo\n";
    } else {
        std::cout << "if: el numero es cero\n";
    }


    //DECISION MULTIPLE
    switch (numero) {
        case 1:
            std::cout << "switch: es uno\n";
            break;
        case 2:
            std::cout << "switch: es dos\n";
            break;
        case 3:
            std::cout << "switch: es tres\n";
            break;
        default:
            std::cout << "switch: otro valor\n";
    }

    std::cout << "for: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "while: ";
    int j = 0;
    while (j < 3) {
        std::cout << j << " ";
        ++j;
    }
    std::cout << "\n";

    std::cout << "do-while: ";
    int k = 0;
    do {
        std::cout << k << " ";
        ++k;
    } while (k < 3);
    std::cout << "\n";

    std::cout << "break/continue en for: ";
    for (int m = 0; m < 5; ++m) {
        if (m == 2) continue;
        if (m == 4) break;
        std::cout << m << " ";
    }
    std::cout << "\n";

    int a = 5;
    int b = 10;
    int mayor = (a > b) ? a : b;
    std::cout << "operador ternario: mayor = " << mayor << "\n";

    return 0;
}
