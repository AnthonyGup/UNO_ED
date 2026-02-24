#include "../../engine/Game.h"
#include "ReverseWildcard.h"

ReverseWildcard::ReverseWildcard(bool hasFlip, int iColor) : WildCard("®", hasFlip, iColor) {
    this->setSimbolo("®", 0); // Símbolo para el estado normal
}


ReverseWildcard::~ReverseWildcard() {}

void ReverseWildcard::applyEffect(Game& engine) {
    engine.reverseDirection();
}

void ReverseWildcard::changeFlip() {
    if (this->isFlipped()) {
        this->setSimbolo("®", 0); // Símbolo para el estado normal
        this->actualColor = COLORS_N[this->INDEX_COLOR]; // Color para el estado normal
    } else {
        this->setSimbolo("®®", 1); // Símbolo para el estado flipped
        this->actualColor = COLORS_F[this->indexColorFlip]; // Color para el estado flipped
    }
}