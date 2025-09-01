/*El sufijo preferido es .h, no .hpp*/

#ifndef MICLASE_HPP   // Include guard: evita que este header se procese más de una vez
#define MICLASE_HPP

// Declaración de la clase MiClase
// Aquí solo decimos al compilador: "existe una clase llamada MiClase con este método"
class MiClase {
public:
    void saludar(); // Declaración del método saludar()
                     // NOTA: Aquí no ponemos el cuerpo, solo informamos que existe
};

#endif // Fin del include guard
