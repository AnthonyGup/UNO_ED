#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

using namespace std;

class Menu {
private:
    const string nombreJuego = "UNO";
    
    void limpiarPantalla();
    void mostrarLinea(int ancho);

public:
    Menu();
    
    void mostrarMenuPrincipal();
    
    int obtenerOpcion(int minimo, int maximo);
    
    ~Menu();
};

#endif