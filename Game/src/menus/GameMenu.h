#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "../engine/Game.h"
#include <iostream>
#include <string>
using namespace std;

// Códigos de color ANSI para mensajes
const string COLOR_RESET = "\033[0m";
const string COLOR_PLAYER = "\033[95m";     // Morado para nombres de jugadores
const string COLOR_SUCCESS = "\033[92m";    // Verde para mensajes de éxito
const string COLOR_ERROR = "\033[91m";      // Rojo para errores/restricciones
const string COLOR_WARNING = "\033[93m";    // Amarillo para advertencias
const string COLOR_INFO = "\033[96m";       // Cian para información

/**
 * Gestiona la interfaz de usuario del juego UNO.
 * Controla toda la interacción con el jugador y la visualización del estado del juego.
 */
class GameMenu {
    private:
        Game* game;
        
        /**
         * Muestra el encabezado principal del juego.
         * Incluye el título y decoración.
         */
        void displayGameHeader();
        
        /**
         * Muestra la información del turno actual.
         * Incluye el nombre del jugador.
         */
        void displayTurnInfo();
        
        /**
         * Muestra la cantidad de cartas en la mano del jugador actual.
         */
        void displayPlayerHand();
        
        /**
         * Muestra la carta actual en mesa.
         * Renderiza la carta con sus colores ANSI correspondientes.
         */
        void displayCurrentCard();
        
        /**
         * Muestra estadísticas generales del juego.
         * Incluye cartas en mazo, descarte y cantidad de jugadores.
         */
        void displayGameStats();
        
        /**
         * Muestra el mensaje de victoria del ganador.
         * Se ejecuta cuando un jugador se queda sin cartas.
         */
        void displayWinner();
        
        /**
         * Espera entrada del usuario antes de continuar.
         */
        void waitForInput();
        
        /**
         * Muestra las cartas del jugador con números de selección encima.
         * Permite al jugador identificar qué carta desea jugar.
         */
        void displayHandWithNumbers();
        
        /**
         * Solicita al jugador que seleccione una carta o robe del mazo.
         * @return El índice de la carta seleccionada o la opción de robar.
         */
        int askPlayerForCard();
        
        /**
         * Procesa el turno completo del jugador.
         * Maneja la selección de carta, validación de jugada y efectos especiales.
         */
        void processPlayerTurn();
        
        /**
         * Solicita al jugador que seleccione un color.
         * Utilizado cuando juega una carta comodín.
         * @return Índice del color seleccionado (0-3).
         */
        int askForColorSelection();
        
        /**
         * Muestra un mensaje de efecto de carta especial.
         * @param effect Descripción del efecto a mostrar.
         */
        void displayEffectMessage(const string& effect);
        
        /**
         * Pregunta al jugador si grita UNO.
         * Se ejecuta cuando al jugador le queda una sola carta.
         * @return true si el jugador gritó UNO.
         */
        bool askForUnoShout();
        
        /**
         * Valida si el jugador debe gritar UNO y aplica penalización si olvida hacerlo.
         * La penalización consiste en robar 2 cartas.
         */
        void validateUnoShout();
        
        /**
         * Pregunta al jugador si desea desafiar una carta +4.
         * @return true si el jugador acepta el desafío.
         */
        bool askForPlusFourChallenge();
        
        /**
         * Maneja el efecto +4 con posible desafío.
         * Verifica la configuración de +4 Dare antes de ofrecer el desafío.
         */
        void handlePlusFourEffect();

    public:
        GameMenu(Game* game);
        ~GameMenu();
        
        /**
         * Inicia el juego completo.
         * Ejecuta la inicialización y el bucle principal del juego.
         */
        void startGame();
        
        /**
         * Ejecuta un turno individual.
         * Muestra información del turno y procesa las acciones del jugador.
         */
        void runTurn();
};

#endif