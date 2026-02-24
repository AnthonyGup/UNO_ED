#include "UnoEngine.h"
#include "Game.h"
#include "../menus/GameMenu.h"

UnoEngine::UnoEngine() : juegoEnCurso(false), cantidadJugadores(2) {
    inicializarJuego();
}

UnoEngine::~UnoEngine() {}

void UnoEngine::inicializarJuego() {
    this->deck = nullptr;
    this->turns = nullptr;
}

void UnoEngine::manejarInicio() {
    try {
        menu.pedirConfiguracion();
        int opcionConfiguracion = menu.obtenerOpcion(1, 2);

        switch (opcionConfiguracion) {
            case 1:
                cout << "Iniciando juego con configuracion predeterminada..." << endl;
                solicitarJugadores();
                break;
            case 2:
                configurarPerzonalizada();
                solicitarJugadores();
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
        
        // Ahora que tenemos la configuración y cantidad de jugadores, crear el juego
        cout << "\nPreparando el juego..." << endl;
        
        // Regenerar el deck y los turnos con la configuración actual
        bool hasFlip = false;
        DeckMaker deckMaker(cantidadJugadores);
        deckMaker.generateDeck(hasFlip);
        deckMaker.shuffleDeck();
        this->deck = deckMaker.getDeckStack();
        
        TurnMaker turnMaker(&cantidadJugadores, deck);
        turnMaker.generateTurns();
        this->turns = turnMaker.getTurns();
        
        // Crear una copia de la configuración para pasarla al Game
        Setting* gameSettings = new Setting(
            configuration.getPlusTwoStacking(),
            configuration.getPlusFourStacking(),
            configuration.getPlusFourDare(),
            configuration.getOptionStealMode(),
            configuration.getSoutUno()
        );
        
        // Crear el objeto Game
        Game* game = new Game(deck, turns, gameSettings);
        
        // Crear el GameMenu y comenzar la partida
        GameMenu* gameMenu = new GameMenu(game);
        gameMenu->startGame();
        
        // Limpiar memoria después del juego
        delete gameMenu;
        delete game;
        
        cout << "\n¡Partida finalizada!" << endl;
        
    } catch (const InputException&) {
        cout << "Error al configurar el juego. Volviendo al menu principal..." << endl;
    }
}

void UnoEngine::solicitarJugadores() {
    try {
        menu.pedirCantidadJugadores();
        cantidadJugadores = menu.obtenerOpcion(2, 10);
        cout << "Cantidad de jugadores seleccionada: " << cantidadJugadores << endl;
    } catch (const InputException&) {
        cout << "Error al leer la cantidad de jugadores. Se usará 2 por defecto." << endl;
        cantidadJugadores = 2;
    }
}

void UnoEngine::configurarPerzonalizada() {
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
                    manejarInicio();
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
