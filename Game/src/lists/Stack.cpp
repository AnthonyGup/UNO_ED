#include "Stack.h"
#include "../exceptions/ListException.h"

Stack::Stack(int size) : topIndex(-1), capacity(size) {
    array = new Card*[capacity];
}

Stack::~Stack() {
    delete[] array;
}

void Stack::insert(Card* value) {
    if (topIndex == capacity - 1) {
        throw FullListException();
    }
    
    topIndex++;
    array[topIndex] = value;
}

void Stack::remove() {
    if (isEmpty()) {
        throw EmptyListException();
    }
    
    topIndex--;
}

Card* Stack::getTop() const {
    if (isEmpty()) {
        throw EmptyListException();
    }
    return array[topIndex];
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}

int Stack::getSize() const {
    return topIndex + 1;
}

void Stack::clear() {
    topIndex = -1;
}
