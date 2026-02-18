#include "PlusFourWildcard.h"

PlusFourWildcard::PlusFourWildcard(string& symbol, bool hasFlip, int iColor) : WildCard(symbol, hasFlip, iColor) {
    drawAmount = 4;
    if (this->hasFlip) drawAmount = 3;
}

PlusFourWildcard::~PlusFourWildcard() {}

void PlusFourWildcard::applyEffect(UnoEngine& engine) {
    //engine.plus(this->getDrawAmount());
    
    //engine.changeColor(engine.selectColor());
}

void PlusFourWildcard::changeFlip() {
    if (this->flipped) // Si actualmente esta flipped, se cambia a normal
    {
        this->drawAmount = 3;
        this->actualColor = colorsN[this->indexColor];
        return;
    }
    // si no esta flipped se cambia a flipped
    this->drawAmount = 6;
    this->actualColor = colorsF[this->indexColorFlip];
}