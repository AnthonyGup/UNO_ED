#include "ColorWildcard.h"

ColorWildcard::ColorWildcard(string& symbol, bool hasFlip, int iColor) : WildCard(symbol, hasFlip, iColor), colorIndex(iColor) {}

ColorWildcard::~ColorWildcard() {}

void ColorWildcard::applyEffect(UnoEngine& engine) {
    // engine.changeColor(colorIndex); // Llama al método del motor del juego para cambiar el color actual a colorIndex4
}

void ColorWildcard::setColorIndex(int index) {
    this->colorIndex = index;
}

int ColorWildcard::getColorIndex() {
    return this->colorIndex;
}