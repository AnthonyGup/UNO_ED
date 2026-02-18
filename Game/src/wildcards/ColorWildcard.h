#ifndef COLORWILDCARD_H
#define COLORWILDCARD_H

#include "../cards/WildCard.h"

class ColorWildcard : public WildCard {

    private:
    int colorIndex; // Índice del color seleccionado por el jugador (0-3)

    public:
        ColorWildcard(string& symbol, bool hasFlip, int iColor);
        ~ColorWildcard() override;

        void applyEffect(UnoEngine& engine) override; // Implementación del método para aplicar el efecto de la carta de cambio de color

        void setColorIndex(int index);
        int getColorIndex();
};


#endif 

