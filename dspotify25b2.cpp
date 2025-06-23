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
        try{
            Genre *genre = genreTable.getItem(genreId);

            try {
                SongNode *songNode = new SongNode(nullptr, songId, nullptr);

                if(genre->getRoot() == nullptr) {

                    genre->setRoot(songNode);
                    songNode->setGenre(genre);

                }
                else {

                    songNode->setParent(genre->getRoot());
                    songNode->setTimesChangedGenre(-songNode->getParent()->getTimesChangedGenre()); //why this works explained in dry part
                }
                genre->setNumSongs(genre->getNumSongs() + 1);
            }catch (...) {
                //if the genre does not exist then it is a failure
                return StatusType::FAILURE;
            }
        } catch (...) {
            return StatusType::ALLOCATION_ERROR;
        }
    }

    return StatusType::SUCCESS;
}



/*
 * this function mesrges the songs under genre1 and genre2 in genre3, it will check input then check that genre1, genre2
 * exist and that genre3 does not exist then it will do the merging logic
 */
StatusType DSpotify::mergeGenres(int genreId1, int genreId2, int genreId3){

    if(genreId1 <= 0 || genreId2 <= 0 || genreId3 <= 0) {
        return StatusType::FAILURE;
    }

    try {
        // if genre3 exists then it is a failure if not there will be an exception
        genreTable.getItem(genreId3);
        return StatusType::FAILURE;

    } catch (...) {

        addGenre(genreId3);

        try {
            Genre *genre1 = genreTable.getItem(genreId1);
            Genre *genre2 = genreTable.getItem(genreId2);
            Genre *genre3 = genreTable.getItem(genreId3);

            if(genre1->getNumSongs() == 0 || genre2->getNumSongs() == 0) {
                //if both genres are empty we don't need to do anything
                return StatusType::SUCCESS;
            }
            //if one of the genres is empty we can do a simpler algorithm
            if(genre1->getNumSongs() == 0) {

                //adjusting times changed genre
                genre2->getRoot()->setTimesChangedGenre(genre2->getRoot()->getTimesChangedGenre() + 1);

                //adjusting genre of the root
                genre2->getRoot()->setGenre(genre3);

                //adjusting the roots of the genres
                genre3->setRoot(genre2->getRoot());
                genre2->setRoot(nullptr);

                //adjusting  num songs
                genre3->setNumSongs(genre2->getNumSongs());
                genre2->setNumSongs(0);

                return StatusType::SUCCESS;
            }

            if(genre2->getNumSongs() == 0) {

                // adjusting times changed genre
                genre1->getRoot()->setTimesChangedGenre(genre1->getRoot()->getTimesChangedGenre() + 1);

                // adjusting genre of the root
                genre1->getRoot()->setGenre(genre3);

                //adjusting the roots of the genres
                genre3->setRoot(genre1->getRoot());
                genre1->setRoot(nullptr);

                //adjusting  num songs
                genre3->setNumSongs(genre1->getNumSongs());
                genre1->setNumSongs(0);

                return StatusType::SUCCESS;
            }
            //if both genres have songs we need to determine which one is bigger and then do the algorithm
            Genre *biggerGenre;
            Genre *smallerGenre;

            if(genre1->getNumSongs() >= genre2->getNumSongs()) {
                biggerGenre = genre1;
                smallerGenre = genre2;
            }
            else {
                biggerGenre = genre2;
                smallerGenre= genre1;
            }

            SongNode *rootOfBiggerGenre = biggerGenre->getRoot();
            SongNode *rootOfSmallerGenre = smallerGenre->getRoot();

            //adjusting times changed genre for both roots
            rootOfSmallerGenre->setTimesChangedGenre(rootOfSmallerGenre->getTimesChangedGenre() -
                rootOfBiggerGenre->getTimesChangedGenre());
            rootOfBiggerGenre->setTimesChangedGenre(rootOfBiggerGenre->getTimesChangedGenre() + 1);

            //adjusting parents
            rootOfSmallerGenre->setParent(rootOfBiggerGenre);

            //adjusting genre of roots
            rootOfSmallerGenre->setGenre(nullptr);
            rootOfBiggerGenre->setGenre(genre3);

            //adjusting the genres pointer to root
            genre1->setRoot(nullptr);
            genre2->setRoot(nullptr);
            genre3->setRoot(rootOfBiggerGenre);

            //adjusting the number of songs in each genre
            genre3->setNumSongs(genre1->getNumSongs() + genre2->getNumSongs());
            genre1->setNumSongs(0);
            genre2->setNumSongs(0);

            return StatusType::SUCCESS;

        } catch (...) {
            //if one of the genres does not exist of there has been an error than failure
            return StatusType::FAILURE;
        }
    }
}




// this function returns the genre of the song, it will check input then check if the song exists then climb up the tree and return the genre
output_t<int> DSpotify::getSongGenre(int songId){

    if(songId <= 0) {
        return StatusType::INVALID_INPUT;
    }

    try {

        SongNode *songNode = songTable.getItem(songId);

        while (songNode->getParent() != nullptr) {
            songNode = songNode->getParent();
        }

        return songNode->getGenre()->getId();

    } catch (...) {
        return StatusType::FAILURE;
    }
}


//ths function returns the number of songs in a genre, it will check input, then check the genre exists,
//and it will return the numsongs of that genre
output_t<int> DSpotify::getNumberOfSongsByGenre(int genreId){

    if(genreId <= 0) {
        return StatusType::INVALID_INPUT;
    }

    try {

        return genreTable.getItem(genreId)->getNumSongs();

    } catch (...) {
        return StatusType::FAILURE;
    }
}



// this function returns the number of times this sond changed genres, it will check input then do the algorithm from dry
output_t<int> DSpotify::getNumberOfGenreChanges(int songId){

    if(songId <= 0) {
        return StatusType::INVALID_INPUT;
    }

    int totalTimesChanged = 0;
    try {

        SongNode *node = songTable.getItem(songId);

        totalTimesChanged += node->getTimesChangedGenre();

        while (node->getParent() != nullptr) {
            node = node->getParent();
            totalTimesChanged += node->getTimesChangedGenre();
        }
        return totalTimesChanged;

    } catch (...) {
        return StatusType::FAILURE;
    }
}
