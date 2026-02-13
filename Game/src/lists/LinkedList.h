#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}
    
    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        size++;
    }
    
    void insertAt(int index, T value) {
        if (index < 0 || index > size) return;
        
        Node<T>* newNode = new Node<T>(value);
        
        if (index == 0) {
            newNode->next = head;
            if (head != nullptr) head->prev = newNode;
            head = newNode;
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            if (current->next != nullptr) current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
        }
        size++;
    }
    
    T remove(int index) {
        if (index < 0 || index >= size || head == nullptr) return T();
        
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        T value = current->data;
        
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        
        delete current;
        size--;
        return value;
    }
    
    T get(int index) {
        if (index < 0 || index >= size) return T();
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
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
};

#endif
