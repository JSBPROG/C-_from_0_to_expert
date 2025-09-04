#include <iostream>

using namespace std;

/*
    ------------------------------------------------------------
    DEMOSTRACIÓN Y TEORÍA DE BOOLEAN VALUES EN C++
    ------------------------------------------------------------

    ¿Qué son los valores booleanos?
    --------------------------------
    Un booleano es un tipo de dato fundamental en C++ que puede tomar
    solo dos valores: `true` (verdadero) o `false` (falso).

    -> Se llaman así por George Boole, matemático creador del álgebra booleana.

    En la vida real, ejemplos de preguntas booleanas:
        - ¿Es una manzana una fruta? -> true
        - ¿Te gusta el brócoli? -> false

    En programación, usamos `bool` para expresar condiciones.
*/

int main() {
    // ---------------------------------------------------------
    // 1. Declaración e inicialización
    // ---------------------------------------------------------
    bool b1 { true };   // inicializado a verdadero
    bool b2 { false };  // inicializado a falso
    bool b3 {};         // default init -> false
    b1 = false;         // reasignación

    cout << "b1 = " << b1 << '\n'; // imprime 0 (false)
    cout << "b2 = " << b2 << '\n'; // imprime 0 (false)
    cout << "b3 = " << b3 << '\n'; // imprime 0 (false)
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 2. Operador NOT (!) para invertir booleanos
    // ---------------------------------------------------------
    bool b4 { !true };   // false
    bool b5 { !false };  // true
    cout << "NOT true = " << b4 << '\n';
    cout << "NOT false = " << b5 << '\n';
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 3. Almacenamiento interno
    // ---------------------------------------------------------
    // Internamente, C++ guarda:
    // - true como 1
    // - false como 0
    // Aunque se vean como 0/1, semánticamente son "falso/verdadero".
    cout << true << " (true como entero)\n";
    cout << false << " (false como entero)\n";
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 4. Usar std::boolalpha para imprimir como true/false
    // ---------------------------------------------------------
    cout << std::boolalpha; // cambia el formato de salida
    cout << "true se imprime como: " << true << '\n';
    cout << "false se imprime como: " << false << '\n';

    // volver al formato numérico
    cout << std::noboolalpha;
    cout << "true otra vez como número: " << true << '\n';
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 5. Conversión entre enteros y booleanos
    // ---------------------------------------------------------
    bool bFalse { 0 };  // 0 -> false
    bool bTrue { 1 };   // 1 -> true
    // bool bError { 2 }; // error: narrowing conversion (con uniform init)

    bool bConv1 = 4;    // cualquier número != 0 se convierte en true
    bool bConv2 = 0;    // cero se convierte en false

    cout << std::boolalpha;
    cout << "bool de 0 -> " << bFalse << '\n';
    cout << "bool de 1 -> " << bTrue << '\n';
    cout << "bool de 4 -> " << bConv1 << '\n';
    cout << "bool de 0 -> " << bConv2 << '\n';
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 6. Entrada de booleanos con cin
    // ---------------------------------------------------------
    /*
        Por defecto, std::cin espera 0 o 1 para un bool.
        Si el usuario escribe "true", fallará silenciosamente.
    */
    bool userBool{};
    cout << "Ingresa un booleano (0 o 1): ";
    cin >> userBool;
    cout << "Ingresaste: " << userBool << '\n';

    // Permitir escribir "true" o "false"
    cin.clear();
    cout << "Ingresa true o false: ";
    cin >> std::boolalpha >> userBool;
    cout << "Ingresaste: " << std::boolalpha << userBool << '\n';
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 7. Funciones que devuelven bool
    // ---------------------------------------------------------
    auto isEqual = [](int x, int y) -> bool {
        return x == y;
    };

    int a = 5, b = 5;
    cout << "¿" << a << " == " << b << "? " << isEqual(a, b) << '\n';

    a = 3; b = 7;
    cout << "¿" << a << " == " << b << "? " << isEqual(a, b) << '\n';
    cout << "---------------------------------------------------------\n";

    /*
        ---------------------------------------------------------
        BEST PRACTICES PARA BOOLEANOS:
        ---------------------------------------------------------
        ✅ Usa `true` y `false` en vez de 1 o 0 para mayor claridad.
        ✅ Usa `std::boolalpha` al imprimir para mejor legibilidad.
        ✅ Nombra las funciones booleanas con "is" o "has":
            - isEven(), isEmpty(), hasAccess().
        ✅ Usa bool para expresar condiciones lógicas, no para almacenar números.
        ⚠️ Recuerda que bool es un tipo integral: true = 1, false = 0.
        ⚠️ Evita comparar directamente con true/false:
            if (b == true) -> redundante
            if (b)         -> más claro
    */

    return 0;
}
