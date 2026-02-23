#include "Player.h"

Player::Player() : nombre("") {}

Player::Player(string nombre) : nombre(nombre) {}

Player::~Player () {}

string Player::getNombre() {
    return nombre;
}

void Player::setNombre(string nombre) {
    this->nombre = nombre;
}
