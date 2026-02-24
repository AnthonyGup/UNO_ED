#include <iostream>
#include "engine/UnoEngine.h"

#ifdef _WIN32
#include <windows.h>
#ifndef CP_UTF8
#define CP_UTF8 65001
#endif
#endif

using namespace std;

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    
    UnoEngine juego; 
    juego.ejecutar();
    
    return 0;
}