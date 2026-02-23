#include "Stack.h"
#include "../exceptions/ListException.h"
#include <cstdlib>
#include <ctime>

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

void Stack::shuffle() {
    if (topIndex <= 0) {
        return;
    }

    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }

    for (int i = topIndex; i > 0; i--) {
        int range = i + 1;
        int limit = RAND_MAX - (RAND_MAX % range);
        int value;

        do {
            value = rand();
        } while (value >= limit);

        int j = value % range;

        Card* temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void Stack::remove() {
    if (isEmpty()) {
        throw EmptyListException();
    }

    topIndex--;
}

Card* Stack::pop() {
    if (isEmpty()) {
        throw EmptyListException();
    }

    Card* card = array[topIndex];
    topIndex--;
    return card;
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

void Stack::clearAndDeleteCards() {
    while (!isEmpty()) {
        Card* card = pop();
        delete card;
    }
}
