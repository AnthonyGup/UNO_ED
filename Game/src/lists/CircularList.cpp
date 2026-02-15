#include "CircularList.h"
#include "../exceptions/ListException.h"

template <typename T>
CircularList<T>::CircularList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
CircularList<T>::~CircularList() {
    clear();
}

template <typename T>
int CircularList<T>::getSize() { 
    return size;
}

template <typename T>
void CircularList<T>::insertFirst(T* value) {
    Node<T>* newNode = new Node<T>(value);
    if(this->isEmpty()) {
        newNode->setNext(newNode);
        newNode->setPrev(newNode);
        head = newNode;
        tail = newNode;
    } else {
        head->setPrev(newNode);
        newNode->setNext(head);
        newNode->setPrev(tail);
        tail->setNext(newNode);
        head = newNode;
    }
    size++;
}

template <typename T>
void CircularList<T>::insertAt(int index, T* value) {
    if (index < 0 || index > size) {
        throw InvalidIndexException(index, size);
    }
    
    if (this->isEmpty() || index == 0) {
        insertFirst(value);
        return;
    }

    if (index == size) {
        insertLast(value);
        return;
    }

    Node<T>* prevNode = this->getAt(index - 1);
    Node<T>* newNode = new Node<T>(value);
    Node<T>* nextNode = prevNode->getNext();
    newNode->setNext(nextNode);
    newNode->setPrev(prevNode);
    nextNode->setPrev(newNode);
    prevNode->setNext(newNode);
    size++;
}

template <typename T>
Node<T>* CircularList<T>::getAt(int index) {
    if (index < 0 || index >= size || this->isEmpty()) {
        throw InvalidIndexException(index, size);
    }

    Node<T>* current = this->head;

    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return current;
}

template <typename T>
bool CircularList<T>::isEmpty() {
    return this->head == nullptr;
}

template <typename T>
Node<T>* CircularList<T>::getTail() {
    if (this->isEmpty()) {
        throw EmptyListException();
    }
    return tail;
}

template <typename T>
void CircularList<T>::insertLast(T* value) {
    if (this->isEmpty()) {
        insertFirst(value);
        return;
    }

    Node<T>* newNode = new Node<T>(value);
    newNode->setNext(head);
    newNode->setPrev(tail);
    tail->setNext(newNode);
    head->setPrev(newNode);
    tail = newNode;
    size++;
}

template <typename T>
void CircularList<T>::deleteFirst() {
    if (this->isEmpty()) {
        throw EmptyListException();
    }

    // Si solo hay un nodo
    if (head->getNext() == head) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }

    // Para cuando hay más de un nodo
    Node<T>* nodeToDelete = head;
    head = head->getNext();
    tail->setNext(head);
    head->setPrev(tail);
    delete nodeToDelete;
    size--;
}

template <typename T>
void CircularList<T>::deleteLast() {
    if (this->isEmpty()) {
        throw EmptyListException();
    }

    // Si solo hay un nodo
    if (head->getNext() == head) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }

    // Si hay más de un nodo
    Node<T>* nodeToDelete = tail;
    tail = tail->getPrev();
    tail->setNext(head);
    head->setPrev(tail);
    delete nodeToDelete;
    size--;
}

template <typename T>
bool CircularList<T>::deleteAt(int index) {
    if (index < 0 || index >= size) {
        throw InvalidIndexException(index, size);
    }

    if (this->isEmpty()) {
        throw EmptyListException();
    }

    if (index == 0) {
        deleteFirst();
        return true;
    }

    if (index == size - 1) {
        deleteLast();
        return true;
    }

    // Para posiciones intermedias
    Node<T>* prevNode = this->getAt(index - 1);
    Node<T>* nodeToDelete = prevNode->getNext();
    prevNode->setNext(nodeToDelete->getNext());
    nodeToDelete->getNext()->setPrev(prevNode);
    delete nodeToDelete;
    size--;
    return true;
}

template <typename T>
void CircularList<T>::clear() {
    if (this->isEmpty()) {
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < size; i++) {
        Node<T>* temp = current;
        current = current->getNext();
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}