#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
private:
    string nombre;

public:
    Player();
    Player(string nombre);
    ~Player();

    string getNombre();
    void setNombre(string nombre);
};

#endif
