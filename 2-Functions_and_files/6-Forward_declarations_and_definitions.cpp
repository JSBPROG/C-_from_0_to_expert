#include <iostream>

// ------------------------------------------------------------
// Forward declaration (declaración adelantada)
// Esto le dice al compilador que existe una función llamada "add"
// que toma dos enteros y devuelve un entero.
// No incluye el cuerpo de la función, solo su firma.
// ------------------------------------------------------------
int add(int x, int y); // forward declaration (pure declaration)

// ------------------------------------------------------------
// main
// Aquí podemos llamar a add incluso antes de definirla,
// gracias a la forward declaration
// ------------------------------------------------------------
int main()
{
    // Llamada a add. La forward declaration permite que esto compile.
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';

    // Ejemplo de otra variable local
    int x{10}; // x entra en scope aquí
    std::cout << "x = " << x << '\n';

    return 0; // x y cualquier variable local salen de scope aquí
}

// ------------------------------------------------------------
// Definition (definición) de add
// Aquí implementamos la función declarada anteriormente
// Esta definición también sirve como declaración
// ------------------------------------------------------------
int add(int x, int y) // x y y son parámetros locales a add
{
    int z{ x + y }; // z es una variable local a add
    return z;       // x, y y z son destruidos al salir de la función
}

// ------------------------------------------------------------
// Conceptos clave:
// 1. Forward declaration:
//    - Permite que el compilador conozca la existencia de la función
//      antes de su definición.
//    - Es útil cuando la definición real aparece después o en otro archivo.
//    - Sintaxis: returnType functionName(parameterTypes);
//      Ejemplo: int add(int x, int y);
//
// 2. Definition:
//    - Implementa la función o instancia la variable.
//    - Toda definición también es una declaración.
//
// 3. Declaración pura (pure declaration):
//    - No incluye cuerpo ni instancia.
//    - Forward declarations son ejemplos de pure declarations.
//
// 4. One Definition Rule (ODR):
//    - Dentro de un mismo scope, cada función o variable solo puede definirse una vez.
//    - Variables locales en distintos scopes con el mismo nombre no violan ODR.
//    - Ejemplo válido:
//        int x;          // global
//        void foo() { int x; } // local, distinto scope
//
// 5. Errores comunes:
//    - Llamar a una función antes de declararla -> "identifier not found".
//    - Definir dos veces la misma función en el mismo scope -> redefinition error.
// ------------------------------------------------------------
