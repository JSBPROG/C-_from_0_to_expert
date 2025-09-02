// ============================================================================
// Unsigned integers en C++
// ============================================================================
//
// Un "unsigned integer" (entero sin signo) es un número entero que puede
// representar únicamente valores NO NEGATIVOS (>= 0).
//
// Ejemplo de definición:
//    unsigned int ui;
//    unsigned short us;
//    unsigned long ul;
//    unsigned long long ull;
//
// La palabra clave "unsigned" se antepone al tipo.
//
// ---------------------------------------------------------------------------
// DIFERENCIA ENTRE SIGNED Y UNSIGNED
// ---------------------------------------------------------------------------
// - signed int  -> puede contener números positivos y negativos.
// - unsigned int -> solo números positivos (incluyendo 0).
//
// Ejemplo (1 byte = 8 bits):
//   signed char    -> rango: -128 a 127
//   unsigned char  -> rango: 0 a 255
//
// Ambos almacenan 256 valores distintos, pero el rango se distribuye distinto. 
// ============================================================================

#include <iostream>
using namespace std;

int main() {
    cout << "=== Ejemplo 1: Rango de unsigned ===\n";
    unsigned short x{65535}; // valor máximo que cabe en 16 bits
    cout << "x fue: " << x << '\n';

    x = 65536; // fuera de rango -> wrap-around (mod 2^16)
    cout << "x ahora es: " << x << '\n'; // se convierte en 0

    x = 65537; // otro wrap-around
    cout << "x ahora es: " << x << '\n'; // se convierte en 1

    // ------------------------------------------------------------------------
    cout << "\n=== Ejemplo 2: Wrap-around hacia abajo ===\n";
    unsigned short y{0}; // mínimo en unsigned
    cout << "y fue: " << y << '\n';

    y = -1; // wrap-around hacia el máximo (65535)
    cout << "y ahora es: " << y << '\n';

    y = -2; // wrap-around a 65534
    cout << "y ahora es: " << y << '\n';

    // ------------------------------------------------------------------------
    cout << "\n=== Ejemplo 3: Problema al restar unsigned ===\n";
    unsigned int a{2};
    unsigned int b{3};
    cout << "2 - 3 con unsigned da: " << a - b << '\n';
    // Esperaríamos -1, pero como unsigned no soporta negativos,
    // el resultado es un wrap-around enorme (4294967295 en 32 bits).

    // ------------------------------------------------------------------------
    cout << "\n=== Ejemplo 4: Mezcla de signed y unsigned ===\n";
    unsigned int u{2};
    signed int s{3};
    cout << "2 - 3 con mezcla signed/unsigned da: " << u - s << '\n';
    // "s" se convierte implícitamente a unsigned -> -1 se vuelve 4294967295.
    // Resultado inesperado.

    // ------------------------------------------------------------------------
    cout << "\n=== Ejemplo 5: Comparaciones peligrosas ===\n";
    signed int s2{-1};
    unsigned int u2{1};

    if (s2 < u2) {
        cout << "-1 es menor que 1\n";
    } else {
        cout << "1 es menor que -1 (resultado incorrecto!)\n";
    }

    // ------------------------------------------------------------------------
    cout << "\n=== Ejemplo 6: Funciones con unsigned ===\n";
    auto doSomething = [](unsigned int times) {
        cout << "Ejecutando doSomething() con x = " << times << '\n';
    };

    doSomething(-1); 
    // ERROR LÓGICO: -1 se convierte en 4294967295 (wrap-around).
    // Esto puede causar que el programa "se vuelva loco".


    /*
     la palabra clave auto le indica al compilador que deduzca automáticamente el tipo de la variable a partir de la expresión con la que se inicializa. 
     Esto evita que tengas que escribir el tipo completo, especialmente cuando es largo o complicado, como en funciones lambda o iteradores.
    [](...) { ... } es una lambda, es decir, una función anónima definida en el lugar.

    El compilador deduce automáticamente que doSomething es de tipo lambda con la firma void(unsigned int).

    Gracias a auto, no hay que escribir algo como:

    std::function<void(unsigned int)> doSomething = [](unsigned int times) { ... };

    
    */

    // ------------------------------------------------------------------------
    cout << "\n=== Best practices ===\n";
    cout << "1. Usa signed int para cantidades generales (incluso si no son negativas).\n";
    cout << "2. Evita mezclar signed y unsigned en operaciones.\n";
    cout << "3. Usa unsigned solo cuando:\n";
    cout << "   - Trabajes con manipulación de bits.\n";
    cout << "   - Necesites comportamiento de wrap-around (ej: algoritmos de cifrado).\n";
    cout << "   - Estés en sistemas embebidos donde unsigned sea requerido.\n";
    cout << "4. Cuidado con bucles que decrecen valores unsigned (pueden quedarse infinitos).\n";

    return 0;
}
