#include <iostream>

// ------------------------------------------------------------
// Función add
// x y y son parámetros locales. 
// Son creados cuando se llama la función y destruidos al salir. (Esto son variables locales)
// ------------------------------------------------------------
int add(int x, int y) // x, y: scope local dentro de add
{
    int z = x + y; // z es variable local a add, creada aquí
    return z;      // z destruido al salir de la función, x y y también
} 

// ------------------------------------------------------------
// Función que imprime un saludo
// No usa variables externas; todo local a la función
// ------------------------------------------------------------
void doSomething()
{
    std::cout << "Hello!\n"; // no hay variables locales aquí
}

// ------------------------------------------------------------
// Función para obtener un valor del usuario
// input es local a la función
// Retorna un valor que puede usarse fuera de la función
// ------------------------------------------------------------
int getValueFromUser()
{
    int input{}; // variable local
    std::cout << "Enter an integer: ";
    std::cin >> input;
    return input; // input se destruye aquí, pero su valor se devuelve
}

// ------------------------------------------------------------
// Función para imprimir el doble de un número
// value es parámetro local
// ------------------------------------------------------------
void printDouble(int value) // value es local a esta función
{
    std::cout << value << " doubled is: " << value * 2 << '\n';
}

// ------------------------------------------------------------
// Ejemplo de parámetro no usado
// Usamos la notación /*param*/ para evitar warnings
// ------------------------------------------------------------
void doSomethingWithoutWarning(int /*unusedParam*/)
{
    // nada que hacer aquí
}

int main()
{
    // ---------------------------
    // Variables locales a main
    // ---------------------------
    int a{5}; // a entra en scope aquí
    int b{6}; // b entra en scope aquí

    // ---------------------------
    // Uso de parámetros y variables locales
    // add(a, b) crea parámetros locales x=5 y y=6 dentro de add
    // ---------------------------
    std::cout << "Sum of a and b: " << add(a, b) << '\n';

    // ---------------------------
    // Llamada a función sin parámetros
    // ---------------------------
    doSomething(); // a y b todavía en scope aquí

    // ---------------------------
    // Objeto temporal: retorno directo a std::cout
    // getValueFromUser() devuelve valor temporal
    // Se destruye al final de la expresión
    // ---------------------------
    std::cout << "User entered (temporary object): " << getValueFromUser() << '\n';

    // ---------------------------
    // Guardar valor en variable local
    // num es local a main
    // ---------------------------
    int num{ getValueFromUser() }; 
    printDouble(num); // valor pasado como argumento a printDouble

    // ---------------------------
    // Llamada a función con parámetro no usado
    // ---------------------------
    doSomethingWithoutWarning(42);

    return 0; // a, b y num salen de scope aquí
}
