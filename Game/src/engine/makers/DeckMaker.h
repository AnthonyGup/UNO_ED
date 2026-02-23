#ifndef DECKMAKER_H
#define DECKMAKER_H

#include <string>
#include <cmath>
#include "../../lists/Stack.h"
#include "../../cards/Card.h"
#include "../../cards/NormalCard.h"
#include "../../cards/WildCard.h"
#include "../../cards/wildcards/BlockWildcard.h"
#include "../../cards/wildcards/ColorWildcard.h"
#include "../../cards/wildcards/ReverseWildcard.h"
#include "../../cards/wildcards/PlusTwoWildcard.h"

    class DeckMaker {

        private:
            const int CARDS_AMOUNT = 108;
            int deckSize;
            int players;

            Stack* deckStack;

            int calculateDeckSize(int players);
            void addCard(Card* card);
            void createNormalCards(bool& hasFlip);
            void createWildcards(bool& hasFlip);
        public:
            DeckMaker(int players);
            ~DeckMaker();

            void generateDeck(bool& hasFlip);

            void shuffleDeck();

            Stack* getDeckStack() const;
            int getDeckSize() const;
    };

#endif