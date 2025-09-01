# Cómo diseñar tus primeros programas

## Idea principal
Antes de escribir código, **diseña tu programa**.  
La programación es como la arquitectura: sin un plan, el resultado tendrá muchos errores y será difícil de mantener.  
Un poco de planeación inicial **ahorra tiempo y frustración**.

---

## Pasos de diseño

### 1. Define tu objetivo
- Escribe lo que quieres lograr en **1 o 2 frases**.  
- Mejor expresado como un **resultado para el usuario**.  

**Ejemplos**:
- Permitir al usuario organizar una lista de contactos.
- Generar un mapa de mazmorras.
- Calcular el tiempo de caída de un objeto.

---

### 2. Define requisitos
Son las **condiciones y capacidades** que debe cumplir el programa.  
Se centran en el **qué**, no en el **cómo**.

**Ejemplos**:
- Guardar números para usarlos después.
- Producir resultados en menos de 10s.
- Tener menos de 0.1% de fallas.

---

### 3. Define herramientas, objetivos y respaldo
- ¿En qué sistema/arquitectura correrá?
- ¿Qué IDE o lenguaje usarás?
- ¿Trabajarás solo o en equipo?
- **Respaldo del código**:
  - Copia en nube (Dropbox, GitHub).
  - Uso de sistemas de control de versiones (Git).

---

### 4. Divide problemas complejos en simples
- Método **top-down**: dividir un problema grande en subproblemas.  
- Método **bottom-up**: agrupar tareas pequeñas para formar el todo.

**Ejemplo (limpiar la casa):**
```
Limpiar la casa
 ├── Aspirar alfombra
 ├── Limpiar baños
 │    ├── Lavar lavabo
 │    └── Fregar inodoro
 └── Limpiar cocina
      ├── Limpiar encimeras
      └── Sacar la basura
```

---

### 5. Define la secuencia de eventos
Ordena las tareas.  
Ejemplo de **calculadora**:
1. Obtener primer número.
2. Obtener operación.
3. Obtener segundo número.
4. Calcular.
5. Mostrar resultado.

---

## Implementación

### Paso 1: Esquema de `main`
Escribe la estructura general como un **borrador**:
```cpp
int main()
{
    // getUserInput();
    // getMathematicalOperation();
    // calculateResult();
    // printResult();

    return 0;
}
```

---

### Paso 2: Implementar funciones
1. Define el prototipo.
2. Escribe la función.
3. **Prueba** la función antes de seguir.

Ejemplo:
```cpp
#include <iostream>

int getUserInput()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    return input;
}

int main()
{
    int value{ getUserInput() };
    std::cout << value << '\n'; // prueba
    return 0;
}
```

---

### Paso 3: Prueba final
Cuando termines, prueba el programa completo.  
Si algo falla, corrígelo y repite.

---

## Consejos clave

| Consejo | Explicación |
|---------|-------------|
| Manténlo simple | No empieces con proyectos enormes. |
| Agrega características de a poco | Ve incrementando complejidad paso a paso. |
| Una cosa a la vez | Mejor 1 tarea bien hecha que 6 a medias. |
| Prueba mientras codificas | Evita acumular cientos de errores. |
| No busques perfección al inicio | El código inicial siempre evoluciona. |
| Optimiza para mantenimiento, no rendimiento | Es más importante que tu código sea claro y fácil de mejorar. |

---

## Conclusión
- **El diseño previo es fundamental** para ahorrar errores y tiempo.  
- Divide, organiza y prueba paso a paso.  
- Programas complejos surgen de programas simples que funcionan bien.

> “Un sistema complejo que funciona siempre proviene de un sistema simple que funcionaba.”  
> —John Gall
