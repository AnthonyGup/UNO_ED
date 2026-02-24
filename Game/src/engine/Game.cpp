 #include "Game.h"
#include <iostream>

Game::Game(Stack *deck, CircularList *turns, Setting *settings) : deck(deck), turns(turns), settings(settings) {
    this->actualTurn = nullptr;
    this->discardPile = nullptr;
    this->currentEffectiveColor = -1;
    this->currentEffectiveSymbol = "";
}

Game::~Game() {
    if (deck != nullptr) {
        deck->clearAndDeleteCards();
    }

    if (discardPile != nullptr) {
        discardPile->clearAndDeleteCards();
    }

    delete deck;
    delete discardPile;

    if (turns != nullptr) {
        while (!turns->isEmpty()) {
            NodeC* headNode = turns->getHead();
            if (headNode != nullptr) {
                delete headNode->getData();
            }
            turns->deleteFirst();
        }
    }
    delete turns;

    delete settings;
}

void Game::initialize() {
    this->actualTurn = this->turns->getHead()->getData();
    this->discardPile = new Stack(deck->getSize());

    if (!deck->isEmpty()) {
        Card* firstCard = deck->pop();
        discardPile->insert(firstCard);
        currentEffectiveColor = firstCard->getColorIndex();
        currentEffectiveSymbol = firstCard->getSortSymbol();
    }
}

void Game::nextTurn() {
    NodeC* currentNode = turns->getHead();
    
    NodeC* temp = currentNode;
    do {
        if (temp->getData() == actualTurn) {
            currentNode = temp;
            break;
        }
        temp = turns->getNext(temp);
    } while (temp != turns->getHead());
    
    NodeC* nextNode = turns->getNext(currentNode);
    actualTurn = nextNode->getData();
}

bool Game::isGameOver() const {
    if (!gameRunning) {
        return true;
    }
    
    if (actualTurn != nullptr && actualTurn->getHand()->isEmpty()) {
        return true;
    }
    
    return false;
}

Turn* Game::getActualTurn() const {
    return actualTurn;
}

Card* Game::getCurrentCard() const {
    if (discardPile != nullptr && !discardPile->isEmpty()) {
        return discardPile->getTop();
    }
    return nullptr;
}

Stack* Game::getDeck() const {
    return deck;
}

Stack* Game::getDiscardPile() const {
    return discardPile;
}

CircularList* Game::getTurns() const {
    return turns;
}

Setting* Game::getSettings() const {
    return settings;
}

int Game::getTurnTimeLimit() const {
    return turnTimeLimit;
}

bool Game::canPlayCard(Card* card) const {
    if (card == nullptr || discardPile == nullptr || discardPile->isEmpty()) {
        return false;
    }
    
    bool sameColor = (card->getSortColorIndex() == currentEffectiveColor);
    bool sameSymbol = (card->getSortSymbol() == currentEffectiveSymbol);
    bool isWildcard = (card->getSortColorIndex() < 0 || card->getSortColorIndex() > 3);
    
    return sameColor || sameSymbol || isWildcard;
}

bool Game::playCard(int cardIndex) {
    if (actualTurn == nullptr) {
        return false;
    }
    
    LinkedList* hand = actualTurn->getHand();
    
    if (cardIndex < 0 || cardIndex >= hand->getSize()) {
        return false;
    }
    
    Card* card = hand->getAt(cardIndex);
    
    if (!canPlayCard(card)) {
        return false;
    }
    
    hand->deleteAt(cardIndex);
    discardPile->insert(card);
    
    if (selectedColorForWildcard != -1) {
        currentEffectiveColor = selectedColorForWildcard;
        selectedColorForWildcard = -1;
    } else {
        currentEffectiveColor = card->getColorIndex();
    }
    currentEffectiveSymbol = card->getSortSymbol();
    
    WildCard* wildcard = dynamic_cast<WildCard*>(card);
    if (wildcard != nullptr) {
        wildcard->applyEffect(*this);
    }
    
    return true;
}

bool Game::drawCard() {
    if (actualTurn == nullptr || deck == nullptr) {
        return false;
    }
    
    if (deck->isEmpty()) {
        recycleDeck();
        
        if (deck->isEmpty()) {
            return false;
        }
    }
    
    Card* drawnCard = deck->pop();
    actualTurn->getHand()->insert(drawnCard);
    
    return true;
}

void Game::recycleDeck() {
    if (discardPile == nullptr || discardPile->getSize() <= 1) {
        return;
    }
    
    std::cout << "\n*** El mazo se quedó sin cartas. Barajeando el descarte... ***" << std::endl;
    
    Card* topCard = discardPile->pop();
    
    while (!discardPile->isEmpty()) {
        Card* card = discardPile->pop();
        deck->insert(card);
    }
    
    deck->shuffle();
    discardPile->insert(topCard);
    
    std::cout << "*** Mazo barajeado con " << deck->getSize() << " cartas ***\n" << std::endl;
}

void Game::drawUntilCanPlay() {
    if (actualTurn == nullptr || deck == nullptr || settings == nullptr) {
        return;
    }
    
    if (settings->getOptionStealMode() == 0) {
        drawCard();
    } else {
        bool canPlay = false;
        int maxAttempts = 20;
        int attempts = 0;
        
        while (!canPlay && !deck->isEmpty() && attempts < maxAttempts) {
            drawCard();
            attempts++;
            
            LinkedList* hand = actualTurn->getHand();
            for (int i = 0; i < hand->getSize(); i++) {
                Card* card = hand->getAt(i);
                if (canPlayCard(card)) {
                    canPlay = true;
                    break;
                }
            }
        }
    }
}

void Game::skipNextPlayer() {
    nextTurn();
}

void Game::reverseDirection() {
    if (turns != nullptr) {
        turns->changeDirection();
    }
}

void Game::plus(int amount, bool isPlusTwo, bool isPlusFour) {
    if (settings == nullptr) {
        return;
    }
    
    bool stackingEnabled = false;
    if (isPlusTwo && settings->getPlusTwoStacking()) {
        stackingEnabled = true;
    }
    if (isPlusFour && settings->getPlusFourStacking()) {
        stackingEnabled = true;
    }
    
    if (!stackingEnabled || (!isPlusTwo && !isPlusFour)) {
        stackingEnabled = false;
    }
    
    nextTurn();
    
    for (int i = 0; i < amount; i++) {
        if (!deck->isEmpty()) {
            Card* drawnCard = deck->pop();
            actualTurn->getHand()->insert(drawnCard);
        }
    }
}

void Game::changeColor(int colorIndex) {
}

int Game::selectColor() {
    return selectedColorForWildcard;
}

void Game::setSelectedColor(int colorIndex) {
    selectedColorForWildcard = colorIndex;
}

bool Game::requiresColorSelection(Card* card) const {
    if (card == nullptr) {
        return false;
    }
    
    string symbol = card->getSortSymbol();
    return (symbol == "©" || symbol == "+4" || symbol == "+3");
}

bool Game::canChallengePlusFour(Turn* challengedPlayer, Card* currentCard) const {
    if (challengedPlayer == nullptr || currentCard == nullptr || discardPile == nullptr) {
        return false;
    }
    
    return false;
}

void Game::applyPlusFourChallenge(bool challengeSuccessful) {
    if (settings == nullptr || !settings->getPlusFourDare()) {
        return;
    }
}