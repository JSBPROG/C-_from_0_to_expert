/*
    Constant expressions en C++
    ===========================

    Introducción:
    -------------
    - Una "expresión" es una combinación de literales, variables, operadores y llamadas a funciones.
    - Por defecto, las expresiones se evalúan en *tiempo de ejecución* (runtime).
    - Ejemplo:
        std::cin >> x;      // solo puede ejecutarse en runtime
        std::cout << 5;     // también en runtime (involucra salida por consola)

    - Sin embargo, en C++ existen expresiones que pueden (o deben) evaluarse en *tiempo de compilación*.
    - Estas se llaman **constant expressions**.
*/

/*
    Regla clave:
    ------------
    Una constant expression es una expresión en la que *cada parte* debe poder evaluarse en tiempo de compilación.

    Ejemplo:
        const double x { 1.2 };
        const double y { 3.4 };
        const double z { x + y }; // z puede evaluarse en compile-time
*/

/*
    ¿Por qué son útiles las constant expressions?
    ---------------------------------------------
    ✅ Performance: el cálculo se hace en compilación → programas más rápidos y pequeños.
    ✅ Versatilidad: se pueden usar donde *se requiere* un valor de compilación.
    ✅ Predictibilidad: si algo no es constante, el compilador da error.
    ✅ Calidad: errores se detectan antes, incluso se evita undefined behavior en compile-time.

    Características:
    ----------------
    - Un literal siempre es constant expression (ej: 5, 1.2, "Hola").
    - Operadores entre constantes también lo son (ej: 3+4, 2*sizeof(int)).
    - Variables `const` integrales inicializadas con constantes son aceptadas como constant expressions
      (herencia histórica de C++).
    - Pero hoy en día se prefiere usar `constexpr`.
*/


#include <iostream>
#include <array>

// Función normal → siempre runtime
int getNumber() {
    std::cout << "Introduce un número: ";
    int y{};
    std::cin >> y; // solo en ejecución
    return y;      // runtime
}

// Función no-constexpr aunque retorne constante
int five() {
    return 5; // constante, pero no constexpr → solo runtime
}

// Ejemplo de constexpr function
constexpr int doble(int x) {
    return x * 2; // puede evaluarse en compilación si x es constante
}

int main() {
    std::cout << "=== Ejemplos de constant expressions ===\n";

    // --- Literales son constant expressions ---
    5;           // ok
    1.2;         // ok
    "Hola!";     // ok

    // --- Operadores con constantes ---
    5 + 6;                 // constant expression
    1.2 * 3.4;             // constant expression
    8 - 5.6;               // constant expression
    sizeof(int) + 1;       // constant expression (sizeof se conoce en compilación)

    // --- Funciones normales → runtime ---
    getNumber();           // runtime
    five();                // runtime (aunque devuelve 5)

    // --- Expresiones con std::cout → runtime ---
    std::cout << 5 << '\n'; // runtime

    // --- Const integrales inicializadas con constantes ---
    const int a { 5 };        // usable en constant expressions
    const int b { a };        // ok, b es constante
    const long c { a + 2 };   // ok, sigue siendo constante

    // --- Casos NO constantes ---
    int d { 5 };              // no-const → runtime
    const int e { d };        // no es constante (depende de d)
    const double f { 1.2 };   // NO usable en constant expressions (no integral)

    // --- Uso de constexpr ---
    constexpr int x { 3 + 4 };    // compile-time obligatorio
    int y { 3 + 4 };              // puede evaluarse en runtime o compile-time (depende del compilador)

    std::cout << "\n=== Const vs Constexpr ===\n";
    std::cout << "Const int a: " << a << '\n';
    std::cout << "Constexpr int x: " << x << '\n';
    std::cout << "Int y (no const): " << y << '\n';

    // --- Ejemplo de constexpr function ---
    constexpr int v1 = doble(10);  // compile-time
    int v2 = doble(getNumber());   // runtime (depende de la entrada del usuario)

    std::cout << "\n=== Constexpr function ===\n";
    std::cout << "doble(10) en compile-time = " << v1 << '\n';
    std::cout << "doble(usuario) en runtime = " << v2 << '\n';

    // --- Uso obligatorio de constant expressions ---
    std::array<int, 5> arr1{};         // tamaño fijo en compile-time
    std::array<int, x> arr2{};         // ok, x es constexpr
    // std::array<int, y> arr3{};      // error → y no es constexpr

    return 0;
}

/*
    Consejos y mejores prácticas:
    -----------------------------
    ✅ Usa `constexpr` cuando un valor/función debe conocerse en tiempo de compilación.
    ✅ Usa `const` para variables inmutables, pero prefiere `constexpr` si debe ser constante en compile-time.
    ✅ Recuerda: no todo lo constante en runtime es constante en compile-time.
    ✅ Evita depender del as-if rule → mejor explícitamente marca lo que debe evaluarse en compilación.
    ✅ Usa `static_assert` para comprobar condiciones en compile-time.
    ✅ Ten en cuenta que constant expressions NO pueden incluir:
       - Variables no-const
       - Const no-integrales (ej: double)
       - Retornos de funciones no-constexpr
       - std::cin, std::cout ni operaciones de E/S
       - new, delete, throw, typeid, operador coma
*/
