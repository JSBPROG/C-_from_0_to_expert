#include <iostream>
#include <string>
#include <string_view> // C++17

/*
 * ============================================================
 *                STRINGS EN C++ MODERNO
 * ============================================================
 * Tipos principales:
 * 1. std::string       -> Objeto de cadena, dinámico, copia el contenido
 * 2. std::string_view  -> Vista de cadena, solo lectura, no copia
 *
 * Buenas prácticas:
 * - Usar std::string_view para lectura de cadenas
 * - Evitar pasar std::string por valor si solo lees
 * - Usar constexpr string_view para constantes en tiempo de compilación
 * ============================================================
 */

int main() {

    /*
     * ------------------------------------------------------------
     * 1. std::string: cadenas completas, dinámicas, copiadas
     * ------------------------------------------------------------
     */
    std::string s1{"Hola, mundo!"}; // copia del literal en memoria
    std::cout << "std::string: " << s1 << '\n';

    // Se puede modificar y reasignar
    s1 = "Adiós";
    std::cout << "std::string modificado: " << s1 << '\n';

    // Longitud de la cadena (sin contar null-terminator)
    std::cout << "Longitud de s1: " << s1.length() << '\n';
    // C++20: ssize() devuelve signed integer
    std::cout << "Longitud (signed) de s1: " << std::size(s1) << '\n';

    /*
     * ------------------------------------------------------------
     * 2. std::string_view: vista ligera, solo lectura
     * ------------------------------------------------------------
     */
    std::string_view sv1{s1}; // apunta a s1, no copia
    std::cout << "std::string_view apunta a s1: " << sv1 << '\n';

    // Se puede reasignar a otra cadena
    sv1 = "Nuevo texto"; // solo cambia la vista, no la cadena original
    std::cout << "std::string_view reasignado: " << sv1 << '\n';
    std::cout << "s1 no se modifica: " << s1 << '\n';

    /*
     * ------------------------------------------------------------
     * 3. std::string_view puede inicializarse desde:
     *    - C-style string literal
     *    - std::string
     *    - Otro std::string_view
     * ------------------------------------------------------------
     */
    std::string_view sv_literal{"Hola, literal!"}; // literal C-style
    std::string s2{"Hola, std::string!"};
    std::string_view sv_from_string{s2};
    std::string_view sv_from_view{sv_from_string};

    std::cout << sv_literal << '\n';
    std::cout << sv_from_string << '\n';
    std::cout << sv_from_view << '\n';

    /*
     * ------------------------------------------------------------
     * 4. Parámetros de función
     * ------------------------------------------------------------
     */
    auto printSV = [](std::string_view str) {
        std::cout << "Función printSV: " << str << '\n';
    };

    printSV("Literal"); // C-style
    printSV(s2);        // std::string
    printSV(sv_from_view); // std::string_view

    // std::string_view NO se convierte implícitamente a std::string
    // std::string copy{s2}; // OK explícitamente
    std::string copy_of_sv{sv_from_view}; // conversión explícita
    std::cout << "Conversión explícita a std::string: " << copy_of_sv << '\n';

    /*
     * ------------------------------------------------------------
     * 5. Literales de cadena
     * ------------------------------------------------------------
     */
    using namespace std::string_literals;      // "s" suffix para std::string
    using namespace std::string_view_literals; // "sv" suffix para std::string_view

    std::cout << "C-style literal: " << "foo\n";
    std::cout << "std::string literal: " << "goo\n"s;
    std::cout << "std::string_view literal: " << "moo\n"sv;

    /*
     * ------------------------------------------------------------
     * 6. Constexpr string_view
     * ------------------------------------------------------------
     * - std::string_view soporta constexpr
     * - Ideal para constantes de cadena simbólicas
     */
    constexpr std::string_view greeting{"Hola, compile-time world!"};
    std::cout << greeting << '\n';

    /*
     * ------------------------------------------------------------
     * 7. Comparación rápida std::string vs std::string_view
     * ------------------------------------------------------------
     * std::string
     * - Copia el contenido
     * - Mutable
     * - Lento de inicializar/copy
     * - No soporta constexpr completo
     *
     * std::string_view
     * - No copia, solo apunta
     * - Solo lectura
     * - Muy rápido
     * - Compatible con constexpr
     */

    /*
     * ------------------------------------------------------------
     * 8. Buenas prácticas
     * ------------------------------------------------------------
     * - Usar std::string_view para lectura, especialmente en parámetros
     * - No pasar std::string por valor si solo lees
     * - Usar constexpr string_view para constantes en tiempo de compilación
     * - Cambiar la asignación de std::string_view NO modifica la cadena original
     * - Literales "sv" para std::string_view y "s" para std::string
     */

    return 0;
}
