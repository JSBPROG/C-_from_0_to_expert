/*Best practice

El sufijo es .h ahora mismo como preferido, en muchos IDE ya viene por defecto, pero si se usa otra convención en código heredado, seguirla.*/

#ifndef ADD_H  // Header guard: evita incluir este header más de una vez
#define ADD_H

// ----------------------------
// Este archivo es un "header"
// Contiene **solo declaraciones**, no definiciones de funciones o variables globales
// Permite que otros archivos conozcan la existencia de add() sin definirla todavía
// ----------------------------

// Declaración de la función add.
// Nota: el ";" al final indica que esto es solo una declaración (forward declaration)
int add(int x, int y);

#endif // ADD_H


/*

Un header file (.h) se usa para propagar declaraciones de funciones, clases o variables.

No se deben poner definiciones de funciones normales ni variables globales aquí, para evitar violaciones de la regla de una sola definición (ODR).

El header guard evita que este archivo sea incluido varias veces en distintos .cpp, lo cual generaría errores de compilación.

La declaración permite que cualquier .cpp que lo incluya sepa que existe la función add y cómo llamarla.

*/






/*--------------DECLARA----------------*/