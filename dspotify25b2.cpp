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



StatusType DSpotify::addSong(int songId, int genreId){
    return StatusType::FAILURE;
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
