#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "blackjack.h"
#include "tdas/extra.h"
#include "tdas/stack.h"

// Muestra la mano de cartas usando Stack
void mostrar_cartas_stack(Stack *stack) {
    char pantalla[16][8];
    int cantidad = stack_size(stack);
    int i = 0;
    for (void *ptr = list_first(stack); ptr != NULL; ptr = list_next(stack), i++) {
        int valor = *(int*)ptr;
        const char* nombre;
        if (valor == 1) nombre = " A";
        else if (valor == 11) nombre = " J";
        else if (valor == 12) nombre = " Q";
        else if (valor == 13) nombre = " K";
        else {
            static char num[3];
            snprintf(num, sizeof(num), "%2d", valor);
            nombre = num;
        }
        snprintf(pantalla[i], sizeof(pantalla[i]), "|%s |", nombre);
    }
    for (int j = 0; j < cantidad; j++) printf("┌───┐ ");
    printf("\n");
    for (int j = 0; j < cantidad; j++) printf("%s ", pantalla[j]);
    printf("\n");
    for (int j = 0; j < cantidad; j++) printf("└───┘ ");
    printf("\n");
}

// Suma los valores de una mano, tratando los ases como 1 o 11 según convenga
int sumar_mano_stack(Stack *stack) {
    int suma = 0, ases = 0;
    for (void *ptr = list_first(stack); ptr != NULL; ptr = list_next(stack)) {
        int valor = *(int*)ptr;
        if (valor == 1) valor = 11;
        else if (valor >= 10) valor = 10;
        suma += valor;
        if (*(int*)ptr == 1) ases++;
    }
    while (suma > 21 && ases > 0) {
        suma -= 10;
        ases--;
    }
    return suma;
}

// Libera toda la memoria de las cartas en la mano y el stack
void liberar_mano(Stack *stack) {
    for (void *ptr = list_first(stack); ptr != NULL; ptr = list_next(stack)) {
        free(ptr);
    }
    stack_clean(stack);
    free(stack);
}

