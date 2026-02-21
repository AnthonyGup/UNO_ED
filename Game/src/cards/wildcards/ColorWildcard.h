#ifndef COLORWILDCARD_H
#define COLORWILDCARD_H

#include "../WildCard.h"

class ColorWildcard : public WildCard {

    private:
    int colorIndex; // Índice del color seleccionado por el jugador (0-3)

    public:
        ColorWildcard(bool hasFlip, int iColor);
        ~ColorWildcard() override;

        void applyEffect(UnoEngine& engine) override; // Implementación del método para aplicar el efecto de la carta de cambio de color
        void changeFlip() override; // Implementación del método para cambiar el estado de flip de la carta

        void setColorIndex(int index);
        int getColorIndex();
};


#endif 

