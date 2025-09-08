#include <iostream>
#include <string> // std::string y std::getline

int main() {
    // -------------------------------
    // 1. Creación e inicialización de std::string
    // -------------------------------
    std::string empty{};              // cadena vacía
    std::string name{"Alex"};         // inicialización con literal C-style
    name = "John";                    // reasignación

    std::string numericString{"45"};  // "45" como texto, no como número

    // -------------------------------
    // 2. Entrada de texto segura
    // -------------------------------
    std::cout << "Enter your full name: ";
    std::string fullName{};
    std::getline(std::cin >> std::ws, fullName); // std::ws ignora espacios iniciales

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    // -------------------------------
    // 3. Longitud de std::string
    // -------------------------------
    // std::string::length() devuelve size_t (unsigned)
    int nameLength = static_cast<int>(fullName.length()); 
    int total = age + nameLength;

    std::cout << "Your age + length of name is: " << total << '\n';

    // -------------------------------
    // 4. Concatenación y manipulación
    // -------------------------------
    std::string greeting = "Hello, " + fullName + "!"; 
    std::cout << greeting << '\n';

    // -------------------------------
    // 5. Literales de std::string
    // -------------------------------
    using namespace std::string_literals; // habilita sufijo "s"
    std::string sLiteral = "Welcome"s;
    std::cout << sLiteral << ", " << fullName << "!\n";

    // -------------------------------
    // 6. Notas teóricas y comportamiento
    // -------------------------------
    // - std::string gestiona memoria dinámicamente.
    // - Puede crecer o reducirse según la longitud del texto.
    // - Es null-terminated (C++11 en adelante), pero length() no cuenta el '\0'.
    // - Inicializar una std::string copia el literal, operación costosa.
    // - Pasar std::string por valor a funciones es costoso (usar std::string_view si es posible).
    // - Devuelve std::string por valor está bien para objetos locales o temporales (aprovecha move semantics).
    // - constexpr std::string no se soporta hasta C++20/23; usar std::string_view para constantes en tiempo de compilación.

    return 0;
}



/*
🔑 ---------------Teoría y conceptos clave
std::string vs C-style strings

std::string es seguro y flexible.

Permite asignación, concatenación y manejo dinámico de memoria.

Evita problemas como buffer overflow de los C-style strings.

-----------------------Entrada de texto

std::cin >> str se detiene en espacios.

std::getline(std::cin >> std::ws, str) lee toda la línea y omite espacios iniciales.

-------------------------Longitud de la cadena

str.length() devuelve size_t (unsigned).

Convierte a signed si necesitas hacer cálculos con enteros: static_cast<int>(str.length()).

-----------------------------------Literales std::string

"text"s crea un objeto std::string.

Requiere using namespace std::string_literals.

------------------------------------Memoria y eficiencia

Cada inicialización copia la cadena: operación costosa.

No pases std::string por valor a funciones.

Devuelve std::string por valor solo si es un objeto local o temporal.

-------------------------------------Constexpr

No se puede usar constexpr std::string en C++17.

Para constantes en tiempo de compilación, usa std::string_view.

------------------✅ Buenas prácticas--------------------------------
Usa std::string en lugar de C-style strings siempre que sea posible.

Para entrada de líneas completas, usa std::getline(std::cin >> std::ws, str).

No pases std::string por valor; usa referencia (const std::string&) o std::string_view.

Usa static_cast<int>(str.length()) si necesitas un valor signed.

Prefiere literales "text"s cuando necesites un std::string temporal.

Para constantes en tiempo de compilación, usa std::string_view en vez de std::string.

*/