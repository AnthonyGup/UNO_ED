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

template <typename T>
void Node<T>::setNext(Node<T>* nextNode) {
    this->next = nextNode;
}

template <typename T>
void Node<T>::setPrev(Node<T>* prevNode) {
    this->prev = prevNode;
}