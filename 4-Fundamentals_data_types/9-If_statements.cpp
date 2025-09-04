#include <iostream>
using namespace std;

/*
    ----------------------------------------------------------
    IF STATEMENTS EN C++
    ----------------------------------------------------------

    Definición:
    Un "if statement" permite ejecutar un bloque de código solo si
    cierta condición (expresión condicional) se evalúa como true.

    Sintaxis general:
        if (condition)
            statement;

    - "condition" debe evaluarse a un valor booleano.
    - Si la condición es true -> se ejecuta "statement".
    - Si la condición es false -> se salta "statement".

    Nota: por defecto, un "if" solo afecta a UNA sentencia.
    Para múltiples sentencias, se usan llaves { }.
*/

int main() {
    // ----------------------------------------------------------
    // 1. Ejemplo básico de if
    // ----------------------------------------------------------
    cout << "Ingrese un entero: ";
    int x{};
    cin >> x;

    if (x == 0) // condición: ¿es igual a cero?
        cout << "El valor es cero\n"; // solo se ejecuta si true

    // ----------------------------------------------------------
    // 2. If-else: ejecutar algo cuando la condición es false
    // ----------------------------------------------------------
    if (x == 0)
        cout << "El valor es cero\n";
    else
        cout << "El valor es distinto de cero\n";

    // ----------------------------------------------------------
    // 3. Encadenar condiciones (if - else if - else)
    // ----------------------------------------------------------
    if (x > 0)
        cout << "El valor es positivo\n";
    else if (x < 0)
        cout << "El valor es negativo\n";
    else
        cout << "El valor es cero\n";

    // ----------------------------------------------------------
    // 4. Condiciones basadas en funciones booleanas
    // ----------------------------------------------------------
    auto isEqual = [](int a, int b) -> bool {
        return a == b; // retorna true si son iguales
    };

    int y{};
    cout << "Ingrese otro número: ";
    cin >> y;

    if (isEqual(x, y))
        cout << x << " y " << y << " son iguales\n";
    else
        cout << x << " y " << y << " son distintos\n";

    // ----------------------------------------------------------
    // 5. Condicionales no booleanos (implícitamente convertidos)
    // ----------------------------------------------------------
    int z {4};
    if (z) // cualquier valor != 0 se convierte en true
        cout << "Como z = " << z << " (no es 0), esto imprime hi\n";
    else
        cout << "Como z es 0, imprimiría bye\n";

    /*
        Insight: 
        if (x) significa "si x es distinto de 0".
        Esto puede ser útil pero poco claro, mejor usar comparaciones explícitas.
    */

    // ----------------------------------------------------------
    // 6. Retornos tempranos (early return) en funciones
    // ----------------------------------------------------------
    auto absVal = [](int n) -> int {
        if (n < 0)
            return -n; // early return: termina la función aquí si n < 0
        return n;       // si no se cumple, devuelve n al final
    };

    cout << "abs(4) = " << absVal(4) << '\n';
    cout << "abs(-3) = " << absVal(-3) << '\n';

    /*
        Los retornos tempranos son aceptados hoy en día
        porque simplifican el código y evitan anidaciones innecesarias.
    */

    // ----------------------------------------------------------
    // 7. Ejercicio práctico: número primo entre 0 y 9
    // ----------------------------------------------------------
    cout << "Ingrese un número entre 0 y 9: ";
    int d{};
    cin >> d;

    if (d == 2 || d == 3 || d == 5 || d == 7)
        cout << "El dígito es primo\n";
    else
        cout << "El dígito no es primo\n";

    // ----------------------------------------------------------
    // 8. Mejora de funciones que retornan bool
    // ----------------------------------------------------------
    auto isAllowedToTakeFunRide = []() -> bool {
        cout << "¿Cuál es tu altura en cm?: ";
        double height{};
        cin >> height;

        // Podemos reducir la función: return directamente la condición
        return height >= 140.0;
    };

    if (isAllowedToTakeFunRide())
        cout << "¡Diviértete en el juego!\n";
    else
        cout << "Lo siento, eres demasiado bajo.\n";

    /*
        Best practices con if statements:
        ---------------------------------
        ✅ Usar llaves { } incluso con una sola sentencia -> evita errores.
        ✅ Usar funciones booleanas con nombres claros (isEven, hasAccess).
        ✅ Usar retornos tempranos para simplificar la lógica.
        ✅ Evitar condiciones implícitas como if(x) -> preferir if(x != 0).
        ✅ Encadenar if-else en lugar de varios if independientes.
    */

    return 0;
}
