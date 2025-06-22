//
// Created by oribo on 22/06/2025.
//

#ifndef STACK_H
#define STACK_H

#endif //STACK_H
template <typename T>
class Stack {
private:
    T* data;
    int *hash;
    int size;
public:
    Stack():data(nullptr), hash(nullptr), size(0) {}
    ~Stack();
};