#include <iostream>   // Para std::cout y std::endl
#include <iomanip>    // Para std::hex y std::showbase
#include <typeinfo>   // Para typeid().name()
using namespace std;

/*
--------------------------------------------------------
INTRODUCTION TO FUNDAMENTAL DATA TYPES
--------------------------------------------------------
Este programa muestra ejemplos de:
1. Bits, bytes y direcciones de memoria
2. Cómo se almacenan los datos
3. Los tipos de datos fundamentales de C++
4. Diferencia entre "integer" e "integral"
*/

int main() {
    // -------------------------------------------------
    // 1. BITS, BYTES Y DIRECCIONES DE MEMORIA
    // -------------------------------------------------
    cout << "1. Bits, Bytes y Direcciones de Memoria\n";
    int a = 65; // ejemplo de número entero
    cout << "Valor de a: " << a << endl;
    cout << "Direccion de memoria de a: " << &a << endl;
    cout << "Sizeof(a) (bytes usados): " << sizeof(a) << " bytes\n";
    cout << "Un byte equivale a 8 bits -> "
         << (sizeof(a) * 8) << " bits en total.\n\n";

    // -------------------------------------------------
    // 2. TIPOS FUNDAMENTALES: enteros
    // -------------------------------------------------
    cout << "2. Tipos Fundamentales (Integer)\n";
    short s = 32000;   // tipo entero corto
    int i = -100;      // entero estándar
    long l = 1000000;  // entero largo
    long long ll = 1000000000LL; // entero muy largo

    cout << "short: " << s << " ocupa " << sizeof(s) << " bytes\n";
    cout << "int: " << i << " ocupa " << sizeof(i) << " bytes\n";
    cout << "long: " << l << " ocupa " << sizeof(l) << " bytes\n";
    cout << "long long: " << ll << " ocupa " << sizeof(ll) << " bytes\n\n";

    // -------------------------------------------------
    // 3. TIPOS FUNDAMENTALES: punto flotante
    // -------------------------------------------------
    cout << "3. Tipos Fundamentales (Floating Point)\n";
    float f = 3.14159f;
    double d = 2.718281828;
    long double ld = 1.6180339887L;

    cout << "float: " << f << " ocupa " << sizeof(f) << " bytes\n";
    cout << "double: " << d << " ocupa " << sizeof(d) << " bytes\n";
    cout << "long double: " << ld << " ocupa " << sizeof(ld) << " bytes\n\n";

    // -------------------------------------------------
    // 4. TIPOS FUNDAMENTALES: caracteres
    // -------------------------------------------------
    cout << "4. Tipos Fundamentales (Character)\n";
    char c = 'A';
    wchar_t wc = L'Ω';     // caracter Unicode ancho
    char16_t c16 = u'あ';  // caracter japonés
    char32_t c32 = U'𐍈';  // caracter fuera del BMP

    cout << "char: " << c << " ocupa " << sizeof(c) << " bytes\n";
    cout << "wchar_t: " << wc << " ocupa " << sizeof(wc) << " bytes\n";
    cout << "char16_t ocupa " << sizeof(c16) << " bytes\n";
    cout << "char32_t ocupa " << sizeof(c32) << " bytes\n\n";

    // -------------------------------------------------
    // 5. BOOLEANO
    // -------------------------------------------------
    cout << "5. Boolean\n";
    bool flag = true;
    cout << "bool: " << flag << " ocupa " << sizeof(flag) << " byte\n\n";

    // -------------------------------------------------
    // 6. VOID y nullptr
    // -------------------------------------------------

    /*
    - Un puntero es una variable que almacena la dirección de memoria de otra variable.
    - A veces, queremos inicializar un puntero pero no apuntarlo a nada válido aún.
    - En C++ moderno, usamos "nullptr" para indicar que el puntero no apunta a ningún objeto.
    - Antes de C++11 se usaba NULL o 0, lo cual podía causar ambigüedades.
    
    */
    cout << "6. Void y nullptr\n";
    int* ptr = nullptr; // puntero nulo
    cout << "nullptr es usado para representar un puntero nulo.\n";
    cout << "Direccion almacenada en ptr: " << ptr << "\n\n";

    // -------------------------------------------------
    // 7. INTEGER vs INTEGRAL
    // -------------------------------------------------
    cout << "7. Integer vs Integral\n";
    int x = 42;     // tipo integer
    bool b = true;  // tipo integral pero NO integer
    char letter = 'c'; // tipo integral pero NO integer

    cout << "int (integer): " << x << endl;
    cout << "bool (integral, NO integer): " << b << endl;
    cout << "char (integral, NO integer): " << letter << endl;
    cout << "sizeof(bool): " << sizeof(b) << " byte\n";
    cout << "sizeof(char): " << sizeof(letter) << " byte\n\n";

    // -------------------------------------------------
    // 8. RESUMEN
    // -------------------------------------------------
    cout << "Resumen:\n";
    cout << "- Todos los datos en C++ se almacenan en bits dentro de bytes.\n";
    cout << "- Los tipos fundamentales permiten representar enteros, flotantes, caracteres, booleanos y punteros nulos.\n";
    cout << "- 'Integer' son solo short, int, long, long long.\n";
    cout << "- 'Integral' incluye integer + bool + char y variantes.\n";

    return 0;
}
