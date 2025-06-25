#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tragamonedas.h"
#include "tdas/extra.h"
#define MAX_EMOJIS 6
#define TABLA_HASH_SIZE 50

const char *emojis[MAX_EMOJIS] = {"🍒", "🔔", "🍋", "⭐", "🍇", "💎"};
const int pesos[MAX_EMOJIS] = {12, 10, 9, 8, 6, 5};

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

float jugarTragamonedas(float apuesta) {
    const char *r1 = obtenerEmojiAleatorio();
    const char *r2 = obtenerEmojiAleatorio();
    const char *r3 = obtenerEmojiAleatorio();

    mostrarPantalla(r1, r2, r3);

    if (strcmp(r1, r2) == 0 && strcmp(r2, r3) == 0) {
        float premio = apuesta * 10;
        printf("🎉 ¡Jackpot! Ganaste $%.2f\n", premio);
        return premio;
    } else if (strcmp(r1, r2) == 0 || strcmp(r2, r3) == 0 || strcmp(r1, r3) == 0) {
        float premio = apuesta * 2;
        printf("✨ ¡Ganaste $%.2f!\n", premio);
        return premio;
    } else {
        printf("💔 No ganaste esta vez.\n");
        return 0;
    }
}



