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
        void setNext(Node<T>* nextNode);
        void setPrev(Node<T>* prevNode);
        Node<T>* getNext();
        Node<T>* getPrev();
};

#endif
