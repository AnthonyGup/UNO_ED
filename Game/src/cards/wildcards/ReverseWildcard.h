#ifndef REVERSEWILDCARD_H
#define REVERSEWILDCARD_H

#include "../WildCard.h"

class ReverseWildcard : public WildCard {

    public:
    ReverseWildcard(bool hasFlip, int iColor);
    ~ReverseWildcard() override;

    void applyEffect(UnoEngine& engine) override; // Implementación del método para aplicar el efecto de la carta Reverse Wildcard
    void changeFlip() override; // Implementación del método para cambiar el estado de flip de la carta Reverse Wildcard
};

#endif