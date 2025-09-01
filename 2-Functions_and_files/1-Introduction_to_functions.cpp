#include <iostream> // Necesaria para usar std::cout

// ==============================
// 1. Definición de una función simple
// ==============================

// doPrint() es una función "void" (no devuelve nada).
// Su única tarea es imprimir un mensaje en consola.
void doPrint()
{
    std::cout << "Dentro de doPrint()\n";
}

// ==============================
// 2. Funciones que llaman a otras funciones
// ==============================

// doB() imprime un mensaje simple
void doB()
{
    std::cout << "Dentro de doB()\n";
}

// doA() imprime mensajes antes y después de llamar a doB()
void doA()
{
    std::cout << "Comenzando doA()\n";

    doB(); // llamada a otra función dentro de doA()

    std::cout << "Terminando doA()\n";
}

// ==============================
// 3. Función main() (punto de entrada del programa)
// ==============================

int main()
{
    // main() es la primera función en ejecutarse al iniciar el programa
    std::cout << "Comenzando main()\n";

    // --- Ejemplo 1: Llamar a una función simple ---
    doPrint();  // main() es el "caller", doPrint() es el "callee"

    // --- Ejemplo 2: Llamar varias veces a la misma función ---
    doPrint();  // se puede reutilizar tantas veces como se necesite

    // --- Ejemplo 3: Llamada a una función que llama a otra ---
    doA(); // dentro de doA() se llamará también a doB()

    std::cout << "Terminando main()\n";

    return 0; // el programa finaliza aquí
}

/*En resumen, este es un código para ver cómo unas funciones se pueden llamar dentro de otras y el orden de ejecución*/ 