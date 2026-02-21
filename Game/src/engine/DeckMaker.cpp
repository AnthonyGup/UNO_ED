#include "DeckMaker.h"


DeckMaker::DeckMaker(int players) {
    this->players = players;
    this->deck = new Stack(this->calculateDeckSize(players) * this->CARDS_AMOUNT);
}

DeckMaker::~DeckMaker() {
    delete this->deck;
}

int DeckMaker::calculateDeckSize(int players) {
    double base = ((players - 1) / 6) + 1;
    return floor(base); // Redondea al entero mas pequeño
}


void DeckMaker::createNormalCards(bool& hasFlip) {
    for (int color = 0; color < 4; color++) {
        // Insertar "0" de cada color
        string symbol = "0";
        deck->insert(new NormalCard(symbol, hasFlip, color));
        
        // Insertar números 1-9, 2 de cada uno
        for (int number = 1; number <= 9; number++) {
            for (int count = 0; count < 2; count++) {
                symbol = std::to_string(number);
                deck->insert(new NormalCard(symbol, hasFlip, color));
            }
        }
    }
}

void DeckMaker::createWildcards(bool& hasFlip) {
    for (int color = 0; color < 4; color++) {
        for(int count = 0; count < 2; count++) {
            deck->insert(new BlockWildcard(hasFlip, color));
            deck->insert(new ColorWildcard(hasFlip, color));
            deck->insert(new ReverseWildcard(hasFlip, color));
            deck->insert(new PlusTwoWildcard(hasFlip, color));
        }
    }
}