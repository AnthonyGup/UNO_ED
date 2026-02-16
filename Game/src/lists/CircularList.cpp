#include "CircularList.h"
#include "../exceptions/ListException.h"

template <typename T>
CircularList<T>::CircularList() : head(nullptr), tail(nullptr), size(0), reversed(false) {}

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
    NodeC<T>* newNode = new NodeC<T>(value);
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

    NodeC<T>* prevNode = this->getAt(index - 1);
    NodeC<T>* newNode = new NodeC<T>(value);
    NodeC<T>* nextNode = prevNode->getNext(reversed);
    newNode->setNext(nextNode);
    newNode->setPrev(prevNode);
    nextNode->setPrev(newNode);
    prevNode->setNext(newNode);
    size++;
}

template <typename T>
NodeC<T>* CircularList<T>::getAt(int index) {
    if (index < 0 || index >= size || this->isEmpty()) {
        throw InvalidIndexException(index, size);
    }

    NodeC<T>* current = this->head;

    for (int i = 0; i < index; i++) {
        current = current->getNext(reversed);
    }
    return current;
}

template <typename T>
bool CircularList<T>::isEmpty() {
    return this->head == nullptr;
}

template <typename T>
NodeC<T>* CircularList<T>::getTail() {
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

    NodeC<T>* newNode = new NodeC<T>(value);
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
    if (head->getNext(reversed) == head) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }

    // Para cuando hay más de un nodo
    NodeC<T>* nodeToDelete = head;
    head = head->getNext(reversed);
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
    if (head->getNext(reversed) == head) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }

    // Si hay más de un nodo
    NodeC<T>* nodeToDelete = tail;
    tail = tail->getPrev(reversed);
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
    NodeC<T>* prevNode = this->getAt(index - 1);
    NodeC<T>* nodeToDelete = prevNode->getNext(reversed);
    prevNode->setNext(nodeToDelete->getNext(reversed));
    nodeToDelete->getNext(reversed)->setPrev(prevNode);
    delete nodeToDelete;
    size--;
    return true;
}

template <typename T>
void CircularList<T>::clear() {
    if (this->isEmpty()) {
        return;
    }

    NodeC<T>* current = head;
    for (int i = 0; i < size; i++) {
        NodeC<T>* temp = current;
        current = current->getNext(!reversed);  // Usar dirección normal para limpiar
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Métodos para controlar dirección
template <typename T>
NodeC<T>* CircularList<T>::getNext(NodeC<T>* node) {
    if (node == nullptr) {
        throw std::invalid_argument("Node no puede ser nullptr");
    }
    return node->getNext(reversed);
}

template <typename T>
NodeC<T>* CircularList<T>::getPrev(NodeC<T>* node) {
    if (node == nullptr) {
        throw std::invalid_argument("Node no puede ser nullptr");
    }
    return node->getPrev(reversed);
}

template <typename T>
void CircularList<T>::changeDirection() {
    reversed = !reversed;
}

template <typename T>
bool CircularList<T>::isReversed() const {
    return reversed;
}

template <typename T>
void CircularList<T>::setDirection(bool rev) {
    reversed = rev;
}
