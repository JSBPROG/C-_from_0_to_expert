#include "add.h"     // Incluimos el header propio para conocer la declaración de add()
#include <iostream>  // Incluimos librería estándar para std::cout

// ----------------------------
// Función main
// Punto de entrada del programa
// ----------------------------
int main() {
    // Llamamos a la función add() declarada en add.h e implementada en add.cpp
    int resultado = add(3, 4);

    // Mostramos el resultado en consola usando std::cout
    std::cout << "La suma de 3 y 4 es: " << resultado << '\n';

    return 0;
}

/*
Explicación:

- main.cpp necesita conocer la declaración de add(), por eso incluimos add.h.
- La implementación real está en add.cpp, que se compila y linkea con main.cpp.
- Esto demuestra la separación de:
    Declaración (en el header) vs Definición (en el .cpp)
  lo cual es muy importante para proyectos grandes y mantenibles.
*/

// ----------------------------
// Cómo compilar
// ----------------------------
// En la terminal, ejecutar:
// g++ main.cpp add.cpp -o miPrograma
// ./miPrograma

// ----------------------------
// Mejores prácticas de headers y multi-archivo
// ----------------------------

// 1. Siempre usar header guards (#ifndef / #define / #endif)
// 2. Nunca poner definiciones de funciones o variables normales en headers
// 3. Paired headers: add.cpp ↔ add.h (mismo nombre base)
// 4. Incluir explícitamente los headers necesarios en cada .cpp; no confiar en inclusiones transitivas
// 5. Nunca incluir .cpp en otros archivos
// 6. Declarar funciones en headers, definirlas en .cpp
// 7. Orden recomendado de includes:
//      a) Header propio
//      b) Otros headers del proyecto
//      c) Headers de terceros
//      d) Headers estándar (<iostream>, <vector>)
// 8. Usar doble comilla para headers propios ("add.h") y corchetes para estándar (<iostream>)
// 9. Mantener headers independientes y enfocados
// 10. Documentar en headers cómo usar la función o clase; detalles de implementación en .cpp

// ----------------------------
// Cuántas funciones en un header vs cpp
// ----------------------------

// 1. En el header (.h o .hpp):
//    - Debes declarar todas las funciones que quieras usar en otros archivos.
//    - Es decir, el header contiene solo las declaraciones (prototipos).
//    - No pongas definiciones de funciones normales ni variables globales no constantes.
//    - Ejemplo: si add.cpp tiene una función add() y otra función multiply(),
//      ambas deben estar declaradas en add.h si quieres llamarlas desde main.cpp.

// 2. En el cpp (.cpp):
//    - Debes definir todas las funciones que declaraste en el header correspondiente.
//    - Aquí va el código real de la función, con su cuerpo completo.
//    - Además, puedes tener funciones “helper” internas que no se usan fuera de este cpp;
//      estas no necesitan estar en el header.

// Resumen:
// - Header: solo declaraciones (lo que otros archivos necesitan conocer).
// - CPP: definiciones (implementación) + funciones internas privadas.
