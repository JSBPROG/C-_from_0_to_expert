// ----------------------------
// HEADER GUARD
// ----------------------------
// Evita que este header sea incluido más de una vez en el mismo archivo.
// Esto previene errores de "duplicate definition" cuando hay múltiples inclusiones.
#ifndef SQUARE_H
#define SQUARE_H

// ----------------------------
// Declaraciones de funciones
// ----------------------------

// Declaramos funciones, no las definimos aquí.
// Esto permite que otros archivos puedan usar estas funciones
// sin que se creen duplicados.
int getSquareSides();            // Devuelve el número de lados de un cuadrado
int getSquarePerimeter(int sideLength); // Calcula el perímetro de un cuadrado

#endif // SQUARE_H

/*
NOTA:
- Nunca poner la implementación de funciones normales aquí.
- Solo declaraciones (prototipos) y definiciones de tipos (struct, class, enum).
- Header guard es obligatorio aunque solo haya declaraciones.
*/
