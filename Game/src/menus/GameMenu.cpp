#include "GameMenu.h"



GameMenu::GameMenu(Game* game) : game(game) {}

GameMenu::~GameMenu() {}

void GameMenu::displayGameHeader() {
    cout << "\n========================================" << endl;
    cout << "           JUEGO UNO                    " << endl;
    cout << "========================================" << endl;
}

void GameMenu::displayCurrentCard() {
    Card* currentCard = game->getCurrentCard();
    if (currentCard != nullptr) {
        cout << "\nCarta en mesa:" << endl;
        string symbol = currentCard->getSortSymbol();
        for (int i = 0; i < 3; i++) {
            cout << currentCard->renderLine(i, symbol) << endl;
        }
    }
}

void GameMenu::displayTurnInfo() {
    Turn* turn = game->getActualTurn();
    if (turn != nullptr) {
        Player* player = turn->getJugador();
        cout << "\n>>> Turno de: " << COLOR_PLAYER << player->getNombre() << COLOR_RESET << " <<<" << endl;
    }
}

void GameMenu::displayPlayerHand() {
    Turn* turn = game->getActualTurn();
    if (turn != nullptr) {
        LinkedList* hand = turn->getHand();
        cout << "\nCartas en mano: " << hand->getSize() << endl;
    }
}

void GameMenu::displayHandWithNumbers() {
    Turn* turn = game->getActualTurn();
    if (turn == nullptr) {
        return;
    }
    
    LinkedList* hand = turn->getHand();
    int numCards = hand->getSize();
    
    if (numCards == 0) {
        cout << "\nNo tienes cartas en la mano." << endl;
        return;
    }
    
    hand->sortCardsQuickSort();
    
    cout << "\n--- Tu mano ---" << endl;
    
    cout << "   ";
    for (int i = 0; i < numCards; i++) {
        cout << "  [" << i << "]  ";
    }
    cout << endl;
    
    for (int line = 0; line < 3; line++) {
        cout << "   ";
        for (int i = 0; i < numCards; i++) {
            Card* card = hand->getAt(i);
            string symbol = card->getSortSymbol();
            cout << card->renderLine(line, symbol) << " ";
        }
        cout << endl;
    }
}

int GameMenu::askPlayerForCard() {
    Turn* turn = game->getActualTurn();
    if (turn == nullptr) {
        return -1;
    }
    
    LinkedList* hand = turn->getHand();
    int numCards = hand->getSize();
    
    cout << "\nOpciones:" << endl;
    cout << "  0-" << (numCards - 1) << ": Jugar carta" << endl;
    
    Setting* settings = game->getSettings();
    if (settings != nullptr) {
        if (settings->getOptionStealMode() == 0) {
            cout << "  k: Robar 1 carta del mazo" << endl;
        } else {
            cout << "  k: Robar cartas hasta poder jugar" << endl;
        }
    } else {
        cout << "  k: Robar carta del mazo" << endl;
    }
    
    cout << "\nElige una opción: ";;
    
    string input;
    cin >> input;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }
    
    cin.clear();
    cin.ignore(10000, '\n');
    
    if (input == "k" || input == "K") {
        return -2;
    }
    
    try {
        return stoi(input);
    } catch (...) {
        return -1;
    }
}

