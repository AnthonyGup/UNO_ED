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

    
    void plus(int amount); // Método para aplicar el efecto d +1, +2, +3, +4 o +6 dependiendo del tipo de WildCard
    void changeColor(int colorIndex); // Método para cambiar el color actual de la carta
};

#endif
