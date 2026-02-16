#include "NodeC.h"

template <typename T>
NodeC<T>::NodeC(T* value) : data(value), next(nullptr), prev(nullptr) {}

template <typename T>
NodeC<T>::~NodeC() {
    // El data es responsabilidad del usuario
}

template <typename T>
T* NodeC<T>::getData() const {
    return data;
}

template <typename T>
NodeC<T>* NodeC<T>::getNext(bool reversed) const {
    // Si reversed es true, entendemos la dirección al revés
    // next devuelve prev y prev devuelve next
    if (reversed) {
        return prev;
    }
    return next;
}

template <typename T>
NodeC<T>* NodeC<T>::getPrev(bool reversed) const {
    // Si reversed es true, entendemos la dirección al revés
    if (reversed) {
        return next;
    }
    return prev;
}

template <typename T>
void NodeC<T>::setData(T* value) {
    data = value;
}

template <typename T>
void NodeC<T>::setNext(NodeC<T>* node) {
    next = node;
}

template <typename T>
void NodeC<T>::setPrev(NodeC<T>* node) {
    prev = node;
}
