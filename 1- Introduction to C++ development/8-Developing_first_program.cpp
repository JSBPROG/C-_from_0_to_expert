#include <iostream>

/*Primero: crear una función de multiplicar por 2, siguiendo clean code*/

int doblar_numero() 
{
    int numero;
    std::cout << "Introduce un ENTERO: "; 
    std::cin >> numero;                   
    int resultado = numero * 2;
    return resultado;
}
void mostrar_resultado(int resultado)
{
    std::cout << "Tu numero doblado es " << resultado;
}


/*EJECUCIÓN*/
int main()
{
    int resultado = doblar_numero();
    mostrar_resultado(resultado);
    return 0;
}


/*-----------BUENAS PRÁCTICAS (CLEAN CODE en funciones)------------*/

/*
   8]

## Principios Clean Code para funciones

- Cada función debe tener **una única responsabilidad clara**, cumplir una sola tarea bien definida (Principio de Responsabilidad Única).[2][1]
- Las funciones deben ser **pequeñas** y lo más simples posibles, evitando complejidad innecesaria o funciones que hagan "demasiadas cosas".[8][2]
- Los nombres de funciones deben ser **descriptivos y claros**, expresando exactamente qué hacen, para que el código sea legible sin necesitar comentarios extensos.[4][2]
- Evitar que las funciones tengan efectos secundarios inesperados; deben hacer sólo lo que su nombre promete (principio de transparencia).[1]
- Mantener un **número pequeño de parámetros**, idealmente uno o ninguno; si una función necesita demasiados parámetros, suele ser señal de que hace más de una tarea o que la estructura de datos puede mejorarse.[1]
- Facilitar que las funciones sean **fáciles de probar**, evitando dependencias externas complicadas e incorporando un diseño modular.[4]
- Los comentarios en funciones deben ser mínimos y usados solo para explicar "por qué" algo se hace, no "qué" hace la función (que debe ser evidente por su nombre y su código).[2]
- Eliminar funciones innecesarias o código muerto para evitar confusión.[4]
- Aplicar consistentemente patrones de diseño y estilo para que todas las funciones sean **predecibles** y fáciles de entender.[1]

Estos puntos ayudan a que las funciones sean limpias, legibles, modulares y mantenibles, facilitando el desarrollo y la colaboración.[2][4][1]

[1](https://www.ionos.es/digitalguide/paginas-web/desarrollo-web/clean-code-que-es-el-codigo-limpio/)
[2](https://www.ebiseducation.com/clean-code-que-es-ejemplos)
[3](https://tecnoin.solutions/clean-code-principios-ventajas-ejemplos/)
[4](https://www.trainingit.es/clean-code-principios-ventajas-ejemplos/)
[5](https://www.viewnext.com/clean-code-que-es-y-por-donde-empezar/)
[6](https://www.youtube.com/watch?v=IP07g8KycRs)
[7](https://adictosaltrabajo.com/2011/09/30/clean-code-reglas-principios/)
[8](https://www.in-com.com/es/blog/how-clean-code-principles-transform-your-programming-experience/)




*/