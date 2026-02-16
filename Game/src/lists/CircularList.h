#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "NodeC.h"

template <typename T>
class CircularList {
private:
    NodeC<T>* head;
    NodeC<T>* tail;
    int size;
    bool reversed;  // true = dirección inversa, false = dirección normal

public:
    CircularList();
    ~CircularList();
    
    void insertFirst(T* value);
    void insertLast(T* value);
    void insertAt(int index, T* value);
    void deleteFirst();
    void deleteLast();
    bool deleteAt(int index);
    NodeC<T>* getTail();
    NodeC<T>* getAt(int index);
    NodeC<T>* getNext(NodeC<T>* node);
    NodeC<T>* getPrev(NodeC<T>* node);
    int getSize();
    bool isEmpty();
    void clear();
    
    // Métodos para controlar dirección
    void changeDirection();
    bool isReversed() const;
    void setDirection(bool rev);
};

#endif
