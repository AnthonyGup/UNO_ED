#ifndef PLUS_FOUR_WILDCARD_H
#define PLUS_FOUR_WILDCARD_H

#include "../WildCard.h"
#include <random>
class PlusFourWildcard : public WildCard {
    private:
        int drawAmount;

    public:
        PlusFourWildcard(bool hasFlip, int iColor);
        ~PlusFourWildcard() override;
        void applyEffect(UnoEngine& engine) override; // Implementación del efecto específico para esta carta

        void changeFlip() override; 

        void setDrawAmount(int amountIndex);
        int getDrawAmount();
        int getColorIndex();
};
#endif 