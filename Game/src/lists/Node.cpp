#include "Node.h"

Node::Node(Card* value)
{
    this->data = value;
    this->next = nullptr;
    this->prev = nullptr;
}

Card* Node::getData() {
    return data;
}

Node* Node::getNext() {
    return next;
}

Node* Node::getPrev() {
    return prev;
}

void Node::setNext(Node* nextNode) {
    this->next = nextNode;
}

void Node::setPrev(Node* prevNode) {
    this->prev = prevNode;
}