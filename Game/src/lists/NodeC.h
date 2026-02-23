#ifndef NODEC_H
#define NODEC_H

class Turn; // Forward declaration

class NodeC {
private:
    Turn* data;
    NodeC* next;
    NodeC* prev;

public:
    NodeC(Turn* value);
    ~NodeC();

    Turn* getData() const;

    NodeC* getNext(bool reversed = false) const;
    NodeC* getPrev(bool reversed = false) const;

    void setData(Turn* value);
    void setNext(NodeC* node);
    void setPrev(NodeC* node);
};

#endif
