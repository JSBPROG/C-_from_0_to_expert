#include <iostream>

// Una función simple que devuelve 5
int five()
{
    return 5;
}

int main()
{
    std::cout << "=== INTRODUCCION A EXPRESIONES EN C++ ===\n\n";

    // ==============================
    // INICIALIZACIONES CON EXPRESIONES
    // ==============================

    int a{ 2 };             // expresión literal -> 2
    int b{ 2 + 3 };         // expresión con operador -> evalúa a 5
    int c{ (2 * 3) + 4 };   // expresión compuesta -> evalúa a 10
    int d{ b };             // expresión con variable -> evalúa al valor de b (5)
    int e{ five() };        // expresión con llamada a función -> evalúa al return (5)

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "c = " << c << '\n';
    std::cout << "d = " << d << '\n';
    std::cout << "e = " << e << "\n\n";

    // ==============================
    // EJEMPLOS DE EVALUACION DE EXPRESIONES
    // ==============================

    // Literal -> se evalúa a sí mismo
    std::cout << "Literal 2 se evalúa a: " << 2 << '\n';

    // Variable -> se evalúa al valor que contiene
    std::cout << "Variable b se evalúa a: " << b << '\n';

    // Operadores -> combinan operandos y generan un nuevo valor
    std::cout << "2 + 3 se evalúa a: " << 2 + 3 << '\n';

    // Función -> se evalúa a lo que devuelve
    std::cout << "five() se evalúa a: " << five() << "\n\n";

    // ==============================
    // EXPRESIONES CON EFECTOS SECUNDARIOS
    // ==============================

    int x{};

    // Operador de asignación (=) tiene efecto secundario:
    // asigna valor a la variable, y también devuelve la variable
    std::cout << "(x = 5) devuelve: " << (x = 5) << '\n';
    std::cout << "Ahora x vale: " << x << '\n';

    // Operador de inserción (<<) imprime en consola y devuelve std::cout
    std::cout << "Efecto secundario: imprime en consola\n";
    (std::cout << "Hola mundo con operador <<\n") << '\n';

    // ==============================
    // EXPRESSION STATEMENTS
    // ==============================
    x = 2 + 3; // Expresión (2 + 3) dentro de un statement (termina en ;)
    std::cout << "x = " << x << "\n\n";

    // Useless expression statement: compila pero no hace nada
    (2 * 3); // se evalúa a 6 y luego se descarta

    // ==============================
    // SUBEXPRESIONES, FULL EXPRESSIONS Y COMPOUND EXPRESSIONS
    // ==============================
    std::cout << "=== SUBEXPRESIONES Y COMPOUND EXPRESSIONS ===\n";

    std::cout << "Ejemplo: 2 -> full expression (literal)\n";
    std::cout << "Ejemplo: 2 + 3 -> full expression con subexpresiones 2 y 3\n";
    std::cout << "Ejemplo: x = 4 + 5 -> compound expression:\n";
    std::cout << "    subexpresiones: x y (4 + 5)\n";
    std::cout << "    subexpresiones de (4 + 5): 4 y 5\n";

    x = 4 + 5; // compound expression: usa operador+ y operador=
    std::cout << "Resultado de x = 4 + 5: " << x << '\n';

    return 0;
}
