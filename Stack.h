//
// Created by oribo on 22/06/2025.
//

#ifndef STACK_H
#define STACK_H

#endif //STACK_H
template <typename T>
class Stack {
private:
    struct IntNode {
        int id;
        int data;
        IntNode *next;
        IntNode(int id, int data) : id(id), data(data), next(nullptr) {}
        IntNode(): id(0), data(0),next(nullptr) {}
    };
    T** data;
    IntNode** hash;
    int size;
    int capacity;

public:
    Stack():data(new T*[1]), hash(new IntNode[1]), size(0), capacity(1) {}
    int getSize() const;
    void setSize(int size);
    T* getItem(int id) const;
    void push(T item);
    ~Stack();
};