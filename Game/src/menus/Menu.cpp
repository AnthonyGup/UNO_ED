#include "Menu.h"

using namespace std;

Menu::Menu() : nombreJuego("UNO") {}

Menu::~Menu() {
    // Liberar recursos si es necesario
}

void Menu::limpiarPantalla() {
    system("cls");  // En Windows
    // Linux: system("clear");
}

void Menu::mostrarLinea(int ancho) {
    for (int i = 0; i < ancho; i++) {
        cout << "=";
    }
    cout << endl;
}

void Menu::mostrarMenuPrincipal() {
    limpiarPantalla();
    mostrarLinea(40);
    cout << "   BIENVENIDO A " << nombreJuego << endl;
    mostrarLinea(40);
    cout << "1. Iniciar Juego" << endl;
    cout << "2. Reglas" << endl;
    cout << "3. Salir" << endl;
    mostrarLinea(40);
}

int Menu::obtenerOpcion(int minimo, int maximo) {
    int opcion;
    bool valida = false;
    
    while (!valida) {
        cout << "Ingresa tu opcion (" << minimo << "-" << maximo << "): "<< endl;
        cin >> opcion;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida. Intenta de nuevo." << endl;
        } else if (opcion >= minimo && opcion <= maximo) {
            valida = true;
        } else {
            cout << "Opción fuera de rango." << endl;
        }
    }
    
    return opcion;
}