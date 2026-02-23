#ifndef TURN_H
#define TURN_H

#include "Player.h"
#include "../lists/LinkedList.h"

class Turn {
private:
    Player * jugador;
    LinkedList* hand;

public:
    Turn(Player* jugador, LinkedList* hand);
    ~Turn();

    Player* getJugador();
    void setJugador(Player* jugador);

    LinkedList* getHand();
    void setHand(LinkedList* hand);
};

#endif
