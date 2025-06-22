#include "stack.h"
template<typename T>
int Stack<T>::getSize() const {
    return size;
}
template<typename T>
void Stack<T>::setSize(int size) {
    this->size = size;
}