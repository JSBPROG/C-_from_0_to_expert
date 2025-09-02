// ========================================================
// Enteros de ancho fijo y std::size_t
// ========================================================

//
// Este archivo explica los enteros en C++ y cómo usar
// enteros de ancho fijo y std::size_t correctamente.
// ========================================================

#include <iostream>
#include <cstdint> // Para enteros de ancho fijo
#include <cstddef> // Para std::size_t

int main() {

    // ====================================================
    // 1. Tamaño mínimo garantizado de los enteros
    // ====================================================
    /*
    - C++ garantiza un tamaño mínimo para los enteros, 
      pero pueden ser mayores según la arquitectura.
    - Ejemplo: int tiene un tamaño mínimo de 16 bits, 
      pero normalmente es de 32 bits en arquitecturas modernas.
    - Problema: si asumimos que int es 32 bits, puede fallar 
      en sistemas donde int sea solo 16 bits (overflow o comportamiento indefinido).
    */

    std::cout << "=== 1. Tamaño mínimo garantizado ===\n";

    int x {32767};        // Puede ser 16 o 32 bits
    x = x + 1;            // Overflow si int es 16 bits
    std::cout << "Valor de x: " << x << " (depende del tamaño de int)\n\n";

    // ====================================================
    // 2. Perspectiva sobre memoria y rango
    // ====================================================
    /*
    - Si asumimos int de 16 bits para ser seguros:
        - Rango seguro muy limitado
    - Si asumimos int de 32 bits:
        - Estamos desperdiciando memoria en sistemas donde solo necesitamos 16 bits
    - En la mayoría de casos, el desperdicio de 2 bytes no es crítico,
      pero si se crean millones de enteros, sí afecta memoria.
    */

    // ====================================================
    // 3. Enteros de ancho fijo (Fixed-width integers)
    // ====================================================
    /*
    - Introducidos en C++11 para garantizar el mismo tamaño
      en cualquier arquitectura.
    - Definidos en <cstdint>
    
    Tipos más comunes:

    std::int8_t    : 1 byte firmado, rango -128 a 127
    std::uint8_t   : 1 byte sin signo, rango 0 a 255
    std::int16_t   : 2 bytes firmado, rango -32,768 a 32,767
    std::uint16_t  : 2 bytes sin signo, rango 0 a 65,535
    std::int32_t   : 4 bytes firmado, rango -2,147,483,648 a 2,147,483,647
    std::uint32_t  : 4 bytes sin signo, rango 0 a 4,294,967,295
    std::int64_t   : 8 bytes firmado
    std::uint64_t  : 8 bytes sin signo
    */

    std::cout << "=== 3. Enteros de ancho fijo ===\n";

    std::int32_t y {32767}; // Siempre 32 bits
    y = y + 1;              // 32768 siempre cabe
    std::cout << "int32_t y: " << y << "\n";

    // ====================================================
    // 4. Advertencia sobre int8_t y uint8_t
    // ====================================================
    /*
    - int8_t y uint8_t suelen comportarse como char en la mayoría de sistemas
      y pueden no imprimirse como números.
    - Para imprimir correctamente, se puede forzar la conversión a int.
    */

    std::int8_t z {65};
    std::cout << "int8_t z (+z para imprimir como número): " << +z << "\n\n";

    // ====================================================
    // 5. Tipos fast y least (Opcional)
    // ====================================================
    /*
    - int_fast#_t / uint_fast#_t: el tipo más rápido con al menos # bits
    - int_least#_t / uint_least#_t: el tipo más pequeño con al menos # bits
    - No siempre recomendable usar: tamaño puede variar según arquitectura
    */

    std::cout << "=== 5. Tipos fast y least ===\n";
    std::cout << "int_least8_t: " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "int_least16_t: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "int_least32_t: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << "int_fast8_t: " << sizeof(std::int_fast8_t) * 8 << " bits\n";
    std::cout << "int_fast16_t: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
    std::cout << "int_fast32_t: " << sizeof(std::int_fast32_t) * 8 << " bits\n\n";

    // Ejemplo de comportamiento diferente:
    std::uint_fast16_t fastVar {0};
    fastVar = fastVar - 1; // Overflow
    std::cout << "std::uint_fast16_t después de underflow: " << fastVar << "\n\n";

    // ====================================================
    // 6. Qué es std::size_t
    // ====================================================
    /*
    - Tipo alias implementado como entero sin signo
    - Usado para tamaños de objetos o longitudes
    - Devuelto por sizeof
    - Garantizado al menos 16 bits
    - Usualmente coincide con el ancho de direcciones del sistema
    */

    int a {5};
    std::size_t s {sizeof(a)};
    std::cout << "sizeof(a) devuelve std::size_t: " << s << "\n";

    std::cout << "sizeof(std::size_t): " << sizeof(std::size_t) << " bytes\n\n";

    // ====================================================
    // 7. Mejores prácticas
    // ====================================================
    /*
    - Preferir int cuando no importa el tamaño
    - Preferir std::int#_t cuando se necesita rango garantizado
    - Preferir std::uint#_t para manipulación de bits o wrap-around definido
    - Evitar:
        * short y long (usar enteros de ancho fijo)
        * fast y least
        * enteros sin signo para cantidades
        * int8_t/uint8_t (usar 16 bits en su lugar)
        * enteros específicos de compilador
    */

    return 0;
}
