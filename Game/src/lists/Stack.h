#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack {
private:
    Node<T>* top;
    int size;

public:
    Stack();
    ~Stack();
    
    void insert(T* value);
    void remove();
    T* getTop() const;
    bool isEmpty() const;
    int getSize() const;
    void clear();
};

#endif
