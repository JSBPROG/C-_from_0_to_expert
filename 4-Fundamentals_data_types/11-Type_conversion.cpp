// ------------------------------------------------------------
// 4.12 — Introduction to type conversion and static_cast
// ------------------------------------------------------------
//
// En este archivo veremos:
// 1. Conversión implícita de tipos
// 2. Conversión explícita con static_cast
// 3. Pérdida de información en conversiones
// 4. Conversión entre tipos signed y unsigned
// 5. Problemas comunes con std::int8_t y std::uint8_t
//
// Toda la teoría se explica en comentarios junto a ejemplos prácticos.
// ------------------------------------------------------------

#include <iostream>
#include <cstdint>  // para std::int8_t y std::uint8_t

// Función que recibe un double
void printDouble(double x) {
    std::cout << "printDouble: " << x << '\n';
}

// Función que recibe un int
void printInt(int x) {
    std::cout << "printInt: " << x << '\n';
}

int main() {
    // ------------------------------------------------------------
    // 1. Conversión implícita de tipos
    // ------------------------------------------------------------
    // Cuando pasamos un int a una función que espera un double,
    // el compilador convierte el valor automáticamente (int -> double).
    // Esto se llama "type conversion implícita".
    int y{5};
    printDouble(y); // y (int=5) se convierte a double=5.0

    // Ocurre lo mismo con literales:
    printDouble(5); // int literal 5 se convierte a double=5.0

    // ------------------------------------------------------------
    // 2. Conversión implícita con posible pérdida de datos
    // ------------------------------------------------------------
    // Si pasamos un double a una función que espera un int,
    // el compilador intentará convertirlo, PERO se perderá la parte fraccionaria.
    // El compilador suele dar una advertencia (warning).
    printInt(5.5); // double=5.5 -> int=5 (se pierde el .5)

    // ------------------------------------------------------------
    // 3. Conversión explícita con static_cast
    // ------------------------------------------------------------
    // static_cast<tipo>(expresión) permite convertir de forma explícita.
    // Esto le dice al compilador: "Sí, quiero convertir este valor".
    // El compilador NO dará warnings en este caso.
    printInt(static_cast<int>(5.5)); // conversión intencional

    // También se puede usar para cambiar cómo se interpreta un valor char.
    char ch{'a'}; // 'a' tiene código ASCII 97
    std::cout << "El carácter es: " << ch
              << " y su valor entero es: " << static_cast<int>(ch) << '\n';

    // ------------------------------------------------------------
    // 4. Conversión entre signed y unsigned
    // ------------------------------------------------------------
    unsigned int u1{5};
    int s1{static_cast<int>(u1)}; // unsigned -> signed (sin pérdida)
    std::cout << "unsigned 5 convertido a signed: " << s1 << '\n';

    int s2{-1};
    // signed -> unsigned puede causar "wrap-around" (cambio de rango)
    unsigned int u2{static_cast<unsigned int>(s2)};
    std::cout << "-1 convertido a unsigned: " << u2 << '\n';
    // En 32 bits, esto imprime 4294967295 (máximo valor de uint32_t)

    // ------------------------------------------------------------
    // 5. Problemas con std::int8_t y std::uint8_t
    // ------------------------------------------------------------
    // Aunque se llaman "int", la mayoría de compiladores los tratan como chars.
    std::int8_t myInt{65}; // 65 es 'A' en ASCII
    std::cout << "std::int8_t con valor 65 se imprime como: " << myInt << '\n';
    // Probablemente imprime 'A' en lugar de 65.

    // Solución: usar static_cast para imprimir como número.
    std::cout << "Interpretado como entero: " << static_cast<int>(myInt) << '\n';

    // Ejemplo con entrada de usuario
    std::cout << "Ingresa un número entre 0 y 127: ";
    std::int8_t userInput{};
    std::cin >> userInput;

    // Si ingresamos "35", se interpreta como '3' (ASCII=51)
    std::cout << "El valor almacenado es: " << static_cast<int>(userInput) << '\n';

    // ------------------------------------------------------------
    // CONCLUSIONES Y BEST PRACTICES
    // ------------------------------------------------------------
    // - Usa conversiones implícitas cuando sean seguras (int -> double).
    // - Evita conversiones implícitas con pérdida (double -> int).
    // - Usa static_cast cuando quieras ser explícito y evitar warnings.
    // - Ten cuidado al convertir entre signed y unsigned (puede haber wrap).
    // - std::int8_t y std::uint8_t suelen comportarse como chars:
    //   usa static_cast<int> si quieres verlos como números.
    //
    // Best practice: Siempre que haya una posible pérdida de información,
    // utiliza static_cast para dejar claro que la conversión es intencional.
    // ------------------------------------------------------------

    return 0;
}
