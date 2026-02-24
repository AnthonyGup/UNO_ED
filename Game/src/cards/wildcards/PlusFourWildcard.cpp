#include "../../engine/Game.h"
#include "PlusFourWildcard.h"

PlusFourWildcard::PlusFourWildcard(bool hasFlip, int iColor) : WildCard("+4", hasFlip, -1) {
    drawAmount = 4;
    setSimbolo("+4", 0);
    if (this->hasFlip) {
        drawAmount = 3;
        setSimbolo("+3", 0);
    }
}

PlusFourWildcard::~PlusFourWildcard() {}

void PlusFourWildcard::applyEffect(Game& engine) {
    engine.plus(this->getDrawAmount(), false, true);
    int selectedColor = engine.selectColor();
    engine.changeColor(selectedColor);
}

void PlusFourWildcard::changeFlip() {
    if (this->flipped)
    {
        this->drawAmount = 3;
        this->actualColor = COLORS_N[0];
        return;
    }
    this->drawAmount = 6;
    this->actualColor = COLORS_F[0];
}

int PlusFourWildcard::getDrawAmount() {
    return drawAmount;
}

void PlusFourWildcard::setDrawAmount(int amountIndex) {
    this->drawAmount = amountIndex;
}

int PlusFourWildcard::getColorIndex() {
    return -1;
}