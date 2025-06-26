#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tragamonedas.h"
#include "tdas/extra.h"

#define MAX_EMOJIS 6
#define TABLA_HASH_SIZE 50

// Símbolos del tragamonedas con sus pesos (probabilidades)
const char *emojis[MAX_EMOJIS] = {"🍒", "🔔", "🍋", "⭐", "🍇", "💎"};
const int pesos[MAX_EMOJIS] = {12, 10, 9, 8, 6, 5}; // Suma total = 50 (TABLA_HASH_SIZE)

char *tabla_hash[TABLA_HASH_SIZE];

// Inicializa la tabla hash con los emojis según sus pesos
void inicializarTablaHash() {
    int idx = 0;
    for (int i = 0; i < MAX_EMOJIS; i++) {
        for (int j = 0; j < pesos[i]; j++) {
            if (idx < TABLA_HASH_SIZE) {
                tabla_hash[idx++] = (char *)emojis[i];
            }
        }
    }
    // Semilla para números aleatorios
    srand((unsigned int)time(NULL));
}

// Obtiene un emoji aleatorio de la tabla hash
const char* obtenerEmojiAleatorio() {
    if (TABLA_HASH_SIZE == 0) return emojis[0]; // Protección por si está vacío
    int index = rand() % TABLA_HASH_SIZE;
    return tabla_hash[index];
}

// Muestra la interfaz visual del tragamonedas
void mostrarPantalla(const char *e1, const char *e2, const char *e3) {
    printf("\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⣀⣤⣴⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣤⣤⣀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⢸⣿⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣿⡇⠀⠀⣤⣄⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸⣿⣿⡇⢸⣿⣿⡇⢸⣿⣿⡇⠀⣿⡇⠀⠀⠛⠛⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸%s⡇⢸%s⡇⢸%s⡇ ⣿⡇  ⣷\n", e1, e2, e3);
    printf("⠀⠀⠀⠀⠀⠀⢸⣿⠀⢸⣿⣿⡇⢸⣿⣿⡇⢸⣿⣿⡇⠀⣿⡇⠀⣾⡇⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⢸⣿⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣿⡇⠀⣿⡿⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠙⠃⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⢀⣴⣿⠟⠛⠛⢻⡿⠛⠛⠛⢻⣿⣿⡟⠋⠉⠉⠛⢿⣦⡀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⢰⣿⣿⣥⣤⣤⣤⣾⣧⣤⣤⣤⣿⣿⣿⣷⣦⣤⣤⣶⣿⣿⣿⡆⠀⠀⠀\n");
    printf("⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀\n");
    printf("\n");
}

// Función principal del juego
float jugarTragamonedas(float apuesta) {
    // Verificación básica de la apuesta
    if (apuesta <= 0) {
        printf("Error: Apuesta inválida.\n");
        return 0;
    }

    // Generar los tres emojis aleatorios
    const char *r1 = obtenerEmojiAleatorio();
    const char *r2 = obtenerEmojiAleatorio();
    const char *r3 = obtenerEmojiAleatorio();

    // Mostrar la pantalla con los resultados
    mostrarPantalla(r1, r2, r3);

    // Determinar el premio según los resultados
    if (strcmp(r1, r2) == 0 && strcmp(r2, r3) == 0) {
        float premio = apuesta * 10; // Jackpot
        printf("🎉 ¡Jackpot! Ganaste $%.2f\n", premio);
        return premio;
    } 
    else if (strcmp(r1, r2) == 0 || strcmp(r2, r3) == 0 || strcmp(r1, r3) == 0) {
        float premio = apuesta * 2; // Premio menor
        printf("✨ ¡Ganaste $%.2f!\n", premio);
        return premio;
    } 
    else {
        printf("💔 No ganaste esta vez.\n");
        return 0;
    }
}
