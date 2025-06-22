//
// Created by Yotam Konopnicki on 22/06/2025.
//
#include "Genre.h"

Genre::Genre(int genreId): root(nullptr), genreId(genreId) {}

Genre::~Genre() = default;

int Genre::getId() const {
    return genreId;
}

SongNode *Genre::getRoot() const {
    return root;
}

void Genre::setRoot(SongNode *root) {
    this->root = root;
}





