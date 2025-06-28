# Casino Virtual en C

## Descripción

Este sistema es un casino virtual desarrollado en C, donde los usuarios pueden jugar a distintos juegos de azar: tragamonedas, ruleta y blackjack. El usuario puede gestionar su saldo, realizar apuestas y disfrutar de una experiencia interactiva por consola. El sistema está diseñado para ser educativo y entretenido, mostrando el uso de estructuras de datos y lógica de juegos en C.

## Cómo compilar y ejecutar

El casino está implementado en C y puede ejecutarse fácilmente usando **Visual Studio Code** y la extensión **C/C++ Extension Pack** de Microsoft. Sigue estos pasos para compilar y ejecutar el proyecto en tu equipo local:

### Requisitos previos:

- Tener instalado [Visual Studio Code](https://code.visualstudio.com/).
- Instalar la extensión **C/C++** (Microsoft).
- Tener instalado un compilador de C (como **gcc**). En Windows, se recomienda [MinGW](https://www.mingw-w64.org/) o [WSL](https://learn.microsoft.com/en-us/windows/wsl/).

### Pasos para compilar y ejecutar:

1. **Descarga y descomprime** el archivo `.zip` en una carpeta de tu elección.
2. **Abre el proyecto en Visual Studio Code**
    - Inicia Visual Studio Code.
    - Selecciona `Archivo > Abrir carpeta...` y elige la carpeta donde descomprimiste el proyecto.
3. **Compila el código**
    - Abre el archivo principal (`casino.c`).
    - Abre la terminal integrada (`Terminal > Nueva terminal`).
    - Compila el programa con el siguiente comando:
        ```bash
        gcc *.c tdas/*.c -o casino
        ```
4. **Ejecuta el programa**
    - Una vez compilado, ejecuta la aplicación con:
        ```
        ./casino
        ```

## Funcionalidades

### Funcionando correctamente:

- Registro de usuario con nombre y saldo inicial.
- Jugar a las **tragamonedas**: apuesta, giro de rodillos y premios según coincidencias.
- Jugar a la **ruleta**: apuesta en diferentes modalidades (número, color, par/impar, docenas).
- Jugar a **blackjack**: apuesta, cartas, lógica de banca y jugador.
- Agregar saldo en cualquier momento.
- Validación de saldo y apuestas.
- Interfaz interactiva por consola.

### Problemas conocidos:

- El sistema no guarda el historial de partidas ni el saldo entre ejecuciones.
- No hay soporte para múltiples usuarios simultáneos.
- La validación de entradas podría mejorarse para evitar errores por entradas no numéricas.

### A mejorar:

- Implementar guardado y carga de partidas/saldo.
- Mejorar la interfaz gráfica (por ejemplo, usando ncurses).
- Añadir más juegos o modos de apuesta.
- Soporte para rankings o estadísticas de usuario.

## Ejemplo de uso

**Paso 1: Registro de usuario**

Al iniciar el programa, se solicita el nombre y el saldo inicial.

```
Ingrese su nombre: Juan
Ingrese su saldo inicial: $1000
¡Registro exitoso! ¡Mucha suerte, Juan!
```

**Paso 2: Menú principal y selección de juego**

El usuario puede elegir entre tragamonedas, ruleta, blackjack, agregar saldo o salir.

```
Menu Principal
Jugador: Juan
Saldo: $1000.00
1. Jugar Tragamonedas
2. Jugar Ruleta
3. Jugar Blackjack
4. Agregar saldo
5. Salir
Seleccione una opcion:
```

**Paso 3: Jugar Tragamonedas**

```
Bienvenido a las tragamonedas!
Reglas:
- Apuesta un monto.
- Gira 3 rodillos con símbolos aleatorios.
- Si salen 3 símbolos iguales → Premio mayor.
- Si salen 2 símbolos iguales → Premio menor.
- Si no hay coincidencias → Pierdes la apuesta.

Ingrese su apuesta: $100
[...se muestra el resultado...]
Saldo actual: $950.00
¿Jugar otra vez? (1. Sí / 2. No):
```

**Paso 4: Jugar Ruleta**

```
Bienvenido a la ruleta!
Puedes apostar en los siguientes modos:
1. Número exacto (paga 35:1)
2. Par o impar (paga 1:1)
3. Rojo o negro (paga 1:1)
4. Docenas (paga 2:1)

Ingresa el monto a apostar: $50
Selecciona el tipo de apuesta: 3
1. Rojo
2. Negro
Selecciona: 1
[...se muestra el resultado...]
Saldo actual: $1000.00
```

**Paso 5: Jugar Blackjack**

```
Bienvenido al BLACKJACK!
Reglas:
- El objetivo es sumar lo más cerca de 21 sin pasarte.
- Recibes 2 cartas y puedes pedir más o plantarte.
- Si te pasas de 21, pierdes automáticamente.
- Luego juega la banca. Gana quien esté más cerca de 21.

¿Cuánto deseas apostar? $200
Tus cartas: (18)
┌───┐ ┌───┐
| 10| |  8|
└───┘ └───┘
Carta visible del dealer:
┌───┐
|  7|
└───┘
¿Qué deseas hacer? [p] Pedir carta / [q] Quedarse:
```

**Paso 6: Agregar saldo**

```
Ingrese el monto a agregar: $500
Saldo actualizado: $1500.00
```

**Paso 7: Salir**

```
Gracias por jugar, hasta luego
```

## Contribuciones

### Leandro Bravo:

- Desarrollo y diseño de blackjack.
- Revisión de código.

### Eliana Garcia:

- Diseño de interfaz de usuario.
- Diseño de menús y navegación

### Alex Reyes:
- Diseño de arte ASCII para la consola.
- Desarrollo y diseño de Tragamonedas.

### Anahys Vera:

- Gestión de saldos.
- Desarrollo y diseño de Ruleta.
