// You can edit anything you want in this file.
// However you need to implement all public DSpotify function, as provided below as a template

#include "dspotify25b2.h"


DSpotify::DSpotify() = default;

DSpotify::~DSpotify() = default;


// add genre adds a genre to the genre table, first if checks the input, then it check if the genre already exists
// then it adds it
StatusType DSpotify::addGenre(int genreId){

    if( genreId <= 0) {
        return StatusType::INVALID_INPUT;
    }

    try {
        // we will try to find the genre in the genre table, if it is found then failure because the genre alredy exists
        genreTable.getItem(genreId);
        return StatusType::FAILURE;

    } catch (...) {
        try {

            Genre *genre = new Genre(genreId);
            genreTable.push(genre);

        } catch (...) {
            return StatusType::ALLOCATION_ERROR;
        }
    }
    return StatusType::SUCCESS;
}



/*
 * add song adds a song who's genre is genreId
 * first it will check the input, then it will check if the song already exists or the genre does not exist
 * then if everything is good it will add it to the
 */
StatusType DSpotify::addSong(int songId, int genreId){

    if(songId <= 0 || genreId <= 0) {
        return StatusType::INVALID_INPUT;
    }

    try {
        // if it finds the song in question then it is an error
        songTable.getItem(songId);
        return StatusType::FAILURE;

    } catch (...) {

        Genre *genre = genreTable.getItem(genreId);

        try {
            SongNode *songNode = new SongNode(nullptr, songId, nullptr);

            if(genre->getRoot() == nullptr) {
                genre->setRoot(songNode);
                songNode->setGenre(genre);
            }
            else {
                songNode->setParent(genre->getRoot());
            }
        } catch (...) {
            return StatusType::ALLOCATION_ERROR;
        }

    } catch (...) {
        //if the genre does not exist then it is a failure
        return StatusType::FAILURE;
    }

    return StatusType::SUCCESS;
}




StatusType DSpotify::mergeGenres(int genreId1, int genreId2, int genreId3){
    return StatusType::FAILURE;
}

output_t<int> DSpotify::getSongGenre(int songId){
    return 0;
}

output_t<int> DSpotify::getNumberOfSongsByGenre(int genreId){
    return 0;
}

output_t<int> DSpotify::getNumberOfGenreChanges(int songId){
    return 0;
}
