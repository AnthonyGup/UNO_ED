 #include "Game.h"

Game::Game(Stack *deck, CircularList *turns) : deck(deck), turns(turns) {}

Game::~Game() {
    delete deck;
    delete turns;
}


 