void iniciar_blackjack(float *saldo) {
    char seguir = 's';
    while (*saldo > 0 && (seguir == 's' || seguir == 'S')) {
        limpiarPantalla();

        printf("========================================\n");
        printf("\x1b[33m");
        printf("  _           _              _     \n");
        printf(" |_| |   /\\  /  |/   |  /\\  /  |/ \n");
        printf(" |_| |_ /--\\ \\_ |\\ \\_| /--\\ \\_ |\\ \n\n");
        printf("\x1b[0m");
        printf("========================================\n");
        printf("Saldo actual: \x1b[32m$%.2f\x1b[0m\n", *saldo);
        printf("----------------------------------------\n");

        float apuesta;
        printf("¿Cuánto deseas apostar? $");
        scanf("%f", &apuesta);

        if (apuesta <= 0 || apuesta > *saldo) {
            printf("\x1b[31mApuesta inválida.\x1b[0m\n");
            presioneTeclaParaContinuar();
            continue;
        }

        limpiarPantalla();

        srand((unsigned int)time(NULL));
        Stack *jugador = stack_create();
        Stack *dealer = stack_create();
        char opcion;

        // Repartir dos cartas al jugador y al dealer
        for (int i = 0; i < 2; i++) {
            int *carta_j = malloc(sizeof(int));
            *carta_j = (rand() % 13) + 1;
            stack_push(jugador, carta_j);

            int *carta_d = malloc(sizeof(int));
            *carta_d = (rand() % 13) + 1;
            stack_push(dealer, carta_d);
        }

        int suma_jugador = sumar_mano_stack(jugador);
        int suma_dealer = sumar_mano_stack(dealer);

        printf("========================================\n");
        printf("\x1b[33m");
        printf("  _           _              _     \n");
        printf(" |_| |   /\\  /  |/   |  /\\  /  |/ \n");
        printf(" |_| |_ /--\\ \\_ |\\ \\_| /--\\ \\_ |\\ \n\n");
        printf("\x1b[0m");
        printf("========================================\n");
        printf("Apuesta actual: \x1b[36m$%.2f\x1b[0m\n", apuesta);
        printf("----------------------------------------\n");
        printf("Tus cartas: (\x1b[36m%d\x1b[0m)\n", suma_jugador);
        mostrar_cartas_stack(jugador);
        printf("Carta visible del dealer:\n");
        // Mostrar solo la primera carta del dealer
        Stack *dealer_visible = stack_create();
        int *primera = malloc(sizeof(int));
        *primera = *(int*)list_first(dealer);
        stack_push(dealer_visible, primera);
        mostrar_cartas_stack(dealer_visible);
        liberar_mano(dealer_visible);
        printf("----------------------------------------\n");

        // Turno del jugador
        while (1) {
            printf("¿Qué deseas hacer? [\x1b[32mp\x1b[0m] Pedir carta / [\x1b[33mq\x1b[0m] Quedarse: ");
            scanf(" %c", &opcion);
            if (opcion == 'p' || opcion == 'P') {
                int *carta = malloc(sizeof(int));
                *carta = (rand() % 13) + 1;
                stack_push(jugador, carta);
                suma_jugador = sumar_mano_stack(jugador);

                limpiarPantalla();
                printf("========================================\n");
                printf("\x1b[33m");
                printf("  _           _              _     \n");
                printf(" |_| |   /\\  /  |/   |  /\\  /  |/ \n");
                printf(" |_| |_ /--\\ \\_ |\\ \\_| /--\\ \\_ |\\ \n\n");
                printf("\x1b[0m");
                printf("========================================\n");
                printf("Apuesta actual: \x1b[36m$%.2f\x1b[0m\n", apuesta);
                printf("----------------------------------------\n");

                printf("Obtuviste:\n");
                Stack *carta_stack = stack_create();
                int *c = malloc(sizeof(int));
                *c = *carta;
                stack_push(carta_stack, c);
                mostrar_cartas_stack(carta_stack);
                liberar_mano(carta_stack);

                printf("Tus cartas: (\x1b[36m%d\x1b[0m)\n", suma_jugador);
                mostrar_cartas_stack(jugador);
                printf("Carta visible del dealer:\n");
                dealer_visible = stack_create();
                primera = malloc(sizeof(int));
                *primera = *(int*)list_first(dealer);
                stack_push(dealer_visible, primera);
                mostrar_cartas_stack(dealer_visible);
                liberar_mano(dealer_visible);
                printf("----------------------------------------\n");

                if (suma_jugador > 21) {
                    printf("\n\x1b[31m¡Te pasaste! Pierdes $%.2f.\x1b[0m\n", apuesta);
                    *saldo -= apuesta;
                    break;
                }
            } else if (opcion == 'q' || opcion == 'Q') {
                break;
            } else {
                printf("Opción no válida. Usa 'p' para pedir carta o 'q' para quedarse.\n");
            }
        }

        // Solo juega el dealer si el jugador no se pasó
        if (suma_jugador <= 21) {
            printf("\nTurno del dealer...\n");
            printf("Cartas del dealer: (\x1b[36m%d\x1b[0m)\n", suma_dealer);
            mostrar_cartas_stack(dealer);
            int suma_dealer_actual = suma_dealer;
            while (suma_dealer_actual < 17) {
                int *carta = malloc(sizeof(int));
                *carta = (rand() % 13) + 1;
                stack_push(dealer, carta);
                suma_dealer_actual = sumar_mano_stack(dealer);
                printf("El dealer saca un\n");
                Stack *carta_stack = stack_create();
                int *c = malloc(sizeof(int));
                *c = *carta;
                stack_push(carta_stack, c);
                mostrar_cartas_stack(carta_stack);
                liberar_mano(carta_stack);
                printf("\nCartas del dealer: (\x1b[36m%d\x1b[0m)\n", suma_dealer_actual);
                mostrar_cartas_stack(dealer);
            }

            // Resultado
            printf("----------------------------------------\n");
            if (suma_dealer_actual > 21 || suma_jugador > suma_dealer_actual) {
                printf("\x1b[32m¡Ganaste! Ganas $%.2f\x1b[0m\n", apuesta);
                *saldo += apuesta;
            } else if (suma_jugador == suma_dealer_actual) {
                printf("\x1b[33mEmpate. Recuperas tu apuesta.\x1b[0m\n");
            } else {
                printf("\x1b[31mPerdiste $%.2f\x1b[0m\n", apuesta);
                *saldo -= apuesta;
            }
        }

        printf("----------------------------------------\n");
        printf("Saldo actual: \x1b[32m$%.2f\x1b[0m\n", *saldo);

        liberar_mano(jugador);
        liberar_mano(dealer);

        if (*saldo <= 0) {
            printf("\n\x1b[31mTe has quedado sin saldo. Volviendo al menú principal.\x1b[0m\n");
            getchar();
            break;
        }

        printf("\n¿Quieres jugar otra partida de Blackjack? (\x1b[32ms\x1b[0m/\x1b[31mn\x1b[0m): ");
        scanf(" %c", &seguir);

        if (seguir == 's' || seguir == 'S') {
            presioneTeclaParaContinuar();
        }
    }
}
