#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <limits>
#include "../exceptions/InputException.h"
#include "../engine/settings/Setting.h"

using namespace std;

class Menu {
private:
    const string nombreJuego = "UNO";
    bool iniciarJuego = false;
    
    void limpiarPantalla();
    /**
     * Muestra una línea horizontal de un ancho específico.
     * @param ancho El número de caracteres que tendrá la línea.
     */
    void mostrarLinea(int ancho);
    
    /**
     * Limpia el buffer de entrada de forma segura
     */
    void limpiarBuffer();

public:
    Menu();
    int obtenerOpcion(int minimo, int maximo);
    
    /**
     * Muestra el menú principal del juego, con opciones para iniciar partida, ver reglas, configurar y salir.
     */
    void mostrarMenuPrincipal();

    /**
     * Muestra las reglas del juego UNO, explicando el objetivo, las cartas especiales y cómo se juega.
     */
    void mostrarReglas();

    /**
     * Permite cambiar alguans reglas del juego
     */
    void pedirConfiguracion();

    /**
     * Muestra el menú para elegir la cantidad de jugadores.
     */
    void pedirCantidadJugadores();

    /**
     * Muestra las configuraciones y lo que puede cambiar
     */
    void mostrarConfiguracion();
    void mostrarConfiguracion(Setting& configuration);
    void mostrarMenuStacking(Setting& configuration);
    void mostrarMenuDare(Setting& configuration);
    void mostrarMenuStealMode(Setting& configuration);
    void mostrarMenuSoutUno(Setting& configuration);
    void pausarPantalla();

    ~Menu();

};

#endif