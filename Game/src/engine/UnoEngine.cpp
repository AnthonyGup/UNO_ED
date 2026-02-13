#include "UnoEngine.h"

UnoEngine::UnoEngine() : juegoEnCurso(false) {
    inicializarJuego();
}

UnoEngine::~UnoEngine() {
    // Limpiar recursos si es necesario
}

void UnoEngine::inicializarJuego() {
    // Aquí iría la lógica de inicialización del juego
}

void UnoEngine::ejecutar() {
    bool continuarPrograma = true;
    
    while (continuarPrograma) {
        // Mostrar menú principal
        menu.mostrarMenuPrincipal();
        int opcion = menu.obtenerOpcion(1, 3);
        
        switch(opcion) {
            case 1:
                // Iniciar juego
                cout << "Iniciando juego..." << endl;
                break;
            case 2:
                // Mostrar reglas
                break;
            case 3:
                // Salir
                cout << "Gracias por jugar UNO!" << endl;
                continuarPrograma = false;
                break;
        }
    }
}
