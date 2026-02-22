#include "PlusFourWildcard.h"

PlusFourWildcard::PlusFourWildcard(bool hasFlip, int iColor) : WildCard(*(new string("+4")), hasFlip, iColor) {
    drawAmount = 4;
    setSimbolo(*(new string("+4")), 0);
    if (this->hasFlip) {
        drawAmount = 3;
        setSimbolo(*(new string("+3")), 0);
    }
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
        this->actualColor = COLORS_N[this->INDEX_COLOR];
        return;
    }
    // si no esta flipped se cambia a flipped
    this->drawAmount = 6;
    this->actualColor = COLORS_F[this->indexColorFlip];
}

int PlusFourWildcard::getColorIndex() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    return dis(gen); // Devuelve un número aleatorio entre 0 y 3 para seleccionar un color al azar
}