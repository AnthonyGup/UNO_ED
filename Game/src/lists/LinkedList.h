#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "../cards/Card.h"

class LinkedList {
private:
    Node* head;
    int size;

    bool isOnlyDigits(string text);
    int toNumber(string text);
    bool isColorlessOrNumberless(Card* card);

    void swapNodeData(Node* a, Node* b);
    bool shouldGoBeforeOrEqual(Card* left, Card* right);
    Node* partition(Node* low, Node* high);
    void quickSortRec(Node* low, Node* high);
    Node* getTail(Node* node);

public:
    LinkedList();
    ~LinkedList();

    bool insertFirst(Card* value);
    void insert(Card* value);
    bool insertAt(int index, Card* value);
    bool deleteAt(int index);
    Card* getAt(int index);
    bool isEmpty();
    int getSize();
    void clear();
    void sortCardsQuickSort();
};

#endif
