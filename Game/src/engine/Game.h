#ifndef GAME_H
#define GAME_H

#include "UnoEngine.h"
#include "../lists/Stack.h"
#include "../lists/CircularList.h"
#include "../lists/LinkedList.h"
#include "../cards/Card.h"
#include "../cards/WildCard.h"
#include "../cards/NormalCard.h"
#include "../cards/wildcards/BlockWildcard.h"
#include "../cards/wildcards/ColorWildcard.h"
#include "../cards/wildcards/ReverseWildcard.h"
#include "../cards/wildcards/PlusTwoWildcard.h"
#include "../cards/wildcards/PlusFourWildcard.h"



class Game {
    private:
        Stack* deck = nullptr;
        Stack* discardPile = nullptr;
        CircularList* turns = nullptr;

    public:
        Game(Stack *deck, CircularList *turns);
        ~Game();

        void start();
        

};

#endif