void GameMenu::processPlayerTurn() {
    displayHandWithNumbers();
    
    bool turnComplete = false;
    
    while (!turnComplete) {
        int choice = askPlayerForCard();
        
        Turn* turn = game->getActualTurn();
        LinkedList* hand = turn->getHand();
        int numCards = hand->getSize();
        
        if (choice == -2) {
            int deckSizeBefore = game->getDeck()->getSize();
            game->drawUntilCanPlay();
            int deckSizeAfter = game->getDeck()->getSize();
            int cardsDrawn = deckSizeBefore - deckSizeAfter;
            
            if (cardsDrawn > 0) {
                if (cardsDrawn == 1) {
                    cout << "\n" << COLOR_INFO << "¡Robaste 1 carta del mazo!" << COLOR_RESET << endl;
                } else {
                    cout << "\n" << COLOR_INFO << "¡Robaste " << cardsDrawn << " cartas del mazo!" << COLOR_RESET << endl;
                }
                displayHandWithNumbers();
                turnComplete = true;
            } else {
                cout << "\n" << COLOR_ERROR << "¡No hay cartas en el mazo!" << COLOR_RESET << endl;
            }
        }
        else if (choice >= 0 && choice < numCards) {
            Card* selectedCard = hand->getAt(choice);
            
            if (game->canPlayCard(selectedCard)) {
                if (game->requiresColorSelection(selectedCard)) {
                    int color = askForColorSelection();
                    game->setSelectedColor(color);
                }
                
                string cardSymbol = selectedCard->getSortSymbol();
                
                if (game->playCard(choice)) {
                    cout << "\n" << COLOR_SUCCESS << "¡Jugaste: " << cardSymbol << "!" << COLOR_RESET << endl;
                    
                    validateUnoShout();
                    
                    if (cardSymbol == "Ø") {
                        displayEffectMessage("¡El siguiente jugador pierde su turno!");
                    } else if (cardSymbol == "®") {
                        displayEffectMessage("¡La dirección del juego se invirtió!");
                    } else if (cardSymbol == "+2" || cardSymbol == "+1") {
                        Setting* settings = game->getSettings();
                        if (settings != nullptr && settings->getPlusTwoStacking()) {
                            displayEffectMessage("¡El siguiente jugador roba cartas! (Puede responder con otro +2)");
                        } else {
                            displayEffectMessage("¡El siguiente jugador roba cartas!");
                        }
                    } else if (cardSymbol == "+4" || cardSymbol == "+3") {
                        handlePlusFourEffect();
                    } else if (cardSymbol == "©") {
                        displayEffectMessage("¡Color cambiado!");
                    }
                    
                    turnComplete = true;
                } else {
                    cout << "\n" << COLOR_ERROR << "Error al jugar la carta." << COLOR_RESET << endl;
                    displayHandWithNumbers();
                }
            } else {
                cout << "\n" << COLOR_ERROR << "¡Esa carta no se puede jugar! (Debe coincidir en color o símbolo)" << COLOR_RESET << endl;
                cout << COLOR_WARNING << "Intenta con otra carta o roba del mazo." << COLOR_RESET << "\n" << endl;
                displayHandWithNumbers();
            }
        }
        else {
            if (choice != -1) {
                cout << "\n" << COLOR_ERROR << "Opción inválida. Intenta de nuevo." << COLOR_RESET << endl;
                displayHandWithNumbers();
            }
        }
    }
}

int GameMenu::askForColorSelection() {
    cout << "\n--- Selecciona un color ---" << endl;
    cout << "  0: \033[91mRojo\033[0m" << endl;
    cout << "  1: \033[93mAmarillo\033[0m" << endl;
    cout << "  2: \033[96mAzul\033[0m" << endl;
    cout << "  3: \033[95mVerde\033[0m" << endl;
    cout << "\nElige un color (0-3): ";
    
    int color;
    cin >> color;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << COLOR_WARNING << "Entrada inválida, se usará Rojo por defecto." << COLOR_RESET << endl;
        return 0;
    }
    
    cin.clear();
    cin.ignore(10000, '\n');
    
    if (color < 0 || color > 3) {
        cout << COLOR_WARNING << "Color inválido, se usará Rojo por defecto." << COLOR_RESET << endl;
        return 0;
    }
    
    const string colorNames[] = {"Rojo", "Amarillo", "Azul", "Verde"};
    const string colorCodes[] = {"\033[91m", "\033[93m", "\033[96m", "\033[95m"};
    cout << COLOR_SUCCESS << "Color seleccionado: " << colorCodes[color] << colorNames[color] << COLOR_RESET << endl;
    
    return color;
}

void GameMenu::displayEffectMessage(const string& effect) {
    cout << "\n" << COLOR_INFO << "*** " << effect << " ***" << COLOR_RESET << "\n" << endl;
}

bool GameMenu::askForUnoShout() {
    cout << "\n¿Gritas UNO? (1 = Sí, 0 = No): ";
    int response;
    cin >> response;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    
    cin.clear();
    cin.ignore(10000, '\n');
    
    return response == 1;
}

