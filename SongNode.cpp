#include "SongNode.h"
//
// Created by Yotam Konopnicki on 22/06/2025.
//

SongNode::SongNode(SongNode *parent, int songId, Genre *genre): parent(parent),
songId(songId), genre(genre), timesChangedGenre(1) {}

SongNode::~SongNode() = default;

Genre *SongNode::getGenre() const {
    return genre;
}


int SongNode::getId() const{
    return songId;
}


SongNode *SongNode::getParent() const{
    return parent;
}


int SongNode::getTimesChangedGenre() const{
    return timesChangedGenre;
}

void SongNode::setGenre(Genre *genre) {
    this->genre = genre;
}

void SongNode::setParent(SongNode *parent) {
    this->parent = parent;
}

void SongNode::setTimesChangedGenre(int times) {
    timesChangedGenre = times;
}





