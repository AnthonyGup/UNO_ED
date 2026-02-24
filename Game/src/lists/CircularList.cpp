#include "CircularList.h"
#include "../exceptions/ListException.h"
#include "../engine/Turn.h"

CircularList::CircularList() : head(nullptr), tail(nullptr), size(0), reversed(false) {}

CircularList::~CircularList()
{
    clear();
}

int CircularList::getSize()
{
    return size;
}

void CircularList::insertFirst(Turn *value)
{
    NodeC *newNode = new NodeC(value);
    if (this->isEmpty())
    {
        newNode->setNext(newNode);
        newNode->setPrev(newNode);
        head = newNode;
        tail = newNode;
    }
    else
    {
        head->setPrev(newNode);
        newNode->setNext(head);
        newNode->setPrev(tail);
        tail->setNext(newNode);
        head = newNode;
    }
    size++;
}

void CircularList::insertAt(int index, Turn *value)
{
    if (index < 0 || index > size)
    {
        throw InvalidIndexException(index, size);
    }

    if (this->isEmpty() || index == 0)
    {
        insertFirst(value);
        return;
    }

    if (index == size)
    {
        insertLast(value);
        return;
    }

    NodeC *prevNode = this->getAt(index - 1);
    NodeC *newNode = new NodeC(value);
    NodeC *nextNode = prevNode->getNext(reversed);
    newNode->setNext(nextNode);
    newNode->setPrev(prevNode);
    nextNode->setPrev(newNode);
    prevNode->setNext(newNode);
    size++;
}

NodeC *CircularList::getAt(int index)
{
    if (index < 0 || index >= size || this->isEmpty())
    {
        throw InvalidIndexException(index, size);
    }

    NodeC *current = this->head;

    for (int i = 0; i < index; i++)
    {
        current = current->getNext(reversed);
    }
    return current;
}

bool CircularList::isEmpty()
{
    return this->head == nullptr;
}

NodeC *CircularList::getTail()
{
    if (this->isEmpty())
    {
        throw EmptyListException();
    }
    return tail;
}

NodeC *CircularList::getHead()
{
    if (this->isEmpty())
    {
        throw EmptyListException();
    }
    return head;
}

void CircularList::insertLast(Turn *value)
{
    if (this->isEmpty())
    {
        insertFirst(value);
        return;
    }

    NodeC *newNode = new NodeC(value);
    newNode->setNext(head);
    newNode->setPrev(tail);
    tail->setNext(newNode);
    head->setPrev(newNode);
    tail = newNode;
    size++;
}

void CircularList::deleteFirst()
{
    if (this->isEmpty())
    {
        throw EmptyListException();
    }

    // Si solo hay un nodo
    if (head->getNext(reversed) == head)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }

    // Para cuando hay más de un nodo
    NodeC *nodeToDelete = head;
    head = head->getNext(reversed);
    tail->setNext(head);
    head->setPrev(tail);
    delete nodeToDelete;
    size--;
}

void CircularList::deleteLast()
{
    if (this->isEmpty())
    {
        throw EmptyListException();
    }

    // Si solo hay un nodo
    if (tail->getPrev(reversed) == tail)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }

    NodeC *nodeToDelete = tail;
    tail = tail->getPrev(reversed);
    tail->setNext(head);
    head->setPrev(tail);
    delete nodeToDelete;
    size--;
}

bool CircularList::deleteAt(int index)
{
    if (index < 0 || index >= size || this->isEmpty())
    {
        throw InvalidIndexException(index, size);
    }

    if (index == 0)
    {
        deleteFirst();
        return true;
    }
    if (index == size - 1)
    {
        deleteLast();
        return true;
    }

    NodeC *nodeToDelete = getAt(index);
    NodeC *prevNode = nodeToDelete->getPrev(reversed);
    NodeC *nextNode = nodeToDelete->getNext(reversed);
    prevNode->setNext(nextNode);
    nextNode->setPrev(prevNode);
    delete nodeToDelete;
    size--;
    return true;
}

void CircularList::clear()
{
    while (!isEmpty())
    {
        deleteFirst();
    }
}

void CircularList::changeDirection()
{
    reversed = !reversed;
}

bool CircularList::isReversed() const
{
    return reversed;
}

void CircularList::setDirection(bool rev)
{
    reversed = rev;
}

NodeC *CircularList::getNext(NodeC *node)
{
    if (node == nullptr || this->isEmpty())
    {
        throw EmptyListException();
    }
    return node->getNext(reversed);
}

NodeC *CircularList::getPrev(NodeC *node)
{
    if (node == nullptr || this->isEmpty())
    {
        throw EmptyListException();
    }
    return node->getPrev(reversed);
}
