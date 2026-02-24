#include "TurnMaker.h"

TurnMaker::TurnMaker(int *playersAmount, Stack* deck) : playersAmount(playersAmount), DECK(deck) {
    this->players = new Player*[*(this->playersAmount)];
    this->turnos = nullptr;
}
void TurnMaker::createPlayers() {
    for (int i = 0; i < *(this->playersAmount); i++) {
        Player* playerTemp = new Player("Player " + std::to_string(i + 1));
        this->players[i] = playerTemp;
    }
}

void TurnMaker::dealCards() {
    for (int i = 0; i < *(this->playersAmount); i++) {
        LinkedList* hand = new LinkedList();
        for (int j = 0; j < 7; j++) {
            hand->insert(this->DECK->pop());
        }
        this->turnos->insertAt(i, new Turn(this->players[i], hand));
    }
}

void TurnMaker::generateTurns() {
    this->createCircularList();
    this->createPlayers();
    this->dealCards();
}

void TurnMaker::createCircularList() {
    this->turnos = new CircularList();
}

CircularList* TurnMaker::getTurns() {
    return this->turnos;
}

TurnMaker::~TurnMaker() {
    delete[] this->players;
}
