#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack {
private:
    Node<T>* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}
    
    ~Stack() {
        while (top != nullptr) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        size++;
    }
    
    T pop() {
        if (top == nullptr) return T();
        
        T value = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        size--;
        return value;
    }
    
    T peek() {
        if (top == nullptr) return T();
        return top->data;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    int getSize() {
        return size;
    }
    
    void clear() {
        while (top != nullptr) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
};

#endif
