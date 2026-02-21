#include "ReverseWildcard.h"

ReverseWildcard::ReverseWildcard(bool hasFlip, int iColor) : WildCard(*(new string("®")), hasFlip, iColor) {
    if(this->hasFlip) {
        this->setSimbolo(*(new string("®®")), 1);
    }
}


ReverseWildcard::~ReverseWildcard() {
    // Destructor de la carta Reverse Wildcard, no necesita liberar recursos adicionales
}

void ReverseWildcard::applyEffect(UnoEngine& engine) {
    // Implementación del efecto de la carta Reverse Wildcard, invierte el orden de juego en el motor del juego
    //engine.reverseDirection();
}

void ReverseWildcard::changeFlip() {
   //Implementar esto
}