#include "Card.h"

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

string Card::renderLine(int index, string& valor) {
    if (index == 0) return "┌────┐";
    if (index == 1) return "│ " + center(valor) + " │";
    return "└────┘";
}