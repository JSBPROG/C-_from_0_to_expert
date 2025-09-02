/*
==================================================================
    TUTORIAL: Enteros con signo (signed integers) en C++
==================================================================

1. ¿QUÉ ES UN ENTERO?
---------------------
- Un entero es un número entero (positivo, negativo o cero).
- Ejemplos: -2, -1, 0, 1, 2
- C++ provee 4 tipos fundamentales de enteros con signo:

    Tipo            Tamaño mínimo
    ---------------------------------
    short           16 bits
    int             16 bits (típicamente 32 en arquitecturas modernas)
    long            32 bits
    long long       64 bits

*Nota*: C++ garantiza **tamaños mínimos**, no exactos. Usa `sizeof` para comprobar
el tamaño en tu compilador y arquitectura.

==================================================================

2. DEFINICIÓN DE ENTEROS CON SIGNO
----------------------------------
El modificador `signed` es opcional, porque los enteros son con signo por defecto.

    short s;      // preferido
    int i;        // preferido
    long l;       // preferido
    long long ll; // preferido

También se puede escribir redundante:
    signed int si;        // válido, pero innecesario
    signed long long sll; // válido, pero innecesario

*BUENA PRÁCTICA*: Usa los nombres cortos sin `int` extra ni `signed`.

==================================================================

3. EL RANGO DE LOS ENTEROS CON SIGNO
------------------------------------
- La cantidad de valores que un entero puede almacenar depende de su tamaño en bits.
- Fórmula para n bits: rango = -(2^(n-1)) a (2^(n-1) - 1)

Ejemplos:
    8 bits  -> -128 a 127
    16 bits -> -32,768 a 32,767
    32 bits -> -2,147,483,648 a 2,147,483,647
    64 bits -> -9,223,372,036,854,775,808 a 9,223,372,036,854,775,807

- Hoy en día, todas las arquitecturas modernas usan **complemento a dos (two's complement)**,
  lo cual es requerido por C++20.

==================================================================

4. OVERFLOW
-----------
- Si intentas guardar un valor fuera del rango representable, ocurre overflow.
- En C++ esto es **comportamiento indefinido** para enteros con signo.

Ejemplo:
    int x { 2'147'483'647 }; // máximo valor de int (32 bits típicos)
    x = x + 1;               // overflow → comportamiento indefinido

En muchas máquinas esto se ve como un "ciclo" (pasa a negativo),
pero no es confiable.

*BUENA PRÁCTICA*: Si sospechas que un valor puede superar el rango,
usa un tipo más grande (ej: long long).

==================================================================

5. DIVISIÓN ENTERA
------------------
- Cuando divides dos enteros, el resultado siempre es un entero.
- La parte fraccionaria se **trunca** (no se redondea).

Ejemplo:
    20 / 4  → 5
    8 / 5   → 1  (0.6 se descarta)
    -8 / 5  → -1

*ADVERTENCIA*: Ten cuidado, perderás decimales. Si quieres decimales,
usa tipos de punto flotante (ej: double).

==================================================================
*/

#include <iostream>
#include <climits> // Para límites de tipos (INT_MAX, etc.)

using namespace std;

int main() {
    cout << "=== DEMOSTRACION DE ENTEROS CON SIGNO ===\n\n";

    // Tamaños reales de los tipos en esta máquina
    cout << "sizeof(short):      " << sizeof(short)      << " bytes\n";
    cout << "sizeof(int):        " << sizeof(int)        << " bytes\n";
    cout << "sizeof(long):       " << sizeof(long)       << " bytes\n";
    cout << "sizeof(long long):  " << sizeof(long long)  << " bytes\n";

    cout << "\n=== RANGOS MAXIMOS Y MINIMOS ===\n";
    cout << "INT_MIN:  " << INT_MIN  << "\n";
    cout << "INT_MAX:  " << INT_MAX  << "\n";
    cout << "LLONG_MIN:" << LLONG_MIN << "\n";
    cout << "LLONG_MAX:" << LLONG_MAX << "\n";

    cout << "\n=== DEMOSTRACION DE OVERFLOW ===\n";
    int x { INT_MAX }; // valor máximo del int en esta máquina
    cout << "Valor inicial (INT_MAX): " << x << "\n";
    x = x + 1; // overflow → comportamiento indefinido
    cout << "Tras sumar 1 → (resultado indefinido): " << x << "\n";

    cout << "\n=== DIVISION ENTERA ===\n";
    cout << "20 / 4 = " << 20 / 4 << "\n";  // resultado exacto
    cout << "8 / 5  = " << 8 / 5  << "\n";  // parte decimal truncada
    cout << "-8 / 5 = " << -8 / 5 << "\n";  // negativo truncado hacia 0

    cout << "\n=== BUENAS PRACTICAS ===\n";
    cout << "- Prefiere usar short, int, long, long long sin 'int' redundante.\n";
    cout << "- Evita el prefijo 'signed', ya que los enteros son signed por defecto.\n";
    cout << "- Verifica tamaños con sizeof en lugar de asumir.\n";
    cout << "- Usa tipos más grandes si existe riesgo de overflow.\n";
    cout << "- Ten cuidado con la division entera (se trunca el resultado).\n";

    cout << "\n=== FIN DEL TUTORIAL ===\n";
    return 0;
}
