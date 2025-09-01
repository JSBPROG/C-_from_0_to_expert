/*
===========================================
   TUTORIAL: Syntax errors y Semantic errors
   ----------------------------------------
   - Un error de *sintaxis* ocurre cuando
     escribimos algo que no sigue las reglas
     gramaticales de C++.
     -> El compilador los detecta y NO compila.

   - Un error *semántico* ocurre cuando el
     código es válido sintácticamente, pero
     su *significado* no es correcto o no hace
     lo que queremos.
     -> Algunos se detectan en compilación.
     -> Otros sólo aparecen en tiempo de ejecución.

   En este archivo veremos ejemplos comentados
   para entender cada caso.
===========================================
*/

#include <iostream>

// --------------------------------------
// Ejemplo de error de sintaxis (NO compila)
// --------------------------------------
/*
int main( // falta el paréntesis de cierre
{
    int 1x; // un identificador no puede empezar con número
    std::cout << "Hola"; << x +++ << '\n'; // operador "+++" no existe
    return 0 // falta el punto y coma
}
*/

// --------------------------------------
// Ejemplo de error semántico detectado en compilación
// --------------------------------------
/*
int main()
{
    5 = x; // ❌ No se puede asignar un valor a un literal, además x no está declarado
    return "hola"; // ❌ main debe devolver un int, no una cadena
}
*/

// --------------------------------------
// Ejemplo de error semántico detectado en ejecución
// --------------------------------------
void divisionPorCero() {
    int a {10};
    int b {0};

    // Compila bien, pero en ejecución ocurre error:
    // División por cero es indefinida
    std::cout << a << " / " << b << " = " << a / b << '\n';
}

// --------------------------------------
// Ejemplo de semántico: comportamiento indefinido
// --------------------------------------
void variableNoInicializada() {
    int x; // x contiene basura (no está inicializado)
    std::cout << "Valor de x: " << x << '\n'; // resultado impredecible
}

// --------------------------------------
// Ejemplo de semántico: error de lógica
// --------------------------------------
int add(int x, int y) {
    return x - y; // ❌ queríamos sumar, pero restamos
}

void probarAdd() {
    std::cout << "5 + 3 = " << add(5, 3) << '\n'; // debería dar 8, da 2
}

// --------------------------------------
// Ejemplo de semántico: código inalcanzable
// --------------------------------------
void codigoInalcanzable() {
    return; // la función termina aquí

    std::cout << "Esto nunca se ejecuta\n"; // código muerto
}

// --------------------------------------
// Función main: podemos ir probando ejemplos
// --------------------------------------
int main() {
    // Comentamos/descomentamos para probar cada caso
    // divisionPorCero();
    // variableNoInicializada();
    probarAdd();
    // codigoInalcanzable();

    return 0;
}

/*
===========================================
          BUENAS PRÁCTICAS
===========================================

1. Diferencia siempre:
   - Compilación = traducción de código a binario.
   - Ejecución = correr el programa ya compilado.

2. Usa el compilador como primera herramienta
   de detección de errores (si no compila, revisa
   bien la sintaxis).

3. Inicializa SIEMPRE tus variables antes de usarlas.

4. Haz pruebas con casos simples para detectar
   errores de lógica.

5. Usa comentarios para documentar qué debe hacer
   una función -> así es más fácil detectar cuando
   el código hace otra cosa.

6. Depura con debugger paso a paso para encontrar
   errores de tiempo de ejecución.

7. Evita "código muerto" o inalcanzable: limpia tu
   código para que sea claro.

8. Compila con *warnings activados* (-Wall en g++) y
   tómate los warnings en serio.

===========================================
*/
