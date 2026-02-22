#include "ReverseWildcard.h"

ReverseWildcard::ReverseWildcard(bool hasFlip, int iColor) : WildCard(*(new string("®")), hasFlip, iColor) {
    this->setSimbolo(*(new string("®")), 0); // Símbolo para el estado normal
}


ReverseWildcard::~ReverseWildcard() {}

void ReverseWildcard::applyEffect(UnoEngine& engine) {
    //engine.reverseDirection();
}

void ReverseWildcard::changeFlip() {
    if (this->isFlipped()) {
        this->setSimbolo(*(new string("®")), 0); // Símbolo para el estado normal
        this->actualColor = COLORS_N[this->INDEX_COLOR]; // Color para el estado normal
    } else {
        this->setSimbolo(*(new string("®®")), 1); // Símbolo para el estado flipped
        this->actualColor = COLORS_F[this->indexColorFlip]; // Color para el estado flipped
    }
}