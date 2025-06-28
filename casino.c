#include <windows.h>
#include <stdio.h>
#include "tdas/extra.h"
#include "tragamonedas.h"
#include "ruleta.h"
#include "blackjack.h"

void pantallaBienvenida() {
    printf("\n");
    printf("  ______    ______    ______   ______  __    __   ______  \n");
    printf(" /      \\  /      \\  /      \\ |      \\|  \\  |  \\ /      \\ \n");
    printf("|  $$$$$$\\|  $$$$$$\\|  $$$$$$\\ \\$$$$$$| $$\\ | $$|  $$$$$$\\\n");
    printf("| $$   \\$$| $$__| $$| $$___\\$$  | $$  | $$$\\| $$| $$  | $$\n");
    printf("| $$      | $$    $$ \\$$    \\   | $$  | $$$$\\ $$| $$  | $$\n");
    printf("| $$   __ | $$$$$$$$ _\\$$$$$$\\  | $$  | $$\\$$ $$| $$  | $$\n");
    printf("| $$__/  \\| $$  | $$|  \\__| $$ _| $$_ | $$ \\$$$$| $$__/ $$\n");
    printf(" \\$$    $$| $$  | $$ \\$$    $$|   $$ \\| $$  \\$$$ \\$$    $$\n");
    printf("  \\$$$$$$  \\$$   \\$$  \\$$$$$$  \\$$$$$$ \\$$   \\$$  \\$$$$$$ \n");
    printf("\n\n");
}

void mostrarT() {
    printf("\n\x1b[36m"); // Activa color cyan
    printf("████████╗██████╗  █████╗  ██████╗  █████╗ ███╗   ███╗ ██████╗ ███╗   ██╗███████╗██████╗  █████╗ ███████╗\n");
    printf("╚══██╔══╝██╔══██╗██╔══██╗██╔════╝ ██╔══██╗████╗ ████║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔══██╗██╔════╝\n");
    printf("   ██║   ██████╔╝███████║██║  ███╗███████║██╔████╔██║██║   ██║██╔██╗ ██║█████╗  ██║  ██║███████║███████╗\n");
    printf("   ██║   ██╔══██╗██╔══██║██║   ██║██╔══██║██║╚██╔╝██║██║   ██║██║╚██╗██║██╔══╝  ██║  ██║██╔══██║╚════██║\n");
    printf("   ██║   ██║  ██║██║  ██║╚██████╔╝██║  ██║██║ ╚═╝ ██║╚██████╔╝██║ ╚████║███████╗██████╔╝██║  ██║███████║\n");
    printf("   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝ ╚═╝  ╚═╝╚══════╝\n");
    printf("\x1b[0m"); // Restablece el color
    printf("\n");
    presioneTeclaParaContinuar();
    limpiarPantalla();
}

void mostrarR() {
    printf("  _          _ ___     \n");
    printf(" |_) | | |  |_  |  /\\  \n");
    printf(" | \\ |_| |_ |_  | /--\\ \n");
    printf("\n");
    presioneTeclaParaContinuar();
    limpiarPantalla();
}

void mostrarB() {
    printf("  _           _              _     \n");
    printf(" |_| |   /\\  /  |/   |  /\\  /  |/ \n");
    printf(" |_| |_ /--\\ \\_ |\\ \\_| /--\\ \\_ |\\ \n");
    printf("\n");
    presioneTeclaParaContinuar();
    limpiarPantalla();
}

void registroUsuario(char *nombre, float *saldo){
    printf("\x1b[36m╔══════════════════════════════════════════════════════╗\x1b[0m\n");
    printf("\x1b[36m║\x1b[0m\x1b[33m         ¡Bienvenido(a) al Casino Virtual!            \x1b[0m\x1b[36m║\x1b[0m\n");
    printf("\x1b[36m╚══════════════════════════════════════════════════════╝\x1b[0m\n");

    printf("\nIngrese su nombre:");
    scanf("%s",nombre);
    limpiarBuffer();

    do {
        printf("Ingrese su saldo inicial: \x1b[32m$\x1b[0m");
        scanf("%f",saldo);
        limpiarBuffer();
        if(*saldo <= 0){
            printf("\x1b[31mEl saldo debe ser mayor a cero.\n\x1b[0m");
        }
    } while(*saldo <= 0);

    printf("\x1b[33m\n¡Registro exitoso! ¡Mucha suerte, %s!\n\x1b[0m", nombre);
    presioneTeclaParaContinuar();
    limpiarPantalla();
}

