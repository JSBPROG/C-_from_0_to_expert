#include <iostream>
#include <limits>
#include "functions.h"

int main() {
    int age{};
    std::cout << "Introduce tu edad: ";

    // Control de errores de entrada
    while (!(std::cin >> age)) {
        std::cin.clear(); // limpiar el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar entrada inválida
        std::cout << "Entrada inválida. Introduce un número entero: ";
    }

    Functions func;
    std::cout << func.esAdult(age) << std::endl;

    return 0;
}
