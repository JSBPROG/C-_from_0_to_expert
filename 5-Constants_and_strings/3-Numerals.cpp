/*
    Sistemas numéricos en C++
    ==========================

    En matemáticas y programación, un "sistema numérico" es una forma de representar
    cantidades usando un conjunto de símbolos y una base.

    Los principales sistemas que usamos en programación son:

    1) Decimal (base 10)
       - Es el que usamos en la vida cotidiana.
       - Dígitos válidos: 0,1,2,3,4,5,6,7,8,9
       - Ejemplo: 1234 significa (1*1000 + 2*100 + 3*10 + 4)

    2) Binario (base 2)
       - Usado internamente por las computadoras (todo es 0s y 1s).
       - Dígitos válidos: 0,1
       - Ejemplo: 1010 (binario) = 1*8 + 0*4 + 1*2 + 0*1 = 10 (decimal)
       - En C++ se escribe con prefijo 0b → 0b1010

    3) Octal (base 8)
       - Dígitos válidos: 0–7
       - Ejemplo: 012 (octal) = 1*8 + 2*1 = 10 (decimal)
       - En C++ se escribe con prefijo 0 (cero inicial) → 012
       - Hoy casi no se usa, pero históricamente era popular en Unix.

    4) Hexadecimal (base 16)
       - Muy usado en programación, sobre todo en direcciones de memoria,
         gráficos, colores y depuración.
       - Dígitos válidos: 0–9 y A–F (A=10, B=11, ..., F=15)
       - Ejemplo: 0xF = 15 decimal
       - Ejemplo: 0x10 = 16 decimal
       - En C++ se escribe con prefijo 0x → 0x1A, 0xFF

    --------------------------------------------------------
    Funcionalidades que vamos a ver en este archivo:
    - Literales decimales, binarios, octales y hexadecimales
    - Separadores de dígitos (C++14+)
    - Conversión y salida en diferentes bases (std::dec, std::hex, std::oct)
    - Impresión en binario con std::bitset
    - Impresión en binario con std::format / std::print (C++20/23)
*/

#include <iostream>
#include <bitset>   // Para imprimir binarios
#if __cplusplus >= 202002L
#include <format>   // C++20
#endif
#if __cplusplus >= 202302L
#include <print>    // C++23
#endif

int main() {
    // -------- DECIMAL --------
    int decimal = 12; // Por defecto los números son decimales
    std::cout << "Decimal: " << decimal << '\n';

    // -------- OCTAL --------
    int octal = 012; // Prefijo 0 indica octal
    std::cout << "Octal (012 en decimal): " << octal << '\n'; // imprime 10

    // -------- HEXADECIMAL --------
    int hexadecimal = 0xF; // Prefijo 0x indica hexadecimal
    std::cout << "Hexadecimal (0xF en decimal): " << hexadecimal << '\n'; // imprime 15

    // -------- BINARIO (C++14+) --------
    int binario = 0b1010; // Prefijo 0b indica binario
    std::cout << "Binario (0b1010 en decimal): " << binario << '\n'; // imprime 10

    // -------- SEPARADORES DE DIGITOS (C++14+) --------
    // Permiten escribir números grandes de forma más legible
    long numeroGrande = 2'132'673'462;
    std::cout << "Número grande con separadores: " << numeroGrande << '\n';

    // -------- CAMBIAR BASE DE SALIDA --------
    // std::dec → imprime en decimal
    // std::hex → imprime en hexadecimal
    // std::oct → imprime en octal
    int x = 12;
    std::cout << "\nMostrando el mismo número en distintas bases:\n";
    std::cout << "Decimal: " << std::dec << x << '\n';
    std::cout << "Hexadecimal: " << std::hex << x << '\n';
    std::cout << "Octal: " << std::oct << x << '\n';

    // -------- MOSTRAR EN BINARIO CON std::bitset --------
    // std::bitset permite visualizar valores en forma binaria.
    std::bitset<8> b1{0b1100'0101};
    std::bitset<8> b2{0xC5};
    std::cout << "\nBinario con std::bitset:\n";
    std::cout << "b1: " << b1 << '\n';
    std::cout << "b2: " << b2 << '\n';
    std::cout << "Temporal: " << std::bitset<4>{0b1010} << '\n';

    // -------- OPCIONES AVANZADAS (C++20/23) --------
#if __cplusplus >= 202002L
    // std::format → permite dar formato a la salida con especificadores
    std::cout << "\nCon std::format (C++20):\n";
    std::cout << std::format("{:b}\n", 0b1010);   // imprime binario simple
    std::cout << std::format("{:#b}\n", 0b1010);  // imprime con prefijo 0b
#endif

#if __cplusplus >= 202302L
    // std::print → imprime directamente con formato (más moderno)
    std::println("\nCon std::print (C++23):");
    std::println("{:b} {:#b}", 0b1010, 0b1010);
#endif

    return 0;
}

/*
    Resumen y conclusiones:
    -----------------------
    - Decimal: sistema habitual (base 10).
    - Binario: base 2, esencial en computación.
    - Octal: base 8, poco usado actualmente.
    - Hexadecimal: base 16, muy práctico en programación.

    Notas prácticas en C++:
    - Decimal: se escribe normalmente → 42
    - Octal: prefijo 0 → 052
    - Hexadecimal: prefijo 0x → 0x2A
    - Binario: prefijo 0b → 0b101010
    - Separadores de dígitos (') ayudan a la legibilidad → 1'000'000

    Para imprimir:
    - std::dec, std::oct, std::hex → cambian la base de salida.
    - std::bitset<N> → muestra en binario.
    - std::format / std::print (C++20/23) → permiten salida con formato avanzado.
*/
