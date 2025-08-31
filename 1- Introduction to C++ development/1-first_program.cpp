#include <iostream>                 //Biblioteca de entrada/salida

int main()                          //Solo podrá haber una función main en un programa en C++, nos va a retornar un 0, por eso es de tipo int
{
	std::cout << "Hello, world!";
	return 0;                       //El 0 indica que todo ha ido bien
}

/*
#include <iostream>
Esta línea le dice al compilador:
“Voy a usar funciones para entrada y salida en consola (como imprimir en pantalla), así que necesito la librería que las contiene.”

iostream significa Input/Output Stream (flujo de entrada/salida).

2. int main()
Aquí empieza el programa principal.

main es la función que se ejecuta primero en cualquier programa en C++.

int significa que la función va a devolver un número entero al terminar (en este caso, el código de salida).

3. { ... }
Las llaves indican el bloque de código que pertenece a la función main.

Todo lo que está dentro es lo que se ejecutará.

4. std::cout << "Hello, world!";
Esto imprime el texto "Hello, world!" en la pantalla.

std:: indica que estamos usando el espacio de nombres estándar (Standard).

cout significa character output (salida de caracteres), es como decir “escribe en pantalla”.

<< es el operador de inserción, sirve para “enviar” cosas a la salida (la pantalla).

"Hello, world!" es la cadena de texto que se mostrará.

5. return 0;
Esto devuelve el valor 0 al sistema operativo cuando el programa termina.

0 significa que todo salió bien (sin errores).


*/