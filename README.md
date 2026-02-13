*Este proyecto ha sido creado como parte del currículo de 42 por tpaes.*

# ft_printf

## 📖 Descripción

El objetivo de este proyecto es reimplementar la función printf() de
la biblioteca estándar de C (libc).

`ft_printf` es una función variádica capaz de interpretar una cadena de
formato y sustituir los especificadores de conversión por los valores
correspondientes recibidos como argumentos.

Este proyecto permite profundizar en:

-   El funcionamiento interno de `printf`
-   El manejo de argumentos variables en C
-   La conversión de números a diferentes bases
-   La correcta gestión de `stdout`

------------------------------------------------------------------------

## 🔎 Conversiones obligatorias implementadas

  Especificador   Descripción
  --------------- ---------------------------
  `%c`            Carácter
  `%s`            Cadena de caracteres
  `%p`            Puntero en hexadecimal
  `%d`            Entero decimal
  `%i`            Entero decimal
  `%u`            Entero sin signo
  `%x`            Hexadecimal en minúsculas
  `%X`            Hexadecimal en mayúsculas
  `%%`            Símbolo `%`

------------------------------------------------------------------------

## ⚙️ Instrucciones

### 📦 Compilación

``` bash
make
```

Genera el archivo:

    libftprintf.a

### 🧹 Reglas disponibles

make        # Compila la librería
make clean  # Elimina archivos objeto
make fclean # Elimina objetos y la librería
make re     # Recompilación completa

------------------------------------------------------------------------

## 🚀 Uso

Incluye el header en tu proyecto:
#include "ft_printf.h"

Compila enlazando la librería:
cc main.c libftprintf.a
Ejemplo:

ft_printf("Número: %d\n", 42);

------------------------------------------------------------------------

### Flujo interno

1.  Recorrido del string 'format'.
2.  Detección del carácter '%'.
3.  Identificación del especificador.
4.  Extracción del argumento correspondiente con 'va_arg'.
5.  Llamada a la función específica de impresión.
6.  Acumulación del número total de caracteres impresos.

Cada función auxiliar devuelve la cantidad de caracteres que imprime,
permitiendo un conteo preciso en 'ft_printf'.

------------------------------------------------------------------------

### Documentación técnica

man 3 printf
man stdarg

### Conceptos estudiados

-   Funciones variádicas en C
-   Promoción automática de tipos
-   Conversión decimal y hexadecimal
-   Gestión de punteros
-   Representación de memoria
-   Arquitectura modular en C

------------------------------------------------------------------------

## 🤖 Uso de IA

La IA se ha utilizado exclusivamente como herramienta de apoyo
conceptual para:

-   Comprender el funcionamiento de 'va_list'
-   Aclarar dudas sobre promociones de tipos
-   Resolver dudas teóricas del estándar C