#include <iostream>
#include <string> // Necesario para std::string

int main()
{
    // ==============================
    // 1. Impresiones básicas con std::cout
    // ==============================
    std::cout << 5;                      // Número entero
    std::cout << "\n";                   // Salto de línea
    std::cout << "Hola soy un texto\n";  // Cadena de texto
    std::cout << 'A';                    // Carácter (comillas simples)

    /* En C++ casi todo es un objeto, excepto las funciones */

    // ==============================
    // 2. Instanciación de variables
    // ==============================
    // "Instanciación" significa que una variable ha sido creada (memoria reservada)
    // y opcionalmente inicializada (aunque sea con valor por defecto).
    // Un objeto instanciado a veces se llama "instancia".

    int x = 10;                   // Entero
    int y {10};                   // Inicialización con llaves (C++11)
    float f = 3.14f;              // Número decimal simple precisión
    double d = 3.14159;           // Doble precisión
    char c = 'Z';                 // Carácter
    bool b = true;                // Booleano
    std::string s = "Hola C++";   // Cadena de texto

    // ==============================
    // 3. Declaración sin inicialización
    // ==============================
    int z;  // Declarada pero NO inicializada (valor indefinido, peligroso)
    z = 20; // Inicialización posterior

    /*+------ TIP -------+
      Mejor declarar e inicializar en la misma línea.
      Evita declarar varias variables en la misma línea.
    +--------------------+*/

    // ==============================
    // 4. Impresión de variables
    // ==============================
    std::cout << x << "\n";
    std::cout << f << "\n";

    // ==============================
    // 5. Reasignación
    // ==============================
    x = 15;
    std::cout << x << "\n";

    // ==============================
    // 6. Inicializaciones y conversiones
    // ==============================
    int a = 3.14;   // No error, pero a = 3 (truncamiento)
    // int b{3.14}; // ERROR: inicialización uniforme no permite conversión peligrosa

    // Diferentes formas:
    int v1;         // default-initialization (sin valor definido)
    int v2 = 5;     // copy-initialization
    int v3(6);      // direct-initialization
    int v4{7};      // direct-list-initialization (moderna)
    int v5{};       // value-initialization (llaves vacías = 0)

    // ==============================
    // 7. ¿Cuándo usar {0} vs {} ?
    // ==============================
    int n1 {0}; // Usa {0} si el valor inicial importa y lo usarás
    std::cout << n1; // Aquí se usa el 0

    int n2 {}; // Usa {} si lo vas a sobrescribir de inmediato
    std::cin >> n2; // Reemplazamos el valor inicial

    // ==============================
    // 8. Inicialización múltiple (a EVITAR)
    // ==============================
    int i = 5, j = 6;      // copy-initialization
    int k(7), l(8);        // direct-initialization
    int m{9}, n{10};       // direct-list-initialization
    int p{}, q{};          // value-initialization (ambos a 0)

    // ¡PELIGRO! Esto NO inicializa ambas variables:
    int r, s = 5; // r no está inicializada
    // CORRECTO:
    int r2 = 5, s2 = 5;

    return 0;
}

/*
=============================================================
INSTANCIACIÓN
=============================================================
- Instanciar = crear una variable (reserva memoria) y opcionalmente inicializarla.
- Se aplica más a objetos de clase, pero también a variables básicas.

=============================================================
INICIALIZACIÓN UNIFORME { } [RECOMENDADA]
=============================================================
✔ Evita conversiones peligrosas (double → int).
✔ Permite inicialización con llaves vacías: int x{}; // x = 0
✔ Sintaxis clara y consistente.
✔ Reduce errores sutiles.

INICIALIZACIÓN POR COPIA (=) [TRADICIONAL]
✔ Compatible con versiones antiguas.
✔ Permite conversiones implícitas (pérdida de datos).
✔ Todavía usada en tipos básicos.

=============================================================
¿CUÁNDO USAR {0} VS {} ?
=============================================================
✔ {0}: Cuando el valor inicial tiene un significado y lo usarás.
   Ejemplo: int x{0}; std::cout << x;
✔ {}: Cuando el valor será reemplazado inmediatamente.
   Ejemplo: int x{}; std::cin >> x;

=============================================================
INICIALIZACIÓN MÚLTIPLE
=============================================================
- Puedes inicializar varias variables en una línea, PERO:
  int a = 4, b = 5; // correcto
  int a, b = 5;     // INCORRECTO: a no se inicializa
- Cada variable necesita su propio inicializador.
- Mejor evitar esta práctica por claridad.

=============================================================
VARIABLES INICIALIZADAS PERO NO USADAS
=============================================================
- Los compiladores suelen dar warnings si defines una variable pero no la usas.
- Si tienes activado "tratar warnings como errores" (-Werror), el código no compilará.
- Opciones:
  1) Eliminar la variable si no la necesitas.
  2) Usarla en alguna parte.
  3) Usar [[maybe_unused]] (desde C++17):

    [[maybe_unused]] double pi { 3.14159 };
    [[maybe_unused]] double gravity { 9.8 };

- Esto evita el warning y el compilador probablemente optimiza la variable fuera.

Ejemplo completo:
#include <iostream>
int main()
{
    [[maybe_unused]] double pi { 3.14159 };
    [[maybe_unused]] double gravity { 9.8 };
    [[maybe_unused]] double phi { 1.61803 };

    std::cout << pi << '\n';
    std::cout << phi << '\n';

    return 0;
}

=============================================================
ALMACENAMIENTO DE VARIABLES EN MEMORIA
=============================================================
- Locales y dinámicas: RAM (stack o heap).
- Globales/estáticas: RAM en áreas fijas.
- Constantes: a veces en memoria de solo lectura.
- Programa completo: en RAM, con caché para optimización.
*/

// ==============================
// FIN DEL PROGRAMA
// ==============================