void GameMenu::validateUnoShout() {
    Turn* turn = game->getActualTurn();
    if (turn == nullptr) {
        return;
    }
    
    Setting* settings = game->getSettings();
    if (settings == nullptr || !settings->getSoutUno()) {
        return;
    }
    
    LinkedList* hand = turn->getHand();
    
    if (hand->getSize() == 1) {
        bool shoutedUno = askForUnoShout();
        
        if (shoutedUno) {
            cout << "\n" << COLOR_SUCCESS << "¡" << COLOR_PLAYER << turn->getJugador()->getNombre() << COLOR_SUCCESS << " gritó UNO!" << COLOR_RESET << endl;
        } else {
            cout << "\n" << COLOR_ERROR << "¡" << COLOR_PLAYER << turn->getJugador()->getNombre() << COLOR_ERROR << " olvidó gritar UNO!" << COLOR_RESET << endl;
            cout << COLOR_WARNING << "Penalización: Roba 2 cartas." << COLOR_RESET << endl;
            
            for (int i = 0; i < 2; i++) {
                game->drawCard();
            }
        }
    }
}

bool GameMenu::askForPlusFourChallenge() {
    cout << "\n¿Desafías el +4? (1 = Sí, 0 = No): ";
    cout << COLOR_INFO << "Si desafías y el jugador anterior tenía otra carta válida, él roba 4." << COLOR_RESET << endl;
    cout << COLOR_WARNING << "Si estás equivocado, robas 6 cartas tú." << COLOR_RESET << endl;
    
    int response;
    cin >> response;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    
    cin.clear();
    cin.ignore(10000, '\n');
    
    return response == 1;
}

void GameMenu::handlePlusFourEffect() {
    Setting* settings = game->getSettings();
    
    if (settings == nullptr || !settings->getPlusFourDare()) {
        displayEffectMessage("¡El siguiente jugador roba 4 cartas y cambia el color!");
        return;
    }
    
    bool wantsToChallenge = askForPlusFourChallenge();
    
    if (wantsToChallenge) {
        cout << "\n" << COLOR_INFO << "¡Desafío activado!" << COLOR_RESET << endl;
        cout << COLOR_WARNING << "(Nota: La verificación completa requiere historial de turnos)" << COLOR_RESET << endl;
        cout << COLOR_INFO << "Por ahora se aplicará el efecto normal." << COLOR_RESET << endl;
        displayEffectMessage("¡El siguiente jugador roba 4 cartas y cambia el color!");
    } else {
        displayEffectMessage("¡El siguiente jugador roba 4 cartas y cambia el color!");
    }
}

void GameMenu::displayGameStats() {
    cout << "\n--- Estado del juego ---" << endl;
    cout << "Cartas en el mazo: " << game->getDeck()->getSize() << endl;
    cout << "Cartas en descarte: " << game->getDiscardPile()->getSize() << endl;
    cout << "Jugadores: " << game->getTurns()->getSize() << endl;
}

void GameMenu::displayWinner() {
    Turn* turn = game->getActualTurn();
    if (turn != nullptr) {
        cout << "\n****************************************" << endl;
        cout << "    " << COLOR_SUCCESS << "¡¡¡ " << COLOR_PLAYER << turn->getJugador()->getNombre() << COLOR_SUCCESS << " GANA !!!" << COLOR_RESET << endl;
        cout << "****************************************\n" << endl;
    }
}

void GameMenu::waitForInput() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore();
    cin.get();
}

void GameMenu::startGame() {
    displayGameHeader();
    
    game->initialize();
    
    cout << "\n" << COLOR_INFO << "Iniciando partida..." << COLOR_RESET << endl;
    displayCurrentCard();
    displayGameStats();
    
    cout << "\n" << COLOR_SUCCESS << "¡Comencemos!" << COLOR_RESET << "\n" << endl;
    
    int roundCount = 0;
    const int maxRounds = 50;
    
    while (!game->isGameOver() && roundCount < maxRounds) {
        runTurn();
        
        if (game->isGameOver()) {
            displayWinner();
            break;
        }
        
        game->nextTurn();
        roundCount++;
    }
    
    if (roundCount >= maxRounds && !game->isGameOver()) {
        cout << "\n=== Límite de turnos alcanzado ===" << endl;
        displayGameStats();
    }
}

void GameMenu::runTurn() {
    displayTurnInfo();
    displayCurrentCard();
    
    processPlayerTurn();
    
    cout << "\n" << COLOR_INFO << "Turno completado." << COLOR_RESET << "\n" << endl;
}