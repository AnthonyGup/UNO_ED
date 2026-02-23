#include "NodeC.h"

NodeC::NodeC(Turn* value) : data(value), next(nullptr), prev(nullptr) {}

NodeC::~NodeC() {
    // El data es responsabilidad del usuario
}

Turn* NodeC::getData() const {
    return data;
}

NodeC* NodeC::getNext(bool reversed) const {
    if (reversed) {
        return prev;
    }
    return next;
}

NodeC* NodeC::getPrev(bool reversed) const {
    if (reversed) {
        return next;
    }
    return prev;
}

void NodeC::setData(Turn* value) {
    data = value;
}

void NodeC::setNext(NodeC* node) {
    next = node;
}

void NodeC::setPrev(NodeC* node) {
    prev = node;
}
