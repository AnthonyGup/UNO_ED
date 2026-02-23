#include "Setting.h"

//Stacking
bool Setting::getPlusTwoStacking() {
    return plusTwoStacking;
}

void Setting::setPlusTwoStacking(bool value) {
    plusTwoStacking = value;
}

bool Setting::getPlusFourStacking() {
    return plusFourStacking;
}


void Setting::setPlusFourStacking(bool value) {
    plusFourStacking = value;
}


//+4 dare
bool Setting::getPlusFourDare() {
    return plusFourDare;
}   


void Setting::setPlusFourDare(bool value) {
    plusFourDare = value;
}

//Steal mode
int Setting::getOptionStealMode() {
    return optionStealMode;
}           

void Setting::setOptionStealMode(int value) {
    optionStealMode = value;
}

//Shout UNO
bool Setting::getSoutUno() {
    return soutUno;
}

void Setting::setSoutUno(bool value) {
    soutUno = value;
}

//Win whit black card