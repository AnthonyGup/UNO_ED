#include "Setting.h"

// Constructores
Setting::Setting() {
    // Los valores por defecto ya están inicializados en el .h
}

Setting::Setting(bool plusTwo, bool plusFour, bool dare, int stealMode, bool uno) 
    : plusTwoStacking(plusTwo), plusFourStacking(plusFour), 
      plusFourDare(dare), optionStealMode(stealMode), soutUno(uno) {
}

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