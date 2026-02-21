#ifndef NORMALCARD_H
#define NORMALCARD_H

#include "Card.h"

class NormalCard : public Card { 
    private:
        
    public:
        NormalCard(string& symbol, bool hasFlip, int iColor);
        ~NormalCard();

        void changeFlip() override;
};

#endif