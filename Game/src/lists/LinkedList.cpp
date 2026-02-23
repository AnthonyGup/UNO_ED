#include "LinkedList.h"
#include "../exceptions/ListException.h"

LinkedList::LinkedList() : head(nullptr), size(0) {}

bool LinkedList::insertFirst(Card *value)
{
    if (head == nullptr)
    {
        head = new Node(value);
        size++;
        return true;
    }
    return false;
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->getNext();
        delete temp;
    }
}

void LinkedList::insert(Card *value)
{
    if (!insertFirst(value))
    {
        Node* newNode = new Node(value);
        Node *current = head;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(newNode);
        newNode->setPrev(current);
        size++;
    }
}

bool LinkedList::insertAt(int index, Card* value)
{
    if (index < 0 || index > size) {
        throw InvalidIndexException(index, size);
    }

    if (index == 0)
    {
        return insertFirst(value);
    }
    else
    {
        Node *newNode = new Node(value);
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        if (current->getNext() != nullptr)
        {
            current->getNext()->setPrev(newNode);
        }
        current->setNext(newNode);
        newNode->setPrev(current);
    }
    size++;
    return true;
}

bool LinkedList::deleteAt(int index)
{
    if (index < 0 || index >= size || head == nullptr) {
        throw InvalidIndexException(index, size);
    }

    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    if (current->getPrev() != nullptr)
    {
        current->getPrev()->setNext(current->getNext());
    }
    else
    {
        head = current->getNext();
    }

    if (current->getNext() != nullptr)
    {
        current->getNext()->setPrev(current->getPrev());
    }

    delete current;
    size--;
    return true;
}

Card* LinkedList::getAt(int index)
{
    if (index < 0 || index >= size || head == nullptr) {
        throw InvalidIndexException(index, size);
    }
    Node* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    return current->getData();
}

bool LinkedList::isEmpty()
{
    return head == nullptr;
}

int LinkedList::getSize()
{
    return size;
}

void LinkedList::clear()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
    size = 0;
}