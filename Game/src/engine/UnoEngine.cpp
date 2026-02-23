#include "UnoEngine.h"

UnoEngine::UnoEngine() : juegoEnCurso(false) {
    inicializarJuego();
}

UnoEngine::~UnoEngine() {}

void UnoEngine::inicializarJuego() {
    // Aquí iría la lógica de inicialización del juego
}

void UnoEngine::manejarInicioJuego() {
    try {
        menu.pedirConfiguracion();
        int opcionConfiguracion = menu.obtenerOpcion(1, 2);

        switch (opcionConfiguracion) {
            case 1:
                cout << "Iniciando juego con configuracion predeterminada..." << endl;
                break;
            case 2:
                manejarConfiguracionPersonalizada();
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
    } catch (const InputException&) {
        cout << "Error al configurar el juego. Volviendo al menu principal..." << endl;
    }
}

void UnoEngine::manejarConfiguracionPersonalizada() {
    bool salir = false;

    while (!salir) {
        menu.mostrarConfiguracion(configuration);
        int opcion = menu.obtenerOpcion(1, 6);

        try {
            switch (opcion) {
                case 1:
                    configurarStacking();
                    break;
                case 2:
                    configurarDare();
                    break;
                case 3:
                    configurarStealMode();
                    break;
                case 4:
                    configurarSoutUno();
                    break;
                case 5:
                    salir = true;
                    return;
                case 6:
                    salir = true;
                    break;
                default:
                    cout << "Opción no válida" << endl;
                    break;
            }
        } catch (...) {
            cout << "Continuando..." << endl;
        }
    }
}

void UnoEngine::configurarStacking() {
    bool salir = false;

    while (!salir) {
        menu.mostrarMenuStacking(configuration);
        int option = menu.obtenerOpcion(1, 4);

        try {
            switch (option) {
                case 1:
                    configuration.setPlusTwoStacking(!configuration.getPlusTwoStacking());
                    break;
                case 2:
                    configuration.setPlusFourStacking(!configuration.getPlusFourStacking());
                    break;
                case 3:
                    cout << "1. Permite responder a un +2 con otro +2 (acumula +4 al siguiente y así sucesivamente)." << endl;
                    cout << "2. Permite responder a un +4 con otro +4." << endl;
                    cout << "Restricción: No se puede poner un +2 sobre un +4." << endl;
                    menu.pausarPantalla();
                    break;
                case 4:
                    salir = true;
                    break;
                default:
                    break;
            }
        } catch (...) {
            cout << "Continuando..." << endl;
        }
    }
}

void UnoEngine::configurarDare() {
    bool salir = false;

    while (!salir) {
        menu.mostrarMenuDare(configuration);
        int option = menu.obtenerOpcion(1, 3);

        try {
            switch (option) {
                case 1:
                    configuration.setPlusFourDare(!configuration.getPlusFourDare());
                    break;
                case 2:
                    cout << "Si un jugador lanza un +4, el afectado puede 'Retar'" << endl;
                    cout << "Si el lanzador tenía otra carta del color actual en su mano o un número actual: el lanzador roba 4." << endl;
                    cout << "Si el lanzador no tenía otra opción: el que retó roba 6 (los 4 originales + 2 de penalización)." << endl;
                    cout << "[ENTER] para continuar" << endl;
                    menu.pausarPantalla();
                    break;
                case 3:
                    salir = true;
                    break;
                default:
                    break;
            }
        } catch (...) {
            cout << "Continuando..." << endl;
        }
    }
}

void UnoEngine::configurarStealMode() {
    bool salir = false;

    while (!salir) {
        menu.mostrarMenuStealMode(configuration);
        int option = menu.obtenerOpcion(1, 3);

        try {
            switch (option) {
                case 1:
                    configuration.setOptionStealMode(configuration.getOptionStealMode() == 0 ? 1 : 0);
                    break;
                case 2:
                    cout << "Modo de robo determina cuántas cartas debe robar un jugador si no puede jugar." << endl;
                    cout << "Opción 1: El jugador roba una carta y termina su turno." << endl;
                    cout << "Opción 2: El jugador sigue robando cartas hasta que robe una que pueda jugar." << endl;
                    cout << "[ENTER] para continuar" << endl;
                    menu.pausarPantalla();
                    break;
                case 3:
                    salir = true;
                    break;
                default:
                    break;
            }
        } catch (...) {
            cout << "Continuando..." << endl;
        }
    }
}

void UnoEngine::configurarSoutUno() {
    bool salir = false;

    while (!salir) {
        menu.mostrarMenuSoutUno(configuration);
        int option = menu.obtenerOpcion(1, 3);

        try {
            switch (option) {
                case 1:
                    configuration.setSoutUno(!configuration.getSoutUno());
                    break;
                case 2:
                    cout << "El jugador debe escribir 'UNO' antes de terminar su turno si le queda 1 carta." << endl;
                    cout << "Si no lo hace y alguien lo reporta antes del siguiente turno: roba 2." << endl;
                    cout << "Si alguien reporta erróneamente: el reportador roba 2." << endl;
                    cout << "[ENTER] para continuar" << endl;
                    menu.pausarPantalla();
                    break;
                case 3:
                    salir = true;
                    break;
                default:
                    break;
            }
        } catch (...) {
            cout << "Continuando..." << endl;
        }
    }
}

void UnoEngine::ejecutar() {
    bool continuarPrograma = true;
    
    while (continuarPrograma) {
        try {
            // Mostrar menú principal
            menu.mostrarMenuPrincipal();
            int opcion = menu.obtenerOpcion(1, 3);

            switch(opcion) {
                case 1:
                    manejarInicioJuego();
                    break;
                    
                case 2:
                    try {
                        menu.mostrarReglas();
                    } catch (const exception& e) {
                        cout << "Error al mostrar las reglas: " << e.what() << endl;
                    }
                    break;
                    
                case 3:
                    // Salir
                    cout << "Gracias por jugar UNO!" << endl;
                    continuarPrograma = false;
                    break;
                    
                default:
                    cout << "Opción no válida" << endl;
                    break;
            }
            
        } catch (const InputException& e) {
            // Si hay un error crítico de entrada, preguntar si desea continuar
            cout << "\nError crítico de entrada. ¿Desea continuar? (s/n): ";
            string respuesta;
            try {
                getline(cin, respuesta);
                if (respuesta.empty() || (respuesta[0] != 's' && respuesta[0] != 'S')) {
                    cout << "Saliendo del juego..." << endl;
                    continuarPrograma = false;
                }
            } catch (...) {
                cout << "Saliendo del juego por seguridad..." << endl;
                continuarPrograma = false;
            }
        } catch (const exception& e) {
            cout << "Error inesperado: " << e.what() << endl;
            cout << "Volviendo al menu principal..." << endl;
        }
    }
}
