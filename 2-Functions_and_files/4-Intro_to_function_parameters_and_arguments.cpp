#include <iostream>

// ----------- EJEMPLOS BÁSICOS -----------

// Función que no recibe parámetros
void doPrint()
{
    std::cout << "En doPrint()\n";
}

// Función que recibe un parámetro
void printValue(int x)
{
    std::cout << "El valor es: " << x << '\n';
}

// Función que recibe dos parámetros y devuelve un resultado
int add(int x, int y)
{
    return x + y;
}

// ----------- USANDO RETURN Y PARÁMETROS -----------

// Pedimos un número al usuario y lo retornamos
int getValueFromUser()
{
    std::cout << "Introduce un número entero: ";
    int input{};
    std::cin >> input;
    return input;
}

// Recibimos un valor como parámetro y lo usamos
void printDouble(int value)
{
    std::cout << value << " multiplicado por 2 es: " << value * 2 << '\n';
}

// ----------- MÁS EJEMPLOS CON EXPRESIONES -----------

int multiply(int z, int w)
{
    return z * w;
}

// ----------- UNREFERENCED / UNNAMED PARAMETERS -----------

// Parámetro sin usar (compilador dará warning)
void doSomethingWithWarning(int count)
{
    // antes se usaba "count", pero ahora no hace nada
}

// Parámetro sin nombre (no da warning)
void doSomethingWithoutWarning(int /*count*/)
{
    // esta funcion tiene un parámetro que no se usa, como no tiene nombre, no lanza el warning aunque no se use.
}

// ----------- PROGRAMA PRINCIPAL -----------

int main()
{
    // Ejemplo 1: funciones básicas
    doPrint();                  // sin parámetros
    printValue(6);              // con un parámetro
    std::cout << add(4, 5) << '\n';  // con dos parámetros y retorno

    // Ejemplo 2: combinación de return + parámetros
    int num{ getValueFromUser() };
    printDouble(num);           // pasamos "num" como argumento

    // Ejemplo 3: uso directo del return como argumento
    printDouble(getValueFromUser());

    // Ejemplo 4: expresiones como argumentos
    std::cout << add(1 + 2, 3 * 4) << '\n'; // pasa 3 y 12 → imprime 15

    int a{5};
    std::cout << add(a, a) << '\n'; // pasa 5 y 5 → imprime 10

    std::cout << add(1, multiply(2, 3)) << '\n'; // pasa 1 y (2*3=6) → 7
    std::cout << add(1, add(2, 3)) << '\n';      // pasa 1 y (2+3=5) → 6

    // Ejemplo 5: parámetros no usados
    doSomethingWithWarning(10);
    doSomethingWithoutWarning(20);

    return 0;
}

/*
======================= NOTA DE BUENAS PRÁCTICAS =======================

1. Usa parámetros para pasar información a las funciones, en lugar de depender
   de variables globales o intentar "adivinar" datos dentro de la función.

2. Usa valores de retorno para devolver resultados de las funciones.
   Esto hace el código modular y reutilizable.

3. Cuando un parámetro ya no se usa:
   - No le des nombre para evitar warnings.
   - O bien documenta con un comentario qué representaba: (int /*count*)

4. Evita repetir código (principio DRY). 
   Si un fragmento se repite, conviértelo en función con parámetros.

5. Es válido usar directamente el retorno de una función como argumento de otra,
   pero si la expresión se complica demasiado, guarda el valor en una variable
   intermedia para mantener el código legible.

=======================================================================
*/
