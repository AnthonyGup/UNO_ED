#include "PlusTwoWildcard.h"

PlusTwoWildcard::PlusTwoWildcard(bool hasFlip, int iColor) : WildCard(*(new string("+2")), hasFlip, iColor), drawAmount(2) {
    drawAmount = 2;
    this->setSimbolo(*(new string("+2")), 0);
    if(this->hasFlip) {
        this->drawAmount = 1;
        this->setSimbolo(*(new string("+1")), 0);
    }
}

PlusTwoWildcard::~PlusTwoWildcard() {}

void PlusTwoWildcard::applyEffect(UnoEngine& engine) {
    //engine.plus(this->getDrawAmount());

}

void PlusTwoWildcard::changeFlip() {
    if (this->flipped) // Si actualmente esta flipped, se cambia a normal
    {
        this->drawAmount = 1;
        this->actualColor = COLORS_N[this->INDEX_COLOR];
        return;
    }
    // si no esta flipped se cambia a flipped
    this->drawAmount = 2;
    this->actualColor = COLORS_F[this->indexColorFlip];
}

int PlusTwoWildcard::getDrawAmount() {
    return drawAmount;
}
void PlusTwoWildcard::setDrawAmount(int amountIndex) {
    this->drawAmount = amountIndex;
}
