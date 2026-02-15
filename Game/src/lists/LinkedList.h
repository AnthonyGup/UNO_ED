#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    bool insertFirst(T* value);
    void insert(T* value);
    bool insertAt(int index, T* value);
    bool deleteAt(int index);
    T getAt(int index);
    bool isEmpty();
    int getSize();
    void clear();
};

#endif
