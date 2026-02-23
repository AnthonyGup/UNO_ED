#include "DeckMaker.h"


DeckMaker::DeckMaker(int players) {
    this->players = players;
    this->deckSize = this->calculateDeckSize(players) * this->CARDS_AMOUNT;
    this->deck = new Card*[this->deckSize];
    this->deckStack = new Stack(this->deckSize);

    for (int i = 0; i < this->deckSize; i++) {
        this->deck[i] = nullptr;
    }
}

DeckMaker::~DeckMaker() {
    for (int i = 0; i < this->deckSize; i++) {
        delete this->deck[i];
    }

    delete[] this->deck;
    delete this->deckStack;
}

int DeckMaker::calculateDeckSize(int players) {
    double base = (static_cast<double>(players - 1) / 6.0) + 1.0;
    return floor(base); // Redondea al entero mas pequeño
}

void DeckMaker::addCard(Card* card, int& insertionIndex) {
    if (insertionIndex >= this->deckSize) {
        delete card;
        return;
    }

    this->deck[insertionIndex] = card;
    insertionIndex++;
}

void DeckMaker::createNormalCards(bool& hasFlip, int& insertionIndex) {
    for (int color = 0; color < 4; color++) {
        // Insertar "0" de cada color
        string symbol = "0";
        addCard(new NormalCard(symbol, hasFlip, color), insertionIndex);
        
        // Insertar números 1-9, 2 de cada uno
        for (int number = 1; number <= 9; number++) {
            for (int count = 0; count < 2; count++) {
                symbol = std::to_string(number);
                addCard(new NormalCard(symbol, hasFlip, color), insertionIndex);
            }
        }
    }
}

void DeckMaker::createWildcards(bool& hasFlip, int& insertionIndex) {
    for (int color = 0; color < 4; color++) {
        for(int count = 0; count < 2; count++) {
            addCard(new BlockWildcard(hasFlip, color), insertionIndex);
            addCard(new ColorWildcard(hasFlip, color), insertionIndex);
            addCard(new ReverseWildcard(hasFlip, color), insertionIndex);
            addCard(new PlusTwoWildcard(hasFlip, color), insertionIndex);
        }
    }
}

void DeckMaker::generateDeck(bool& hasFlip) {
    for (int i = 0; i < this->deckSize; i++) {
        delete this->deck[i];
        this->deck[i] = nullptr;
    }

    int insertionIndex = 0;

    int decksToBuild = this->calculateDeckSize(this->players);
    for (int i = 0; i < decksToBuild; i++) {
        createNormalCards(hasFlip, insertionIndex);
        createWildcards(hasFlip, insertionIndex);
    }
}

void DeckMaker::shuffleDeck() {
    if (this->deckSize <= 1) {
        return;
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    bool* used = new bool[this->deckSize];
    Card** shuffled = new Card*[this->deckSize];

    for (int i = 0; i < this->deckSize; i++) {
        used[i] = false;
        shuffled[i] = nullptr;
    }

    for (int i = 0; i < this->deckSize; i++) {
        int range = this->deckSize;
        int limit = RAND_MAX - (RAND_MAX % range);
        int value;

        int randomIndex;
        do {
            do {
                value = rand();
            } while (value >= limit);

            randomIndex = value % range;
        } while (used[randomIndex]);

        used[randomIndex] = true;
        shuffled[i] = this->deck[randomIndex];
    }

    this->deckStack->clear();
    for (int i = 0; i < this->deckSize; i++) {
        this->deckStack->insert(shuffled[i]);
    }

    delete[] shuffled;
    delete[] used;
}

Card** DeckMaker::getDeck() const {
    return this->deck;
}

Stack* DeckMaker::getDeckStack() const {
    return this->deckStack;
}

int DeckMaker::getDeckSize() const {
    return this->deckSize;
}