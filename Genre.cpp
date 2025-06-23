//
// Created by Yotam Konopnicki on 22/06/2025.
//
#include "Genre.h"

Genre::Genre(int genreId): root(nullptr), genreId(genreId), numSongs(0){}

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


int Genre::getNumSongs() const {
    return numSongs;
}

void Genre::setNumSongs(int numSongs) {
    this->numSongs = numSongs;
}




