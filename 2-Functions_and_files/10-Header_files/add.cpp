#include "add.h"   // Incluimos nuestro header para asegurar que la declaración coincida
#include <iostream> // Incluimos solo si necesitamos funciones de entrada/salida

// ----------------------------
// Definición de la función add
// Aquí está la implementación real de la función
// Esta definición se compilará solo una vez, en add.cpp
// ----------------------------
int add(int x, int y) {
    return x + y;
}


/*
Incluimos el header propio (add.h) para que el compilador pueda verificar que la definición de la función coincide con su declaración.

Nunca hacemos #include "add.cpp" en otro archivo; esto puede causar conflictos de definición.

La función real vive solo en add.cpp y se enlaza al resto del proyecto durante la fase de linking.

*/


/*---------------------IMPLEMENTA------------------*/