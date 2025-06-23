//
// Created by oribo on 22/06/2025.
//

#ifndef STACK_H
#define STACK_H

#endif //STACK_H
template <typename T>
class hashTable {
private:
    struct IntNode {
        int id;
        int data;
        IntNode *next;
        IntNode(int id, int data) : id(id), data(data), next(nullptr) {}
        IntNode(): id(0), data(0),next(nullptr) {}
        ~IntNode() {
            delete next;
        }
    };

    T** data;
    IntNode** hash;
    int size;
    int capacity;

public:
    hashTable();
    int getSize() const;
    void setSize(int size);
    T* getItem(int id) const;
    void push(T* item);
    ~hashTable();
};