#include "LinkedList.h"
#include "../exceptions/ListException.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template <typename T>
bool LinkedList<T>::insertFirst(T *value)
{
    if (head == nullptr)
    {
        head = new Node<T>(value);
        size++;
        return true;
    }
    return false;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->getNext();
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::insert(T *value)
{
    if (!insertFirst(value))
    {
        Node<T>* newNode = new Node<T>(value);
        Node<T> *current = head;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(newNode);
        newNode->setPrev(current);
    }
    size++;
}

template <typename T>
bool LinkedList<T>::insertAt(int index, T* value)
{
    if (index < 0 || index > size) {
        throw InvalidIndexException(index, size);
    }

    Node<T> *newNode = new Node<T>(value);

    if (index == 0)
    {
        return insertFirst(value);
    }
    else
    {
        Node<T> *current = head;
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

template <typename T>
bool LinkedList<T>::deleteAt(int index)
{
    if (index < 0 || index >= size || head == nullptr) {
        throw InvalidIndexException(index, size);
    }

    Node<T> *current = head;
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

template <typename T>
void LinkedList<T>::clear()
{

    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->getNext();
        delete temp;
    }
    size = 0;
}

template <typename T>
T LinkedList<T>::getAt(int index)
{
    if (index < 0 || index >= size) {
        throw InvalidIndexException(index, size);
    }
    Node<T> *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    return current->getData();
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
int LinkedList<T>::getSize()
{
    return size;
}