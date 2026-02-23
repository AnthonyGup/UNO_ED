#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "../cards/Card.h"

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    bool insertFirst(Card* value);
    void insert(Card* value);
    bool insertAt(int index, Card* value);
    bool deleteAt(int index);
    Card* getAt(int index);
    bool isEmpty();
    int getSize();
    void clear();
};

#endif
