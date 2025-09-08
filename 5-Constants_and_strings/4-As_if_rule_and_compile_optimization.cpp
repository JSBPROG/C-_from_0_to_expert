/*
    Optimización y la regla "as-if" en C++
    ======================================

    Introducción:
    -------------
    Optimizar un programa significa hacerlo más eficiente:
    - Que corra más rápido
    - Que consuma menos memoria
    - Que use mejor los recursos

    Hay dos tipos de optimización:
    - Manual (hecha por el programador → elige mejores algoritmos, estructuras de datos, paraleliza tareas, etc.)
    - Automática (hecha por el compilador → optimizaciones de bajo nivel como reordenar, eliminar o transformar código)

    Compiladores modernos (g++, clang, MSVC) son *compiladores optimizadores*:
    - Analizan el código y aplican transformaciones
    - El resultado debe ser más eficiente
    - Y, gracias a la "regla as-if", no puede cambiar el *comportamiento observable* del programa
*/

/*
    La regla "as-if":
    -----------------
    El compilador puede modificar el programa *como quiera*,
    siempre que no cambie el comportamiento observable:
    - Salida por consola
    - Lectura/escritura de archivos
    - Operaciones de red, etc.

    Ejemplo: cambiar "i = i * 2;" por "i <<= 1;".
    → El resultado es el mismo (doblar el valor de i), pero puede ser más rápido.

    Excepción: Elision de constructores (copy/move) → el compilador puede omitirlos
    aunque tengan efectos observables.
*/


#include <iostream>
#include <bitset>

/*
    Ejemplo 1: Constant folding
    ---------------------------
    El compilador puede evaluar expresiones *constantes* en tiempo de compilación.
*/
void ejemplo_constant_folding() {
    int x { 3 + 4 }; // Esto será optimizado a int x{7}
    std::cout << "Constant folding: " << x << '\n'; // imprime 7
}

/*
    Ejemplo 2: Constant propagation
    --------------------------------
    El compilador sustituye variables constantes por sus valores directamente.
*/
void ejemplo_constant_propagation() {
    int x { 7 };
    std::cout << "Constant propagation: " << x << '\n'; // optimizado a std::cout << 7;
}

/*
    Ejemplo 3: Dead code elimination
    --------------------------------
    El compilador elimina variables o instrucciones que no afectan el programa.
*/
void ejemplo_dead_code_elimination() {
    int x { 7 }; // x nunca se usa → puede ser eliminado
    std::cout << "Dead code elimination: " << 7 << '\n';
}

/*
    Ejemplo 4: Const ayuda a optimizar
    ----------------------------------
    Usar const garantiza al compilador que la variable no cambiará.
    Esto permite aplicar propagación y eliminar variables innecesarias.
*/
void ejemplo_const() {
    const int x { 7 };
    std::cout << "Const ayuda a optimizar: " << x << '\n';
}

/*
    Ejemplo 5: Compile-time vs Runtime constants
    --------------------------------------------
    - Compile-time constant → valor conocido en compilación
    - Runtime constant → valor conocido en ejecución
*/
int cinco() {
    return 5; // el valor se conoce solo en ejecución
}

int main() {
    std::cout << "=== Ejemplo de optimizaciones ===\n";

    ejemplo_constant_folding();
    ejemplo_constant_propagation();
    ejemplo_dead_code_elimination();
    ejemplo_const();

    // Constantes de tiempo de compilación
    const int a { 5 };   // compile-time constant
    const double b { 1.2 };
    const int c { a };   // también compile-time constant

    // Constantes de tiempo de ejecución
    int x { 10 };
    const int d { x };        // runtime constant (valor depende de x)
    const int e { cinco() };  // runtime constant (valor se calcula en ejecución)

    std::cout << "\n=== Constantes ===\n";
    std::cout << "Compile-time const: a=" << a << ", b=" << b << ", c=" << c << '\n';
    std::cout << "Runtime const: d=" << d << ", e=" << e << '\n';

    return 0;
}

/*
    Consejos y mejores prácticas:
    -----------------------------
    ✅ Usa "const" siempre que sea posible:
       - Le da información extra al compilador
       - Facilita optimizaciones (propagación, eliminación)

    ✅ Escribe código legible antes que microoptimizado:
       - El compilador hará optimizaciones de bajo nivel por ti
       - Tú céntrate en algoritmos y estructuras de datos eficientes

    ✅ Usa "constexpr" si el valor debe conocerse en tiempo de compilación
       - Más seguro y más optimizable

    ✅ No optimices prematuramente
       - Primero escribe un código correcto y claro
       - Luego mide el rendimiento con un profiler
       - Optimiza lo que realmente importa

    ✅ Recuerda: optimizaciones complican el debugging
       - En compilación Debug: desactiva optimizaciones (-O0)
       - En compilación Release: activa optimizaciones (-O2, -O3)

    ✅ La "regla as-if" es tu amiga:
       - Confía en el compilador
       - Tu tarea es escribir código limpio
       - El compilador ya se encargará de transformarlo en eficiente
*/
