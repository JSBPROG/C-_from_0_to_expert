#include "square.h"  // Incluimos header propio
#include "wave.h"    // Incluimos otro header que a su vez incluye square.h
#include <iostream>  // Librería estándar

int main() {
    // Usamos funciones definidas en square.cpp
    std::cout << "Un cuadrado tiene " << getSquareSides() << " lados\n";
    std::cout << "Perímetro de un cuadrado de lado 5: "
              << getSquarePerimeter(5) << '\n';
    return 0;
}

/*
EXPLICACIÓN:

- main.cpp incluye square.h y wave.h.
- wave.h incluye square.h.
- Gracias a los header guards (#ifndef / #define / #endif) 
  square.h solo se copia una vez por archivo.
- Cada archivo obtiene la declaración de funciones sin duplicarlas.
- La implementación de las funciones está únicamente en square.cpp,
  evitando errores de "duplicate definition" en el linker.
*/


/*----------COMPILACIÓN-----------*/

/*
                    g++ main.cpp square.cpp -o programa
                    ./programa
*/

/*-------------------MEJORES PRÁCTICAS----------------------------*/

/*
/*
1. Usar header guards en TODOS los headers.
2. Declarar funciones y tipos en headers; definir funciones solo en .cpp.
3. Cada .cpp incluye su header correspondiente (paired header).
4. No incluir archivos .cpp en otros archivos.
5. Orden recomendado de includes:
   a) Header propio
   b) Otros headers del proyecto
   c) Librerías externas
   d) Librerías estándar
6. Usar "" para headers propios, <> para headers estándar.
7. Mantener headers enfocados y documentados.
8. Incluso si solo hay declaraciones, header guards son obligatorios.
*/



