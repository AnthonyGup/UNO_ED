#include "BlockWildcard.h"

BlockWildcard::BlockWildcard(bool hasFlip, int iColor) : WildCard(*(new string("Ø")), hasFlip, iColor) {
    this->setSimbolo(*(new string("Ø")), 0);
}

BlockWildcard::~BlockWildcard() {}

void BlockWildcard::applyEffect(UnoEngine& engine) {
    // Lógica para aplicar el efecto de la carta de bloqueo
    // Por ejemplo, podrías hacer que el siguiente jugador pierda su turno
    //engine.skipPlayers(this->indexOfPlayers);
}

void BlockWildcard::changeFlip() {

    if (this->isFlipped()) {
        this->setSimbolo(this->simbolo[0], this->INDEX_COLOR); // Volver al símbolo normal
        this->actualColor = this->COLORS_N[this->INDEX_COLOR]; // Volver al color normal
    } else {
        this->setSimbolo(this->simbolo[1], this->indexColorFlip); // Cambiar al símbolo flipped
        this->actualColor = this->COLORS_F[this->indexColorFlip]; // Cambiar al color flipped
    }
    this->flipped = !this->flipped; // Cambiar el estado de flipped
}