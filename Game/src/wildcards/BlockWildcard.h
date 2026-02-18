#ifndef WILDCARDS_BLOCKWILDCARD_H
#define WILDCARDS_BLOCKWILDCARD_H

#include "../cards/WildCard.h"

class BlockWildcard : public WildCard {
    public:
    BlockWildcard(string& symbol, bool hasFlip, int iColor);
    ~BlockWildcard() override;

    void applyEffect(UnoEngine& engine) override; // Implementación del método para aplicar el efecto de la carta

    
}

#endif