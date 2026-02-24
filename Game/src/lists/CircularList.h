#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "NodeC.h"

class Turn; // Forward declaration

class CircularList {
private:
    NodeC* head;
    NodeC* tail;
    int size;
    bool reversed;

public:
    CircularList();
    ~CircularList();

    void insertFirst(Turn* value);
    void insertLast(Turn* value);
    void insertAt(int index, Turn* value);
    void deleteFirst();
    void deleteLast();
    bool deleteAt(int index);
    NodeC* getHead();
    NodeC* getTail();
    NodeC* getAt(int index);
    NodeC* getNext(NodeC* node);
    NodeC* getPrev(NodeC* node);
    int getSize();
    bool isEmpty();
    void clear();

    void changeDirection();
    bool isReversed() const;
    void setDirection(bool rev);
};

#endif
