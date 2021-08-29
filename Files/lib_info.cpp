// Project 01: Music Library Tool
// The goal of this project is to reorganize a music discography file 
//      into something that's easier to understand. 
// COSC 302
// Swasti Mishra and Katie Nuchols
// Date: August 24th, 2021
// Professor Emrich

# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include <map>
# include <fstream>
# include <sstream>

using namespace std;

//void Print(vector<vector<string>> album, vector<int> sets, vector<int> albumx);
//string TotalTime(vector<vector<string>> album, vector<int> sets);
// Functions

struct Song { 
    struct Artist *artist ;
    string title;
    int time;  // could also be a string
    int track;

    Song( string title , int time , int track){
        this->artist = nullptr ;
        this->title = title ;
        this->time = time ;
        this->track = track ;
    } ;
};

struct Album {
    map <int, Song* > songs ;
    string name ;
    int time ;
    int nsongs ;

    Album( string name ){
        this->name = name ;
        this->time = 0 ;
        this->nsongs = 0 ;
    } ;
} ;

struct Artist {
    map <string, Album* > albums;
    string name;
    int time;
    int nsongs;
    
    Artist( string name ){
        this->name = name ;
        this->time = 0 ;
        this->nsongs = 0 ;
    } ;
};

int main( int argc, char *argv[]){

    // Variables 
    // This set of variables reads in the data from each line of text
    string songTitle ;
    string songTime ;
    string artistName ;
    string albumName ;
    string songGenre ;
    int songTrack ;

    // This set of variables names iterators for the first map
    map <string, Artist* > NameArtist ;
    map <string, Artist* >::iterator it ;
    // This set of variables names iterators for the second map
    map <string, Album* > NameAlbum ;
    map <string, Album* >::iterator it2 ;

    map <string, Song* > NameSong ;
    map <int, Song* >::iterator it3 ;
    
    // This set of variables declares pointers
    Artist *artist ;
    Song *song ;
    Album *album ;

    // These two are used for calculation of song time
    int minutes, seconds ;

    ifstream file ;
    file.open( argv[1] ) ;

    // Reads in from the line of data
    while( file >> songTitle >> songTime >> artistName >> albumName >> songGenre >> songTrack ){
    
        // Reads in title and replaces underscores with space
        replace( songTitle.begin(), songTitle.end(), '_', ' ' ) ;
        
        // Reads in time data and calculates the length of a song
        sscanf(songTime.c_str() , "%d:%d", &minutes, &seconds);
        song = new Song( songTitle, ( minutes * 60 + seconds ), songTrack ) ;

        // Reads in the Artist name and replaces underscores with spaces
        replace( artistName.begin(), artistName.end(), '_', ' ' ) ;
        it = NameArtist.find(artistName);
        
        // Creates a new artist if the artist name doesn't already exist 
        if ( it == NameArtist.end()){
            artist = new Artist(artistName) ;
            NameArtist[artistName] = artist ;
        }
        else{ 
            artist = it->second ;
        }
        artist->time += song->time ;
        song->artist = artist ;
        artist->nsongs++ ;

        //katie added
        //song->title = artist;

        //katie added

        // Reads in the Album name and replaces underscores with spaces
        replace( albumName.begin(), albumName.end(), '_', ' ');
        it2 = NameAlbum.find(albumName) ;

        // might not be necessary 
        if ( it2 == NameAlbum.end()){
            album = new Album(albumName) ;
            NameAlbum[albumName] = album;
        }
        else{
            album = it2->second ;
        }
        artist->albums[albumName] = album ;
        album->nsongs++ ;
        album->time += ( minutes * 60 + seconds );
        album->songs[songTrack] = song ;

        //figure out how to only print last one

    }
    int Minutes, Seconds;
    for( it = NameArtist.begin() ; it != NameArtist.end()--; ++it) {
        Minutes = (it->second->time / 60);
        Seconds = (it->second->time)-(Minutes * 60);
        cout << it->first << ": " << it->second->nsongs << ", ";
        printf("%d:%02d\n", Minutes, Seconds);
        for( it2 = it->second->albums.begin(); it2 != it->second->albums.end(); ++it2){
            printf("%8c", ' ');
            cout << it2->first << ": " << it2->second->nsongs << ", ";
            printf("%d:%02d\n", Minutes, Seconds);
            //for loop to iterate through this part
            
            for( it3 = it2->second->songs.begin(); it3 != it2->second->songs.end(); ++it3){
                printf("%16c", ' ');
                Minutes = (it3->second->time / 60);
                Seconds = (it3->second->time)-(Minutes * 60);
                cout << it3->second->track << ". " << it3->second->title << ": ";
                printf("%d:%02d\n", Minutes, Seconds);
            }
        }
    }
    return EXIT_SUCCESS;
}

// Artist: # of songs, total time
//         Album: # of songs, total time
//                 track: song time
// it's 8 spaces indented for the album and sixteen for the track