#ifndef PLUS_FOUR_WILDCARD_H
#define PLUS_FOUR_WILDCARD_H

#include "../cards/WildCard.h"
class PlusFourWildcard : public WildCard {
    private:
        int drawAmount;

    public:
        PlusFourWildcard(string& symbol, bool hasFlip, int iColor);
        ~PlusFourWildcard() override;
        void applyEffect(UnoEngine& engine) override; // Implementación del efecto específico para esta carta

        void changeFlip() override; 

        void setDrawAmount(int amountIndex);
        int getDrawAmount();
};
#endif 