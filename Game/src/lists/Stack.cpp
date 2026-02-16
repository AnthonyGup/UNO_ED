#include "Stack.h"
#include "../exceptions/ListException.h"

template <typename T>
Stack<T>::Stack() : top(nullptr), size(0) {}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
void Stack<T>::insert(T* value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->setNext(top);
    top = newNode;
    size++;
}

template <typename T>
T Stack<T>::remove() {
    if (isEmpty()) {
        throw EmptyListException();
    }
    
    T value = top->getData();
    Node<T>* temp = top;
    top = top->getNext();
    delete temp;
    size--;
    return value;
}

template <typename T>
T Stack<T>::getTop() const {
    if (isEmpty()) {
        throw EmptyListException();
    }
    return top->getData();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
int Stack<T>::getSize() const {
    return size;
}

template <typename T>
void Stack<T>::clear() {
    while (top != nullptr) {
        Node<T>* temp = top;
        top = top->getNext();
        delete temp;
    }
    size = 0;
}
