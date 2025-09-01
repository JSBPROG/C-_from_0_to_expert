#include "Header.hpp"  // Incluimos el header de MiClase para conocer su interfaz
#include <iostream>      // Incluimos iostream para usar std::cout y std::endl

// Definición del método saludar()
// Ahora le decimos al compilador qué hace el método
void MiClase::saludar() {
    std::cout << "Hola desde MiClase" << std::endl;
}

int main() {
    // Creamos un objeto de la clase MiClase
    MiClase obj;

    // Llamamos al método saludar del objeto
    // Esto imprime "Hola desde MiClase" en pantalla
    obj.saludar();

    return 0; // Fin del programa
}


/*IMPORTANTE:

Con .hpp se usa include, con .cpp se utiliza el comando de consola de g++, esto es porque:

cpp es para compilación e implementación.
hpp es para declaración

Errores comunes si te equivocas:

Haces #include "MiClase.cpp" en main.cpp
→ El preprocesador copia todo MiClase.cpp dentro de main.cpp.
→ Al compilar, MiClase.cpp se compila 2 veces, causando errores de redefinición.

*/