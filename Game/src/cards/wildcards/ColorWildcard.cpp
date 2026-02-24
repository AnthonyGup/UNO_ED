#include "../../engine/Game.h"
#include "ColorWildcard.h"

ColorWildcard::ColorWildcard(bool hasFlip, int iColor) : WildCard("©", hasFlip, -1), colorIndex(-1) {
    this->setSimbolo("©", 0);
}

ColorWildcard::~ColorWildcard() {}

void ColorWildcard::applyEffect(Game& engine) {
    int selectedColor = engine.selectColor();
    this->setColorIndex(selectedColor);
    engine.changeColor(selectedColor);
}

void ColorWildcard::setColorIndex(int index) {
    this->colorIndex = index;
}

int ColorWildcard::getColorIndex() {
    return -1;
}

void ColorWildcard::changeFlip() {
    
}