#include <iostream>
#include "Three_numbers.h"

int main() {
    int num1{}, num2{}, num3{};

    std::cout << "Escribe tres números: ";
    std::cin >> num1 >> num2 >> num3;

    ThreeNumbers numbers(num1, num2, num3);

    // La presentación se maneja aquí, no en la clase, esto nos permite sepaarar la lógica de la presentación.
    std::cout << "El mayor es: " << numbers.findLargest() << std::endl;

    return 0;
}
