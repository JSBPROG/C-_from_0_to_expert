#include <iostream>

// ------------------------
// MACROS
// Un macro es una **sustitución de texto** que hace el preprocesador antes de compilar.
// No es una variable: el compilador nunca "crea" un objeto para un macro,
// solo reemplaza el identificador por su valor literal en el código.
#define MY_NAME "Alex"  // macro con sustitución de texto
#define MY_AGE 25       // macro numérico
#define PRINT_JOE       // macro sin valor, usado para condicionales

/*
Diferencia con variables:
- std::string name = "Alex"; crea un objeto en memoria en tiempo de ejecución.
- #define MY_NAME "Alex"; no crea nada, solo reemplaza "MY_NAME" por "Alex" en el código.
*/

// ------------------------
// CONDICIONALES DE COMPILACIÓN
// Permiten incluir o excluir bloques de código según macros definidos.
// Esto se hace **antes de compilar** (en tiempo de preprocesamiento), no en tiempo de ejecución.

void conditionalExamples() {
#ifdef PRINT_JOE
    // Se compila solo si PRINT_JOE está definido
    std::cout << "PRINT_JOE está definido: Joe\n";
#endif

#ifndef PRINT_BOB
    // Se compila solo si PRINT_BOB NO está definido
    std::cout << "PRINT_BOB NO está definido: Bob\n";
#endif

#if 0
    // Bloque que nunca se compila
    // útil para "comentar" código largo que incluye comentarios dentro
    std::cout << "Este código nunca se ejecuta\n";
#endif

#if 1
    // Bloque que siempre se compila
    std::cout << "Este código siempre se ejecuta\n";
#endif
}

// ------------------------
// #include
// Inserta el contenido de otro archivo en la posición del #include antes de compilar.
// Ejemplo simulado: si tuviéramos Alex.h con "#define MY_HOBBY "Programar"", se podría usar así:
#define MY_HOBBY "Programar"

// ------------------------
// FUNCIÓN PRINCIPAL
int main() {
    std::cout << "Mi nombre es: " << MY_NAME << '\n';  // reemplazo por preprocesador
    std::cout << "Mi edad es: " << MY_AGE << '\n';     // reemplazo por preprocesador
    std::cout << "Mi hobby es: " << MY_HOBBY << '\n';  // reemplazo por preprocesador

    conditionalExamples();  // probamos los condicionales de compilación

    return 0;
}

/*
-----------------------------------
Notas y buenas prácticas
-----------------------------------
1. Macros (#define)
   - Son sustituciones de texto antes de la compilación.
   - No ocupan memoria ni tienen tipo; se diferencian de las variables en esto.
   - Útiles para:
       * Constantes simples
       * Activar/desactivar bloques de código con condicionales (#ifdef)
   - Mejor práctica: usar solo si no hay alternativas (const, constexpr, inline).
   - Convención: nombres en MAYÚSCULAS para distinguir macros.

2. Condicionales de compilación (#ifdef, #ifndef, #if, #endif)
   - Permiten incluir/excluir bloques según macros definidos.
   - #ifdef: si está definido
   - #ifndef: si NO está definido
   - #if 0 / #if 1: para desactivar o activar bloques grandes de código
   - Útiles para:
       * Probar código
       * Controlar compilación según plataforma
       * Evitar redefiniciones múltiples
   - Se resuelven **antes de compilar**, no en tiempo de ejecución.

3. #include
   - Inserta el contenido de un archivo en la posición del #include.
   - Permite dividir código en headers y organizar programas grandes.
   - Evitar #include de .cpp; solo incluir headers (.h/.hpp), son archivos aparte para definir headers (9.1).

4. Scope del preprocesador
   - Las macros son válidas desde su definición hasta el final del archivo.
   - No respetan scopes de C++ (funciones, clases, etc.).

5. Siempre usar un solo main por proyecto.
   - Para probar múltiples ejemplos en un solo archivo, crear funciones auxiliares y llamarlas desde main.
*/
