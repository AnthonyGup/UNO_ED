#ifndef UNO_ENGINE_H
#define UNO_ENGINE_H

#include "../menus/Menu.h"
#include "../exceptions/InputException.h"
#include "settings/Setting.h"
#include <string>
#include <iostream>

using namespace std;

class UnoEngine {
private:
    Menu menu;
    Setting configuration;
    bool juegoEnCurso;
    
    void inicializarJuego();
    void manejarInicioJuego();
    void manejarConfiguracionPersonalizada();
    void configurarStacking();
    void configurarDare();
    void configurarStealMode();
    void configurarSoutUno();

public:
    UnoEngine();
    ~UnoEngine();
    
    void ejecutar();
};

#endif
