//
// Created by Yotam Konopnicki on 22/06/2025.
//
#pragma once
#include "SongNode.h"

/*
 * Genre is class of a genre of songs, every genre has a pointer to a reversed tree of songs that are from this genre
 * and (see SongNode class) the songs tree also has a pointer to the genre
 @param root: the root for the reversed tree of songs
 @param genreId: the id of the genre
 @param numSongs: the number of songs in the reversed tree
*/
class Genre {
private:
    SongNode *root;
    int genreId;
    int numSongs;

public:
    explicit Genre(int genreId);

    ~Genre();

    void setRoot(SongNode *root);
    SongNode *getRoot() const;

    int getId() const;
    int getNumSongs() const;
    void setNumSongs(int numSongs);

};
