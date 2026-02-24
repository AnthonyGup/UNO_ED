#include "Turn.h"

Turn::Turn(Player *jugador, LinkedList *hand) : jugador(jugador), hand(hand)
{
    if (this->hand == nullptr)
    {
        this->hand = new LinkedList();
    }
}

Turn::~Turn()
{
    delete jugador;
    delete hand;
}

Player *Turn::getJugador()
{
    return jugador;
}

void Turn::setJugador(Player *jugador)
{
    if (this->jugador == jugador)
    {
        return;
    }

    delete this->jugador;
    this->jugador = jugador;
}

LinkedList *Turn::getHand()
{
    return hand;
}

void Turn::setHand(LinkedList *hand)
{
    if (this->hand == hand)
    {
        return;
    }

    delete this->hand;
    this->hand = hand;

    if (this->hand == nullptr)
    {
        this->hand = new LinkedList();
    }
}
