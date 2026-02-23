#include "DeckMaker.h"


DeckMaker::DeckMaker(int players) {
    this->players = players;
    this->deckSize = this->calculateDeckSize(players) * this->CARDS_AMOUNT;
    this->deckStack = new Stack(this->deckSize);
}

DeckMaker::~DeckMaker() {
    this->deckStack->clearAndDeleteCards();
    delete this->deckStack;
}

int DeckMaker::calculateDeckSize(int players) {
    double base = (static_cast<double>(players - 1) / 6.0) + 1.0;
    return floor(base); // Redondea al entero mas pequeño
}

void DeckMaker::addCard(Card* card) {
    if (this->deckStack->getSize() >= this->deckSize) {
        delete card;
        return;
    }

    this->deckStack->insert(card);
}

void DeckMaker::createNormalCards(bool& hasFlip) {
    for (int color = 0; color < 4; color++) {
        // Insertar "0" de cada color
        string symbol = "0";
        addCard(new NormalCard(symbol, hasFlip, color));
        
        // Insertar números 1-9, 2 de cada uno
        for (int number = 1; number <= 9; number++) {
            for (int count = 0; count < 2; count++) {
                symbol = std::to_string(number);
                addCard(new NormalCard(symbol, hasFlip, color));
            }
        }
    }
}

void DeckMaker::createWildcards(bool& hasFlip) {
    for (int color = 0; color < 4; color++) {
        for(int count = 0; count < 2; count++) {
            addCard(new BlockWildcard(hasFlip, color));
            addCard(new ColorWildcard(hasFlip, color));
            addCard(new ReverseWildcard(hasFlip, color));
            addCard(new PlusTwoWildcard(hasFlip, color));
        }
    }
}

void DeckMaker::generateDeck(bool& hasFlip) {
    this->deckStack->clearAndDeleteCards();

    int decksToBuild = this->calculateDeckSize(this->players);
    for (int i = 0; i < decksToBuild; i++) {
        createNormalCards(hasFlip);
        createWildcards(hasFlip);
    }
}

void DeckMaker::shuffleDeck() {
    this->deckStack->shuffle();
}

Stack* DeckMaker::getDeckStack() const {
    return this->deckStack;
}

int DeckMaker::getDeckSize() const {
    return this->deckSize;
}