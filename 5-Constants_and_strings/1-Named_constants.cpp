/*
    ================================================
    5.1 — Constant variables (named constants) en C++
    ================================================

    INTRODUCCIÓN
    ------------
    En programación, una **constante** es un valor que
    NO puede cambiar durante la ejecución del programa.

    C++ soporta varios tipos de constantes:
      1. Constantes literales (ej: 42, 3.14, 'A').
      2. Constantes nombradas (con identificadores).
      3. Constantes definidas con macros (#define).
      4. Enumeraciones (enum).

    En esta lección nos enfocamos en **constant variables**
    que son la forma más segura y moderna en C++.

    ------------------------------------------------
    VENTAJAS DE USAR CONST VARIABLES
    ------------------------------------------------
    - Previenen errores: no se pueden reasignar por accidente.
    - Hacen el código más legible: un nombre describe al valor.
    - Permiten que el compilador optimice mejor.
    - Reducen la complejidad: sabemos que su valor no cambia.

    BEST PRACTICE:
    > Si un valor NO debería cambiar nunca, usa 'const'.
*/

#include <iostream>
using namespace std;

int main()
{
    // ===============================
    // 1. Declaración de const variable
    // ===============================
    const double earthGravity { 9.8 };   // const antes del tipo (estilo preferido)
    int const sidesInSquare { 4 };       // "east const" style (aceptado, pero menos común)

    cout << "La gravedad de la Tierra es: " << earthGravity << " m/s^2\n";
    cout << "Un cuadrado tiene " << sidesInSquare << " lados.\n\n";

    // ===============================
    // 2. Const debe inicializarse
    // ===============================
    int edadUsuario{};
    cout << "Ingresa tu edad: ";
    cin >> edadUsuario;

    const int constAge { edadUsuario }; // inicializamos con una variable normal

    cout << "Tu edad almacenada en const es: " << constAge << "\n";
    // constAge = 30; // ❌ ERROR: no se puede modificar

    // ===============================
    // 3. Constantes en funciones
    // ===============================
    auto printInt = [](const int x) {
        cout << "Valor recibido: " << x << '\n';
        // x = 10; // ❌ ERROR: x es const
    };

    printInt(42);

    /*
        Nota:
        No solemos usar 'const' en parámetros por valor, ya que
        son copias locales y no importa si se modifican.
        Pero sí tiene sentido con parámetros por referencia o puntero.
    */

    // ===============================
    // 4. Const en retornos
    // ===============================
    auto getValue = []() -> const int {
        return 5;
    };

    cout << "Const return: " << getValue() << "\n";
    // Para tipos primitivos no tiene mucho sentido devolver const por valor.
    // En tipos complejos (objetos) se analiza caso a caso.

    // ===============================
    // 5. Comparación con macros
    // ===============================
    // ❌ NO RECOMENDADO:
    #define PI 3.14159

    // ✅ RECOMENDADO:
    const double pi { 3.14159 };

    cout << "\nCon #define PI = " << PI << " (macro, menos seguro)\n";
    cout << "Con const pi   = " << pi << " (const, más seguro y legible)\n\n";

    /*
        PROBLEMAS DE LAS MACROS:
        - No respetan el ámbito (scope).
        - Pueden causar errores raros de compilación.
        - No aparecen bien en el depurador.
        - Se sustituyen de forma textual (menos seguridad).
    */

    // ===============================
    // 6. Buenas prácticas
    // ===============================
    cout << "Buenas prácticas con const:\n";
    cout << "1. Usa 'const' siempre que un valor no deba cambiar.\n";
    cout << "2. Prefiere 'const' a #define para constantes.\n";
    cout << "3. Usa nombres descriptivos (ej: earthGravity).\n";
    cout << "4. Recuerda que 'const' hace parte del tipo.\n";
    cout << "5. Evita const en parámetros por valor y retornos simples.\n";

    return 0;
}

/*
    EJEMPLOS ÚTILES:
    ----------------
    - Definir constantes físicas/matemáticas:
        const double kPi { 3.14159 };
        const double kSpeedOfLight { 299792458.0 }; // en m/s

    - Configuración en juegos:
        const int kMaxLives { 3 };
        const double kGravity { 9.81 };

    - Valores de aplicación:
        const string appName { "MiPrograma" };

    CONSEJO:
    -------
    En proyectos grandes, coloca tus constantes globales
    en un header central (ej: "constants.h") usando 'inline const'.
    Así puedes reutilizarlas en todo el programa.
*/
