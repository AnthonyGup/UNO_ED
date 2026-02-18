#ifndef PLUSTWO_WILDCARD_H
#define PLUSTWO_WILDCARD_H

#include "../cards/WildCard.h"
#include "../engine/UnoEngine.h"

class PlusTwoWildcard : public WildCard {
private:

    int drawAmount; // Cantidad de cartas que el siguiente jugador debe robar (1 o 2 dependiendo del estado flip)

public:
    PlusTwoWildcard(string& symbol, bool hasFlip, int iColor);
    ~PlusTwoWildcard() override;
    void applyEffect(UnoEngine& engine) override;

    void changeFlip() override;

    int getDrawAmount();
    void setDrawAmount(int amountIndex);
};

#endif