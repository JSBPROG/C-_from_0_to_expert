#include <iostream>
#include <iomanip>   // para std::setprecision
#include <limits>    // para std::numeric_limits

using namespace std;

/*
    ------------------------------------------------------------
    DEMOSTRACIÓN Y TEORÍA DE FLOATING POINT EN C++
    ------------------------------------------------------------

    Los números enteros son muy útiles, pero a veces necesitamos:
    - Valores muy grandes o muy pequeños.
    - Números con parte fraccionaria (decimales).
    Para esto usamos los tipos "de coma flotante" (floating point).

    La palabra "floating" significa que el punto decimal puede "flotar":
    hay flexibilidad en la cantidad de dígitos antes y después del punto.

    TIPOS FUNDAMENTALES EN C++:
    ---------------------------
    float       -> precisión simple (4 bytes en casi todos los sistemas).
    double      -> precisión doble (8 bytes, el más usado).
    long double -> precisión extendida (8, 12 o 16 bytes, según plataforma).
                   ⚠️ Su tamaño depende del compilador/arquitectura.

    Todos son "signed", es decir, pueden almacenar valores positivos y negativos.

    NORMA IEEE 754:
    ----------------
    En casi todos los sistemas modernos, los floats y doubles siguen el estándar
    IEEE 754, que define cómo se representan en binario.
*/

int main() {
    cout << boolalpha; // imprimirá "true/false" en vez de 1/0

    // ---------------------------------------------------------
    // 1. Compatibilidad IEEE 754
    // ---------------------------------------------------------
    cout << "¿float es IEEE 754? " << numeric_limits<float>::is_iec559 << '\n';
    cout << "¿double es IEEE 754? " << numeric_limits<double>::is_iec559 << '\n';
    cout << "¿long double es IEEE 754? " << numeric_limits<long double>::is_iec559 << '\n';
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 2. Definición de variables floating point
    // ---------------------------------------------------------
    float f = 5.0f;         // sufijo f -> literal tipo float
    double d = 5.0;         // por defecto, un número decimal es double
    long double ld = 5.0L;  // sufijo L -> long double

    cout << "float f = " << f << '\n';
    cout << "double d = " << d << '\n';
    cout << "long double ld = " << ld << '\n';
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 3. Tamaños típicos
    // ---------------------------------------------------------
    cout << "sizeof(float) = " << sizeof(float) << " bytes\n";
    cout << "sizeof(double) = " << sizeof(double) << " bytes\n";
    cout << "sizeof(long double) = " << sizeof(long double) << " bytes\n";
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 4. Impresión de valores y notación científica
    // ---------------------------------------------------------
    cout << 5.0 << '\n';           // imprime "5" (omite el .0 si es entero exacto)
    cout << 6.7f << '\n';          // imprime "6.7"
    cout << 9876543.21 << '\n';    // imprime en notación científica
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 5. Precisión
    // ---------------------------------------------------------
    cout << setprecision(9);  // mostrar hasta 9 dígitos significativos
    float f2 { 123456789.0f }; // tiene 10 dígitos, float solo puede manejar ~7
    cout << "float con 10 dígitos: " << f2 << '\n'; // pérdida de precisión
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 6. Ejemplo clásico: 0.1 en binario
    // ---------------------------------------------------------
    double d2 { 0.1 };
    cout << setprecision(17);
    cout << "0.1 almacenado en double: " << d2 << '\n';
    // En binario, 0.1 no se puede representar exactamente.
    // Se guarda una aproximación -> pequeñas diferencias al imprimir.
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 7. Rounding errors (errores de redondeo)
    // ---------------------------------------------------------
    double d1 { 1.0 };
    double dsum { 0.1 + 0.1 + 0.1 + 0.1 + 0.1 +
                  0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // debería ser 1.0
    cout << "d1 = " << d1 << '\n';
    cout << "dsum (0.1 * 10) = " << dsum << '\n';
    // Veremos que no es exactamente 1.0, sino 0.9999999999999999
    cout << "---------------------------------------------------------\n";

    // ---------------------------------------------------------
    // 8. NaN e Inf
    // ---------------------------------------------------------
    double zero { 0.0 };
    double posinf { 5.0 / zero }; // +inf
    double neginf { -5.0 / zero }; // -inf
    double nan { zero / zero };   // NaN (indefinido)

    cout << "Positivo infinito: " << posinf << '\n';
    cout << "Negativo infinito: " << neginf << '\n';
    cout << "NaN: " << nan << '\n';

    double pzero { 0.0 / posinf };  // +0
    double nzero { -0.0 / posinf }; // -0
    cout << "Cero positivo: " << pzero << '\n';
    cout << "Cero negativo: " << nzero << '\n';
    cout << "---------------------------------------------------------\n";

    /*
        ---------------------------------------------------------
        BEST PRACTICES:
        ---------------------------------------------------------
        1. Prefiere double sobre float:
           - float suele tener demasiada poca precisión (~7 dígitos).
           - double ofrece ~16 dígitos, mucho más seguro.

        2. Usa sufijos correctos en literales:
           5.0   -> double
           5.0f  -> float
           5.0L  -> long double

        3. No asumas que tus números en coma flotante son exactos.
           - Siempre hay errores de redondeo.
           - Comparar floats con "==" casi nunca es buena idea.
             Mejor compara con un margen de tolerancia.

        4. No uses floating point para dinero o cálculos financieros.
           - Usa enteros (ej: representar centavos) o librerías especiales.

        5. Evita depender del comportamiento de long double,
           ya que cambia entre compiladores y plataformas.
    */

    return 0;
}
