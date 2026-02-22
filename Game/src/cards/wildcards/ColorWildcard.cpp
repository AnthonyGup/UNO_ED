#include "ColorWildcard.h"

ColorWildcard::ColorWildcard(bool hasFlip, int iColor) : WildCard(*(new string("©")), hasFlip, iColor), colorIndex(iColor) {
    this->setSimbolo(*(new string("©")), 0); // Símbolo para el estado normal    
}

ColorWildcard::~ColorWildcard() {}

void ColorWildcard::applyEffect(UnoEngine& engine) {
    // engine.changeColor(colorIndex); // Llama al método del motor del juego para cambiar el color actual a colorIndex4
}

void ColorWildcard::setColorIndex(int index) {
    this->colorIndex = index;
}

int ColorWildcard::getColorIndex() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    return dis(gen); // Devuelve un número aleatorio entre 0 y 3 para seleccionar un color al azar
}

void ColorWildcard::changeFlip() {
    
}