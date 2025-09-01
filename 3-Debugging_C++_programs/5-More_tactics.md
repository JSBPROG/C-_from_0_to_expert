# More Debugging Tactics (Resumen)

En esta lección se exploran técnicas para mejorar el uso de mensajes de depuración, evitando los problemas que tienen los `std::cout` o `std::cerr` tradicionales.

---

## Problemas con los mensajes de depuración simples

- Ensucian el código con muchas líneas extras.  
- Mezclan la salida normal con la salida de depuración.  
- Obligan a modificar el código para agregarlos o quitarlos.  
- No se pueden reutilizar fácilmente.  

---

## 1. Usar directivas del preprocesador (`#define`)

Podemos activar o desactivar los mensajes de depuración con una sola línea, sin borrar el código.

```cpp
#include <iostream>

#define ENABLE_DEBUG // comentar esta línea para desactivar depuración

int getUserInput()
{
#ifdef ENABLE_DEBUG
    std::cerr << "getUserInput() called\n";
#endif
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
#ifdef ENABLE_DEBUG
    std::cerr << "main() called\n";
#endif
    int x{ getUserInput() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
```

✅ Ventaja: permite reutilizar los mensajes de depuración sin borrarlos.  
❌ Desventaja: aún genera bastante "ruido" en el código.

---

## 2. Usar un **logger**

Un **logger** permite registrar información en un archivo de log (secuencial y con marca de tiempo).  
Esto evita ensuciar la salida del programa y facilita compartir el log para diagnosticar problemas.

Ejemplo con [plog](https://github.com/SergiusTheBest/plog):

```cpp
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>

int getUserInput()
{
    PLOGD << "getUserInput() called"; // Mensaje de depuración al log

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    // Inicializar logger en modo debug
    plog::init(plog::debug, "Logfile.txt");

    PLOGD << "main() called";

    int x{ getUserInput() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
```

Ejemplo de salida en **Logfile.txt**:

```
2018-12-26 20:03:33.295 DEBUG [4752] [main@19] main() called
2018-12-26 20:03:33.296 DEBUG [4752] [getUserInput@7] getUserInput() called
```

### Ventajas de un logger:
- No mezcla la salida normal del programa con la de depuración.  
- Fácil de activar/desactivar.  
- Más limpio y profesional en proyectos grandes.  

Con plog, para desactivar temporalmente los logs:

```cpp
plog::init(plog::none, "Logfile.txt"); // Desactiva la mayoría de mensajes
```

---

## Conclusión

- Para proyectos pequeños o pruebas rápidas: `#define ENABLE_DEBUG` puede ser suficiente.  
- Para proyectos grandes o compartidos: usar un **logger** (como `plog` o `spdlog`) es mucho más conveniente y profesional.

