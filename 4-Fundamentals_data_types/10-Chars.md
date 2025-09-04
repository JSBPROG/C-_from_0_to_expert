# Chars en C++

Hasta este punto, los tipos de datos fundamentales que hemos visto sirven para almacenar **números** (enteros y de punto flotante) o **valores booleanos** (verdadero/falso).  
Pero, ¿qué pasa si queremos almacenar **letras o signos de puntuación**?

Ejemplo inicial:

```cpp
#include <iostream>

int main()
{
    std::cout << "Would you like a burrito? (y/n)";

    // Queremos que el usuario introduzca 'y' o 'n'

    return 0;
}
```

El tipo de dato **`char`** fue diseñado para **guardar un único carácter** (una letra, número, símbolo o espacio en blanco).  
Internamente, un `char` es un número entero que representa un código **ASCII**.

---

## ASCII

ASCII significa *American Standard Code for Information Interchange*.  
Mapea los caracteres ingleses y algunos símbolos a números entre **0 y 127**.

Ejemplo:  
- Código `97` → `'a'`  
- Código `65` → `'A'`

### Literales de caracteres
- Siempre van entre comillas simples: `'g'`, `'1'`, `' '`.  
- Ejemplo de inicialización:

```cpp
char ch1{ 'a' }; // inicializa con 'a' (código 97, preferido)
char ch2{ 97 };  // inicializa con entero 97 (equivale a 'a', no preferido)
```

⚠️ Cuidado: `'5'` no es lo mismo que `5`.  
- `'5'` → código ASCII 53  
- `5` → valor numérico 5

---

## Tabla ASCII

| Código | Símbolo | Código | Símbolo | Código | Símbolo | Código | Símbolo |
|--------|---------|--------|---------|--------|---------|--------|---------|
| 0      | NUL     | 32     | (esp)  | 64     | @       | 96     | `       |
| 1      | SOH     | 33     | !      | 65     | A       | 97     | a       |
| ...    | ...     | ...    | ...    | ...    | ...     | ...    | ...     |
| 31     | US      | 63     | ?      | 95     | _       | 127    | DEL     |

- Códigos **0-31 y 127** → *no imprimibles* (control de dispositivos, hoy obsoletos).  
- Códigos **32-126** → caracteres imprimibles.

---

## Imprimir `char`

```cpp
#include <iostream>

int main()
{
    char ch1{ 'a' };
    std::cout << ch1; // imprime 'a'

    char ch2{ 98 };
    std::cout << ch2; // imprime 'b'

    return 0;
}
```

Salida:
```
ab
```

También se pueden imprimir literales directamente:

```cpp
std::cout << 'c'; // imprime c
```

---

## Leer `char`

```cpp
#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: ";

    char ch{};
    std::cin >> ch;

    std::cout << "You entered: " << ch << '\n';
    return 0;
}
```

Entrada/salida:
```
Input a keyboard character: q
You entered: q
```

⚠️ Si introduces varios caracteres, `std::cin` solo guarda el primero en la variable `char`.

---

### Ejemplo: varios caracteres en el buffer

```cpp
std::cin >> ch; // si escribes "abcd", guarda 'a'
std::cin >> ch; // ahora extrae 'b' del buffer
```

Entrada:
```
abcd
```

Salida:
```
You entered: a
You entered: b
```

---

## Extraer espacios en blanco

Por defecto, `std::cin` **ignora espacios iniciales**.  
Ejemplo:

```cpp
#include <iostream>

int main()
{
    char ch{};
    std::cin >> ch; // ignora espacios
}
```

Solución: usar `std::cin.get()`:

```cpp
std::cin.get(ch); // NO ignora espacios
```

---

## Tamaño y rango

- Un `char` siempre mide **1 byte**.  
- Puede ser **signed** o **unsigned** (depende del compilador).  
  - `signed char`: -128 a 127  
  - `unsigned char`: 0 a 255  

---

## Secuencias de escape

Empiezan con `\` y representan caracteres especiales.  
Ejemplos comunes:
- `\n` → nueva línea
- `\t` → tabulación
- `\'` → comilla simple
- `\"` → comilla doble
- `\\` → barra invertida

Tabla completa:

| Nombre | Símbolo | Significado |
|--------|---------|-------------|
| Alert  | `\a`    | beep |
| Backspace | `\b` | retroceso |
| Newline | `\n` | nueva línea |
| Tab    | `\t` | tab horizontal |
| Comilla simple | `\'` | `'` |
| Comilla doble  | `\"` | `"` |
| Backslash      | `\\` | `\` |

Ejemplo:

```cpp
std::cout << "\"Texto entre comillas\"\n";
std::cout << "Una barra invertida: \\\n";
std::cout << "Hex 6F es: '\x6F'\n";
```

Salida:
```
"Texto entre comillas"
Una barra invertida: \
Hex 6F es: 'o'
```

---

## Cuidado con los literales multicaracter

Ejemplo de error común:

```cpp
std::cout << add(1, 2) << '/n'; // usamos / en vez de \
```

Salida inesperada (depende del compilador):
```
312142
```

✔️ Siempre usar `'\n'` y no `'/n'`.

---

## Otros tipos de char

- `wchar_t` → no recomendado (salvo en Windows API).  
- `char8_t` (C++20) → UTF-8.  
- `char16_t` → UTF-16.  
- `char32_t` → UTF-32.  

> Solo usa estos si trabajas con Unicode.  
> Para ASCII estándar, usa `char`.

---

## Resumen

- `char` almacena **un carácter ASCII** en 1 byte.  
- Siempre usa **comillas simples** para literales (`'a'`, `'5'`, `'\n'`).  
- Usa `std::cin.get()` si necesitas leer espacios en blanco.  
- Evita literales multicaracter (`'56'`).  
- Para Unicode, usa `char16_t` o `char32_t`.