void mostrarMenuPrincipal(char *nombre, float saldo) {
    printf("\x1b[35m╔══════════════════════════════════════════════════════╗\x1b[0m\n");
    printf("\x1b[35m║\x1b[0m              \x1b[36m🎰  C A S I N O   V I R T U A L  🎰     \x1b[35m║\x1b[0m\n");
    printf("\x1b[35m╠══════════════════════════════════════════════════════╣\x1b[0m\n");
    printf("\x1b[35m║\x1b[0m  Jugador: \x1b[33m%-30s\x1b[0m            \x1b[35m║\x1b[0m\n", nombre);
    printf("\x1b[35m║\x1b[0m  Saldo:   \x1b[32m$%-35.2f\x1b[0m      \x1b[35m║\x1b[0m\n", saldo);
    printf("\x1b[35m╠══════════════════════════════════════════════════════╣\x1b[0m\n");
    printf("\x1b[35m║\x1b[0m  \x1b[33m1.\x1b[0m 🎰  Jugar Tragamonedas                           \x1b[35m║\x1b[0m\n");
    printf("\x1b[35m║\x1b[0m  \x1b[33m2.\x1b[0m 🎯  Jugar Ruleta                                 \x1b[35m║\x1b[0m\n");
    printf("\x1b[35m║\x1b[0m  \x1b[33m3.\x1b[0m 🃏  Jugar Blackjack                              \x1b[35m║\x1b[0m\n");
    printf("\x1b[35m║\x1b[0m  \x1b[33m4.\x1b[0m 💰  Agregar saldo                                \x1b[35m║\x1b[0m\n");
    printf("\x1b[35m║\x1b[0m  \x1b[33m5.\x1b[0m 🚪  Salir del casino                             \x1b[35m║\x1b[0m\n");
    printf("\x1b[35m╚══════════════════════════════════════════════════════╝\x1b[0m\n");
}


float agregarSaldo(float saldo){
    float monto;
    do{
        printf("Ingrese el monto a agregar: $");
        scanf("%f", &monto);
        if(monto <= 0){
            printf("Monto invalido");
        }
    }while(monto <= 0 );
    saldo += monto;
    printf("Saldo actualizado: $%.2f\n",saldo);
    presioneTeclaParaContinuar();
    return saldo;
}

int verificarSaldo(float saldo) {
    if (saldo <= 0) {
        printf("\n\x1b[31m[!] No tienes saldo suficiente para jugar. Agrega saldo primero.\x1b[0m\n");
        return 1; // Indica que no hay saldo suficiente
    }
    return 0; // Hay saldo suficiente
}

int main(){
    SetConsoleOutputCP(CP_UTF8);//caracteres en la consola
    inicializarTablaHash(); //implementacion tabla hash para tragamonedas
    char nombre[50];
    float saldo;
    int opcion;
    
    pantallaBienvenida();
    presioneTeclaParaContinuar();
    limpiarPantalla();
    registroUsuario(nombre,&saldo); 
    do {
        mostrarMenuPrincipal(nombre,saldo);
        printf("\x1b[36m\n>>>\x1b[0m Seleccione una opción [1-5]: \x1b[33m");
        scanf("%d", &opcion);
        printf("\x1b[0m"); 
        limpiarBuffer();
        switch (opcion){
        case 1:
            if (verificarSaldo(saldo)) break;
            mostrarT();
            printf("========================================\n");
            printf("       \x1b[33m¡Bienvenido a las TRAGAMONEDAS!\x1b[0m     \n");
            printf("========================================\n");
            printf("\x1b[36mReglas:\x1b[0m\n");
            printf("  - Apuesta un monto.\n");
            printf("  - Se giran \x1b[35m3 rodillos\x1b[0m con símbolos aleatorios.\n");
            printf("  - Si salen \x1b[32m3 símbolos iguales\x1b[0m → Premio mayor 💰.\n");
            printf("  - Si salen \x1b[33m2 símbolos iguales\x1b[0m → Premio menor 🎉.\n");
            printf("  - Si no hay coincidencias → Pierdes la apuesta ❌.\n");
            printf("----------------------------------------\n");
            presioneTeclaParaContinuar();
            limpiarPantalla();
            float apuesta;
            printf("Ingrese su apuesta: $");
            scanf("%f", &apuesta);
            limpiarBuffer();
            if (apuesta > 0 && apuesta <= saldo) {
                saldo -= apuesta;
                saldo += jugarTragamonedas(apuesta, &saldo);
            } else {
                printf("Apuesta inválida.\n");
            }
            presioneTeclaParaContinuar();
            break;
        case 2:
        // Jugar Ruleta
            if (verificarSaldo(saldo)) break;
            mostrarR();
            limpiarPantalla();
            jugarRuleta(&saldo);
            presioneTeclaParaContinuar();
            break;
        case 3:
        // JUgar Blackjack
            if (verificarSaldo(saldo)) break;
            mostrarB();
            iniciar_blackjack(&saldo);
            presioneTeclaParaContinuar();
            break;
        case 4: 
            saldo = agregarSaldo(saldo);
            break;
        case 5:
            printf("Gracias por jugar, hasta luego %s!\n",nombre);
            break;
        default:
            printf("Opcion invalida, por favor intente nuevamente.\n");
        }
        limpiarBuffer();
        limpiarPantalla();
    }while (opcion != 5);

    return 0;

}
