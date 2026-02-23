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
        Node *newNode = new Node(value);
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

bool LinkedList::insertAt(int index, Card *value)
{
    if (index < 0 || index > size)
    {
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
    if (index < 0 || index >= size || head == nullptr)
    {
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

Card *LinkedList::getAt(int index)
{
    if (index < 0 || index >= size || head == nullptr)
    {
        throw InvalidIndexException(index, size);
    }
    Node *current = head;
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
        Node *temp = head;
        head = head->getNext();
        delete temp;
    }
    size = 0;
}

// Comienza el quicksort ================================================================

bool LinkedList::isOnlyDigits(string text)
{
    if (text.empty())
    {
        return false;
    }

    for (char ch : text)
    {
        if (ch < '0' || ch > '9')
        {
            return false;
        }
    }

    return true;
}

int LinkedList::toNumber(string text)
{
    if (!isOnlyDigits(text))
    {
        return -1;
    }
    return stoi(text);
}

bool LinkedList::isColorlessOrNumberless(Card *card)
{
    if (card == nullptr)
    {
        return true;
    }

    int colorIndex = card->getSortColorIndex();
    string symbol = card->getSortSymbol();

    bool hasColor = colorIndex >= 0 && colorIndex <= 3;
    bool hasNumber = isOnlyDigits(symbol);

    return !hasColor || !hasNumber;
}

void LinkedList::swapNodeData(Node *a, Node *b)
{
    if (a == nullptr || b == nullptr || a == b)
    {
        return;
    }

    Card *temp = a->getData();
    a->setData(b->getData());
    b->setData(temp);
}

bool LinkedList::shouldGoBeforeOrEqual(Card *left, Card *right)
{
    if (left == nullptr || right == nullptr)
    {
        return left != nullptr;
    }

    bool leftSpecial = isColorlessOrNumberless(left);
    bool rightSpecial = isColorlessOrNumberless(right);

    if (leftSpecial != rightSpecial)
    {
        return !leftSpecial;
    }

    int leftColor = left->getSortColorIndex();
    int rightColor = right->getSortColorIndex();

    if (leftColor != rightColor)
    {
        return leftColor < rightColor;
    }

    string leftSymbol = left->getSortSymbol();
    string rightSymbol = right->getSortSymbol();
    int leftNumber = toNumber(leftSymbol);
    int rightNumber = toNumber(rightSymbol);

    if (leftNumber != -1 && rightNumber != -1)
    {
        return leftNumber <= rightNumber;
    }

    if (leftNumber != -1)
    {
        return true;
    }

    if (rightNumber != -1)
    {
        return false;
    }

    return leftSymbol <= rightSymbol;
}

Node *LinkedList::partition(Node *low, Node *high)
{
    Card *pivot = high->getData();
    Node *i = low->getPrev();

    for (Node *j = low; j != high; j = j->getNext())
    {
        if (shouldGoBeforeOrEqual(j->getData(), pivot))
        {
            if (i == nullptr)
            {
                i = low;
            }
            else
            {
                i = i->getNext();
            }
            swapNodeData(i, j);
        }
    }

    if (i == nullptr)
    {
        i = low;
    }
    else
    {
        i = i->getNext();
    }

    swapNodeData(i, high);
    return i;
}

void LinkedList::quickSortRec(Node *low, Node *high)
{
    if (low == nullptr || high == nullptr || low == high || low == high->getNext())
    {
        return;
    }

    Node *pivot = partition(low, high);

    if (pivot != nullptr && pivot->getPrev() != nullptr)
    {
        quickSortRec(low, pivot->getPrev());
    }

    if (pivot != nullptr && pivot->getNext() != nullptr)
    {
        quickSortRec(pivot->getNext(), high);
    }
}

Node *LinkedList::getTail(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    while (node->getNext() != nullptr)
    {
        node = node->getNext();
    }
    return node;
}

void LinkedList::sortCardsQuickSort()
{
    if (head == nullptr || head->getNext() == nullptr)
    {
        return;
    }

    Node *tail = getTail(head);
    quickSortRec(head, tail);
}