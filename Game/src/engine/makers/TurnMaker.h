#ifndef TURNMAKER_H
#define TURNMAKER_H

#include "../../lists/CircularList.h"
#include "DeckMaker.h"
#include "../../engine/Player.h"
#include "../Turn.h"

class TurnMaker {
    private:
        Stack* DECK;
        CircularList* turnos;
        Player** players;
        int* playersAmount;

        void createPlayers();
        void dealCards();
        void createCircularList();
    public:
        TurnMaker(int* playersAmount, Stack* deck);
        ~TurnMaker();

        void generateTurns();

        CircularList* getTurns();
};

#endif