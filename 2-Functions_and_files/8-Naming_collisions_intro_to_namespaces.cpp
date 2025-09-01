#include <iostream>

// ====================================================
// Ejemplo 1: Naming collisions
// ====================================================

// Si definimos la misma función en dos archivos diferentes sin namespaces,
// ocurrirá un error de linker si ambos archivos son parte del mismo proyecto.
// Por ejemplo, si a.cpp y main.cpp definen lo mismo:
//
// void myFcn(int x) { std::cout << x; }
// void myFcn(int x) { std::cout << 2*x; }
//
// Al compilar ambos archivos juntos, el linker se quejará de "naming collision".

// ====================================================
// Ejemplo 2: Local scope evita colisiones de variables
// ====================================================

void functionA() {
    int x{5}; // x es local a functionA
    std::cout << "functionA x = " << x << "\n";
}

void functionB() {
    int x{10}; // x es local a functionB, no hay conflicto
    std::cout << "functionB x = " << x << "\n";
}

// ====================================================
// Ejemplo 3: Namespaces para evitar colisiones de funciones
// ====================================================

// Namespace math con funciones "add" y "multiply"
namespace math {
    int add(int a, int b) {
        return a + b;
    }

    int multiply(int a, int b) {
        return a * b;
    }
}

// Namespace physics con función "add" diferente, es interesante para agrupaciones, pero más interesante aún creo que es evitar nombres genéricos de variables.
namespace physics {
    double add(double a, double b) {
        return a + b + 0.001; // simulamos una operación distinta
    }
}

// ====================================================
// Ejemplo 4: Uso de std::cout con namespace explícito
// ====================================================

int main() {
    functionA();
    functionB();

    // Usando namespaces explícitamente para evitar colisiones
    int sumMath = math::add(3, 4);
    double sumPhysics = physics::add(3.0, 4.0);

    std::cout << "math::add(3,4) = " << sumMath << "\n";
    std::cout << "physics::add(3.0,4.0) = " << sumPhysics << "\n";

    // Ejemplo correcto de std::cout con namespace explícito
    std::cout << "Hello, world!" << std::endl;

    return 0;
}

// ====================================================
// Notas y Best Practices
// ====================================================

/*
1. Evita naming collisions:
   - Dos identificadores con el mismo nombre en el mismo scope producen un error.
   - Dos funciones globales idénticas en diferentes archivos producen un error de linker.
   - Local scope de variables dentro de funciones previene colisiones.

2. Namespaces:
   - Proporcionan un scope separado para agrupar identificadores relacionados.
   - Los nombres dentro de un namespace no colisionan con nombres de otros namespaces o del global scope.
   - Usa nombres de namespaces significativos, como 'math', 'physics', etc.

3. Global namespace:
   - Todo lo que no esté dentro de un namespace o clase está en el global namespace.
   - Evita definir variables globales no constantes para prevenir conflictos y problemas de mantenimiento.

4. std namespace:
   - Todas las funciones y objetos de la biblioteca estándar están en 'std'.
   - Usa `std::cout` explícitamente para evitar confusión y posibles conflictos.
   - Evita `using namespace std;` en archivos de cabecera o en programas grandes para no introducir ambigüedades.
   - Esto es crítico porque en programas grandes podrías definir tu propia función `cout()` que colisione con `std::cout`.

5. Scope y calificador de nombre:
   - Para acceder a un identificador en un namespace: `namespace_name::identifier`
   - Esto se llama "qualified name" y es la manera más segura de usar namespaces.

6. Resumen clave:
   - Local scope protege variables.
   - Namespaces protegen funciones y variables globales.
   - Siempre sé explícito con el namespace de std para I/O.
   - Evita usar-directives a nivel global en programas grandes.

   Warning

Avoid using-directives (such as using namespace std;) 
at the top of your program or in header files. They violate the reason why namespaces were added in the first place.
En su lugar puede hacerse en una funcion, por ejemplo, para escribir menos.
*/


/*Si uso: 

using namespace (nombre de funcion)

entonces no tengo que escribirla de ahi en adelante (global)

Por ejemplo:

using namespace std;

A continuacion en lugar de 

std::cout

usaría:

cout

Esto no es recomendable, lo mejor sería como el ejemplo de arriba, namespace::funcion


En python sería como std.count, el namespace es como un alias de clase.*/