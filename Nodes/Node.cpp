#include "Node.h"

template<typename T>
Node<T>::Node(Node *parent, int songId, T *genrePointer): parent(parent), songId(songId), genrePointer(genrePointer){};


template<typename T>
Node<T>::~Node() = default;
