#include <iostream>
#include <cstdlib> // Para EXIT_SUCCESS y EXIT_FAILURE

// ================== 1. Programa inicial ==================
/*
   Pedimos un número y mostramos el doble.
   Sin usar funciones todavía.
*/
void ejemplo1()
{
    std::cout << "\n=== EJEMPLO 1 ===\n";
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;

    std::cout << num << " doubled is: " << num * 2 << '\n';
}

// ================== 2. Función sin valor de retorno ==================
/*
   Intento de encapsular la entrada en una función "void".
   El problema: el valor se pierde porque no se devuelve nada. (Si es void, puede mostrarse por pantalla o puede servir para cambiar un valor.)
*/
void getValueFromUserVoid()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
}

void ejemplo2()
{
    std::cout << "\n=== EJEMPLO 2 ===\n";
    getValueFromUserVoid(); // El usuario ingresa un número pero se pierde

    int num{}; // nunca se inicializa con el valor
    std::cout << num << " doubled is: " << num * 2 << '\n'; // siempre 0
}

// ================== 3. Función con valor de retorno ==================
/*
   Solución: la función devuelve el valor ingresado.
*/
int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input; // devolvemos el número
}

void ejemplo3()
{
    std::cout << "\n=== EJEMPLO 3 ===\n";
    int num{ getValueFromUser() }; // usamos el valor devuelto
    std::cout << num << " doubled is: " << num * 2 << '\n';
}

// ================== 4. Función que siempre devuelve el mismo valor ==================
/*
   Ejemplo de función que retorna un valor fijo.
*/
int returnFive()
{
    return 5;
}

void ejemplo4()
{
    std::cout << "\n=== EJEMPLO 4 ===\n";
    std::cout << returnFive() << '\n';        // imprime 5
    std::cout << returnFive() + 2 << '\n';    // imprime 7
    returnFive(); // se ignora el valor
}

// ================== 5. Función sin return -> Undefined Behavior ==================
/*
   Si una función promete devolver algo y no lo hace,
   el comportamiento es indefinido (UB).
*/
int getValueFromUserUB()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    // Falta return → UB
}

void ejemplo5()
{
    std::cout << "\n=== EJEMPLO 5 ===\n";
    int num{ getValueFromUserUB() }; // UB
    std::cout << num << " doubled is: " << num * 2 << '\n';
}

// ================== 6. Reutilización de funciones (DRY) ==================
/*
   Usamos la misma función dos veces para evitar código duplicado.
*/
void ejemplo6()
{
    std::cout << "\n=== EJEMPLO 6 ===\n";
    int x{ getValueFromUser() }; // primera llamada
    int y{ getValueFromUser() }; // segunda llamada

    std::cout << x << " + " << y << " = " << x + y << '\n';
}

// ================== main ==================
int main()
{
    std::cout << "LECCION: FUNCIONES CON VALORES DE RETORNO\n";

    ejemplo1(); // programa básico
    ejemplo2(); // función void que pierde datos
    ejemplo3(); // función que devuelve valor
    ejemplo4(); // función returnFive
    // ejemplo5(); // cuidado: UB, descomentar para probar
    ejemplo6(); // función reutilizada (DRY)

    return EXIT_SUCCESS; // convención: 0 o EXIT_SUCCESS si todo ok
}



// ================== NOTAS ==================

//Follow DRY: “Don’t repeat yourself”. If you need to do something more than once, consider how to modify your code to remove as much redundancy as possible.
//Follow KISS: “Keep it simple, stupid”. Always opt for the simplest solution that works. Avoid unnecessary complexity.
//Follow YAGNI: “You aren’t gonna need it”. Don’t add functionality until you actually need it. Always implement things when you actually need them, never when you just foresee that you need them.
//Functions should do one thing and do it well. If a function is trying to do too much, consider breaking it into smaller, more focused functions.
