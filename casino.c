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
}

void mostrarR() {
    printf("  _          _ ___     \n");
    printf(" |_) | | |  |_  |  /\\  \n");
    printf(" | \\ |_| |_ |_  | /--\\ \n");
    printf("\n");
    presioneTeclaParaContinuar();
}

void mostrarB() {
    printf("  _           _              _     \n");
    printf(" |_| |   /\\  /  |/   |  /\\  /  |/ \n");
    printf(" |_| |_ /--\\ \\_ |\\ \\_| /--\\ \\_ |\\ \n");
    printf("\n");
    presioneTeclaParaContinuar();
}

void registroUsuario(char *nombre, float *saldo){
    printf("Bienvenido al casino \n");
    printf("Ingrese su nombre: ");
    scanf("%s",nombre);
    limpiarBuffer();

    do {
        printf("Ingrse su saldo inicial: $");
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
    printf("5. Ver saldo actual \n");
    printf("6. Salir \n");
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
    return saldo;
}

void mostrarSaldo(char *nombre, float saldo){
    printf("Jugador: %s \n",nombre);
    printf("Saldo actual: $%.2f\n", saldo);
}

int main(){
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
        // jugar Tragamonedas
            mostrarT();
            limpiarPantalla();
            printf("Bienvenido a las tragamonedas!\n");
            printf("Reglas:\n");
            printf("- Apuesta un monto.\n");
            printf("- Gira 3 rodillos con símbolos aleatorios.\n");
            printf("- Si salen 3 símbolos iguales → Premio mayor.\n");
            printf("- Si salen 2 símbolos iguales → Premio menor.\n");
            printf("- Si no hay coincidencias → Pierdes la apuesta.\n");
            presioneTeclaParaContinuar();
            limpiarPantalla();
            break;
        case 2:
        // Jugar Ruleta
            mostrarR();
            limpiarPantalla();
            printf("Bienvenido a la ruleta!\n");
            printf("Reglas:\n");
            printf("- Apuesta eligiendo una opción:\n");
            printf("  1. Número exacto (0–36)\n");
            printf("  2. Par o impar\n");
            printf("  3. Rojo o negro\n");
            printf("  4. Docena (1–12, 13–24, 25–36)\n");
            printf("- Se gira la ruleta y cae un número.\n");
            printf("- Si tu apuesta coincide, ganas según el tipo.\n");
            presioneTeclaParaContinuar();
            limpiarPantalla();
            break;
        case 3:
        // JUgar Blackjack
            mostrarB();
            limpiarPantalla();
            printf("Bienvenido al Blackjack!\n");
            printf("Reglas:\n");
            printf("- El objetivo es sumar lo más cerca de 21 sin pasarte.\n");
            printf("- Recibes 2 cartas y puedes:\n");
            printf("  1. Pedir carta (\"Hit\")\n");
            printf("  2. Plantarte (\"Stand\")\n");
            printf("- Si te pasas de 21, pierdes automáticamente.\n");
            printf("- Luego juega la banca. Gana quien esté más cerca de 21.\n");
            presioneTeclaParaContinuar();
            limpiarPantalla();
            break;
        case 4: 
            saldo = agregarSaldo(saldo);
            break;
        case 5:
            mostrarSaldo(nombre,saldo);
            break;
        case 6:
            printf("Gracias por jugar, hasta luego %s!\n",nombre);
            break;
        default:
            printf("Opcion invalida, por favor intente nuevamente.\n");
        }
        
    }while (opcion != 6);

    return 0;

}