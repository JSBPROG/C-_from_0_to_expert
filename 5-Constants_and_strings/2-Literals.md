# Literals en C++


---

## Introducción

En programación, un **literal** es un valor escrito directamente en el código fuente.  
Ejemplos:

```cpp
return 5;                     // 5 es un literal entero
bool myNameIsAlex { true };   // true es un literal booleano
double d { 3.4 };             // 3.4 es un literal de punto flotante (double)
std::cout << "Hello, world!"; // "Hello, world!" es un literal de cadena C
```

Los literales son llamados a veces **literal constants** porque **su significado no se puede redefinir**:  
el número `5` siempre significa el entero 5.

---

## El tipo de un literal

Al igual que los objetos tienen tipo, **todos los literales también lo tienen**.  
El compilador deduce el tipo a partir del valor.

- `5` → `int`  
- `true` → `bool`  
- `3.4` → `double`  
- `'a'` → `char`  
- `"Hello"` → `const char[6]` (5 letras + terminador nulo `null`)

### Tabla de literales por defecto

| Literal               | Ejemplo           | Tipo por defecto      | Nota                                    |
|-----------------------|------------------|----------------------|----------------------------------------|
| Entero                | `5`, `0`, `-3`  | `int`                | Puede convertirse a otros tipos         |
| Booleano              | `true`, `false` | `bool`               |                                        |
| Punto flotante        | `1.2`, `0.0`    | `double`             | **No float** por defecto                |
| Carácter              | `'a'`, `'
'`   | `char`               | Literal de un solo carácter             |
| Cadena C              | `"Hello"`       | `const char[n]`      | Incluye terminador nulo |


---

## Literal Suffixes

Si el tipo por defecto no es el deseado, se le puede agregar un **sufijo**.

| Tipo                 | Sufijo       | Ejemplo     | Resultado                 |
|----------------------|-------------|-------------|---------------------------|
| Entero sin signo     | `u` / `U`  | `5u`        | `unsigned int`           |
| Long                 | `l` / `L`  | `5L`        | `long`                   |
| Long long            | `ll` / `LL`| `5LL`       | `long long`              |
| Unsigned long long   | `ull` / ...| `5ULL`      | `unsigned long long`     |
| Float                | `f` / `F`  | `5.0f`      | `float`                  |
| Long double          | `l` / `L`  | `5.0L`      | `long double`            |
| String               | `s`        | `"hi"s`     | `std::string`            |
| String view          | `sv`       | `"hi"sv`    | `std::string_view`       |

⚠️ Casos especiales:  
- `s` y `sv` **deben ser minúsculas**.  
- `ll` o `LL` deben estar en la misma mayúscula/minúscula (no `lL`).  

**Best practice:** usar **`L` mayúscula** en vez de `l` (minúscula puede confundirse con `1`).  

---

## Ejemplos de literales integrales

```cpp
#include <iostream>
int main() {
    std::cout << 5   << '\n'; // int
    std::cout << 5L  << '\n'; // long
    std::cout << 5u  << '\n'; // unsigned int
}
```

En la práctica, el compilador convierte `int` → otro tipo si hace falta:

```cpp
int a { 5 };          // ok, int
unsigned int b { 6 }; // el compilador convierte 6 (int) → unsigned int
long c { 7 };         // convierte 7 (int) → long
```

---

## Literales de punto flotante

Por defecto, los literales de coma flotante son `double`.  

```cpp
std::cout << 5.0  << '\n'; // double
std::cout << 5.0f << '\n'; // float
```

⚠️ Error común:

```cpp
float f { 4.1 }; // warning: 4.1 es double, no float
```

Soluciones:

```cpp
float f { 4.1f }; // usar sufijo f
double d { 4.1 }; // usar double
```

---

## Notación científica

C++ soporta **notación estándar** y **científica**:

```cpp
double pi { 3.14159 };    // estándar
double avogadro { 6.02e23 }; // 6.02 × 10^23
double charge { 1.6e-19 };   // 1.6 × 10^-19
```

---

## Literales de cadena

```cpp
#include <iostream>
int main() {
    std::cout << "Hello, world!"; // string literal
}
```

Características:  
1. Siempre terminan con `\0` → `"hello"` ocupa 6 chars.  
2. Son **const objects** creados al inicio del programa y viven hasta el final.  
3. Tipo: `const char[n]`.  

Ejemplo:  

```cpp
const char* s = "hello"; // apunta a memoria estática con "hello\0"
```

---

## Magic Numbers

Un **magic number** es un literal usado sin contexto.

Ejemplo malo:

```cpp
const int maxStudentsPerSchool { numClassrooms * 30 };
setMax(30); // ¿qué significa este 30?
```

Ejemplo bueno:

```cpp
const int maxStudentsPerClass { 30 };
const int totalStudents{ numClassrooms * maxStudentsPerClass };

const int maxNameLength{ 30 };
setMax(maxNameLength);
```

### Cuándo **NO** es mágico
- Valores obvios (`-1, 0, 1, 1000 en conversiones`).
- IDs secuenciales (`player1, player2`).

**Best practice:**  
Evitar números mágicos → usar `const` o `constexpr` con nombres descriptivos.

---

## Conclusión

- Los **literals** son valores directos en el código.  
- Siempre tienen un tipo deducido.  
- Usar **sufijos** cuando se necesita otro tipo.  
- Evitar **magic numbers** → preferir constantes con nombres claros.  
- Para cadenas, recordar que los **C-style strings** terminan en `\0`.  

---
