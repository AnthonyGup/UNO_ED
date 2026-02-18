#ifndef REVERSEWILDCARD_H
#define REVERSEWILDCARD_H

#include "../cards/WildCard.h"

class ReverseWildcard : public WildCard {

    public:
    ReverseWildcard(string& symbol, bool hasFlip, int iColor);
    ~ReverseWildcard() override;

    void applyEffect(UnoEngine& engine) override; // Implementación del método para aplicar el efecto de la carta Reverse Wildcard

};

#endif