#include <iostream>

// ============================================================
// 1. Función void básica
// ============================================================
// Una función puede ejecutar código sin devolver un valor.
// "void" indica que no regresa nada al llamador.
void printHi()
{
    std::cout << "Hi" << '\n';

    // No necesitamos "return".
    // Al final de la función, el control vuelve automáticamente al caller.
}

// ============================================================
// 2. Función void con return vacío
// ============================================================
// Un return vacío dentro de una función void sirve para terminarla antes.
// Pero ponerlo al final es redundante.
void printHello()
{
    std::cout << "Hello" << '\n';

    return; // Esto es opcional y redundante aquí.
}

// ============================================================
// 3. Void functions no pueden usarse donde se espera un valor
// ============================================================
// Ejemplo de error de compilación si intentamos "usar el retorno".
void printWorld()
{
    std::cout << "World" << '\n';
}

// ============================================================
// 4. Comparación entre función void y función con retorno
// ============================================================
void returnNothing() // no retorna nada
{
}

int returnFive() // retorna un entero
{
    return 5;
}

// ============================================================
// 5. Error: intentar devolver un valor desde void
// ============================================================
/*
void badVoidFunction()
{
    std::cout << "In badVoidFunction()" << '\n';

    return 5; // ❌ ERROR: no se puede devolver un valor en una función void
}
*/

// ============================================================
// MAIN
// ============================================================
int main()
{
    std::cout << "=== EJEMPLO 1: Llamar a funcion void ===\n";
    printHi(); // imprime "Hi", no devuelve nada

    std::cout << "\n=== EJEMPLO 2: Return vacio en void ===\n";
    printHello(); // imprime "Hello"

    std::cout << "\n=== EJEMPLO 3: Uso incorrecto de void ===\n";
    printWorld(); // ✅ válido
    // std::cout << printWorld(); // ❌ ERROR: printWorld() no devuelve nada

    std::cout << "\n=== EJEMPLO 4: Comparando void y no-void ===\n";
    returnNothing();   // ✅ podemos llamar aunque no devuelva nada
    returnFive();      // ✅ podemos ignorar el retorno
    std::cout << returnFive() << '\n'; // ✅ usamos el retorno (imprime 5)
    // std::cout << returnNothing(); // ❌ ERROR: no devuelve valor

    // Ejemplo 5 ya está comentado porque no compila.

    return 0;
}

/*
============================================================
📌 NOTAS Y BUENAS PRÁCTICAS
============================================================

1. Una función void se usa cuando queremos ejecutar código
   por su efecto (ej. imprimir en pantalla) y no necesitamos
   devolver un valor.

2. No pongas "return;" al final de una función void
   → es redundante (la función regresa sola).

3. Sí puedes usar "return;" vacío en mitad de una función void
   si quieres terminarla antes de llegar al final.

4. No intentes usar una función void en un contexto
   que espera un valor (ej. dentro de std::cout, en una suma, etc.).

5. Una función void no puede devolver un valor → hacerlo es
   un error de compilación.

6. Puedes llamar tanto funciones void como funciones que
   retornan valor en solitario (ignorando el retorno).
   Ej: returnFive();  // ok, aunque no uses el 5

============================================================
*/
