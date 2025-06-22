//This file does not contain checks for allocation failure or any extreme unusual cases

#include <stdexcept>
#include "stack.h"
template<typename T>
int Stack<T>::getSize() const {
    return size;
}
template<typename T>
void Stack<T>::setSize(int size) {
    this->size = size;
}

template<typename T>
void Stack<T>::push(T item) {
    if (size >= capacity) {
        //This part should move data into a new bigger array
        int oldCapacity = capacity;
        capacity *= 2;
        T** temp = new T* [capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        //This part should move hash into a new bigger array
        IntNode** temp2 = new IntNode* [capacity];
        for (int i = 0; i < oldCapacity; i++) {
            if (hash[i]!=nullptr) {
                IntNode* currIndex = hash[i];
                while(currIndex!=nullptr) {
                    int currId = currIndex->id;
                    int firstIndex = currId%capacity;
                    if (temp2[firstIndex]!=nullptr) {
                        IntNode* currNode = temp2[firstIndex];
                        while(currNode->next!=nullptr) {
                            currNode = currNode->next;
                        }
                        currNode->next = currIndex;
                    }
                    else {
                        temp2[firstIndex] = currIndex;
                    }
                    currIndex = currIndex->next;
                }
            }
        }
        delete [] hash;
        hash = temp2;
    }
    int currId = item.getId(); //We need to make sure T types have this function!!!
    int firstIndex = currId%capacity;
    if (hash[firstIndex]!=nullptr) {
        IntNode* currNode = hash[firstIndex];
        while(currNode->next!=nullptr) {
            currNode = currNode->next;
        }
        currNode->next = new IntNode(currId, size);
    }
    else {
        hash[firstIndex] = new IntNode(currId, size);
    }
    data[size++] = item;
}
template<typename T>
T* Stack<T>::getItem(int id) const {
    int firstIndex = id%capacity;
    IntNode* currIndex = hash[id];
    while (currIndex!=nullptr) {
        if (currIndex->data == id) {
            return currIndex->data;
        }
        currIndex = currIndex->next;
    }
    throw std::out_of_range("Item not found");//shouldn't happen whatsoever
}
template<typename T>
Stack<T>::~Stack() {
    for (int i = 0; i < capacity; i++) {
        delete data[i];
        delete hash[i];
    }
    delete [] data;
    delete [] hash;
}
