# A strategy for debugging  


---

Cuando depuramos un programa, la mayor parte del tiempo no se gasta corrigiendo el bug, sino **encontrando dónde está**. Una vez localizado, repararlo suele ser trivial.  

En esta lección veremos cómo encontrar errores.

---

## 1. Encontrar problemas inspeccionando el código

En programas pequeños, muchas veces podemos adivinar dónde está el bug simplemente mirando el código.  

Ejemplo:  

```cpp
int main()
{
    getNames();   // pedir al usuario una lista de nombres
    sortNames();  // ordenarlos alfabéticamente
    printNames(); // imprimirlos

    return 0;
}
```

Si en vez de ordenarlos de forma alfabética los imprime en orden inverso, lo más probable es que el error esté en `sortNames()`.  
Con programas pequeños esto es sencillo.  

Pero, a medida que los programas crecen:  
- Hay más líneas que revisar.  
- El código se vuelve más complejo.  
- Puede que la salida no dé pistas claras de dónde falla.  
- Los bugs pueden estar basados en **malas suposiciones** (más difíciles de detectar visualmente).  

En esos casos necesitamos otra estrategia.

---

## 2. Encontrar problemas ejecutando el programa

Si no podemos detectar el bug inspeccionando el código, podemos **observar el comportamiento en ejecución** y deducir dónde falla.  

La estrategia general es:  
1. **Reproducir el problema.**  
2. **Ejecutar el programa y recoger información** que ayude a reducir el rango del error.  
3. **Repetir el proceso** hasta aislar la causa.  

---

### 2.1 Reproducir el problema  

Reproducir el problema significa lograr que ocurra de manera **consistente**.  
- Si el problema aparece siempre en el mismo punto → es fácil.  
- Si ocurre sólo bajo ciertas condiciones (en ciertas computadoras, con cierta entrada, etc.), hay que definir **pasos de reproducción**.  

👉 Cuanto más reproducible sea un bug, más fácil será diagnosticarlo.  

Ejemplo:  

```cpp
#include <iostream>

int main()
{
    int a = 10;
    int b = 0;
    std::cout << a / b << std::endl; // el programa siempre falla aquí (división por cero)
    return 0;
}
```

En este caso, el bug es **100% reproducible**.

---

### 2.2 Aislar el problema: la analogía del juego **hi-lo**

Imagina el juego de adivinar un número entre 1 y 10:  

- Tú dices: `5`  
- Respuesta: "Muy bajo"  
- Tú dices: `8`  
- Respuesta: "Muy alto"  
- Tú dices: `7`  
- Respuesta: "Correcto"  

En pocas pruebas llegas al número.  

🔍 En depuración, usamos una estrategia similar:  
- **Si el problema no ha aparecido todavía en cierta parte del programa → está más adelante.**  
- **Si el problema ya aparece en cierta parte → está antes.**  

Ejemplo práctico:  

```cpp
#include <iostream>

int main()
{
    int x = 5;
    int y = 3;
    int resultado = x - y; // debería ser suma, pero usamos el operador equivocado

    std::cout << "DEBUG: x = " << x << ", y = " << y << std::endl;
    std::cout << "DEBUG: resultado = " << resultado << std::endl;

    std::cout << "5 + 3 = " << resultado << std::endl;

    return 0;
}
```

Salida:  

```
DEBUG: x = 5, y = 3
DEBUG: resultado = 2
5 + 3 = 2
```

Gracias a los `DEBUG prints`, podemos ver que el problema ocurre **en la operación matemática antes de imprimir el resultado**.  

---

## 3. Conclusiones y buenas prácticas  

- **Empieza reproduciendo el problema.**  
- **Divide y conquista:** acota poco a poco dónde ocurre el bug.  
- **Usa prints de depuración (`std::cout`) o un depurador integrado.**  
- **Elimina partes del código** de la búsqueda cuando confirmes que no influyen.  
- **No confíes en tus suposiciones iniciales:** el bug puede estar donde menos lo esperes.  
- **La experiencia mejora la intuición:** con la práctica serás más rápido encontrando dónde mirar.  

---


