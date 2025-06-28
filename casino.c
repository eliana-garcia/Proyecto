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
    printf(" ___ _        __            _        _  _        __ \n");
    printf("  | |_)  /\\  /__  /\\  |\\/| / \\ |\\ | |_ | \\  /\\  (_  \n");
    printf("  | | \\ /--\\ \\_| /--\\ |  | \\_/ | \\| |_ |_/ /--\\ __) \n");
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
    printf("Bienvenido al casino \n");
    printf("Ingrese su nombre: ");
    scanf("%s",nombre);
    limpiarBuffer();

    do {
        printf("Ingrese su saldo inicial: $");
        scanf("%f",saldo);
        limpiarBuffer();
        if(*saldo <= 0){
            printf("El saldo debe ser mayor a cero. \n");
        }
    } while(*saldo <= 0);
    presioneTeclaParaContinuar();
    limpiarPantalla();
}

void mostrarMenuPrincipal(char *nombre, float saldo){
    printf("  Menu Principal \n");
    printf("Jugador: %s \n",nombre);
    printf("Saldo: $%.2f\n",saldo);
    printf("1. Jugar Tragamonedas\n");
    printf("2. Jugar Ruleta\n");
    printf("3. Jugar Blackjack\n");
    printf("4. Agregar saldo \n");
    printf("5. Salir \n");
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
        printf("Seleccione una opcion: \n");
        scanf("%d", &opcion);
        limpiarBuffer();
        switch (opcion){
        case 1:
            if (verificarSaldo(saldo)) break;
            mostrarT();
            printf("Bienvenido a las tragamonedas!\n");
            printf("Reglas:\n");
            printf("- Apuesta un monto.\n");
            printf("- Gira 3 rodillos con símbolos aleatorios.\n");
            printf("- Si salen 3 símbolos iguales → Premio mayor.\n");
            printf("- Si salen 2 símbolos iguales → Premio menor.\n");
            printf("- Si no hay coincidencias → Pierdes la apuesta.\n");
            presioneTeclaParaContinuar();
            limpiarPantalla();
            float apuesta;
            printf("Ingrese su apuesta: $");
            scanf("%f", &apuesta);
            limpiarBuffer();
            if (apuesta > 0 && apuesta <= saldo) {
                saldo -= apuesta;
                saldo += jugarTragamonedas(apuesta);
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
