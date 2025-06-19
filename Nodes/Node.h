//
// Created by Yotam Konopnicki on 18/06/2025.
//

#ifndef NODE_H
#define NODE_H

#endif //NODE_H

template <typename T>
class Node {

private:
    Node *parent;
    int songId;
    T *genrePointer;

public:
    Node(Node *parent, int songId, T *genrePointer);

    ~Node();
};
