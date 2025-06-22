//
// Created by Yotam Konopnicki on 22/06/2025.
//
#pragma once


class Genre;



/*
 * This is the class for nodes of reversed tree of songs that have a genre,
 * the parent is the parent in the reversed tree.
 @param sonId: the id of the song
 * genre is only for the root of the tree if not it is nullptr
 * and timeschanged is used for gettimeschanged function and changes of that variable is explained in the dry part
 */
class SongNode {

private:
    SongNode *parent{};
    int songId{};
    Genre *genre{};
    int timesChangedGenre{};

public:
    SongNode(SongNode *parent, int songId, Genre *genre);

    ~SongNode();

    Genre *getGenre() const;
    int getId() const;
    int getTimesChangedGenre() const;
    SongNode *getParent() const;
    void setParent(SongNode *parent);
    void setGenre(Genre *genre);
    void setTimesChangedGenre(int times);

};
