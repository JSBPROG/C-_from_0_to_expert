#include <iostream>
#include <string>
#include <string_view>

/*
 * ============================================================
 *                 STD::STRING_VIEW - TEORÍA + EJEMPLOS
 * ============================================================
 *
 * Conceptos fundamentales:
 *
 * 1. std::string
 *    - Es un "owner" (propietario) de la cadena.
 *    - Copia la cadena inicial en memoria propia.
 *    - Garantiza que su contenido sea independiente del valor
 *      que se le pasó para inicializarlo.
 *    - Modificar un std::string no afecta a las copias que ya existen.
 *    - Coste: Inicializar y copiar std::string es relativamente caro.
 *
 * 2. std::string_view
 *    - Es un "viewer" (espectador) de la cadena.
 *    - No copia la cadena, simplemente crea una vista sobre
 *      la cadena existente.
 *    - Solo lectura: no permite modificar la cadena subyacente.
 *    - Muy eficiente, pero depende de que la cadena original
 *      siga existiendo y no sea modificada.
 *    - Coste: Inicialización y copia de std::string_view es barata.
 *
 * Advertencias clave:
 * - No usar std::string_view sobre temporales (dangling view).
 * - Modificar un std::string invalida cualquier std::string_view
 *   que lo esté viendo.
 * - std::string_view puede no ser null-terminated si apunta a una
 *   subcadena.
 * ============================================================
 */

int main() {

    /*
     * ------------------------------------------------------------
     * 1. Ejemplo de propietario (owner) vs espectador (viewer)
     * ------------------------------------------------------------
     */

    // std::string como propietario
    std::string owner{"Hello, world!"};
    // std::string_view como espectador
    std::string_view viewer{owner};

    std::cout << "Viewer inicial: " << viewer << '\n';
    std::cout << "Owner inicial: " << owner << '\n';

    /*
     * Modificar el owner invalida el viewer.
     * Esto es porque std::string puede cambiar su memoria interna
     * al reasignar el contenido, dejando dangling al viewer.
     */
    owner = "New content"; // invalida viewer
    // std::cout << viewer << '\n'; // <-- undefined behavior

    // Revalidación: asignamos viewer de nuevo
    viewer = owner;
    std::cout << "Viewer revalidado: " << viewer << '\n';

    /*
     * ------------------------------------------------------------
     * 2. Dangling std::string_view
     * ------------------------------------------------------------
     * Las vistas no deben apuntar a objetos que se destruyen.
     * Esto sucede frecuentemente con variables locales o literales temporales.
     */

    std::string_view dangling{};
    {
        std::string temp{"Temporary"};  // local del bloque
        dangling = temp;               // viewer apunta a temp
    } // temp destruido aquí
    // std::cout << dangling << '\n'; // <-- undefined behavior

    /*
     * Ejemplo con función que retorna std::string temporal:
     */
    auto getName = []() -> std::string {
        return "Alex";
    };
    std::string tempName = getName();  // copia segura
    std::string_view safeName{tempName};
    std::cout << "Safe name: " << safeName << '\n';

    /*
     * ------------------------------------------------------------
     * 3. std::string_view como parámetro de función
     * ------------------------------------------------------------
     *
     * Ventajas:
     * - Evita copiar la cadena.
     * - Puede aceptar C-style string, std::string o std::string_view.
     * - Seguridad: mientras la cadena original exista, es seguro.
     */

    auto printSV = [](std::string_view str) {
        std::cout << str << '\n';
    };

    printSV("C-style literal"); // seguro: literal siempre existe
    printSV(owner);             // seguro: owner existe
    printSV(viewer);            // seguro: viewer apunta a owner

    /*
     * ------------------------------------------------------------
     * 4. Retorno seguro de std::string_view
     * ------------------------------------------------------------
     *
     * Solo seguro si:
     * - Retornamos un literal C-style.
     * - Retornamos un std::string_view que apunta a un argumento
     *   que vive más allá de la función.
     *
     * Ejemplo seguro:
     */
    auto getBoolName = [](bool b) -> std::string_view {
        if (b) return "true";  // literal -> seguro
        return "false";        // literal -> seguro
    };
    std::cout << getBoolName(true) << " " << getBoolName(false) << '\n';

    /*
     * Retorno de parámetro std::string_view:
     */
    auto firstAlphabetical = [](std::string_view s1, std::string_view s2) -> std::string_view {
        return (s1 < s2) ? s1 : s2;
    };

    std::string a{"World"};
    std::string b{"Hello"};
    std::cout << "First alphabetical: " << firstAlphabetical(a, b) << '\n';

    /*
     * ------------------------------------------------------------
     * 5. Modificación de la vista
     * ------------------------------------------------------------
     * Funciones: remove_prefix, remove_suffix
     * - Modifican solo la vista, no la cadena original
     */
    std::string_view str{"Peach"};
    std::cout << "Original: " << str << '\n';

    str.remove_prefix(1); // quita 1 caracter al inicio
    std::cout << "remove_prefix(1): " << str << '\n';

    str.remove_suffix(2); // quita 2 caracteres al final
    std::cout << "remove_suffix(2): " << str << '\n';

    // Reset de la vista
    str = "Peach";
    std::cout << "Reset: " << str << '\n';

    /*
     * ------------------------------------------------------------
     * 6. Subcadenas sin copiar
     * ------------------------------------------------------------
     * std::string_view permite ver solo parte de una cadena
     * sin copiarla.
     */
    std::string_view word{"snowball"};
    std::string_view sub = word.substr(0, 4); // "snow"
    std::cout << "Subcadena: " << sub << '\n';

    /*
     * Nota: std::string_view puede no ser null-terminated
     * Convertir a std::string si se necesita null-terminator
     */
    std::string_view part = word.substr(1, 3); // "now" -> no null-terminated
    std::cout << "Subcadena no null-terminated: " << part << '\n';
    std::string copy_part{part}; // copia a std::string null-terminated

    /*
     * ------------------------------------------------------------
     * 7. Guía rápida std::string vs std::string_view
     * ------------------------------------------------------------
     * std::string:
     * - Modificable
     * - Almacena entrada de usuario
     * - Retorno de funciones por valor
     *
     * std::string_view:
     * - Solo lectura
     * - Parámetros de función
     * - Subcadenas sin copiar
     * - Literales C-style
     *
     * Buenas prácticas:
     * - Evitar std::string por valor si solo se lee
     * - No usar std::string_view sobre temporales
     * - Revalidar views si se modifica el string original
     * - Convertir a std::string si se necesita null-termination
     */

    return 0;
}
