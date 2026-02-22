#ifndef WILDCARD_H
#define WILDCARD_H

#include "Card.h"

using UnoEngine = class UnoEngine; // Declaración anticipada para evitar dependencias circulares
class WildCard : public Card {
protected:

public:
    WildCard(string& symbol, bool hasFlip, int iColor);
    ~WildCard() override;

    virtual void applyEffect(UnoEngine& engine) = 0; // Método abstracto para aplicar el efecto de la carta
};

#endif