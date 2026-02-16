#ifndef NORMALCARD_H
#define NORMALCARD_H

#include "Card.h"

class NormalCard : public Card { 
    private:
        int color; // 0 = rojo, 1 = amarillo, 2 = azul, 3 = verde
        int number; // 0-9

        int flipColor; // 0 = rosa, 1 = naranja, 2 = turquesa, 3 = violeta
        int flipNumber;
        bool hasFlip;

        int index; // Indice para identificar su posicion en la mano del jugador

    public:
        NormalCard(int color, int number);
        ~NormalCard() override;

        int getColor();
        int getNumber();
        int getColor(bool flipped);
        int getNumber(bool flipped);
        int getIndex() const;

        void setIndex(int newIndex);
        void setFlipSide(int newColor, int newNumber);
        bool hasFlipSide();
};

#endif