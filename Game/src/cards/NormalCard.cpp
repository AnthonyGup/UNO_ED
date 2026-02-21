#include "NormalCard.h"

NormalCard::NormalCard(string& symbol, bool hasFlip, int iColor) : Card(symbol, hasFlip, iColor) {}

NormalCard::~NormalCard() {}

void NormalCard::changeFlip() {
    if (flipped) {
        acutalSymbol = simbolo[0];
        actualColor = COLORS_N[INDEX_COLOR];
    } else {
        acutalSymbol = simbolo[1];
        actualColor = COLORS_F[indexColorFlip];
    }
}
