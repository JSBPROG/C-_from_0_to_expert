/*
    Constexpr Variables y Funciones en C++
    ======================================

    Introducción:
    -------------
    - `const` declara un valor inmutable después de la inicialización.
    - `constexpr` garantiza que un valor o función pueda evaluarse en tiempo de compilación.
    - Las variables `constexpr` deben inicializarse con una constant expression.
    - Las funciones `constexpr` pueden llamarse en contextos de compile-time.

    Diferencias clave:
    -----------------
    const:
        - El valor no cambia tras inicialización.
        - Puede evaluarse en runtime o compile-time.
    constexpr:
        - Valor siempre usable en constant expressions.
        - Debe inicializarse con una constant expression.
        - Implícitamente const.
*/

// Librerías
#include <iostream>
#include <array>

// Función normal -> return runtime
int five() {
    return 5;
}

// Función constexpr -> evaluable en compile-time si argumentos son constant expressions
constexpr int cmax(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    std::cout << "=== Const vs Constexpr ===\n";

    // --- Variables ---
    int a { 5 };                 // runtime constant
    const int b { a };            // const, pero depende de a → runtime
    const int c { 5 };            // const integral con initializer constante → usable en constant expression
    constexpr int d { 5 };        // constexpr → compile-time
    constexpr double e { 1.2 };   // constexpr no integral → compile-time

    std::cout << "Const c: " << c << ", Constexpr d: " << d << ", Constexpr double e: " << e << "\n";

    // --- Errores de inicialización ---
    int age{};
    std::cout << "Introduce tu edad: ";
    std::cin >> age;
    // constexpr int myAge { age }; // ERROR: age no es constant expression
    // constexpr int f { five() };   // ERROR: five() no es constexpr

    // --- Constexpr y arrays ---
    const int arrLen = 5;          // const integral con initializer constante → compile-time
    int arr[arrLen];                // válido
    constexpr int arrLen2 = 10;
    int arr2[arrLen2];              // válido

    // --- Funciones constexpr ---
    int m1 { cmax(5, 6) };          // runtime o compile-time
    const int m2 { cmax(5, 6) };    // runtime o compile-time
    constexpr int m3 { cmax(5, 6) }; // compile-time obligatorio

    std::cout << "m1: " << m1 << ", m2: " << m2 << ", m3: " << m3 << "\n";

    // --- Constexpr vs const en inicialización ---
    const int x = 4 + 5;           // runtime constant
    constexpr int y = 4 + 5;       // compile-time constant

    std::cout << "x (const): " << x << ", y (constexpr): " << y << "\n";

    // --- Consejos de buenas prácticas ---
    /*
        ✅ Usa constexpr siempre que necesites un valor que deba ser evaluable en compile-time.
        ✅ Usa const para constantes runtime.
        ✅ Constexpr puede aplicarse a tipos no integrales (double, arrays, etc.).
        ✅ Constexpr variables son implícitamente const.
        ✅ No puedes inicializar constexpr con:
            - Variables runtime
            - Retornos de funciones no-constexpr
            - std::cin/std::cout
    */

    return 0;
}
