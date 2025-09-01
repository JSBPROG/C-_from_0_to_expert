#include <iostream> // Biblioteca necesaria para usar std::cout y std::cin

int main()
{
    // ==============================
    //  LITERALES
    // ==============================
    std::cout << "Ejemplo de Literales y Variables\n\n";

    // Literal de tipo cadena (string literal)
    std::cout << "Hola mundo!" << '\n'; // "Hola mundo!" es un literal de tipo cadena

    // Literal entero
    std::cout << 5 << '\n'; // 5 es un literal entero

    // Variable inicializada con un literal
    int x { 5 };  // x es una variable que contiene el literal 5
    std::cout << x << '\n'; // Imprime el valor de la variable (que también es 5)

    // Diferencia clave:
    // - El literal 5 está directamente incrustado en el código compilado.
    // - La variable x guarda una copia de ese valor en memoria.

    // ==============================
    //  OPERADORES
    // ==============================
    std::cout << "\nEjemplo de Operadores\n\n";

    // Operador de suma (+) con dos literales
    std::cout << 1 + 2 << '\n'; // Imprime 3 (suma de 1 y 2)

    // Operadores aritméticos básicos
    std::cout << "3 + 4 = " << 3 + 4 << '\n'; // operador+ (suma)
    std::cout << "10 - 6 = " << 10 - 6 << '\n'; // operador- (resta)
    std::cout << "7 * 2 = " << 7 * 2 << '\n'; // operador* (multiplicación)
    std::cout << "20 / 4 = " << 20 / 4 << '\n'; // operador/ (división)

    // Operador de asignación (=) con su efecto secundario
    int y {};    // Inicializamos y en 0
    y = 10;      // Asignamos el valor 10 a y
    std::cout << "El valor de y es: " << y << '\n'; // Imprime 10

    // Demostración de encadenamiento con operador=
    int a{}, b{};
    a = b = 5; // Primero b = 5, devuelve b, luego a = (b)
    std::cout << "a = " << a << ", b = " << b << '\n';

    // Demostración de encadenamiento con operador<<
    std::cout << "Hola " << "mundo!" << '\n';

    // ==============================
    //  OPERADORES UNARIOS Y BINARIOS
    // ==============================
    int n { 5 };

    // Operador unario (-)
    std::cout << "El opuesto de 5 es: " << -n << '\n'; // -5

    // Operador binario (-)
    std::cout << "7 - 3 = " << 7 - 3 << '\n'; // 4

    // ==============================
    //  CADENA DE OPERADORES
    // ==============================
    std::cout << "\nEjemplo de cadena de operadores:\n";
    std::cout << "2 * 3 + 4 = " << 2 * 3 + 4 << '\n';
    // Primero 2 * 3 = 6, luego 6 + 4 = 10 (respeta el orden PEMDAS)

    return 0; // Fin del programa
}
