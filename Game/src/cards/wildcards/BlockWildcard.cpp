#include "../../engine/Game.h"
#include "BlockWildcard.h"

BlockWildcard::BlockWildcard(bool hasFlip, int iColor) : WildCard("Ø", hasFlip, iColor) {
    this->setSimbolo("Ø", 0);
}

BlockWildcard::~BlockWildcard() {}

void BlockWildcard::applyEffect(Game& engine) {
    // Lógica para aplicar el efecto de la carta de bloqueo
    // El siguiente jugador pierde su turno
    engine.skipNextPlayer();
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