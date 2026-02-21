#include "Card.h"

Card::Card(string& symbol, bool hasFlip, int iColor) : INDEX_COLOR(iColor) {
    this->hasFlip = hasFlip;
    this->setSimbolo(symbol, 0);
    this->actualColor = COLORS_N[iColor];
}

Card::~Card() {}

string Card::center(string& text) {
    string t = text;
    if (t.length() > 2) {
        t = t.substr(0, 2);
    }

    int espacios = 2 - t.length();
    int izq = espacios / 2;
    int der = espacios - izq;

    return string(izq, ' ') + t + string(der, ' ');
}

void Card::setSimbolo(string& sim, int index) {
    this->simbolo[index] = sim;
}

string Card::renderLine(int index, string& valor) {
    if (index == 0) {
        return this->actualColor + "┌────┐" + this->RESET;
    }
    if (index == 1) { 
        return this->actualColor + "│ " + center(valor) + " │" + this->RESET;
    }
    return this->actualColor + "└────┘" + this->RESET;
    /*
        for (int fila = 0; fila < Carta::ALTO; fila++) {
            for (int i = 0; i < numCartas; i++) {
                cout << mano[i]->renderLinea(
                ) << " ";
            }
        cout << endl;
        }
*/
}

bool Card::isFlipped() {
    return flipped; 
}

void Card::setFlipped(bool flipped) {
    this->flipped = flipped;
}

void Card::setHandIndex(int newIndex) {
    this->HandIndex = newIndex;
}

int Card::getHandIndex() {
    return this->HandIndex;
}

void Card::flip() {
    if (this->hasFlip)
	{
		this->setFlipped(!this->isFlipped()); 
		this->changeFlip();
	}
}

void Card::setFlipAtributes(int colorFlip, string& simbolFlip) {
    this->indexColorFlip = colorFlip;
    this->setSimbolo(simbolFlip, 1);
}