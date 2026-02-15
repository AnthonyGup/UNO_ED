#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
    
    private:
        T* data;
        Node<T>* next;
        Node<T>* prev;
    
    public:
        Node(T* value);
        T* getData();
        Node<T>* getNext();
        Node<T>* getPrev();
};

#endif
