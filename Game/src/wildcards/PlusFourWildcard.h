#ifndef PLUS_FOUR_WILDCARD_H
#define PLUS_FOUR_WILDCARD_H

#include "WildCard.h"
class PlusFourWildcard : public WildCard {
    public:
        PlusFourWildcard();
        ~PlusFourWildcard() override;

        void applyEffect(UnoEngine& engine) override; // Implementación del efecto específico para esta carta
        void flip() override; // Implementación del método flip específico para esta carta
};
#endif 