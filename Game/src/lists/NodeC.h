#ifndef NODEC_H
#define NODEC_H

template <typename T>
class NodeC {
private:
    T* data;
    NodeC<T>* next;
    NodeC<T>* prev;

public:
    NodeC(T* value);
    ~NodeC();
    
    T* getData() const;
    
    // Métodos que consideran la dirección
    NodeC<T>* getNext(bool reversed = false) const;
    NodeC<T>* getPrev(bool reversed = false) const;
    
    // Métodos de configuración
    void setData(T* value);
    void setNext(NodeC<T>* node);
    void setPrev(NodeC<T>* node);
};

#endif
