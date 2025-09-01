/*
    TEMA: Variables no inicializadas y comportamiento indefinido (Undefined Behavior)

    1. ¿Qué es una variable no inicializada?
       - En C++, cuando declaras una variable sin darle un valor inicial,
         su contenido será lo que ya había en esa posición de memoria.
         Esto se llama "basura" o "garbage value".
       - C++ no pone automáticamente 0 ni otro valor por defecto (excepto en casos específicos, como variables globales).

    2. Nomenclatura importante:
       - Inicializada: Se le da un valor en el momento de la definición.
           int x { 5 }; // inicializada
       - Asignación: Se le da un valor después de definirla.
           int x;
           x = 5; // asignada después
       - No inicializada: No tiene un valor conocido (puede ser cualquier cosa).

    3. ¿Por qué es peligroso?
       - Si usamos una variable sin inicializar, el comportamiento del programa es INDEFINIDO.
       - Puede imprimir números aleatorios, dar errores más adelante o incluso "funcionar bien" a veces.

    4. Reglas importantes:
       - SIEMPRE inicializa tus variables.
       - Evita todo código que cause comportamiento indefinido.
*/

#include <iostream>

// Truco para "engañar" al compilador y evitar warnings
void doNothing(int&) {}

int main()
{
    // Ejemplo 1: Variable no inicializada
    int x; // No tiene valor conocido (UNDEFINED BEHAVIOR si se usa directamente)

    doNothing(x); // Le hacemos creer al compilador que se usa antes de imprimir

    std::cout << "Valor de x (no inicializada): " << x << '\n';
    // ¿Qué imprimirá? NADIE LO SABE. Cada ejecución puede dar un número distinto.

    /*
        POSIBLES RESULTADOS:
        - Un número grande aleatorio.
        - Siempre el mismo número (depende del compilador o configuración).
        - Cero (si el compilador está en modo debug y rellena la memoria con un patrón).
    */

    // Ejemplo 2: Inicialización correcta
    int y {}; // Inicialización por valor (se pone en 0)
    std::cout << "Valor de y (inicializada en 0): " << y << '\n';

    return 0;
}

/*
    NOTAS IMPORTANTES:
    -------------------
    - Algunos compiladores en modo "debug" inicializan memoria con valores fijos para ayudarte a detectar errores,
      por ejemplo: Visual Studio pone -858993460.
    - En modo "release", normalmente no lo hacen (para optimizar velocidad), por lo que tendrás basura real.

    REGLA DE ORO:
    -------------
    Siempre inicializa tus variables. El coste es mínimo y evitas bugs impredecibles.

    Undefined Behavior (UB):
    -------------------------
    Usar variables no inicializadas es un ejemplo clásico de UB.
    UB significa que el estándar de C++ no define qué pasa.
    Esto puede provocar:
        - Resultados diferentes cada ejecución.
        - Resultados erróneos más adelante.
        - Fallos aleatorios.
        - Que parezca funcionar (hasta que no lo haga).
*/
