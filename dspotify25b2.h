// 
// 234218 Data Structures 1.
// Semester: 2025B (Spring).
// Wet Exercise #2.
// 
// The following header file contains all methods we expect you to implement.
// You MAY add private methods and fields of your own.
// DO NOT erase or modify the signatures of the public methods.
// DO NOT modify the preprocessors in this file.
// DO NOT use the preprocessors in your other code files.
// 

#ifndef DSPOTIFY25SPRING_WET2_H_
#define DSPOTIFY25SPRING_WET2_H_

#include "Genre.h"
#include "hashTable.h"
#include "wet2util.h"

/*
 * the class Dspotify has a table of genres that have reversed tree of songs and also pointers to these songs will be
 * saved in another hash table so we can access to data from songs
 @param genreTable: the hash table of the genres
 @param songTable : the hash table of the songs
 */
class DSpotify {
private:
    //
    // Here you may add anything you want
    //
    hashTable<Genre> genreTable;
    hashTable<SongNode> songTable;
    
public:
    // <DO-NOT-MODIFY> {
    DSpotify();

    virtual ~DSpotify();

    StatusType addGenre(int genreId);

    StatusType addSong(int songId, int genreId);

    StatusType mergeGenres(int genreId1, int genreId2, int genreId3);

    output_t<int> getSongGenre(int songId);

    output_t<int> getNumberOfSongsByGenre(int genreId);

    output_t<int> getNumberOfGenreChanges(int songId);
    // } </DO-NOT-MODIFY>
};

#endif // DSPOTIFY25SPRING_WET2_H_
