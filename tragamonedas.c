#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include "tragamonedas.h"
#include "tdas/extra.h"

#define MAX_EMOJIS 6
#define TABLA_HASH_SIZE 50

const char *emojis[MAX_EMOJIS] = {"🍒", "🔔", "🍋", "⭐", "🍇", "💎"};
const int pesos[MAX_EMOJIS] = {12, 10, 9, 8, 6, 5};
const float multiplicadores[MAX_EMOJIS] = {2.0f, 2.5f, 3.0f, 5.0f, 7.0f, 10.0f};

char *tabla_hash[TABLA_HASH_SIZE];

void inicializarTablaHash() {
    int idx = 0;
    for (int i = 0; i < MAX_EMOJIS; i++) {
        for (int j = 0; j < pesos[i]; j++) {
            if (idx < TABLA_HASH_SIZE) {
                tabla_hash[idx++] = (char *)emojis[i];
            }
        }
    }
    srand((unsigned int)time(NULL));
}

const char* obtenerEmojiAleatorio() {
    int index = rand() % TABLA_HASH_SIZE;
    return tabla_hash[index];
}

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

float jugarTragamonedas(float apuesta_inicial, float *saldo_disponible) {
    float premio_total = 0;
    float apuesta = apuesta_inicial;
    int continuar = 1;

    // Validación inicial
    if (apuesta <= 0.0 || apuesta > *saldo_disponible) {
        printf("\x1b[31mError: Apuesta inválida (%.2f). Debe ser mayor a 0 y menor o igual a tu saldo (%.2f)\x1b[0m\n", 
               apuesta, *saldo_disponible);
        return 0;
    }

    do {
        limpiarPantalla();

        const char *r1 = obtenerEmojiAleatorio();
        const char *r2 = obtenerEmojiAleatorio();
        const char *r3 = obtenerEmojiAleatorio();

        mostrarPantalla(r1, r2, r3);

        float premio = 0;
        int emoji_index1 = -1, emoji_index2 = -1, emoji_index3 = -1;

        // Buscar índices de emojis
        for (int i = 0; i < MAX_EMOJIS; i++) {
            if (strcmp(r1, emojis[i]) == 0) emoji_index1 = i;
            if (strcmp(r2, emojis[i]) == 0) emoji_index2 = i;
            if (strcmp(r3, emojis[i]) == 0) emoji_index3 = i;
        }

        // Calcular premio
        if (emoji_index1 == emoji_index2 && emoji_index2 == emoji_index3) {
            premio = apuesta * multiplicadores[emoji_index1];
            printf("🎉 ¡Jackpot! Ganaste $%.2f (x%.1f)\n", premio, multiplicadores[emoji_index1]);
            *saldo_disponible += premio;
            premio_total += premio;
        } 
        else if (emoji_index1 == emoji_index2 || emoji_index2 == emoji_index3 || emoji_index1 == emoji_index3) {
            int matching_index = (emoji_index1 == emoji_index2) ? emoji_index1 : 
                               (emoji_index2 == emoji_index3) ? emoji_index2 : emoji_index3;
            premio = apuesta * (multiplicadores[matching_index] * 0.5f);
            printf("✨ ¡Ganaste $%.2f (x%.1f)!\n", premio, multiplicadores[matching_index] * 0.5f);
            *saldo_disponible += premio;
            premio_total += premio;
        } 
        else {
            printf("💔 No ganaste esta vez.\n");
            *saldo_disponible -= apuesta;
        }

        printf("\n\x1b[32mSaldo actual: $%.2f\x1b[0m\n", *saldo_disponible);

        // Validación para continuar
        if (*saldo_disponible <= 0) {
            printf("\x1b[31m¡Saldo agotado!\x1b[0m\n");
            break;
        }

        printf("¿Jugar otra vez? (1. Sí / 2. No): ");
        if (scanf("%d", &continuar) != 1 || continuar != 1) {
            limpiarBuffer();
            break;
        }

        // Validación de nueva apuesta
        do {
            printf("Ingresa tu apuesta (Saldo: $%.2f): $", *saldo_disponible);
            if (scanf("%f", &apuesta) != 1) {
                printf("\x1b[31mEntrada inválida\x1b[0m\n");
                limpiarBuffer();
                continuar = 0;
                break;
            }

            if (apuesta <= 0 || apuesta > *saldo_disponible) {
                printf("\x1b[31mApuesta inválida. Debe ser entre $0.01 y $%.2f\x1b[0m\n", *saldo_disponible);
            } else {
                break;
            }
        } while (1);

        if (*saldo_disponible <= 0) {
            printf("\x1b[31m¡Saldo agotado!\x1b[0m\n");
            break;
        }

    } while (continuar == 1);

    return premio_total;
}
