# Tácticas básicas de depuración


---

## 1. Comentar partes del código
- Si el programa falla, comenta fragmentos para reducir el área de búsqueda.
- Tres resultados posibles:
  1. **El error desaparece** → el código comentado era culpable.
  2. **El error no cambia** → ese código no era el problema.
  3. **El error cambia o surge otro** → el código comentado es necesario, vuelve a activarlo.

**Advertencia:** recuerda descomentar lo que probaste. El uso de control de versiones ayuda a revertir cambios.

**Tip:** existen librerías como `dbg` que permiten dejar sentencias de depuración sin afectar el modo release.

---

## 2. Validar el flujo del código
- Problemas comunes: funciones llamadas de más, de menos o nunca.
- Agrega mensajes al inicio de cada función para verificar su ejecución.
- Usa `std::cerr` en lugar de `std::cout` porque no está bufferizado, lo que asegura que los mensajes aparezcan incluso si el programa falla justo después.

Ejemplo: olvidar los paréntesis al llamar a una función:
```cpp
std::cout << getValue;   // Incorrecto
std::cout << getValue(); // Correcto
```

---

## 3. Imprimir valores
- Algunos errores provienen de cálculos o argumentos incorrectos.
- Imprime valores de variables y parámetros en puntos críticos.

### Ejemplo 1
Error: pasar un literal en vez de una variable.
```cpp
int z{ add(x, 5) }; // debería ser add(x, y)
```

### Ejemplo 2
Error: devolver `--x` en vez de `x`.
```cpp
return --x; // incorrecto
return x;   // correcto
```
La depuración paso a paso mostró dónde se alteraba el valor.

---

## Desventajas de depurar con impresiones
- Ensucia el código y la salida del programa.
- Requiere reescribir y recompilar para cada prueba.
- Puede introducir nuevos errores si no se elimina correctamente.
