#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "Node.h"

template <typename T>
class CircularList {
private:
    Node<T>* head;
    int size;

public:
    CircularList() : head(nullptr), size(0) {}
    
    ~CircularList() {
        if (head == nullptr) return;
        Node<T>* current = head;
        do {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }
    
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node<T>* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
        size++;
    }
    
    void insertAt(int index, T value) {
        if (index < 0 || index > size) return;
        
        if (index == 0) {
            Node<T>* newNode = new Node<T>(value);
            if (head == nullptr) {
                head = newNode;
                head->next = head;
                head->prev = head;
            } else {
                Node<T>* last = head->prev;
                newNode->next = head;
                newNode->prev = last;
                last->next = newNode;
                head->prev = newNode;
                head = newNode;
            }
            size++;
            return;
        }
        
        Node<T>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }
    
    T remove(int index) {
        if (index < 0 || index >= size || head == nullptr) return T();
        
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        T value = current->data;
        
        if (current == head && size == 1) {
            delete head;
            head = nullptr;
        } else if (current == head) {
            head = head->next;
            current->prev->next = head;
            head->prev = current->prev;
            delete current;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        
        size--;
        return value;
    }
    
    T get(int index) {
        if (index < 0 || index >= size || head == nullptr) return T();
        
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    int getSize() {
        return size;
    }
    
    void clear() {
        if (head == nullptr) return;
        Node<T>* current = head;
        do {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
        head = nullptr;
        size = 0;
    }
};

#endif
