#ifndef UNO_ENGINE_H
#define UNO_ENGINE_H

#include "../menus/Menu.h"
#include "makers/DeckMaker.h"
#include "../exceptions/InputException.h"
#include "settings/Setting.h"
#include "makers/TurnMaker.h"
#include <string>
#include <iostream>

using namespace std;

class UnoEngine {
private:
    Menu menu;

    CircularList *turns;
    Setting configuration;
    Stack* deck;


    bool juegoEnCurso;
    int cantidadJugadores;
    
    void inicializarJuego();
    void manejarInicio();
    void solicitarJugadores();
    void configurarPerzonalizada();
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
