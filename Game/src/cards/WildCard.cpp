#include "WildCard.h"

WildCard::WildCard() : chosenColor(-1), flipChosenColor(-1), hasFlip(false) {}

WildCard::~WildCard() {}

void WildCard::setChosenColor(int color) {
    chosenColor = color;
}

int WildCard::getChosenColor() {
    return chosenColor;
}

void WildCard::setFlipChosenColor(int color) {
    flipChosenColor = color;
    hasFlip = true;
}

int WildCard::getChosenColor(bool flipped) {
    if (flipped && hasFlip) {
        return flipChosenColor;
    }
    return chosenColor;
}

void WildCard::enableFlipSide() {
    hasFlip = true;
}

bool WildCard::hasFlipSide() {
    return hasFlip;
}
