#include <iostream>
#include <string> // Necesario para std::string

int main()
{
    // ====================================================================
    // 1. La librería de Entrada/Salida (iostream)
    // ====================================================================

    // Para usar std::cout, std::cin, etc., se debe incluir la cabecera iostream.
    // std::cout: "character output", envía datos a la consola.
    // std::cin: "character input", lee datos del teclado.
    // El operador de inserción '<<' envía datos *a* std::cout.
    // El operador de extracción '>>' obtiene datos *de* std::cin.
    
    // std::cout puede imprimir texto, números y variables.
    std::cout << "Hola mundo!\n";
    std::cout << "El número es: " << 42 << '\n';
    
    // std::endl vs '\n'
    // std::endl genera una nueva línea y *vacía el búfer de salida* (es más lento).
    // '\n' solo genera una nueva línea (es más rápido y preferido).
    // El búfer es un área de memoria donde se almacenan los datos antes de ser enviados.
    
    std::cout << "Hola" << std::endl; // Usa std::endl (vacía el búfer)
    std::cout << "Mundo" << '\n';     // Usa '\n' (más eficiente)

    // ====================================================================
    // 2. Uso de std::cin para entrada del usuario
    // ====================================================================
    
    int x; // Variable para almacenar la entrada
    std::cout << "Introduce un número: ";
    std::cin >> x; // Espera a que el usuario introduzca un número y lo almacena en x
    
    std::cout << "Introdujiste: " << x << '\n';

    // Se pueden leer múltiples valores en una sola línea
    int y, z;
    std::cout << "Introduce dos números (separados por un espacio): ";
    std::cin >> y >> z;
    std::cout << "Introdujiste: " << y << " y " << z << '\n';

    return 0;
}