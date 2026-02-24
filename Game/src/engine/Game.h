#ifndef GAME_H
#define GAME_H

#include "settings/Setting.h"
#include "Turn.h"
#include "../lists/Stack.h"
#include "../lists/CircularList.h"
#include "../lists/LinkedList.h"
#include "../cards/Card.h"
#include "../cards/WildCard.h"
#include "../cards/NormalCard.h"

/**
 * Gestiona la lógica principal del juego UNO.
 * Controla el flujo de turnos, validación de jugadas y efectos de cartas especiales.
 */
class Game
{
private:
    Stack *deck = nullptr;
    Stack *discardPile = nullptr;
    CircularList *turns = nullptr;
    Setting *settings = nullptr;
    Turn *actualTurn = nullptr;
    bool gameRunning = true;
    int turnTimeLimit = 30;
    int selectedColorForWildcard = -1;
    int currentEffectiveColor = -1;      // Color efectivo actual (usado para validación después de wildcards)
    string currentEffectiveSymbol = "";  // Símbolo efectivo actual (usado para validación)

public:
    Game(Stack *deck, CircularList *turns, Setting *settings);
    ~Game();

    /**
     * Inicializa el juego estableciendo el turno inicial y colocando la primera carta en el descarte.
     * Debe llamarse antes de comenzar la partida.
     */
    void initialize();

    /**
     * Avanza al siguiente turno respetando la dirección actual del juego.
     * La dirección puede ser modificada por cartas especiales de reversa.
     */
    void nextTurn();

    /**
     * Verifica si el juego ha terminado.
     * @return true si algún jugador se quedó sin cartas o si el juego fue detenido.
     */
    bool isGameOver() const;

    /**
     * Verifica si una carta puede ser jugada según las reglas de UNO.
     * Usa el color y símbolo efectivos (cache) para validar correctamente después de wildcards.
     * Una carta es válida si coincide en color efectivo, símbolo efectivo o es un comodín.
     * @param card La carta a validar.
     * @return true si la carta puede ser jugada.
     */
    bool canPlayCard(Card *card) const;

    /**
     * Juega una carta del índice especificado de la mano del jugador actual.
     * Mueve la carta al descarte y aplica sus efectos si es especial.
     * @param cardIndex Índice de la carta en la mano del jugador.
     * @return true si la carta fue jugada exitosamente.
     */
    bool playCard(int cardIndex);

    /**
     * Permite al jugador actual robar una carta del mazo.
     * Si el mazo está vacío, se recicla automáticamente el descarte.
     * @return true si se robó una carta exitosamente.
     */
    bool drawCard();

    /**
     * Recicla las cartas del descarte al mazo cuando este se queda vacío.
     * Mantiene la carta superior del descarte en juego y baraja las demás.
     */
    void recycleDeck();

    /**
     * Salta el turno del siguiente jugador.
     * Efecto aplicado por la carta de bloqueo.
     */
    void skipNextPlayer();

    /**
     * Invierte la dirección del juego.
     * Efecto aplicado por la carta de reversa.
     */
    void reverseDirection();

    /**
     * Aplica el efecto de cartas +2 o +4 haciendo que el siguiente jugador robe cartas.
     * Respeta las configuraciones de stacking si están habilitadas.
     * @param amount Cantidad de cartas a robar.
     * @param isPlusTwo Indica si es una carta +2.
     * @param isPlusFour Indica si es una carta +4.
     */
    void plus(int amount, bool isPlusTwo = false, bool isPlusFour = false);

    /**
     * Cambia el color activo del juego.
     * Utilizado por cartas comodín que permiten cambiar el color.
     * @param colorIndex Índice del nuevo color (0-3).
     */
    void changeColor(int colorIndex);

    /**
     * Obtiene el color seleccionado previamente por el jugador.
     * @return Índice del color seleccionado.
     */
    int selectColor();

    /**
     * Establece el color seleccionado desde la interfaz.
     * @param colorIndex Índice del color seleccionado (0-3).
     */
    void setSelectedColor(int colorIndex);

    /**
     * Verifica si una carta requiere selección de color.
     * @param card La carta a verificar.
     * @return true si la carta es un comodín que requiere selección de color.
     */
    bool requiresColorSelection(Card *card) const;

    /**
     * Permite robar cartas según el modo configurado en Settings.
     * Modo 0: roba solo una carta. Modo 1: roba hasta poder jugar.
     */
    void drawUntilCanPlay();

    /**
     * Verifica si el desafío +4 es válido.
     * Requiere historial de turnos para verificar si el jugador tenía otra carta válida.
     * @param challengedPlayer El jugador que jugó el +4.
     * @param currentCard La carta +4 jugada.
     * @return true si el desafío es válido.
     */
    bool canChallengePlusFour(Turn *challengedPlayer, Card *currentCard) const;

    /**
     * Aplica el resultado del desafío +4.
     * Si el desafío es exitoso, el jugador que jugó el +4 roba 4 cartas.
     * Si falla, el desafiante roba 6 cartas.
     * @param challengeSuccessful Indica si el desafío fue exitoso.
     */
    void applyPlusFourChallenge(bool challengeSuccessful);

    //getters
    Turn *getActualTurn() const;
    Card *getCurrentCard() const;
    Stack *getDeck() const;
    Stack *getDiscardPile() const;
    CircularList *getTurns() const;
    Setting *getSettings() const;
    int getTurnTimeLimit() const;
};

#endif