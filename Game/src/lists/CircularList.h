#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "Node.h"

template <typename T>
class CircularList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    CircularList();
    ~CircularList();
    
    void insertFirst(T* value);
    void insertLast(T* value);
    void insertAt(int index, T* value);
    void deleteFirst();
    void deleteLast();
    bool deleteAt(int index);
    Node<T>* getTail();
    Node<T>* getAt(int index);
    int getSize();
    bool isEmpty();

    void clear();
};

#endif
