/*
==================================================================
    TUTORIAL: Tamaño de objetos y el operador sizeof en C++
==================================================================

1. ORGANIZACIÓN DE LA MEMORIA
-----------------------------
- La memoria de un programa se organiza en bytes (1 byte = 8 bits).
- Cada dirección de memoria puede almacenar 1 byte.
- Un objeto en C++ ocupa uno o más bytes según su tipo.
  Ejemplo:
    char        -> 1 byte
    int         -> 4 bytes (en muchas arquitecturas modernas)
    double      -> 8 bytes

- Cuando usamos variables, el compilador ya sabe cuántos bytes debe reservar
  según el tipo de la variable.

==================================================================

2. ¿POR QUÉ IMPORTA EL TAMAÑO DE UN OBJETO?
--------------------------------------------
A) Capacidad de almacenamiento
   - La cantidad de valores posibles depende del número de bits.
   - Fórmula: con n bits → 2^n valores posibles.
   Ejemplos:
     1 bit   -> 2 valores (0 o 1)
     8 bits  -> 256 valores
     16 bits -> 65,536 valores

B) Uso de memoria
   - Cada objeto ocupa espacio en la RAM.
   - En programas pequeños, la diferencia no importa.
   - En programas grandes (ej. videojuegos con millones de objetos),
     sí puede ser crítico.

* CONSEJO: No optimices memoria de forma prematura. 
  Es mejor escribir código claro y optimizar solo cuando sea necesario.

==================================================================

3. TAMAÑOS MÍNIMOS GARANTIZADOS POR C++
---------------------------------------
El estándar de C++ define tamaños mínimos pero no exactos:

    Tipo          Mínimo       Típico (x64)
    ----------------------------------------
    bool          1 byte       1 byte
    char          1 byte       1 byte
    short         2 bytes      2 bytes
    int           2 bytes      4 bytes
    long          4 bytes      4 u 8 bytes
    long long     8 bytes      8 bytes
    float         4 bytes      4 bytes
    double        8 bytes      8 bytes
    long double   8 bytes      8, 12 o 16 bytes
    nullptr_t     4 bytes      4 u 8 bytes

*IMPORTANTE*: No asumas que un tipo tendrá siempre el mismo tamaño en
todas las arquitecturas. Usa `sizeof` para saberlo.

==================================================================

4. EL OPERADOR sizeof
---------------------
- Devuelve el tamaño en bytes de un objeto o tipo.
- Se puede aplicar a:
  A) Un tipo: sizeof(int)
  B) Una variable: sizeof(x)

Ejemplo rápido:
    int x{};
    cout << sizeof(int); // tamaño del tipo int
    cout << sizeof(x);   // tamaño de la variable x

*Nota*: sizeof(void) es un error (void es un tipo incompleto).
En GCC, con extensiones habilitadas, puede devolver 1.

==================================================================

5. STATIC_ASSERT PARA PORTABILIDAD
----------------------------------
Si tu programa requiere que un tipo tenga un tamaño mínimo,
usa static_assert para evitar compilaciones en arquitecturas no compatibles.

Ejemplo:
    static_assert(sizeof(int) >= 4, "El int debe tener al menos 4 bytes");

==================================================================

6. RENDIMIENTO
--------------
- Los tipos fundamentales son muy rápidos en procesadores modernos.
- Usar un tipo más pequeño no siempre significa mejor rendimiento.
- Muchas CPUs están optimizadas para enteros de 32 bits,
  lo que hace que un `int` (32 bits) pueda ser más rápido que un `short` (16 bits).

==================================================================

7. EJEMPLO PRÁCTICO: sizeof en acción
-------------------------------------
Este programa imprime los tamaños reales de los tipos fundamentales
en tu compilador y arquitectura.
==================================================================
*/

#include <iostream>
#include <iomanip>   // std::setw para alinear la salida
#include <climits>   // CHAR_BIT para número de bits en un byte

using namespace std;

int main() {
    cout << "=== DEMOSTRACION DEL OPERADOR sizeof ===\n\n";

    // Mostrar cuántos bits tiene un byte en esta arquitectura
    cout << "Un byte tiene " << CHAR_BIT << " bits\n\n";

    // Alinear salida a la izquierda
    cout << left;

    // Mostrar tamaños de tipos fundamentales
    cout << setw(16) << "bool:"        << sizeof(bool)        << " bytes\n";
    cout << setw(16) << "char:"        << sizeof(char)        << " bytes\n";
    cout << setw(16) << "short:"       << sizeof(short)       << " bytes\n";
    cout << setw(16) << "int:"         << sizeof(int)         << " bytes\n";
    cout << setw(16) << "long:"        << sizeof(long)        << " bytes\n";
    cout << setw(16) << "long long:"   << sizeof(long long)   << " bytes\n";
    cout << setw(16) << "float:"       << sizeof(float)       << " bytes\n";
    cout << setw(16) << "double:"      << sizeof(double)      << " bytes\n";
    cout << setw(16) << "long double:" << sizeof(long double) << " bytes\n";
    cout << setw(16) << "nullptr_t:"   << sizeof(nullptr_t)   << " bytes\n";

    cout << "\n=== sizeof aplicado a variables ===\n";
    int x{};
    double y{};
    cout << "sizeof(x): " << sizeof(x) << " bytes (int)\n";
    cout << "sizeof(y): " << sizeof(y) << " bytes (double)\n";

    // Ejemplo de portabilidad con static_assert
    static_assert(sizeof(int) >= 4, "El int debe tener al menos 4 bytes");

    cout << "\n=== EJEMPLO DE BUENAS PRACTICAS ===\n";
    cout << "- Usa sizeof para verificar tamaños antes de asumir.\n";
    cout << "- Usa static_assert para asegurar portabilidad.\n";
    cout << "- No optimices memoria prematuramente, enfócate en claridad.\n";
    cout << "- Usa tipos fijos de <cstdint> (ej. int32_t, uint64_t) si necesitas\n";
    cout << "  un tamaño garantizado.\n";

    cout << "\n=== FIN DEL TUTORIAL ===\n";
    return 0;
}
