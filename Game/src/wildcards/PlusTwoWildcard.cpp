#include "PlusTwoWildcard.h"

PlusTwoWildcard::PlusTwoWildcard(string& symbol, bool hasFlip, int iColor) : WildCard(symbol, hasFlip, iColor), drawAmount(2) {
    if(this->hasFlip) drawAmount = 1;
}

PlusTwoWildcard::~PlusTwoWildcard() {}

void PlusTwoWildcard::applyEffect(UnoEngine& engine) {
    //engine.plus(this->getDrawAmount());

}

void PlusTwoWildcard::changeFlip() {
    if (this->flipped) // Si actualmente esta flipped, se cambia a normal
    {
        this->drawAmount = 1;
        this->actualColor = colorsN[this->indexColor];
        return;
    }
    // si no esta flipped se cambia a flipped
    this->drawAmount = 2;
    this->actualColor = colorsF[this->indexColorFlip];
}

int PlusTwoWildcard::getDrawAmount() {
    return drawAmount;
}
void PlusTwoWildcard::setDrawAmount(int amountIndex) {
    this->drawAmount = amountIndex;
}
