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

int main(){

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
    map <int, Song* > NameAlbum ;
    map <int, Song* >::iterator itna ;
    
    // This set of variables declares pointers
    Artist *artist ;
    Song *song ;
    Album *album ;

    // These two are used for calculation of song time
    int minutes, seconds ;

    // Reads in from the line of data
    while( cin >> songTitle >> songTime >> artistName >> albumName >> songGenre >> songTrack ){
    
        // Reads in title and replaces underscores with space
        replace( songTitle.begin(), songTitle.end(), '_', ' ' ) ;
        
        // Reads in time data and calculates the length of a song
        scanf("%i:%i", songTime, minutes, seconds);
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

        // Reads in the Album name and replaces underscores with spaces
        replace( albumName.begin(), albumName.end(), '_', ' ');
//        itna = NameAlbum.find(albumName) ;

        if ( itna == NameAlbum.end()){
            album = new Album(albumName) ; 
        }
        else{
//            album = itna->second ;
        }
        artist->albums[albumName] = album ;
        album->nsongs++ ;
        album->time += ( minutes*60+seconds );
//        album->album[songTrack] = song ;
    }
}


    
void Print(vector<vector<string>> album, vector<int> sets, vector<int> albumx){
    char space = ' ' ;
    printf("%s: %d, total time\n",
    album[sets.at(0)].at(2).c_str(), sets.size()) ;
    
    for ( int j = 0 ; j < albumx.size()-1 ; j++){
        if ( album[sets.at(j)].at(3) == album[sets.at(j+1) ].at(3) ){
            continue ;
        }
        else{
            printf("%8c%s: %d, total time\n" , space, album[sets.at(j+1)].at(3).c_str(), sets.size());  
            printf("%16c%s. %s: %s\n", space, album[sets.at(j+1)].at(5).c_str(),
                    album[sets.at(j+1)].at(0).c_str(), album[sets.at(j+1)].at(1).c_str());  
        }

    }
    printf("%8c%s: %d, total time\n" , space, album[sets.at(0)].at(3).c_str(), sets.size());

    // * we need to make a function that finds the total amount of time in the file so that can be impemented into the code
    
    for(int i = 0; i < sets.size(); i++){
        printf("%16c%s. %s: %s\n", space, album[sets.at(i)].at(5).c_str(),
        album[sets.at(i)].at(0).c_str(), album[sets.at(i)].at(1).c_str());
        
    }

}
// Finally prints the cleaned data

// Artist: # of songs, total time
//         Album: # of songs, total time
//                 track: song time
// it's 8 spaces indented for the album and sixteen for the track
