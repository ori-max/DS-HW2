//This file does not contain checks for allocation failure or any extreme unusual cases

#include <stdexcept>
#include "hashTable.h"

template<typename T>
hashTable<T>::hashTable():data(new T*[1]()), hash(new IntNode*[1]()), size(0), capacity(1) {}


template<typename T>
int hashTable<T>::getSize() const {
    return size;
}


template<typename T>
void hashTable<T>::setSize(int size) {
    this->size = size;
}

template<typename T>
void hashTable<T>::push(T* item) {
    if (size >= capacity) {
        //This part should move data into a new bigger array
        int oldCapacity = capacity;
        capacity *= 2;
        T** temp = new T* [capacity]();
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        //This part should move hash into a new bigger array
        IntNode** temp2 = new IntNode* [capacity]();
        for (int i = 0; i < oldCapacity; i++) {
            IntNode* currIndex = hash[i];
            while (currIndex!=nullptr) {
                IntNode* nextNode = currIndex->next;
                int currId = currIndex->id;
                int firstIndex = currId%capacity;
                currIndex->next = temp2[firstIndex];
                temp2[firstIndex] = currIndex;

                currIndex = nextNode;
            }
        }
        delete [] hash;
        hash = temp2;
    }

    int currId = item->getId(); //We need to make sure T types have this function!!!
    int firstIndex = currId%capacity;
    IntNode* newNode = new IntNode(currId, size);
    newNode->next = hash[firstIndex];
    hash[firstIndex] = newNode;
    data[size++] = item;
}


template<typename T>
T* hashTable<T>::getItem(int id) const {
    int firstIndex = id%capacity;
    IntNode* currIndex = hash[firstIndex];
    while (currIndex!=nullptr) {
        if (currIndex->id == id) {
            return data[currIndex->data];
        }
        currIndex = currIndex->next;
    }
    throw std::out_of_range("Item not found");//shouldn't happen whatsoever
}


template<typename T>
hashTable<T>::~hashTable() {
    for (int i = 0; i < capacity; i++) {
        delete data[i];
        delete hash[i];
    }
    delete [] data;
    delete [] hash;
}
