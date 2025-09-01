/*
===========================================
        TUTORIAL: The Debugging Process
===========================================

Cuando un programa compila bien pero da un
resultado incorrecto, no se trata de un error
de sintaxis, sino de un **error semántico** o
**lógico**.

El proceso general de depuración consta de 6 pasos:

1. Encontrar la causa raíz del problema.
2. Asegurarse de entender por qué ocurre.
3. Determinar cómo arreglarlo.
4. Aplicar la corrección en el código.
5. Retestar para confirmar que el problema
   se resolvió.
6. Retestar para asegurarse de que no se
   introdujeron nuevos errores.

Ejemplo: función `add` que debería sumar,
pero resta.
===========================================
*/

#include <iostream>

// --------------------------------------
// Paso 1: Código con un bug (función mal definida)
// --------------------------------------
int add(int x, int y) {
    return x - y; // ❌ Error: debería sumar, no restar
}

int main() {
    std::cout << "5 + 3 = " << add(5, 3) << '\n';
    // Esperado: 8
    // Obtenido: 2

    return 0;
}

/*
===========================================
        PROCESO DE DEPURACIÓN
===========================================

🔍 1. Encontrar la causa raíz:
    - La salida incorrecta ocurre en main.
    - La función `add(5, 3)` devuelve 2 en vez de 8.
    - Inputs (5 y 3) son correctos.
    - El error debe estar dentro de la función `add`.
    - Línea sospechosa: `return x - y;`

🤔 2. Entender el problema:
    - La función que debería sumar, está restando.
    - El operador usado es `-` en lugar de `+`.

🛠️ 3. Determinar el arreglo:
    - Cambiar el operador de resta por el de suma.

✏️ 4. Aplicar la corrección:
    int add(int x, int y) {
        return x + y; // ✅ ahora sí suma
    }

🧪 5. Retestar:
    - Ejecutar de nuevo el programa.
    - Salida: "5 + 3 = 8"
    - Resultado correcto.

🔁 6. Retest adicional:
    - Probar con otros valores: `add(10, 7) = 17`.
    - Verificar que no se introdujeron nuevos errores.

===========================================
          BUENAS PRÁCTICAS DE DEPURACIÓN
===========================================

✅ Escribe poco código y pruébalo seguido.
✅ Usa mensajes en consola para verificar entradas y salidas.
✅ Divide el problema: prueba cada función por separado.
✅ Revisa primero las líneas donde se imprime el resultado.
✅ Usa un debugger paso a paso para seguir la ejecución.
✅ Asegúrate de entender el "por qué" del error, no sólo de corregirlo.
✅ Después de reparar, prueba casos adicionales para confirmar.

===========================================
*/
