# Palabras Reservadas en C++ (Keywords)

C++ tiene 92 palabras reservadas (según C++23). Estas palabras tienen un significado especial y **no pueden usarse como identificadores**.

## Lista completa con explicación

### `alignas`
Especifica el alineamiento de una variable o estructura.

### `alignof`
Devuelve el requisito de alineamiento de un tipo.

### `and`
Operador lógico AND (equivalente a &&).

### `and_eq`
Operador AND compuesto (equivalente a &=).

### `asm`
Permite insertar código ensamblador (no estándar moderno).

### `auto`
Deducción automática del tipo de variable.

### `bitand`
Operador bit a bit AND (equivalente a &).

### `bitor`
Operador bit a bit OR (equivalente a |).

### `bool`
Tipo de dato booleano (true/false).

### `break`
Termina un bucle o switch.

### `case`
Etiqueta de un switch para comparar valores.

### `catch`
Captura excepciones en un bloque try.

### `char`
Tipo de carácter (normalmente 1 byte).

### `char8_t`
Tipo para UTF-8 (desde C++20).

### `char16_t`
Tipo para UTF-16.

### `char32_t`
Tipo para UTF-32.

### `class`
Define una clase.

### `compl`
Operador bit a bit NOT (equivalente a ~).

### `concept`
Define conceptos para templates (C++20).

### `const`
Especifica que un valor no puede cambiar.

### `consteval`
Evalúa una expresión en tiempo de compilación (C++20).

### `constexpr`
Evalúa en tiempo de compilación si es posible.

### `constinit`
Inicialización constante en tiempo de compilación (C++20).

### `const_cast`
Convierte punteros/referencias eliminando const.

### `continue`
Salta a la siguiente iteración del bucle.

### `co_await`
Operador para corrutinas (C++20).

### `co_return`
Devuelve desde una corrutina.

### `co_yield`
Produce un valor desde una corrutina.

### `decltype`
Devuelve el tipo de una expresión.

### `default`
Valor por defecto en switch o constructor.

### `delete`
Libera memoria reservada con new.

### `do`
Inicia un bucle do-while.

### `double`
Tipo de número en coma flotante (doble precisión).

### `dynamic_cast`
Convierte punteros con verificación en tiempo de ejecución.

### `else`
Bloque alternativo en un if.

### `enum`
Define un conjunto de valores constantes.

### `explicit`
Evita conversiones implícitas de constructores.

### `export`
Permite exportar templates (raro en práctica).

### `extern`
Declara una variable definida en otro fichero.

### `false`
Valor booleano falso.

### `float`
Número en coma flotante (precisión simple).

### `for`
Bucle for.

### `friend`
Permite acceso a miembros privados desde otra clase.

### `goto`
Salta a una etiqueta (NO recomendado).

### `if`
Condicional if.

### `inline`
Sugerencia para expandir funciones inline.

### `int`
Tipo entero.

### `long`
Tipo entero largo.

### `mutable`
Permite modificar miembros incluso si son const.

### `namespace`
Agrupa identificadores bajo un nombre.

### `new`
Reserva memoria dinámica.

### `noexcept`
Especifica que una función no lanza excepciones.

### `not`
Operador lógico NOT (equivalente a !).

### `not_eq`
Operador distinto (equivalente a !=).

### `nullptr`
Puntero nulo seguro.

### `operator`
Permite sobrecargar operadores.

### `or`
Operador OR lógico (equivalente a ||).

### `or_eq`
Operador OR compuesto (equivalente a |=).

### `private`
Acceso privado en clases.

### `protected`
Acceso protegido en clases.

### `public`
Acceso público en clases.

### `register`
Sugerencia para almacenar en registros (obsoleto).

### `reinterpret_cast`
Conversión forzada entre punteros.

### `requires`
Restricciones en templates (C++20).

### `return`
Devuelve un valor desde una función.

### `short`
Tipo entero corto.

### `signed`
Especifica tipo con signo.

### `sizeof`
Devuelve el tamaño en bytes de un objeto/tipo.

### `static`
Variable o función con almacenamiento estático.

### `static_assert`
Aserción en tiempo de compilación.

### `static_cast`
Conversión segura entre tipos relacionados.

### `struct`
Define una estructura.

### `switch`
Estructura condicional múltiple.

### `template`
Define plantillas (genéricos).

### `this`
Puntero al objeto actual.

### `thread_local`
Variable con almacenamiento por hilo.

### `throw`
Lanza una excepción.

### `true`
Valor booleano verdadero.

### `try`
Bloque para capturar excepciones.

### `typedef`
Crea un alias de tipo (antiguo).

### `typeid`
Devuelve información sobre el tipo en tiempo de ejecución.

### `typename`
Indica que un nombre es un tipo (en templates).

### `union`
Estructura que comparte memoria entre miembros.

### `unsigned`
Tipo sin signo.

### `using`
Alias de tipo o directiva de namespace.

### `virtual`
Indica método virtual para polimorfismo.

### `void`
Indica ausencia de valor de retorno.

### `volatile`
Evita optimizaciones en variables que pueden cambiar fuera del control del programa.

### `wchar_t`
Tipo para caracteres anchos.

### `while`
Bucle while.

### `xor`
Operador XOR lógico (equivalente a ^).

### `xor_eq`
Operador XOR compuesto (equivalente a ^=).




# Identifier naming rules

## ¿Qué es un identificador?
El nombre de una variable (o función, tipo u otro elemento) se llama **identificador**.  
C++ ofrece flexibilidad para nombrarlos, pero existen **reglas obligatorias** y **buenas prácticas recomendadas**.

---

## Reglas para nombrar identificadores

1. **No puede ser una palabra clave (keyword)**  
   - Ejemplo: `int`, `class`, `return` no pueden usarse como identificadores.

2. **Solo puede contener:**  
   - Letras (mayúsculas o minúsculas)  
   - Números  
   - El carácter de subrayado (`_`)  

   ❌ No se permiten otros símbolos ni espacios en blanco.

3. **Debe comenzar con:**  
   - Una letra (mayúscula o minúscula)  
   - O un guion bajo (`_`)  

   ❌ No puede comenzar con un número.

4. **C++ es sensible a mayúsculas y minúsculas (case-sensitive)**  
   - `nvalue`, `nValue` y `NVALUE` son **nombres diferentes**.

---

## Buenas prácticas para nombrar identificadores

✔ Es **convencional** que los nombres de variables comiencen con **minúscula**.  

### Ejemplos correctos y convencionales
```cpp
int value;    // correcto y convencional
```

### Ejemplos NO convencionales
```cpp
int Value;    // NO convencional (empieza con mayúscula)
int VALUE;    // NO convencional (todo en mayúsculas)
int VaLuE;    // NO convencional (pide ayuda psicológica) ;)
```

---

## Nombres de funciones
- Por convención, los nombres de funciones también **empiezan en minúscula**.
- Ejemplo:  
  - `main()` (obligatoria en todo programa C++)  
  - Funciones estándar de la librería también siguen esta convención.
