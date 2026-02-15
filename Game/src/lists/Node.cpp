#include "Node.h"

template <typename T>
Node<T>::Node(T* value)
{
    this->data = value;
    this->next = nullptr;
    this->prev = nullptr;
}

template <typename T>
T* Node<T>::getData() {
    return data;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <typename T>
Node<T>* Node<T>::getPrev() {
    return prev;
}
