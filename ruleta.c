#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ruleta.h"
#include "tdas/extra.h"
#define FG_RESET   "\x1b[0m"
#define FG_ROJO    "\x1b[31m"
#define FG_VERDE   "\x1b[32m"
#define FG_AMARILLO "\x1b[33m"
#define FG_AZUL    "\x1b[34m"
#define FG_CIAN    "\x1b[36m"
#define FG_BLANCO  "\x1b[37m"
#define COLOR_ROJO   1
#define COLOR_NEGRO  0

int esRojo(int numero);
void mostrarMenuRuleta();
int obtenerApuesta();
int elegirTipoApuesta();
int esGanador(int tipo, int eleccion, int resultado);
int obtenerPago(int tipo);
void limpiarPantallaRuleta();
int elegirNumeroGanador();

void jugarRuleta(float *saldo) {
    int continuar = 1;
    srand(time(NULL));

    while (continuar) {
        limpiarPantallaRuleta();
        mostrarMenuRuleta();

        int monto = obtenerApuesta();
        if (monto == 0) {
            printf("Has elegido salir del juego. Gracias por jugar!\n");
            return;
        }

        if (monto > *saldo) {
            printf("No tienes saldo suficiente. Saldo actual: $%.2f\n", *saldo);
            printf("Presiona ENTER para volver al menu principal...\n");
            getchar(); getchar();
            continue;
        }

        int tipo = elegirTipoApuesta();
        int eleccion;

        switch (tipo) {
            case 1:
                printf("Ingresa el numero exacto (0-36): ");
                scanf("%d", &eleccion);
                break;
            case 2:
                printf("1. Par\n2. Impar\nSelecciona: ");
                scanf("%d", &eleccion);
                break;
            case 3:
                printf("1. Rojo\n2. Negro\nSelecciona: ");
                scanf("%d", &eleccion);
                break;
            case 4:
                printf("1. Primera docena (1-12)\n2. Segunda docena (13-24)\n3. Tercera docena (25-36)\nSelecciona: ");
                scanf("%d", &eleccion);
                break;
            default:
                printf("Opcion no valida. Volviendo al menu...\n");
                return;
        }

        printf("\nConfirmar jugada (1. Si / 2. No): ");
        int confirmacion;
        scanf("%d", &confirmacion);
        if (confirmacion != 1) {
            continue;
        }

        int resultado = elegirNumeroGanador();
        printf("\nLA RULETA GIRA... El numero es... %d %s!\n", resultado, esRojo(resultado) ? "Rojo" : "Negro");

        if (esGanador(tipo, eleccion, resultado)) {
            float ganancia = monto * obtenerPago(tipo);
            *saldo += ganancia;
            printf("¡SIII GANASTE! Has ganado $%.2f\n", ganancia);
        } else {
            *saldo -= monto;
            printf("Perdiste:(. Has perdido $%d\n", monto);
        }

        printf("Saldo actual: $%.2f\n", *saldo);

        if (*saldo <= 0) {
            printf("Te has quedado sin saldo.\n");
            printf("Presiona ENTER para salir...\n");
            getchar(); getchar();
            return;
        }

        printf("Deseas jugar otra vez? (1. Si / 2. No): ");
        scanf("%d", &continuar);
    }
}



void mostrarMenuRuleta(){
    printf(FG_CIAN);
    printf(" _______   __    __  __        ________  ________   ______  \n");
    printf("|       \\ |  \\  |  \\|  \\      |        \\|        \\ /      \\ \n");
    printf("| $$$$$$$\\| $$  | $$| $$      | $$$$$$$$ \\$$$$$$$$|  $$$$$$\\\n");
    printf("| $$__| $$| $$  | $$| $$      | $$__       | $$   | $$__| $$\n");
    printf("| $$    $$| $$  | $$| $$      | $$  \\      | $$   | $$    $$\n");
    printf("| $$$$$$$\\| $$  | $$| $$      | $$$$$      | $$   | $$$$$$$$\n");
    printf("| $$  | $$| $$__/ $$| $$_____ | $$_____    | $$   | $$  | $$\n");
    printf("| $$  | $$ \\$$    $$| $$     \\| $$     \\   | $$   | $$  | $$\n");
    printf(" \\$$   \\$$  \\$$$$$$  \\$$$$$$$$ \\$$$$$$$$    \\$$    \\$$   \\$$\n\n");
    printf(FG_RESET );

    printf(FG_AMARILLO "────────────────────────────────────────────────────────────\n" FG_RESET);
    printf("Puedes apostar en los siguientes modos:\n\n");

    printf(FG_VERDE " 1. Número exacto" FG_RESET "   (paga 35:1)\n");
    printf(FG_VERDE " 2. Par o impar" FG_RESET  "     (paga 1:1)\n");
    printf(FG_VERDE " 3. Rojo o negro" FG_RESET  "    (paga 1:1)\n");
    printf(FG_VERDE " 4. Docenas" FG_RESET  "          (1-12, 13-24, 25-36) (paga 2:1)\n");

    printf(FG_AMARILLO "\n────────────────────────────────────────────────────────────\n" FG_RESET);
    printf("🎲  Se gira la ruleta y cae un número aleatorio.\n");
    printf("💰  Si tu apuesta coincide, ganas según el tipo.\n");
    printf(FG_AMARILLO "────────────────────────────────────────────────────────────\n" FG_RESET);
}


int obtenerApuesta() {
    int monto;
    while (1) {
         printf("\nIngresa el monto a apostar " FG_AMARILLO "(0 para salir)" FG_RESET  ": $");
        if (scanf("%d", &monto) != 1) {
            printf("Entrada invalida. Por favor, ingresa un numero.\n");
            while (getchar() != '\n'); 
        } else {
            if (monto < 0) {
                printf("El monto no puede ser negativo.\n");
            } else {
                break;
            }
        }
    }
    return monto;
}


int elegirTipoApuesta() {
    int tipo;
    printf("\nSelecciona el tipo de apuesta:\n");
    printf("1. Numero exacto\n2. Par/Impar\n3. Rojo/Negro\n4. Docenas\nOpcion: ");
    scanf("%d", &tipo);
    return tipo;
}

int esGanador(int tipo, int eleccion, int resultado) {
    switch (tipo) {
        case 1:
            return (resultado == eleccion);
        case 2:
            return (resultado != 0 && resultado % 2 == (eleccion - 1));
        case 3:
            return (resultado != 0 && esRojo(resultado) == (eleccion == 1));
        case 4:
            if (resultado >= 1 && resultado <= 12) return eleccion == 1;
            if (resultado >= 13 && resultado <= 24) return eleccion == 2;
            if (resultado >= 25 && resultado <= 36) return eleccion == 3;
            return 0;
        default:
            return 0;
    }
}

int obtenerPago(int tipo) {
    switch (tipo) {
        case 1: return 35;
        case 2: return 1;
        case 3: return 1;
        case 4: return 2;
        default: return 0;
    }
}

int esRojo(int numero) {
    int rojos[] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    for (int i = 0; i < 18; i++) {
        if (numero == rojos[i]) return 1;
    }
    return 0;
}

int elegirNumeroGanador() {
    int ruleta[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10,11,12,13,14,15,16,17,18,19,
        20,21,22,23,24,25,26,27,28,29,
        30,31,32,33,34,35,36
    };
    int index = rand() % 37;
    return ruleta[index];
}

void limpiarPantallaRuleta(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
