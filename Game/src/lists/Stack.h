#ifndef STACK_H
#define STACK_H

#include "../cards/Card.h"

class Stack {
private:
    Card** array;     // Arreglo de punteros a Card
    int topIndex;     // Índice del elemento en el tope
    int capacity;     // Capacidad del arreglo

public:
    Stack(int size);
    ~Stack();
    
    void insert(Card* value);
    void remove();
    Card* getTop() const;
    bool isEmpty() const;
    int getSize() const;
    void clear();
};

#endif
