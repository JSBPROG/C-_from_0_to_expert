#include <iostream>


int add(int x, int y); //Está definido en functions.cpp, pero para evitar errores de compilación, hacemos esta forward definition. (sería la importación)



int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}



/*Hay que hacer:

g++ main.cpp functions.cpp -o myProgram


de esta forma se compilan ambos archivos y se genera un .exe con ambos archivos, y se ejecuta el .exe

NO hay que incluir, en proyectos grandes, el .cpp en el otro .cpp, sino que se hace la forward declaration (declaración adelantada) en el .cpp que lo necesita.
*/