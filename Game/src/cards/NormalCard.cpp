#include "NormalCard.h"

NormalCard::NormalCard(int color, int number) {
    this->color = color;
    this->number = number;
    this->index = -1; // Inicialmente sin asignar
	this->flipColor = -1;
	this->flipNumber = -1;
	this->hasFlip = false; // Por defecto, no tiene lado flip
}

NormalCard::~NormalCard() {}

int NormalCard::getColor() {
	return color;
}

int NormalCard::getNumber() {
	return number;
}

int NormalCard::getColor(bool flipped) {
	if (flipped && hasFlip) {
		return flipColor;
	}
	return color;
}

int NormalCard::getNumber(bool flipped) {
	if (flipped && hasFlip) {
		return flipNumber;
	}
	return number;
}

int NormalCard::getIndex() const {
	return index;
}

void NormalCard::setIndex(int newIndex) {
	index = newIndex;
}

void NormalCard::setFlipSide(int newColor, int newNumber) {
	flipColor = newColor;
	flipNumber = newNumber;
	hasFlip = true;
}

bool NormalCard::hasFlipSide() {
	return hasFlip;
}
