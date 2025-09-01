#include "square.h" // Incluimos nuestro propio header

// ----------------------------
// Definiciones de funciones
// ----------------------------

// Aquí implementamos las funciones declaradas en square.h
int getSquareSides() {
    return 4; // un cuadrado siempre tiene 4 lados
}

int getSquarePerimeter(int sideLength) {
    return sideLength * getSquareSides();
}

/*
NOTA:
- Aquí sí ponemos la implementación real.
- Podemos tener funciones "helper" internas no declaradas en el header.
- No se repiten definiciones en otros cpp, evitando problemas de linker.
*/
