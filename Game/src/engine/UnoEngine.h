#ifndef UNO_ENGINE_H
#define UNO_ENGINE_H

#include "../menus/Menu.h"
#include <string>

using namespace std;

class UnoEngine {
private:
    Menu menu;
    bool juegoEnCurso;
    
    void inicializarJuego();

public:
    UnoEngine();
    
    void ejecutar();
    
    ~UnoEngine();
};

#endif
