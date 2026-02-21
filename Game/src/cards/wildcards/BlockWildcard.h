#ifndef WILDCARDS_BLOCKWILDCARD_H
#define WILDCARDS_BLOCKWILDCARD_H

#include "../WildCard.h"

class BlockWildcard : public WildCard {
    public:
    BlockWildcard(bool hasFlip, int iColor);
    ~BlockWildcard() override;

    void applyEffect(UnoEngine& engine) override; // Implementación del método para aplicar el efecto de la carta

    void changeFlip() override; // Implementación del método para cambiar el estado de flip de la carta
    
};

#endif