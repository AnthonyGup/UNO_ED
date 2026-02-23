#ifndef DECKMAKER_H
#define DECKMAKER_H

#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "../lists/Stack.h"
#include "../cards/Card.h"
#include "../cards/NormalCard.h"
#include "../cards/WildCard.h"
#include "../cards/wildcards/BlockWildcard.h"
#include "../cards/wildcards/ColorWildcard.h"
#include "../cards/wildcards/ReverseWildcard.h"
#include "../cards/wildcards/PlusTwoWildcard.h"

    class DeckMaker {

        private:
            const int CARDS_AMOUNT = 108;
            int deckSize;
            int players;

            Card** deck;
            Stack* deckStack;

            int calculateDeckSize(int players);
            void addCard(Card* card, int& insertionIndex);
            void createNormalCards(bool& hasFlip, int& insertionIndex);
            void createWildcards(bool& hasFlip, int& insertionIndex);
        public:
            DeckMaker(int players);
            ~DeckMaker();

            void generateDeck(bool& hasFlip);

            void shuffleDeck();

            Card** getDeck() const;
            Stack* getDeckStack() const;
            int getDeckSize() const;
    };

#endif