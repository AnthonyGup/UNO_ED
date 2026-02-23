#ifndef NODE_H
#define NODE_H

#include "../cards/Card.h"

class Node {
private:
    Card* data;
    Node* next;
    Node* prev;
public:
    Node(Card* value);
    Card* getData();
    void setNext(Node* nextNode);
    void setPrev(Node* prevNode);
    Node* getNext();
    Node* getPrev();
};

#endif
