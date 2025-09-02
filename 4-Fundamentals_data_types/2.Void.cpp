// -------------------------------------------------------------
// void_tutorial.cpp
// Ejemplos y teoría sobre el tipo void en C++
//
// 
// -------------------------------------------------------------

#include <iostream>
using namespace std;

// -------------------------------------------------------------
// TEORÍA:
// El tipo "void" en C++ significa "sin tipo".
// Es un tipo incompleto: no puede ser instanciado porque no
// representa ningún valor en memoria.
// -------------------------------------------------------------

// ❌ Ejemplo de uso incorrecto:
// void value; // ERROR: no se puede crear una variable de tipo void

// -------------------------------------------------------------
// 1. FUNCIONES QUE NO RETORNAN VALOR
// -------------------------------------------------------------
void writeValue(int x) // "void" indica que la función no devuelve nada
{
    cout << "El valor de x es: " << x << '\n';
    // No usamos "return" porque no hay nada que devolver
}

// ❌ Ejemplo de error si intentamos devolver un valor en una función void:
#if 0
void noReturn(int x)
{
    cout << "El valor de x es: " << x << '\n';
    return 5; // ERROR: función void no puede retornar valores
}
#endif

// -------------------------------------------------------------
// 2. FUNCIONES QUE NO RECIBEN PARÁMETROS
// -------------------------------------------------------------
// En C, se solía usar "void" en la lista de parámetros para indicar
// que la función no recibe nada:
int getValue_C(void) // válido en C, pero DEPRECATED en C++
{
    int x{};
    cin >> x;
    return x;
}

// En C++, la MEJOR PRÁCTICA  es simplemente dejar la lista vacía:
int getValue_CPP() // forma preferida en C++
{
    int x{}; 
    cin >> x;
    return x;
}

// -------------------------------------------------------------
// 3. OTROS USOS DE VOID
// -------------------------------------------------------------
// Más adelante, C++ permite "punteros void" (void*), que sirven
// para apuntar a cualquier tipo de dato sin importar cuál.
// Sin embargo, son avanzados y se explican junto a los punteros.
// -------------------------------------------------------------

// -------------------------------------------------------------
// PROGRAMA PRINCIPAL
// -------------------------------------------------------------
int main()
{
    cout << "=== DEMOSTRACIÓN DE FUNCIONES CON VOID ===\n";

    cout << "\n1. Funcion void que imprime un valor:\n";
    writeValue(42);

    cout << "\n2. Funcion que no recibe parametros (C):\n";
    cout << "Ingrese un numero: ";
    int valor1 = getValue_C();
    cout << "Valor ingresado (C style): " << valor1 << '\n';

    cout << "\n3. Funcion que no recibe parametros (C++ recomendado):\n";
    cout << "Ingrese otro numero: ";
    int valor2 = getValue_CPP();
    cout << "Valor ingresado (C++ style): " << valor2 << '\n';

    cout << "\n=== FIN DEL PROGRAMA ===\n";
    return 0;
}

// -------------------------------------------------------------
// RESUMEN Y BEST PRACTICES
// -------------------------------------------------------------
// - "void" significa "sin tipo". Es un tipo incompleto, no se pueden
//   crear variables de tipo void.
// - Su uso más común es en funciones que no devuelven nada.
// - También puede usarse en la lista de parámetros de una función
//   para indicar que no recibe ninguno, pero en C++ esto está
//   DEPRECATED. Mejor usar parámetros vacíos: ()
// - Existe "void*" (puntero genérico), pero se estudia junto a punteros.
// - ✅ Best practice: usar "void" solo cuando una función no retorna
//   valor, y usar lista de parámetros vacía en lugar de "void".
// -------------------------------------------------------------
